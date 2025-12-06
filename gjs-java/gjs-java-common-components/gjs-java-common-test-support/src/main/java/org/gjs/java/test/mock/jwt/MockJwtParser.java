package org.gjs.java.test.mock.jwt;

import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.Reader;
import java.nio.charset.StandardCharsets;
import java.util.Date;
import java.util.Map;
import java.util.concurrent.ConcurrentHashMap;

import org.apache.commons.io.IOUtils;
import org.apache.commons.lang3.exception.ExceptionUtils;
import org.slf4j.Logger;
import org.slf4j.LoggerFactory;

import io.jsonwebtoken.Claims;
import io.jsonwebtoken.Header;
import io.jsonwebtoken.Jwe;
import io.jsonwebtoken.Jws;
import io.jsonwebtoken.Jwt;
import io.jsonwebtoken.JwtHandler;
import io.jsonwebtoken.JwtParser;

/**
 * The Class MockJwtParser.
 *
 * Clase de datos de la librería Semilla
 *
 * Mock de un JwtParser.
 *
 * --------------------------------------------------------------------------------------------------------------------
 * Este software es propiedad del Ministerio del Interior CETSE - 2025
 *
 * Queda estrictamente prohibido el uso de programas informáticos sin la
 * correspondiente licencia en los activos de la SES. Los programas informáticos
 * propiedad de la SES están protegidos por la propiedad intelectual, y por
 * tanto está estrictamente prohibida su reproducción, modificación, cesión o
 * comunicación sin la debida autorización. Queda estrictamente prohibido el
 * uso, reproducción, cesión, transformación o comunicación pública de cualquier
 * otro tipo de obra o invención protegida por la propiedad intelectual sin la
 * debida autorización.
 *
 * Subdirección General de Sistemas de la Información y Comunicaciones para la
 * Seguridad Ministerio del Interior Gobierno de España
 * --------------------------------------------------------------------------------------------------------------------
 *
 * @author Semilla
 * @version 4.0.0
 * @since 3.0.0
 *
 */
@SuppressWarnings("deprecation")
public class MockJwtParser implements JwtParser {

	/** The Constant logger. */
	private static final Logger logger = LoggerFactory.getLogger(MockJwtParser.class);

	/** The map jwt. */
	private final Map<String, MockJwtClaims> mapJwt = new ConcurrentHashMap<>();

	/**
	 * Adds the token.
	 *
	 * @param token      the token
	 * @param subject    the subject
	 * @param issuedAt   the issued at
	 * @param expiration the expiration
	 */
	public void addToken(String token, String subject, Date issuedAt, Date expiration) {
		mapJwt.put(token, new MockJwtClaims(subject, issuedAt, expiration));
	}

	/*
	 * (non-Javadoc)
	 *
	 * @see io.jsonwebtoken.io.Parser#parse(java.lang.CharSequence, int, int)
	 */

	@Override
	public Jwt<?, ?> parse(CharSequence input, int start, int end) {
		return mapJwt.get(input);
	}

	/*
	 * (non-Javadoc)
	 *
	 * @see io.jsonwebtoken.io.Parser#parse(java.io.Reader)
	 */

	@Override
	public Jwt<?, ?> parse(Reader reader) {
		try {
			return parse(IOUtils.toString(reader));
		} catch (final IOException e) {
			logger.error(ExceptionUtils.getStackTrace(e));
		}
		return null;
	}

	/*
	 * (non-Javadoc)
	 *
	 * @see io.jsonwebtoken.io.Parser#parse(java.io.InputStream)
	 */

	@Override
	public Jwt<?, ?> parse(InputStream in) {
		return parse(new InputStreamReader(in, StandardCharsets.UTF_8));
	}

	/*
	 * (non-Javadoc)
	 *
	 * @see io.jsonwebtoken.JwtParser#isSigned(java.lang.CharSequence)
	 */

	@Override
	public boolean isSigned(CharSequence compact) {
		return false;
	}

	/*
	 * (non-Javadoc)
	 *
	 * @see io.jsonwebtoken.JwtParser#parse(java.lang.CharSequence)
	 */

	@Override
	public Jwt<?, ?> parse(CharSequence jwt) {
		return mapJwt.get(jwt);
	}

	/*
	 * (non-Javadoc)
	 *
	 * @deprecated (when, why, etc...)
	 *
	 * @see io.jsonwebtoken.JwtParser#parse(java.lang.CharSequence,
	 * io.jsonwebtoken.JwtHandler)
	 */

	@Deprecated
	@Override
	public <T> T parse(CharSequence jwt, JwtHandler<T> handler) {
		return null;
	}

