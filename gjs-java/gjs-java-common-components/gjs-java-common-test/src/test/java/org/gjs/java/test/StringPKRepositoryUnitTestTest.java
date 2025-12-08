package org.gjs.java.test;

import static org.junit.jupiter.api.Assertions.assertEquals;
import static org.junit.jupiter.api.Assertions.assertNotNull;
import static org.junit.jupiter.api.Assertions.assertTrue;
import static org.junit.jupiter.api.Assertions.fail;

import org.apache.commons.lang3.exception.ExceptionUtils;
import org.gjs.java.test.mock.MockRepository;
import org.gjs.java.test.sample.dao.SampleStringEntityRepository;
import org.gjs.java.test.sample.model.SampleStringEntity;
import org.junit.jupiter.api.Test;
import org.springframework.data.jpa.repository.JpaRepository;

@SuppressWarnings("rawtypes")
public class StringPKRepositoryUnitTestTest extends BaseUnitTest<StringPKRepositoryUnitTest> {

	private static class MockSampleEntityRepository extends MockRepository<SampleStringEntity, String> {
	}

	private static class SampleEntityRepositoryUnitTest
			extends StringPKRepositoryUnitTest<SampleStringEntity, SampleStringEntityRepository> {

		public SampleEntityRepositoryUnitTest() {
			super(SampleStringEntityRepository.class, SampleStringEntity.class);
		}

		private static final String RESOURCE_DATA_PATH = "data/sampleStringEntity.csv";

		public boolean prepared = false;
		public boolean initialized = false;
		public boolean executed = false;

		MockSampleEntityRepository mockRepository;

		@Override
		protected JpaRepository<SampleStringEntity, String> getRepository() {
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
	void testStringPKRepositoryUnitTest() {
		try {
			final SampleEntityRepositoryUnitTest test = new SampleEntityRepositoryUnitTest();
			assertNotNull(test.getClazz());
			assertNotNull(test.getEntityClazz());
			assertNotNull(test.getPKClazz());
			assertEquals(SampleStringEntityRepository.class, test.getClazz());
			assertEquals(SampleStringEntity.class, test.getEntityClazz());
			assertEquals(String.class, test.getPKClazz());
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
