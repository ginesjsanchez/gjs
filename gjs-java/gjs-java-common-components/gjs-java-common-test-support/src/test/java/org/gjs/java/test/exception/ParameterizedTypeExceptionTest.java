package org.gjs.java.test.exception;

import static org.junit.jupiter.api.Assertions.assertNotNull;

import org.gjs.java.test.BaseUnitTest;
import org.junit.jupiter.api.Test;

class ParameterizedTypeExceptionTest extends BaseUnitTest<ParameterizedTypeException> {

    @Test
    void testConstructors() {
        final ParameterizedTypeException ex1 = new ParameterizedTypeException("Test");
        final ParameterizedTypeException ex2 = new ParameterizedTypeException("Test", new RuntimeException("Test"));
        assertNotNull(ex1.getMessage());
        assertNotNull(ex2.getMessage());
    }

}
