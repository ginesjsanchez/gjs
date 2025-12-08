package org.gjs.java.exception;

import static org.junit.jupiter.api.Assertions.assertNotNull;

import org.gjs.java.test.BaseClassTest;
import org.junit.jupiter.api.Test;

class GjsExceptionTest extends BaseClassTest<GjsException> {

	@Test
	void testConstructors() {
		final GjsException ex1 = new GjsException();
		final GjsException ex2 = new GjsException(new Throwable());
		final GjsException ex3 = new GjsException("Test", new Throwable());
		final GjsException ex4 = new GjsException("Test");
		final GjsException ex5 = new GjsException("Test", new Throwable(), false, false);
		assertNotNull(ex1.getMessage());
		assertNotNull(ex2.getMessage());
		assertNotNull(ex3.getMessage());
		assertNotNull(ex4.getMessage());
		assertNotNull(ex5.getMessage());
	}

}
