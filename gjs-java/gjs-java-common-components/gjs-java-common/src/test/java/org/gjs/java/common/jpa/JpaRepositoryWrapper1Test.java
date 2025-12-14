package org.gjs.java.common.jpa;

import static org.junit.jupiter.api.Assertions.assertEquals;
import static org.junit.jupiter.api.Assertions.assertNotNull;
import static org.junit.jupiter.api.Assertions.assertNull;
import static org.junit.jupiter.api.Assertions.assertTrue;
import static org.junit.jupiter.api.Assertions.fail;

import java.nio.file.Path;
import java.util.Optional;

import org.apache.commons.lang3.exception.ExceptionUtils;
import org.gjs.java.common.jpa.JpaRepositoryWrapper;
import org.gjs.java.test.BaseUnitTest;
import org.gjs.java.test.mock.MockRepository;
import org.gjs.java.test.samples.pojos.SamplePojo;
import org.junit.jupiter.api.Test;
import org.mockito.ArgumentMatchers;
import org.mockito.Mock;
import org.mockito.Mockito;
import org.springframework.core.io.ClassPathResource;
import org.springframework.data.jpa.repository.JpaRepository;

@SuppressWarnings("rawtypes")
public class JpaRepositoryWrapper1Test extends BaseUnitTest<JpaRepositoryWrapper> {

	static class MockSampleRepository extends MockRepository<SamplePojo, Long> {

		@Override
		protected Class<?> getClazz() {
			return SamplePojo.class;
		}

		@Override
		protected Class<?> getPKClazz() {
			return Long.class;
		}
	}

	@Mock
	JpaRepository<SamplePojo, Long> repository;

	static MockSampleRepository mockRepository;

	@Override
	protected Class<?> getClazz() {
		return JpaRepositoryWrapper.class;
	}

	@Override
	protected void initialize() throws Exception {
		mockRepository = new MockSampleRepository();
	}

	@Test
	void testJpaRepositoryWrapper1() {
		try {
			final Path filePath = currentDir.resolve("data/sample1.csv");
			logger.info("{}", filePath.toAbsolutePath().toString().replace("\\", "\\\\"));
			mockRepository.clear();

			Mockito.when(repository.save(ArgumentMatchers.any(SamplePojo.class)))
					.thenAnswer(invocation -> mockRepository.save(invocation.getArgument(0, SamplePojo.class)));

			final JpaRepositoryWrapper<SamplePojo, Long> repositoryWrapper = new JpaRepositoryWrapper<>(
					SamplePojo.class, Long.class, repository);

			assertNotNull(repositoryWrapper.getEntity());
			assertEquals(SamplePojo.class, repositoryWrapper.getEntity());
			assertNotNull(repositoryWrapper.getPk());
			assertEquals(Long.class, repositoryWrapper.getPk());
			assertNotNull(repositoryWrapper.getRepository());
			assertEquals(repository, repositoryWrapper.getRepository());
			assertNull(repositoryWrapper.getJpaDependencies());
			assertNull(repositoryWrapper.getFieldCorrespondencies());

			assertNull(repositoryWrapper.getDataFile());
			assertEquals(0, mockRepository.count());
			repositoryWrapper.loadCsv();
			assertNull(repositoryWrapper.getDataFile());
			assertEquals(0, mockRepository.count());
			repositoryWrapper.loadCsv(filePath.toFile().getAbsolutePath());
			assertNotNull(repositoryWrapper.getDataFile());
			assertEquals(filePath.toFile().getAbsolutePath(), repositoryWrapper.getDataFile());
			assertEquals(3, mockRepository.count());
			final Optional<SamplePojo> opt = mockRepository.findById(Long.valueOf(1));
			assertNotNull(opt);
			assertTrue(opt.isPresent());
			assertNotNull(opt.get());
			assertEquals(1, opt.get().getId());
			assertNotNull(opt.get().getNombre());
			assertEquals("Sample1", opt.get().getNombre());

		} catch (final Exception e) {
			logger.error(ExceptionUtils.getStackTrace(e));
			fail("Se ha producido un error");
		}
	}

	@Test
	void testJpaRepositoryWrapper2() {
		try {
			final Path filePath = currentDir.resolve("data/sample1.csv");
			logger.info("{}", filePath.toAbsolutePath().toString().replace("\\", "\\\\"));
			mockRepository.clear();

			Mockito.when(repository.save(ArgumentMatchers.any(SamplePojo.class)))
					.thenAnswer(invocation -> mockRepository.save(invocation.getArgument(0, SamplePojo.class)));

			final JpaRepositoryWrapper<SamplePojo, Long> repositoryWrapper = new JpaRepositoryWrapper<>(
					SamplePojo.class, Long.class, repository, filePath.toAbsolutePath().toString());
			assertNotNull(repositoryWrapper.getDataFile());
			assertEquals(filePath.toFile().getAbsolutePath(), repositoryWrapper.getDataFile());
			repositoryWrapper.loadCsv();
			assertEquals(3, mockRepository.count());

			repositoryWrapper.loadCsv();
			assertEquals(3, mockRepository.count());
		} catch (final Exception e) {
			logger.error(ExceptionUtils.getStackTrace(e));
			fail("Se ha producido un error");
		}
	}

	@Test
	void testJpaRepositoryWrapper3() {
		try {
			mockRepository.clear();
			final JpaRepositoryWrapper<SamplePojo, Long> repositoryWrapper = new JpaRepositoryWrapper<>(
					SamplePojo.class, Long.class, repository);

			Mockito.when(repository.save(ArgumentMatchers.any(SamplePojo.class)))
					.thenAnswer(invocation -> mockRepository.save(invocation.getArgument(0, SamplePojo.class)));

			repositoryWrapper.loadCsv(new ClassPathResource("data/sample1.csv"));
			assertNotNull(repositoryWrapper.getDataFile());
			assertEquals(3, mockRepository.count());

			repositoryWrapper.loadCsv();
			assertEquals(3, mockRepository.count());
		} catch (final Exception e) {
			logger.error(ExceptionUtils.getStackTrace(e));
			fail("Se ha producido un error");
		}
	}

	@Test
	void testJpaRepositoryWrapper4() {
		try {
			final Path filePath = currentDir.resolve("data/noexiste.csv");
			logger.info("{}", filePath.toAbsolutePath().toString().replace("\\", "\\\\"));
			mockRepository.clear();

			final JpaRepositoryWrapper<SamplePojo, Long> repositoryWrapper = new JpaRepositoryWrapper<>(
					SamplePojo.class, Long.class, repository, filePath.toAbsolutePath().toString());
			assertNotNull(repositoryWrapper.getDataFile());
			assertEquals(filePath.toFile().getAbsolutePath(), repositoryWrapper.getDataFile());
			repositoryWrapper.loadCsv();
			assertEquals(0, mockRepository.count());

		} catch (final Exception e) {
			logger.error(ExceptionUtils.getStackTrace(e));
			fail("Se ha producido un error");
		}
	}

}
