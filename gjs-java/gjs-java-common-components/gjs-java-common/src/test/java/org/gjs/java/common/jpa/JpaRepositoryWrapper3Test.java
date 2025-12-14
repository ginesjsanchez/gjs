package org.gjs.java.common.jpa;

import static org.junit.jupiter.api.Assertions.assertEquals;
import static org.junit.jupiter.api.Assertions.assertNotNull;
import static org.junit.jupiter.api.Assertions.assertNull;
import static org.junit.jupiter.api.Assertions.assertTrue;
import static org.junit.jupiter.api.Assertions.fail;

import java.util.HashMap;
import java.util.Map;
import java.util.Optional;

import org.apache.commons.lang3.exception.ExceptionUtils;
import org.gjs.java.common.jpa.JpaRepositoryWrapper;
import org.gjs.java.test.BaseUnitTest;
import org.gjs.java.test.mock.MockRepository;
import org.gjs.java.test.mock.MockSimplePKRepository;
import org.gjs.java.test.sample.model.OtherEntity;
import org.gjs.java.test.sample.model.SampleEntity;
import org.gjs.java.test.sample.model.SamplePK;
import org.gjs.java.test.sample.model.SampleWithPKEntity;
import org.junit.jupiter.api.Test;
import org.springframework.core.io.ClassPathResource;

@SuppressWarnings("rawtypes")
public class JpaRepositoryWrapper3Test extends BaseUnitTest<JpaRepositoryWrapper> {

	static class MockSampleRepository extends MockSimplePKRepository<SampleEntity> {

		@Override
		protected Class<?> getClazz() {
			return SampleEntity.class;
		}

	}

	static class MockOtherRepository extends MockSimplePKRepository<OtherEntity> {

		@Override
		protected Class<?> getClazz() {
			return OtherEntity.class;
		}
	}

	static class MockSampleWithPKRepository extends MockRepository<SampleWithPKEntity, SamplePK> {

		@Override
		protected Class<?> getClazz() {
			return SampleWithPKEntity.class;
		}

		@Override
		protected Class<?> getPKClazz() {
			return SamplePK.class;
		}
	}

	static MockSampleRepository mockSampleRepository;
	static MockOtherRepository mockOtherRepository;
	static MockSampleWithPKRepository mockRepository;

	@Override
	protected Class<?> getClazz() {
		return JpaRepositoryWrapper.class;
	}

	@Override
	protected void initialize() throws Exception {
		mockSampleRepository = new MockSampleRepository();
		mockOtherRepository = new MockOtherRepository();
		mockRepository = new MockSampleWithPKRepository();
	}

	@Test
	void testJpaRepositoryWrapper1() {
		try {
			mockRepository.clear();
			mockSampleRepository.clear();
			mockOtherRepository.clear();

			final JpaRepositoryWrapper<SampleEntity, Long> sampleRepositoryWrapper = new JpaRepositoryWrapper<>(
					SampleEntity.class, Long.class, mockSampleRepository);

			final JpaRepositoryWrapper<OtherEntity, Long> otherRepositoryWrapper = new JpaRepositoryWrapper<>(
					OtherEntity.class, Long.class, mockOtherRepository);

			sampleRepositoryWrapper.loadCsv(new ClassPathResource("data/sampleEntity.csv"));
			logger.info("Cargadas {} SampleEntity...", mockSampleRepository.count());
			assertEquals(4, mockSampleRepository.count());

			otherRepositoryWrapper.loadCsv(new ClassPathResource("data/otherEntity.csv"));
			logger.info("Cargadas {} OtherEntity...", mockOtherRepository.count());
			assertEquals(2, mockOtherRepository.count());

			final JpaRepositoryWrapper<SampleWithPKEntity, SamplePK> repositoryWrapper = new JpaRepositoryWrapper<>(
					SampleWithPKEntity.class, SamplePK.class, mockRepository);

			final Map<String, JpaRepositoryWrapper<?, ?>> dependencies = new HashMap<>();
			final Map<String, String> fieldCorrespondencies = new HashMap<>();
			dependencies.put("sampleId", sampleRepositoryWrapper);
			dependencies.put("otherId", otherRepositoryWrapper);
			fieldCorrespondencies.put("sampleId", "sample");
			fieldCorrespondencies.put("otherId", "other");

			repositoryWrapper.setJpaDependencies(dependencies);
			repositoryWrapper.setFieldCorrespondencies(fieldCorrespondencies);

			assertNotNull(repositoryWrapper.getEntity());
			assertEquals(SampleWithPKEntity.class, repositoryWrapper.getEntity());
			assertNotNull(repositoryWrapper.getPk());
			assertEquals(SamplePK.class, repositoryWrapper.getPk());
			assertNotNull(repositoryWrapper.getRepository());
			assertEquals(mockRepository, repositoryWrapper.getRepository());
			assertNotNull(repositoryWrapper.getJpaDependencies());
			assertEquals(2, repositoryWrapper.getJpaDependencies().size());
			assertNotNull(repositoryWrapper.getFieldCorrespondencies());
			assertEquals(2, repositoryWrapper.getFieldCorrespondencies().size());

			assertNull(repositoryWrapper.getDataFile());
			assertEquals(0, mockRepository.count());
			logger.info("Se va a cargar SampleWithPKEntity...");
			repositoryWrapper.loadCsv(new ClassPathResource("data/sampleWithPKEntity.csv"));
			logger.info("Cargadas {} SampleWithFKEntity...", mockRepository.count());
			assertNotNull(repositoryWrapper.getDataFile());
			assertEquals(5, mockRepository.count());

			final SamplePK id = new SamplePK();
			id.setSampleId(1);
			id.setOtherId(1);
			final Optional<SampleWithPKEntity> opt = mockRepository.findById(id);
			assertNotNull(opt);
			assertTrue(opt.isPresent());
			assertNotNull(opt.get());
			assertEquals(id, opt.get().getId());
			assertNotNull(opt.get().getSample());
			assertEquals(id.getSampleId(), opt.get().getSample().getId());
			assertEquals(id.getOtherId(), opt.get().getOther().getId());

		} catch (final Exception e) {
			logger.error(ExceptionUtils.getStackTrace(e));
			fail("Se ha producido un error");
		}
	}

}
