package org.gjs.java.test;

import static org.junit.jupiter.api.Assertions.assertEquals;
import static org.junit.jupiter.api.Assertions.assertNotNull;
import static org.junit.jupiter.api.Assertions.assertTrue;
import static org.junit.jupiter.api.Assertions.fail;

import org.apache.commons.lang3.exception.ExceptionUtils;
import org.gjs.java.test.tester.BaseTester;
import org.gjs.java.test.tester.ToStringTester;
import org.junit.jupiter.api.Test;

@SuppressWarnings("rawtypes")
public class AbstractTesterUnitTestTest extends BaseUnitTest<AbstractTesterUnitTest> {

	private static class ToStringUnitTest extends AbstractTesterUnitTest<ToStringTester> {

		public boolean initialized = false;
		public boolean executed = false;

		private final String PACKAGE_TEST_OK = "org.gjs.java.test.samples.pojos";
		private final String PACKAGE_TEST_KO = "org.gjs.java.test.samples.pojos.error";

		@Override
		protected String getPackageToTestOk() {
			return PACKAGE_TEST_OK;
		}

		@Override
		protected String getPackageToTestKo() {
			return PACKAGE_TEST_KO;
		}

		@Override
		protected BaseTester createTester(boolean stopOnError) {
			return new ToStringTester(stopOnError);
		}

		@Override
		protected void initialize() throws Exception {
			logger.info("Initializing test...");
			initialized = true;
		}

		public void test() {
			super.beforeAll();
			logger.info("Executing test...");
			super.testTester1();
			super.testTester2();
			super.testTester3();
			executed = true;
			super.afterAll();
		}

	}

	@Test
	void testAbstractUnitTest() {
		try {
			final ToStringUnitTest test = new ToStringUnitTest();
			assertNotNull(test.getClazz());
			assertEquals(ToStringTester.class, test.getClazz());
			test.test();
			assertTrue(test.initialized);
			assertTrue(test.executed);
		} catch (final Exception e) {
			logger.error(ExceptionUtils.getStackTrace(e));
			fail("Se ha producido un error");
		}
	}

}
