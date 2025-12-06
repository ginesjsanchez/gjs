package org.gjs.java.test.mock.jwt;

import static org.junit.jupiter.api.Assertions.assertNotNull;

import org.gjs.java.test.BaseUnitTest;
import org.junit.jupiter.api.Test;

public class MockBuilderHeaderTest extends BaseUnitTest<MockBuilderHeader> {

    @Test
    void testMockBuilderHeader1() {
        final MockBuilderHeader mock = new MockBuilderHeader(new MockJwtBuilder());
        assertNotNull(mock.and());
    }

}
