package org.gjs.java.exception;

import static org.junit.jupiter.api.Assertions.assertNotNull;

import org.gjs.java.test.BaseClassTest;
import org.junit.jupiter.api.Test;

class ObjectSupplierExceptionTest extends BaseClassTest<ObjectSupplierException> {

	@Test
	void testConstructors() {
		final ObjectSupplierException ex1 = new ObjectSupplierException("Test");
		final ObjectSupplierException ex2 = new ObjectSupplierException("Test", new RuntimeException("Test"));
		assertNotNull(ex1.getMessage());
		assertNotNull(ex2.getMessage());
	}

}
