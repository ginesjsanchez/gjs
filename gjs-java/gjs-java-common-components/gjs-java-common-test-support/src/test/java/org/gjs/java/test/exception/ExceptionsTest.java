package org.gjs.java.test.exception;

import org.gjs.java.test.AbstractExceptionTest;
import org.junit.jupiter.api.Test;
import org.slf4j.Logger;
import org.slf4j.LoggerFactory;

public class ExceptionsTest extends AbstractExceptionTest {

	/** The Constant logger. */
	private static final Logger logger = LoggerFactory.getLogger(ExceptionsTest.class);

	@Override
	protected String getPackage() {
		return getClass().getPackage().getName();
	}

	@Override
	protected Logger getLogger() {
		return logger;
	}

	@Test
	void testExceptionClasses() {
		super.testClasses();
	}

}
