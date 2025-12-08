package org.gjs.java.test;

import static org.junit.jupiter.api.Assertions.assertEquals;
import static org.junit.jupiter.api.Assertions.assertNotNull;
import static org.junit.jupiter.api.Assertions.assertTrue;
import static org.junit.jupiter.api.Assertions.fail;

import org.apache.commons.lang3.exception.ExceptionUtils;
import org.gjs.java.test.samples.pojos.SamplePojo;
import org.junit.jupiter.api.Test;

public class AbstractClassTestTest extends BaseClassTest<AbstractClassTest> {

	private static class UnitTest extends AbstractClassTest {

		public boolean executed = false;

		@Override
		protected Class<?> getClazz() {
			return SamplePojo.class;
		}

		public void test() {
			super.beforeAll();
			logger.info("Executing test...");
			executed = true;
			super.afterAll();
		}
	}

	@Test
	void testAbstractClassTest() {
		try {
			final UnitTest test = new UnitTest();
			assertNotNull(test.getClazz());
			assertEquals(SamplePojo.class, test.getClazz());
			test.test();
			assertTrue(test.executed);
		} catch (final Exception e) {
			logger.error(ExceptionUtils.getStackTrace(e));
			fail("Se ha producido un error");
		}
	}

}
