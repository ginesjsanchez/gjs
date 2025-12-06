package org.gjs.java.test.mock.jwt;

import static org.junit.jupiter.api.Assertions.assertEquals;
import static org.junit.jupiter.api.Assertions.assertNotNull;
import static org.junit.jupiter.api.Assertions.assertNull;

import java.util.Date;

import org.gjs.java.test.BaseUnitTest;
import org.junit.jupiter.api.Test;

public class MockJwtClaimsTest extends BaseUnitTest<MockJwtClaims> {

    @Test
    void testMockJwtClaims1() {
        final String subject = "subject";
        final Date issuedAt = new Date();
        final Date expiration = new Date();

        final MockClaims mockClaims = new MockClaims(subject, issuedAt, expiration);
        final MockJwtClaims mock = new MockJwtClaims(mockClaims);
        assertNull(mock.getHeader());
        assertNotNull(mock.getPayload());
        assertNotNull(mock.getPayload().getExpiration());
        assertNotNull(mock.getPayload().getIssuedAt());
        assertNotNull(mock.getPayload().getSubject());
        assertEquals(expiration, mock.getPayload().getExpiration());
        assertEquals(issuedAt, mock.getPayload().getIssuedAt());
        assertEquals(subject, mock.getPayload().getSubject());
        assertNotNull(mock.getDigest());
        assertEquals(0, mock.getDigest().length);
    }

    @Test
    void testMockJwtClaims2() {
        final String subject = "subject";
        final Date issuedAt = new Date();
        final Date expiration = new Date();

        final MockJwtClaims mock = new MockJwtClaims(subject, issuedAt, expiration);
        assertNull(mock.getHeader());
        assertNotNull(mock.getPayload());
        assertNotNull(mock.getPayload().getExpiration());
        assertNotNull(mock.getPayload().getIssuedAt());
        assertNotNull(mock.getPayload().getSubject());
        assertEquals(expiration, mock.getPayload().getExpiration());
        assertEquals(issuedAt, mock.getPayload().getIssuedAt());
        assertEquals(subject, mock.getPayload().getSubject());
    }

}
