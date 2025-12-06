package org.gjs.java.test;

import static org.junit.jupiter.api.Assertions.assertNotNull;
import static org.junit.jupiter.api.Assertions.assertTrue;
import static org.junit.jupiter.api.Assertions.fail;

import org.apache.commons.lang3.exception.ExceptionUtils;
import org.gjs.java.test.tester.HashCodeTester;
import org.gjs.java.test.tester.ToStringTester;
import org.junit.jupiter.api.Test;
import org.slf4j.Logger;

public class AbstractPackageTestTest extends BaseUnitTest<AbstractPackageTest> {

	private class PackageTest extends AbstractPackageTest {

		public boolean initialized = false;
		public boolean executed = false;

		public PackageTest() {
			super(new ToStringTester(), new HashCodeTester());
		}

		@Override
		protected void initialize() throws Exception {
			logger.info("Initializing test...");
			initialized = true;
		}

		public void test() {
			super.beforeAll();
			logger.info("Executing test...");
			super.testClasses();
			executed = true;
			super.afterAll();
		}

		@Override
		protected Logger getLogger() {
			return logger;
		}

		@Override
		protected String getPackage() {
			return "org.gjs.java.test.samples.pojos";
		}
	}

	@Test
	void testAbstractPackageTest() {
		try {
			final PackageTest test = new PackageTest();
			assertNotNull(test.getPackage());
			test.test();
			assertTrue(test.initialized);
			assertTrue(test.executed);
		} catch (final Exception e) {
			logger.error(ExceptionUtils.getStackTrace(e));
			fail("Se ha producido un error");
		}
	}

}