	/*
	 * (non-Javadoc)
	 *
	 * @deprecated (when, why, etc...)
	 *
	 * @see io.jsonwebtoken.JwtParser#parseContentJwt(java.lang.CharSequence)
	 */

	@Deprecated
	@Override
	public Jwt<Header, byte[]> parseContentJwt(CharSequence jwt) {
		return null;
	}

	/*
	 * (non-Javadoc)
	 *
	 * @deprecated (when, why, etc...)
	 *
	 * @see io.jsonwebtoken.JwtParser#parseClaimsJwt(java.lang.CharSequence)
	 */

	@Deprecated
	@Override
	public Jwt<Header, Claims> parseClaimsJwt(CharSequence jwt) {
		return null;
	}

	/*
	 * (non-Javadoc)
	 *
	 * @deprecated (when, why, etc...)
	 *
	 * @see io.jsonwebtoken.JwtParser#parseContentJws(java.lang.CharSequence)
	 */

	@Deprecated
	@Override
	public Jws<byte[]> parseContentJws(CharSequence jws) {
		return null;
	}

	/*
	 * (non-Javadoc)
	 *
	 * @deprecated (when, why, etc...)
	 *
	 * @see io.jsonwebtoken.JwtParser#parseClaimsJws(java.lang.CharSequence)
	 */

	@Deprecated
	@Override
	public Jws<Claims> parseClaimsJws(CharSequence jws) {
		return mapJwt.get(jws);
	}

	/*
	 * (non-Javadoc)
	 *
	 * @see io.jsonwebtoken.JwtParser#parseUnsecuredContent(java.lang.CharSequence)
	 */

	@Override
	public Jwt<Header, byte[]> parseUnsecuredContent(CharSequence jwt) {
		return null;
	}

	/*
	 * (non-Javadoc)
	 *
	 * @see io.jsonwebtoken.JwtParser#parseUnsecuredClaims(java.lang.CharSequence)
	 */

	@Override
	public Jwt<Header, Claims> parseUnsecuredClaims(CharSequence jwt) {
		return null;
	}

	/*
	 * (non-Javadoc)
	 *
	 * @see io.jsonwebtoken.JwtParser#parseSignedContent(java.lang.CharSequence)
	 */

	@Override
	public Jws<byte[]> parseSignedContent(CharSequence jws) {
		return null;
	}

	/*
	 * (non-Javadoc)
	 *
	 * @see io.jsonwebtoken.JwtParser#parseSignedContent(java.lang.CharSequence,
	 * byte[])
	 */

	@Override
	public Jws<byte[]> parseSignedContent(CharSequence jws, byte[] unencodedPayload) {
		return null;
	}

	/*
	 * (non-Javadoc)
	 *
	 * @see io.jsonwebtoken.JwtParser#parseSignedContent(java.lang.CharSequence,
	 * java.io.InputStream)
	 */

	@Override
	public Jws<byte[]> parseSignedContent(CharSequence jws, InputStream unencodedPayload) {
		return null;
	}

	/*
	 * (non-Javadoc)
	 *
	 * @see io.jsonwebtoken.JwtParser#parseSignedClaims(java.lang.CharSequence)
	 */

	@Override
	public Jws<Claims> parseSignedClaims(CharSequence jws) {
		return mapJwt.get(jws);
	}

	/*
	 * (non-Javadoc)
	 *
	 * @see io.jsonwebtoken.JwtParser#parseSignedClaims(java.lang.CharSequence,
	 * byte[])
	 */

	@Override
	public Jws<Claims> parseSignedClaims(CharSequence jws, byte[] unencodedPayload) {
		return mapJwt.get(jws);
	}

	/*
	 * (non-Javadoc)
	 *
	 * @see io.jsonwebtoken.JwtParser#parseSignedClaims(java.lang.CharSequence,
	 * java.io.InputStream)
	 */

	@Override
	public Jws<Claims> parseSignedClaims(CharSequence jws, InputStream unencodedPayload) {
		return mapJwt.get(jws);
	}

	/*
	 * (non-Javadoc)
	 *
	 * @see io.jsonwebtoken.JwtParser#parseEncryptedContent(java.lang.CharSequence)
	 */

	@Override
	public Jwe<byte[]> parseEncryptedContent(CharSequence jwe) {
		return null;
	}

	/*
	 * (non-Javadoc)
	 *
	 * @see io.jsonwebtoken.JwtParser#parseEncryptedClaims(java.lang.CharSequence)
	 */

	@Override
	public Jwe<Claims> parseEncryptedClaims(CharSequence jwe) {
		return null;
	}

}
