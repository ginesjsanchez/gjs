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
public class BaseDataControllerUnitTestTest extends BaseUnitTest<BaseDataControllerUnitTest> {

	private static class DataControllerUnitTest1 extends BaseDataControllerUnitTest<SamplePojo, MockModelDataManager> {

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

	private static class DataControllerUnitTest2 extends BaseDataControllerUnitTest<SamplePojo, MockModelDataManager> {

		public boolean initialized = false;
		public boolean executed = false;

		public DataControllerUnitTest2() {
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
	void testBaseDataControllerUnitTest1() {
		try {
			final DataControllerUnitTest1 test = new DataControllerUnitTest1();
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
	void testBaseDataControllerUnitTest2() {
		try {
			final DataControllerUnitTest2 test = new DataControllerUnitTest2();
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
