package org.gjs.java.test;

import static org.junit.jupiter.api.Assertions.assertEquals;
import static org.junit.jupiter.api.Assertions.assertNotNull;
import static org.junit.jupiter.api.Assertions.assertTrue;
import static org.junit.jupiter.api.Assertions.fail;

import org.apache.commons.lang3.exception.ExceptionUtils;
import org.gjs.java.test.samples.pojos.SamplePojo;
import org.junit.jupiter.api.Test;

@SuppressWarnings("rawtypes")
public class BaseClassTestTest extends BaseClassTest<BaseClassTest> {

	private static class ClassTest1 extends BaseClassTest<SamplePojo> {

		public boolean executed = false;

		public void test() {
			super.beforeAll();
			logger.info("Executing test...");
			executed = true;
			super.afterAll();
		}
	}

	private static class ClassTest2 extends BaseClassTest<SamplePojo> {

		public boolean executed = false;

		public ClassTest2() {
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
	void testBaseClassTest1() {
		try {
			final ClassTest1 test = new ClassTest1();
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
	void testBaseClassTest2() {
		try {
			final ClassTest2 test = new ClassTest2();
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
