package org.gjs.java.test;

import static org.junit.jupiter.api.Assertions.assertEquals;
import static org.junit.jupiter.api.Assertions.assertNotNull;
import static org.junit.jupiter.api.Assertions.assertTrue;
import static org.junit.jupiter.api.Assertions.fail;

import org.apache.commons.lang3.exception.ExceptionUtils;
import org.gjs.java.test.mock.MockRepository;
import org.gjs.java.test.sample.dao.SampleEntityRepository;
import org.gjs.java.test.sample.model.SampleEntity;
import org.junit.jupiter.api.Test;
import org.springframework.data.jpa.repository.JpaRepository;

@SuppressWarnings("rawtypes")
public class SimplePKRepositoryUnitTestTest extends BaseUnitTest<SimplePKRepositoryUnitTest> {

	private static class MockSampleEntityRepository extends MockRepository<SampleEntity, Long> {
	}

	private static class SampleEntityRepositoryUnitTest
			extends SimplePKRepositoryUnitTest<SampleEntity, SampleEntityRepository> {

		public SampleEntityRepositoryUnitTest() {
			super(SampleEntityRepository.class, SampleEntity.class);
		}

		private static final String RESOURCE_DATA_PATH = "data/sampleEntity.csv";

		public boolean prepared = false;
		public boolean initialized = false;
		public boolean executed = false;

		MockSampleEntityRepository mockRepository;

		@Override
		protected JpaRepository<SampleEntity, Long> getRepository() {
			return mockRepository;
		}

		@Override
		protected String getResourcePath() {
			return RESOURCE_DATA_PATH;
		}

		@Override
		protected void prepareTestData() throws Exception {
			logger.info("Preparing data...");
			mockRepository = new MockSampleEntityRepository();
			prepared = true;
		}

		@Override
		protected void prepareAditionalTestData() throws Exception {
			logger.info("Loading additionañ data...");
			initialized = true;
		}

		public void test() {
			super.beforeAll();
			logger.info("Executing test...");
			super.testFindAll();
			super.testFindById();
			executed = true;
			super.afterAll();
		}

	}

	@Test
	void testSimplePKRepositoryUnitTest() {
		try {
			final SampleEntityRepositoryUnitTest test = new SampleEntityRepositoryUnitTest();
			assertNotNull(test.getClazz());
			assertNotNull(test.getEntityClazz());
			assertNotNull(test.getPKClazz());
			assertEquals(SampleEntityRepository.class, test.getClazz());
			assertEquals(SampleEntity.class, test.getEntityClazz());
			assertEquals(Long.class, test.getPKClazz());
			assertTrue(test.isValid());
			test.test();
			assertTrue(test.prepared);
			assertTrue(test.initialized);
			assertTrue(test.executed);
		} catch (final Exception e) {
			logger.error(ExceptionUtils.getStackTrace(e));
			fail("Se ha producido un error");
		}
	}

}
