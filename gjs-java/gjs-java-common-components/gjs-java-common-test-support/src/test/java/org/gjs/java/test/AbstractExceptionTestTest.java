package org.gjs.java.test;

import static org.junit.jupiter.api.Assertions.fail;

import org.apache.commons.lang3.exception.ExceptionUtils;
import org.gjs.java.test.samples.pojos.SamplePojo;
import org.junit.jupiter.api.Test;
import org.slf4j.Logger;

public class AbstractExceptionTestTest extends BaseUnitTest<AbstractExceptionTest> {

	private class ExceptionTest extends AbstractExceptionTest {

		public ExceptionTest() {
			super.addSpecialParameter(SamplePojo.class.getCanonicalName(), new SamplePojo(1, "Test"));
		}

		@Override
		protected String getPackage() {
			return "org.gjs.java.test.sample.exception";
		}

		@Override
		protected Logger getLogger() {
			return logger;
		}

	}

	@Test
	void testAbstractExceptionTest() {
		try {
			final ExceptionTest test = new ExceptionTest();
			test.testClasses();
		} catch (final Exception e) {
			logger.error(ExceptionUtils.getStackTrace(e));
			fail("Se ha producido un error");
		}
	}

}
