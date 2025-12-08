package org.gjs.java.test;

import static org.junit.jupiter.api.Assertions.assertTrue;
import static org.junit.jupiter.api.Assertions.fail;

import org.apache.commons.lang3.exception.ExceptionUtils;
import org.junit.jupiter.api.Test;

public class AbstractTestTest extends BaseClassTest<AbstractTest> {

	private static class UnitTest extends AbstractTest {

		public boolean executed = false;

		public void test() {
			super.beforeAll();
			logger.info("Executing test...");
			executed = true;
			super.afterAll();
		}

		@Override
		protected void prepareTest() {
		}

		@Override
		protected void finalizeTest() {
		}
	}

	@Test
	void testAbstractTest() {
		try {
			final UnitTest test = new UnitTest();
			test.test();
			assertTrue(test.executed);
		} catch (final Exception e) {
			logger.error(ExceptionUtils.getStackTrace(e));
			fail("Se ha producido un error");
		}
	}

}
