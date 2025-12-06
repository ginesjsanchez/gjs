package org.gjs.java.test.exception;

import static org.junit.jupiter.api.Assertions.assertNotNull;

import org.gjs.java.test.BaseUnitTest;
import org.junit.jupiter.api.Test;

class DeprecatedExceptionTest extends BaseUnitTest<DeprecatedException> {

    @Test
    void testConstructors() {
        final DeprecatedException ex1 = new DeprecatedException("method");
        assertNotNull(ex1.getMessage());
    }

}
