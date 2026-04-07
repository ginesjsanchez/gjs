package org.gjs.java.test.mock.jwt;

import static org.junit.jupiter.api.Assertions.assertEquals;
import static org.junit.jupiter.api.Assertions.assertNotNull;

import org.gjs.java.test.BaseUnitTest;
import org.junit.jupiter.api.Test;

public class MockJwsHeaderTest extends BaseUnitTest<MockJwsHeader> {

    @Test
    void testMockJwsHeader1() {
        final MockJwsHeader mock = new MockJwsHeader();
        assertNotNull(mock.values());
        assertEquals(0, mock.size());
    }

}
