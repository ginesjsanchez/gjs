package org.gjs.java.enums;

import static org.junit.jupiter.api.Assertions.assertEquals;
import static org.junit.jupiter.api.Assertions.assertFalse;
import static org.junit.jupiter.api.Assertions.assertNotNull;
import static org.junit.jupiter.api.Assertions.assertNull;
import static org.junit.jupiter.api.Assertions.assertTrue;
import static org.junit.jupiter.api.Assertions.fail;

import org.junit.jupiter.api.Test;

import org.gjs.java.test.BaseClassTest;

class ManagedTypeTest extends BaseClassTest<ManagedType> {

    @Test
    void testManagedType() {
        try {
            final ManagedType type = ManagedType.BIGDECIMAL;
            assertNotNull(type.getClassName());
            assertNotNull(type.toString());
            assertNotNull(type.getDefaultObject());
            assertEquals(type.getClassName(), type.toString());
            assertEquals(ManagedType.BIGDECIMAL, type);
            assertTrue(type.equalsTo(ManagedType.BIGDECIMAL.getClassName()));
            assertFalse(type.equalsTo((ManagedType) null));
            assertTrue(type.equalsTo(ManagedType.BIGDECIMAL));
            assertFalse(type.equalsTo((String) null));
            assertFalse(type.equalsTo(""));
        } catch (final Exception e) {
            logger.error(e.getMessage(),e);
            fail("Excepcion inesperada");
        }
    }

    @Test
    void testIsManaged() {
        try {
            assertTrue(ManagedType.isManaged(ManagedType.BIGINTEGER.getClassName()));
            assertTrue(ManagedType.isManaged(ManagedType.BIGDECIMAL.getClassName()));
            assertFalse(ManagedType.isManaged("ABC"));
            assertFalse(ManagedType.isManaged(""));
            assertFalse(ManagedType.isManaged(null));

        } catch (final Exception e) {
            logger.error(e.getMessage(),e);
            fail("Excepcion inesperada");
        }
    }

    @Test
    void testIsSameType() {
        try {
            assertTrue(ManagedType.BIGINTEGER.isSameType("java.math.BigInteger"));
            assertTrue(ManagedType.BIGDECIMAL.isSameType("java.math.BigDecimal"));
            assertFalse(ManagedType.BIGDECIMAL.isSameType("BigDecimal"));
            assertFalse(ManagedType.BIGDECIMAL.isSameType("char"));
            assertFalse(ManagedType.BIGDECIMAL.isSameType(""));
            assertFalse(ManagedType.BIGDECIMAL.isSameType(null));
        } catch (final Exception e) {
            logger.error(e.getMessage(),e);
            fail("Excepcion inesperada");
        }
    }

    @Test
    void testGet() {
        try {
            ManagedType type = ManagedType.get("java.math.BigDecimal");
            assertNotNull(type);
            assertEquals(ManagedType.BIGDECIMAL, type);
            type = ManagedType.get("java.lang.Boolean");
            assertNull(type);
        } catch (final Exception e) {
            logger.error(e.getMessage(),e);
            fail("Excepcion inesperada");
        }
    }

}
