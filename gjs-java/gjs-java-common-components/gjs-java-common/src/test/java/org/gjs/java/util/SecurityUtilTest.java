package org.gjs.java.util;

import static org.junit.jupiter.api.Assertions.assertEquals;
import static org.junit.jupiter.api.Assertions.assertNotNull;
import static org.junit.jupiter.api.Assertions.assertNull;
import static org.junit.jupiter.api.Assertions.fail;

import org.apache.commons.lang3.exception.ExceptionUtils;
import org.gjs.java.test.BaseUnitTest;
import org.junit.jupiter.api.Test;

class SecurityUtilTest extends BaseUnitTest<SecurityUtil> {

	@Test
	void testGetCredentialsFromAuthorizationHeader() {
		try {
			String authHeader = null;
			String[] credentials = SecurityUtil.getCredentialsFromAuthorizationHeader(authHeader);
			assertNull(credentials);
			authHeader = "Bearer f9d876df71dfc72810a497dc38d1c1f467c720d8171da5e2c974647978c645ae";
			credentials = SecurityUtil.getCredentialsFromAuthorizationHeader(authHeader);
			assertNull(credentials);
			authHeader = "Basic QWxhZGRpbjpvcGVuIHNlc2FtZQ==";
			credentials = SecurityUtil.getCredentialsFromAuthorizationHeader(authHeader);
			assertNotNull(credentials);
			for (final String cred : credentials) {
				logger.debug("Credential: {}", cred);
			}
			assertEquals(2, credentials.length);
			assertEquals("Aladdin", credentials[0]);
			assertEquals("open sesame", credentials[1]);
		} catch (final Exception e) {
			logger.error(ExceptionUtils.getStackTrace(e));
			fail("Recibida excepcion");
		}
	}

}
