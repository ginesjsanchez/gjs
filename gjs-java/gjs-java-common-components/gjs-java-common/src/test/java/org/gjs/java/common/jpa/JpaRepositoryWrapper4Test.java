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
import org.gjs.java.test.samples.pojos.SampleStringIdPojo;
import org.junit.jupiter.api.Test;
import org.mockito.ArgumentMatchers;
import org.mockito.Mock;
import org.mockito.Mockito;
import org.springframework.core.io.ClassPathResource;
import org.springframework.data.jpa.repository.JpaRepository;

@SuppressWarnings("rawtypes")
public class JpaRepositoryWrapper4Test extends BaseUnitTest<JpaRepositoryWrapper> {

	static class MockSampleRepository extends MockRepository<SampleStringIdPojo, String> {

		@Override
		protected Class<?> getClazz() {
			return SampleStringIdPojo.class;
		}

		@Override
		protected Class<?> getPKClazz() {
			return String.class;
		}
	}

	@Mock
	JpaRepository<SampleStringIdPojo, String> repository;

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
			final Path filePath = currentDir.resolve("data/sample3.csv");
			logger.info("{}", filePath.toAbsolutePath().toString().replace("\\", "\\\\"));
			mockRepository.clear();

			Mockito.when(repository.save(ArgumentMatchers.any(SampleStringIdPojo.class)))
					.thenAnswer(invocation -> mockRepository.save(invocation.getArgument(0, SampleStringIdPojo.class)));

			final JpaRepositoryWrapper<SampleStringIdPojo, String> repositoryWrapper = new JpaRepositoryWrapper<>(
					SampleStringIdPojo.class, String.class, repository);

			assertNotNull(repositoryWrapper.getEntity());
			assertEquals(SampleStringIdPojo.class, repositoryWrapper.getEntity());
			assertNotNull(repositoryWrapper.getPk());
			assertEquals(String.class, repositoryWrapper.getPk());
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
			final Optional<SampleStringIdPojo> opt = mockRepository.findById(String.valueOf(1));
			assertNotNull(opt);
			assertTrue(opt.isPresent());
			assertNotNull(opt.get());
			assertEquals("1", opt.get().getId());
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
			final Path filePath = currentDir.resolve("data/sample3.csv");
			logger.info("{}", filePath.toAbsolutePath().toString().replace("\\", "\\\\"));
			mockRepository.clear();

			Mockito.when(repository.save(ArgumentMatchers.any(SampleStringIdPojo.class)))
					.thenAnswer(invocation -> mockRepository.save(invocation.getArgument(0, SampleStringIdPojo.class)));

			final JpaRepositoryWrapper<SampleStringIdPojo, String> repositoryWrapper = new JpaRepositoryWrapper<>(
					SampleStringIdPojo.class, String.class, repository, filePath.toAbsolutePath().toString());
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
			final JpaRepositoryWrapper<SampleStringIdPojo, String> repositoryWrapper = new JpaRepositoryWrapper<>(
					SampleStringIdPojo.class, String.class, repository);

			Mockito.when(repository.save(ArgumentMatchers.any(SampleStringIdPojo.class)))
					.thenAnswer(invocation -> mockRepository.save(invocation.getArgument(0, SampleStringIdPojo.class)));

			repositoryWrapper.loadCsv(new ClassPathResource("data/sample3.csv"));
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

			final JpaRepositoryWrapper<SampleStringIdPojo, String> repositoryWrapper = new JpaRepositoryWrapper<>(
					SampleStringIdPojo.class, String.class, repository, filePath.toAbsolutePath().toString());
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
