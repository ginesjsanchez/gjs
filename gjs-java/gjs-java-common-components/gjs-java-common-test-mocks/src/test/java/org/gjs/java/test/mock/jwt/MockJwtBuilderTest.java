package org.gjs.java.test.mock.jwt;

import static org.junit.jupiter.api.Assertions.assertNotNull;

import org.gjs.java.test.BaseUnitTest;
import org.junit.jupiter.api.Test;

public class MockJwtBuilderTest extends BaseUnitTest<MockJwtBuilder> {

    @Test
    void testMockJwtBuilder1() {
        final MockJwtBuilder mock = new MockJwtBuilder();
        assertNotNull(mock.compact());
    }

}
