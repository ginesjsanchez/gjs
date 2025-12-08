package org.gjs.java.test;

import static org.junit.jupiter.api.Assertions.assertEquals;
import static org.junit.jupiter.api.Assertions.assertNotNull;
import static org.junit.jupiter.api.Assertions.assertTrue;
import static org.junit.jupiter.api.Assertions.fail;

import org.apache.commons.lang3.exception.ExceptionUtils;
import org.gjs.java.test.mock.MockModelDataManager;
import org.gjs.java.test.samples.pojos.SamplePojo;
import org.junit.jupiter.api.Test;

@SuppressWarnings("rawtypes")
public class BaseDataServiceUnitTestTest extends BaseUnitTest<BaseDataServiceUnitTest> {

	private static class DataServiceUnitTest1 extends BaseDataServiceUnitTest<SamplePojo, MockModelDataManager> {

		public boolean initialized = false;
		public boolean executed = false;

		@Override
		protected long loadTestData() throws Exception {
			logger.info("Loading data...");
			initialized = true;
			return super.getExpected().length;
		}

		public void test() {
			super.beforeAll();
			logger.info("Executing test...");
			executed = true;
			super.afterAll();
		}

		@Override
		protected MockModelDataManager createMockDatabase() throws Exception {
			return new MockModelDataManager();
		}

	}

	private static class DataServiceUnitTest2 extends BaseDataServiceUnitTest<SamplePojo, MockModelDataManager> {

		public boolean initialized = false;
		public boolean executed = false;

		public DataServiceUnitTest2() {
			super(SamplePojo.class);
		}

		@Override
		protected long loadTestData() throws Exception {
			logger.info("Loading data...");
			initialized = true;
			return super.getExpected().length;
		}

		public void test() {
			super.beforeAll();
			logger.info("Executing test...");
			executed = true;
			super.afterAll();
		}

		@Override
		protected MockModelDataManager createMockDatabase() throws Exception {
			return new MockModelDataManager();
		}

	}

	@Test
	void testBaseDataServiceUnitTest1() {
		try {
			final DataServiceUnitTest1 test = new DataServiceUnitTest1();
			assertNotNull(test.getClazz());
			assertEquals(SamplePojo.class, test.getClazz());
			test.test();
			assertTrue(test.initialized);
			assertTrue(test.executed);
		} catch (final Exception e) {
			logger.error(ExceptionUtils.getStackTrace(e));
			fail("Se ha producido un error");
		}
	}

	@Test
	void testBaseDataServiceUnitTest2() {
		try {
			final DataServiceUnitTest2 test = new DataServiceUnitTest2();
			assertNotNull(test.getClazz());
			assertEquals(SamplePojo.class, test.getClazz());
			test.test();
			assertTrue(test.initialized);
			assertTrue(test.executed);
		} catch (final Exception e) {
			logger.error(ExceptionUtils.getStackTrace(e));
			fail("Se ha producido un error");
		}
	}

}
