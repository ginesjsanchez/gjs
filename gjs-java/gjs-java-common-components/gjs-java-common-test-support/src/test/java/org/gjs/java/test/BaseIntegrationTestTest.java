package org.gjs.java.test;

import static org.junit.jupiter.api.Assertions.assertEquals;
import static org.junit.jupiter.api.Assertions.assertNotNull;
import static org.junit.jupiter.api.Assertions.assertTrue;
import static org.junit.jupiter.api.Assertions.fail;

import org.apache.commons.lang3.exception.ExceptionUtils;
import org.gjs.java.test.samples.pojos.SamplePojo;
import org.junit.jupiter.api.Test;

@SuppressWarnings("rawtypes")
public class BaseIntegrationTestTest extends BaseUnitTest<BaseIntegrationTest> {

	private static class IntegrationTest1 extends BaseIntegrationTest<SamplePojo> {

		public boolean executed = false;

		public void test() {
			super.beforeAll();
			logger.info("Executing test...");
			executed = true;
			super.afterAll();
		}
	}

	private static class IntegrationTest2 extends BaseIntegrationTest<SamplePojo> {

		public boolean executed = false;

		public IntegrationTest2() {
			super(SamplePojo.class);
		}

		public void test() {
			super.beforeAll();
			logger.info("Executing test...");
			executed = true;
			super.afterAll();
		}
	}

	@Test
	void testBaseIntegrationTest1() {
		try {
			final IntegrationTest1 test = new IntegrationTest1();
			assertNotNull(test.getClazz());
			assertTrue(test.isValid());
			assertEquals(SamplePojo.class, test.getClazz());
			test.test();
			assertTrue(test.executed);
		} catch (final Exception e) {
			logger.error(ExceptionUtils.getStackTrace(e));
			fail("Se ha producido un error");
		}
	}

	@Test
	void testBaseIntegrationTest2() {
		try {
			final IntegrationTest2 test = new IntegrationTest2();
			assertNotNull(test.getClazz());
			assertTrue(test.isValid());
			assertEquals(SamplePojo.class, test.getClazz());
			test.test();
			assertTrue(test.executed);
		} catch (final Exception e) {
			logger.error(ExceptionUtils.getStackTrace(e));
			fail("Se ha producido un error");
		}
	}

}
