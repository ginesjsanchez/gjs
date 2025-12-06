package org.gjs.java.test.mock.jwt;

import java.util.Date;

import org.gjs.java.test.exception.DeprecatedException;

import io.jsonwebtoken.Claims;
import io.jsonwebtoken.Jws;
import io.jsonwebtoken.JwsHeader;
import io.jsonwebtoken.JwtVisitor;

/**
 * The Class MockJwtClaims.
 *
 * Clase de datos de la librería Semilla
 *
 * Mock de un JwtClaims.
 *
 * --------------------------------------------------------------------------------------------------------------------
 * Este software es propiedad del Ministerio del Interior CETSE - 2025
 *
 * Queda estrictamente prohibido el uso de programas informáticos sin la correspondiente licencia en los activos de la
 * SES. Los programas informáticos propiedad de la SES están protegidos por la propiedad intelectual, y por tanto está
 * estrictamente prohibida su reproducción, modificación, cesión o comunicación sin la debida autorización. Queda
 * estrictamente prohibido el uso, reproducción, cesión, transformación o comunicación pública de cualquier otro tipo de
 * obra o invención protegida por la propiedad intelectual sin la debida autorización.
 *
 * Subdirección General de Sistemas de la Información y Comunicaciones para la Seguridad Ministerio del Interior
 * Gobierno de España
 * --------------------------------------------------------------------------------------------------------------------
 *
 * @author Semilla
 * @version 4.0.0
 * @since 3.0.0
 *
 */
public class MockJwtClaims implements Jws<Claims> {

    /** The body. */
    private final Claims payload;

    /**
     * Instantiates a new mock jwt claims.
     *
     * @param body
     *            the body
     */
    public MockJwtClaims(MockClaims body) {
        this.payload = body;
    }

    /**
     * Instantiates a new mock jwt claims.
     *
     * @param subject
     *            the subject
     * @param issuedAt
     *            the issued at
     * @param expiration
     *            the expiration
     */
    public MockJwtClaims(String subject, Date issuedAt, Date expiration) {
        this(new MockClaims(subject, issuedAt, expiration));
    }

    /* (non-Javadoc)
     *
     * @see io.jsonwebtoken.Jwt#getHeader() */

    @Override
    public JwsHeader getHeader() {
        return null;
    }

    /* (non-Javadoc)
     *
     * @see io.jsonwebtoken.Jwt#getBody() */

    @Override
    public Claims getBody() {
        throw new DeprecatedException("getBody");
    }

    /* (non-Javadoc)
     *
     * @see io.jsonwebtoken.Jws#getSignature() */

    @Override
    public String getSignature() {
        throw new DeprecatedException("getSignature");
    }

    /* (non-Javadoc)
     *
     * @see io.jsonwebtoken.Jwt#getPayload() */

    @Override
    public Claims getPayload() {
        return payload;
    }

    /* (non-Javadoc)
     *
     * @see io.jsonwebtoken.Jwt#accept(io.jsonwebtoken.JwtVisitor) */

    @Override
    public <T> T accept(JwtVisitor<T> visitor) {
        return null;
    }

    /* (non-Javadoc)
     *
     * @see io.jsonwebtoken.security.DigestSupplier#getDigest() */

    @Override
    public byte[] getDigest() {
        return new byte[] {};
    }

}
