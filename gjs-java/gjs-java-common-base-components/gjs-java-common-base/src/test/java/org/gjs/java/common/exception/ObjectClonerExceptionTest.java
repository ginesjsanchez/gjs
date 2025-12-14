package org.gjs.java.common.exception;

import static org.junit.jupiter.api.Assertions.assertNotNull;

import org.gjs.java.common.exception.ObjectClonerException;
import org.gjs.java.test.BaseClassTest;
import org.junit.jupiter.api.Test;

class ObjectClonerExceptionTest extends BaseClassTest<ObjectClonerException> {

	@Test
	void testConstructors() {
		final ObjectClonerException ex1 = new ObjectClonerException("Test");
		final ObjectClonerException ex2 = new ObjectClonerException("Test", new RuntimeException("Test"));
		assertNotNull(ex1.getMessage());
		assertNotNull(ex2.getMessage());
	}

}
