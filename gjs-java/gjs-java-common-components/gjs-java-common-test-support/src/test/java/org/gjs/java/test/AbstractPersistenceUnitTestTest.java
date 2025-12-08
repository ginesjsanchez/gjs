package org.gjs.java.test;

import static org.junit.jupiter.api.Assertions.assertEquals;
import static org.junit.jupiter.api.Assertions.assertNotNull;
import static org.junit.jupiter.api.Assertions.assertTrue;
import static org.junit.jupiter.api.Assertions.fail;

import org.apache.commons.lang3.exception.ExceptionUtils;
import org.gjs.java.test.samples.pojos.SamplePojo;
import org.junit.jupiter.api.Test;

@SuppressWarnings("rawtypes")
public class AbstractPersistenceUnitTestTest extends BaseUnitTest<AbstractPersistenceUnitTest> {

	private static class PersistenceUnitTest1 extends AbstractPersistenceUnitTest<SamplePojo> {

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

	}

	private static class PersistenceUnitTest2 extends AbstractPersistenceUnitTest<SamplePojo> {

		public boolean initialized = false;
		public boolean executed = false;

		public PersistenceUnitTest2() {
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

	}

	@Test
	void testAbstractPersistenceUnitTest1() {
		try {
			final PersistenceUnitTest1 test = new PersistenceUnitTest1();
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
	void testAbstractPersistenceUnitTest2() {
		try {
			final PersistenceUnitTest2 test = new PersistenceUnitTest2();
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
