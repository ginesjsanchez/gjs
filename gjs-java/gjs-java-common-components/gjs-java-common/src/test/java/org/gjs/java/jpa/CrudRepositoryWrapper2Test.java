package org.gjs.java.jpa;

import static org.junit.jupiter.api.Assertions.assertEquals;
import static org.junit.jupiter.api.Assertions.assertNotNull;
import static org.junit.jupiter.api.Assertions.assertNull;
import static org.junit.jupiter.api.Assertions.assertTrue;
import static org.junit.jupiter.api.Assertions.fail;

import java.util.HashMap;
import java.util.Map;
import java.util.Optional;

import org.apache.commons.lang3.exception.ExceptionUtils;
import org.gjs.java.test.BaseUnitTest;
import org.gjs.java.test.mock.MockRepository;
import org.gjs.java.test.sample.model.SampleEntity;
import org.gjs.java.test.sample.model.SampleWithFKEntity;
import org.junit.jupiter.api.Test;
import org.springframework.core.io.ClassPathResource;

@SuppressWarnings("rawtypes")
public class CrudRepositoryWrapper2Test extends BaseUnitTest<CrudRepositoryWrapper> {

	static class MockSampleRepository extends MockRepository<SampleEntity, Long> {

		@Override
		protected Class<?> getClazz() {
			return SampleEntity.class;
		}

		@Override
		protected Class<?> getPKClazz() {
			return Long.class;
		}
	}

	static class MockSampleWithFKRepository extends MockRepository<SampleWithFKEntity, Long> {

		@Override
		protected Class<?> getClazz() {
			return SampleWithFKEntity.class;
		}

		@Override
		protected Class<?> getPKClazz() {
			return Long.class;
		}
	}

	static MockSampleRepository mockSampleRepository;
	static MockSampleWithFKRepository mockRepository;

	@Override
	protected Class<?> getClazz() {
		return CrudRepositoryWrapper.class;
	}

	@Override
	protected void initialize() throws Exception {
		mockSampleRepository = new MockSampleRepository();
		mockRepository = new MockSampleWithFKRepository();
		// mockRepository.addRelation(new ForeignKey(new DataKey("sampleId"), new
		// DataKey("id")), mockSampleRepository);

	}

	@Test
	void testCrudRepositoryWrapper1() {
		try {
			mockRepository.clear();
			mockSampleRepository.clear();

			final CrudRepositoryWrapper<SampleEntity, Long> sampleRepositoryWrapper = new CrudRepositoryWrapper<>(
					SampleEntity.class, Long.class, mockSampleRepository);

			sampleRepositoryWrapper.loadCsv(new ClassPathResource("data/sampleEntity.csv"));
			logger.info("Cargadas {} SampleEntity...", mockSampleRepository.count());
			assertEquals(4, mockSampleRepository.count());

			final CrudRepositoryWrapper<SampleWithFKEntity, Long> repositoryWrapper = new CrudRepositoryWrapper<>(
					SampleWithFKEntity.class, Long.class, mockRepository);

			final Map<String, CrudRepositoryWrapper<?, ?>> dependencies = new HashMap<>();
			final Map<String, String> fieldCorrespondencies = new HashMap<>();
			dependencies.put("sampleId", sampleRepositoryWrapper);
			fieldCorrespondencies.put("sampleId", "sample");

			repositoryWrapper.setDependencies(dependencies);
			repositoryWrapper.setFieldCorrespondencies(fieldCorrespondencies);

			assertNotNull(repositoryWrapper.getEntity());
			assertEquals(SampleWithFKEntity.class, repositoryWrapper.getEntity());
			assertNotNull(repositoryWrapper.getPk());
			assertEquals(Long.class, repositoryWrapper.getPk());
			assertNotNull(repositoryWrapper.getRepository());
			assertEquals(mockRepository, repositoryWrapper.getRepository());
			assertNotNull(repositoryWrapper.getDependencies());
			assertEquals(1, repositoryWrapper.getDependencies().size());
			assertNotNull(repositoryWrapper.getFieldCorrespondencies());
			assertEquals(1, repositoryWrapper.getFieldCorrespondencies().size());

			assertNull(repositoryWrapper.getDataFile());
			assertEquals(0, mockRepository.count());
			logger.info("Se va a cargar SampleWithFKEntity...");
			repositoryWrapper.loadCsv(new ClassPathResource("data/sampleWithFKEntity.csv"));
			logger.info("Cargadas {} SampleWithFKEntity...", mockRepository.count());
			assertNotNull(repositoryWrapper.getDataFile());
			assertEquals(6, mockRepository.count());

			final Optional<SampleWithFKEntity> opt = mockRepository.findById(Long.valueOf(1));
			assertNotNull(opt);
			assertTrue(opt.isPresent());
			assertNotNull(opt.get());
			assertEquals(1, opt.get().getId());
			assertNotNull(opt.get().getNombre());
			assertEquals("ADM_SEMILLA2", opt.get().getNombre());
			assertNotNull(opt.get().getSample());
			assertNotNull(opt.get().getSample().getId());
			assertEquals(Long.valueOf(1), opt.get().getSample().getId());

		} catch (final Exception e) {
			logger.error(ExceptionUtils.getStackTrace(e));
			fail("Se ha producido un error");
		}
	}

}
