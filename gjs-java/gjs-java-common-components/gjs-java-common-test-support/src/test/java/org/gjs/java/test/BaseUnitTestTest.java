package org.gjs.java.test;

import static org.junit.jupiter.api.Assertions.assertEquals;
import static org.junit.jupiter.api.Assertions.assertNotNull;
import static org.junit.jupiter.api.Assertions.assertTrue;
import static org.junit.jupiter.api.Assertions.fail;

import org.apache.commons.lang3.exception.ExceptionUtils;
import org.gjs.java.test.samples.pojos.SamplePojo;
import org.junit.jupiter.api.Test;

@SuppressWarnings("rawtypes")
public class BaseUnitTestTest extends BaseUnitTest<BaseUnitTest> {

	private static class UnitTest1 extends BaseUnitTest<SamplePojo> {

		public boolean initialized = false;
		public boolean executed = false;

		@Override
		protected void initialize() throws Exception {
			logger.info("Initializing test...");
			initialized = true;
		}

		public void test() {
			super.beforeAll();
			logger.info("Executing test...");
			executed = true;
			super.afterAll();
		}
	}

	private static class UnitTest2 extends BaseUnitTest<SamplePojo> {

		public boolean initialized = false;
		public boolean executed = false;

		public UnitTest2() {
			super(SamplePojo.class);
		}

		@Override
		protected void initialize() throws Exception {
			logger.info("Initializing test...");
			initialized = true;
		}

		public void test() {
			super.beforeAll();
			logger.info("Executing test...");
			executed = true;
			super.afterAll();
		}
	}

	@Test
	void testBaseUnitTest1() {
		try {
			final UnitTest1 test = new UnitTest1();
			assertNotNull(test.getClazz());
			assertTrue(test.isValid());
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
	void testBaseUnitTest2() {
		try {
			final UnitTest2 test = new UnitTest2();
			assertNotNull(test.getClazz());
			assertTrue(test.isValid());
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
