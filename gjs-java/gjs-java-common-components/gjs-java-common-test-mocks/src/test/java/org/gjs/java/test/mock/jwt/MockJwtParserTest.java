package org.gjs.java.test.mock.jwt;

import static org.junit.jupiter.api.Assertions.assertNotNull;
import static org.junit.jupiter.api.Assertions.assertNull;

import java.util.Date;

import org.gjs.java.test.BaseUnitTest;
import org.junit.jupiter.api.Test;

public class MockJwtParserTest extends BaseUnitTest<MockJwtParser> {

    @Test
    void testMockJwtParser1() {
        final MockJwtParser mock = new MockJwtParser();
        assertNull(mock.parse("token"));
        mock.addToken("token", "sujeto", new Date(), null);
        assertNotNull(mock.parse("token"));
    }

}
