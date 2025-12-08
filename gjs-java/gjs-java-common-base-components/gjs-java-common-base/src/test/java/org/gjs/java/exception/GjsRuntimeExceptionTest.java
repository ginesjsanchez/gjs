package org.gjs.java.exception;

import static org.junit.jupiter.api.Assertions.assertNotNull;

import org.gjs.java.test.BaseClassTest;
import org.junit.jupiter.api.Test;

class GjsRuntimeExceptionTest extends BaseClassTest<GjsRuntimeException> {

	@Test
	void testConstructors() {
		final GjsRuntimeException ex1 = new GjsRuntimeException();
		final GjsRuntimeException ex2 = new GjsRuntimeException(new RuntimeException("Test"));
		final GjsRuntimeException ex3 = new GjsRuntimeException("Test", new Throwable());
		assertNotNull(ex1.getMessage());
		assertNotNull(ex2.getMessage());
		assertNotNull(ex3.getMessage());
	}

}
