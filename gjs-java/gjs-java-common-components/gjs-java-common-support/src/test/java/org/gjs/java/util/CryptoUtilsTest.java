package org.gjs.java.util;

import static org.junit.jupiter.api.Assertions.assertEquals;
import static org.junit.jupiter.api.Assertions.assertNotNull;
import static org.junit.jupiter.api.Assertions.fail;

import java.io.IOException;
import java.security.NoSuchAlgorithmException;

import org.apache.commons.lang3.ArrayUtils;
import org.gjs.java.exception.GjsException;
import org.gjs.java.supplier.random.RandomBytesSupplier;
import org.gjs.java.test.BaseClassTest;
import org.junit.jupiter.api.Test;


class CryptoUtilsTest extends BaseClassTest<CryptoUtils> {

    @Test
    void testHash1() throws NoSuchAlgorithmException, IOException {
        try {
            final byte[] bytes = null;
            final String algorithm = null;
            @SuppressWarnings("unused")
            final String hash = CryptoUtils.hash(bytes, algorithm);
            fail("No deberia llegar aqui");
        } catch (final GjsException e) {
            assertNotNull(e);
            logger.debug(e.getMessage());
        } catch (final Exception e) {
            fail("Recibida excepcion: " + e.getMessage());
        }
    }

    @Test
    void testHash2() {
        try {
            final byte[] bytes = new byte[0];
            final String algorithm = null;
            @SuppressWarnings("unused")
            final String hash = CryptoUtils.hash(bytes, algorithm);
            fail("No deberia llegar aqui");
        } catch (final GjsException e) {
            assertNotNull(e);
            logger.debug(e.getMessage());
        } catch (final Exception e) {
            fail("Recibida excepcion: " + e.getMessage());
        }
    }

    @Test
    void testHash3() {
        try {
            final byte[] bytes = new byte[0];
            final String algorithm = "SHA-256";
            final String hash = CryptoUtils.hash(bytes, algorithm);
            assertNotNull(hash);
            assertEquals(64, hash.length());
            assertEquals("e3b0c44298fc1c149afbf4c8996fb92427ae41e4649b934ca495991b7852b855", hash);
            logger.debug("Hash={}", hash);
        } catch (final Exception e) {
            fail("Recibida excepcion: " + e.getMessage());
        }
    }

    @Test
    void testHash4() {
        final RandomBytesSupplier supplier = new RandomBytesSupplier();
        supplier.setNullable(false);
        supplier.setMaxLength(1024);
        try {
            for (int i = 0; i < 10; i = i + 1) {
                final Byte[] bytes = supplier.get();
                final String algorithm = "SHA-256";
                final String hash = CryptoUtils.hash(ArrayUtils.toPrimitive(bytes), algorithm);
                assertNotNull(hash);
                assertEquals(64, hash.length());
                logger.debug("Hash={}", hash);
            }
        } catch (final Exception e) {
            fail("Recibida excepcion: " + e.getMessage());
        }
    }

}
