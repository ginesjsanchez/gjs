package org.gjs.java.test.mock.jwt;

import static org.junit.jupiter.api.Assertions.assertEquals;
import static org.junit.jupiter.api.Assertions.assertNotNull;
import static org.junit.jupiter.api.Assertions.assertNull;
import static org.junit.jupiter.api.Assertions.assertTrue;

import java.util.Date;
import java.util.TreeSet;

import org.gjs.java.test.BaseUnitTest;
import org.junit.jupiter.api.Test;

public class MockClaimsTest extends BaseUnitTest<MockClaims> {

    @Test
    void testMockClaims1() {
        final MockClaims mock = new MockClaims();
        assertTrue(mock.isEmpty());
        assertEquals(0, mock.size());
        assertNull(mock.getAudience());
        assertNull(mock.getExpiration());
        assertNull(mock.getId());
        assertNull(mock.getIssuer());
        assertNull(mock.getIssuedAt());
        assertNull(mock.getNotBefore());
        assertNull(mock.getSubject());
        mock.setAudience(new TreeSet<>());
        mock.setExpiration(new Date());
        mock.setId("is");
        mock.setIssuer("issuer");
        mock.setIssuedAt(new Date());
        mock.setNotBefore(new Date());
        mock.setSubject("subject");
        assertNotNull(mock.getAudience());
        assertNotNull(mock.getExpiration());
        assertNotNull(mock.getId());
        assertNotNull(mock.getIssuer());
        assertNotNull(mock.getIssuedAt());
        assertNotNull(mock.getNotBefore());
        assertNotNull(mock.getSubject());
    }

    @Test
    void testMockClaims2() {
        final String subject = "subject";
        final Date issuedAt = new Date();
        final Date expiration = new Date();

        final MockClaims mock = new MockClaims(subject, issuedAt, expiration);
        assertNotNull(mock.getExpiration());
        assertNotNull(mock.getIssuedAt());
        assertNotNull(mock.getSubject());
        assertEquals(expiration, mock.getExpiration());
        assertEquals(issuedAt, mock.getIssuedAt());
        assertEquals(subject, mock.getSubject());
    }

}
