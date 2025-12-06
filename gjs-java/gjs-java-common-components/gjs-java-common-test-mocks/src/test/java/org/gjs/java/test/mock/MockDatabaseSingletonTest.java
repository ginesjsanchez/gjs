package org.gjs.java.test.mock;

import static org.junit.jupiter.api.Assertions.assertEquals;
import static org.junit.jupiter.api.Assertions.assertNotNull;

import org.gjs.java.test.BaseUnitTest;
import org.junit.jupiter.api.Test;

class MockDatabaseSingletonTest extends BaseUnitTest<MockDatabaseSingleton> {

    @Test
    void testMockDatabaseSingleton() {
        final MockDatabaseSingleton mock = MockDatabaseSingleton.getInstance();
        assertNotNull(mock);
        assertEquals(mock, MockDatabaseSingleton.getInstance());
    }

}
