package org.gjs.java.util;

import static org.junit.jupiter.api.Assertions.assertEquals;
import static org.junit.jupiter.api.Assertions.assertFalse;
import static org.junit.jupiter.api.Assertions.assertNotNull;
import static org.junit.jupiter.api.Assertions.assertNull;
import static org.junit.jupiter.api.Assertions.assertTrue;
import static org.junit.jupiter.api.Assertions.fail;

import java.util.Set;
import java.util.TreeSet;

import org.apache.commons.lang3.exception.ExceptionUtils;
import org.gjs.java.exception.GjsException;
import org.gjs.java.supplier.random.RandomAlphanumericStringSupplier;
import org.gjs.java.test.BaseUnitTest;
import org.junit.jupiter.api.Test;

public class AesUtilTest extends BaseUnitTest<AesUtil> {

	RandomAlphanumericStringSupplier stringSupplier;

	@Override
	protected void initialize() throws Exception {
		stringSupplier = new RandomAlphanumericStringSupplier(35, false, false);
	}

	@Test
	public void testEncryptLong1() {
		try {
			final Long plain = 518L;
			final String encrypted = AesUtil.encryptLong(plain);
			assertNotNull(encrypted);
			logger.info("Encriptado={} ({})", encrypted, encrypted.length());
			final Long decrypted = AesUtil.decryptLong(encrypted);
			assertNotNull(decrypted);
			assertEquals(decrypted, plain);
		} catch (final GjsException e) {
			logger.error(ExceptionUtils.getStackTrace(e));
			fail("Excepcion recibida");
		}
	}

	@Test
	public void testEncryptLong2() {
		try {
			final Long plain = null;
			logger.debug("[{}]", String.valueOf(plain));
			final String encrypted = AesUtil.encryptLong(plain);
			assertNull(encrypted);
			final Long decrypted = AesUtil.decryptLong(encrypted);
			assertNull(decrypted);
		} catch (final GjsException e) {
			logger.error(ExceptionUtils.getStackTrace(e));
			fail("Excepcion recibida");
		}
	}

	@Test
	public void testEncryptLong3() {
		try {
			for (Long plain = 0L; plain < 100L; plain = plain + 1) {
				final String encrypted = AesUtil.encryptLong(plain);
				assertNotNull(encrypted);
				logger.info("Encriptado={} ({})", encrypted, encrypted.length());
				final Long decrypted = AesUtil.decryptLong(encrypted);
				assertNotNull(decrypted);
				assertEquals(decrypted, plain);
			}
		} catch (final GjsException e) {
			logger.error(ExceptionUtils.getStackTrace(e));
			fail("Excepcion recibida");
		}
	}

	@Test
	public void testEncryptString1() {
		try {
			String plain = "maoashi-geri";
			String encrypted = AesUtil.encryptString(plain);
			assertNotNull(encrypted);
			final String decrypted = AesUtil.decryptString(encrypted);
			assertNotNull(decrypted);
			assertEquals(decrypted, plain);

			plain = "t3mp0r4l";
			encrypted = AesUtil.encryptString(plain);
			assertNotNull(encrypted);
			logger.debug("{} : {}", plain, encrypted);

		} catch (final GjsException e) {
			logger.error(e.getMessage(), e);
		}
	}

	@Test
	public void testEncryptString2() {
		try {
			final String plain = null;
			final String encrypted = AesUtil.encryptString(plain);
			assertNull(encrypted);
			final String decrypted = AesUtil.decryptString(encrypted);
			assertNull(decrypted);
		} catch (final GjsException e) {
			logger.error(e.getMessage(), e);
		}
	}

	@Test
	public void testEncryptString3() {
		final RandomAlphanumericStringSupplier supplier = new RandomAlphanumericStringSupplier(64, false, false);
		try {
			final Set<String> setResults = new TreeSet<>();
			for (int i = 0; i < 20; i = i + 1) {
				final String plain = supplier.get();
				if (plain.trim().length() > 0) {
					assertNotNull(plain);
					final String encrypted = AesUtil.encryptString(plain);
					assertNotNull(encrypted);
					logger.info("Plain=[{}]->Encrypted=[{}]", plain, encrypted);
					assertFalse(setResults.contains(encrypted));
					setResults.add(encrypted);
				}
			}
		} catch (final GjsException e) {
			logger.error(e.getMessage(), e);
		}
	}

	@Test
	public void testEncryptDecrypt() {
		try {
			for (int i = 0; i < 1000; i = i + 1) {
				final String plain = stringSupplier.get();
				final String encrypted = AesUtil.encryptString(plain);
				assertNotNull(encrypted);
				assertFalse(encrypted.contains("/"), String.format("Encriptado con '/':%s", (encrypted)));
				assertTrue(ValidationUtils.isValidCid(encrypted), String.format("Formato invalido:%s", (encrypted)));
				final String decrypted = AesUtil.decryptString(encrypted);
				assertNotNull(decrypted);
				assertEquals(decrypted, plain, String.format("Error encrypt/decrypt plain:{}", plain));
			}

		} catch (final GjsException e) {
			logger.error(e.getMessage(), e);
		}
	}

}
