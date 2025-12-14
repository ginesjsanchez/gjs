package org.gjs.java.common.enums;

import static org.junit.jupiter.api.Assertions.assertEquals;
import static org.junit.jupiter.api.Assertions.assertFalse;
import static org.junit.jupiter.api.Assertions.assertNotNull;
import static org.junit.jupiter.api.Assertions.assertNull;
import static org.junit.jupiter.api.Assertions.assertTrue;
import static org.junit.jupiter.api.Assertions.fail;

import org.junit.jupiter.api.Test;
import org.gjs.java.common.enums.PrimitiveType;
import org.gjs.java.test.BaseClassTest;

class PrimitiveTypeTest extends BaseClassTest<PrimitiveType> {

    @Test
    void testPrimitiveType() {
        try {
            final PrimitiveType type = PrimitiveType.INTEGER;
            assertNotNull(type.getClassName());
            assertNotNull(type.getName());
            assertNotNull(type.getArrayTypeName());
            assertNotNull(type.toString());
            assertNotNull(type.getJVMName());
            assertNotNull(type.getDefaultValue());
            assertNotNull(type.getDefaultObject());
            assertNotNull(type.getDefaultArray());
            assertEquals(0, ((int[]) type.getDefaultArray()).length);
            assertEquals(type.getName(), type.toString());
            assertEquals(PrimitiveType.INTEGER, type);
            assertTrue(type.equalsTo(PrimitiveType.INTEGER.getName()));
            assertFalse(type.equalsTo((PrimitiveType) null));
            assertTrue(type.equalsTo(PrimitiveType.INTEGER));
            assertFalse(type.equalsTo((String) null));
            assertFalse(type.equalsTo(""));
        } catch (final Exception e) {
            logger.error(e.getMessage(),e);
            fail("Excepcion inesperada");
        }
    }

    @Test
    void testIsPrimitive() {
        try {
            assertTrue(PrimitiveType.isPrimitive(PrimitiveType.INTEGER.getName()));
            assertTrue(PrimitiveType.isPrimitive(PrimitiveType.INTEGER.getClassName()));
            assertFalse(PrimitiveType.isPrimitive("ABC"));
            assertFalse(PrimitiveType.isPrimitive(""));
            assertFalse(PrimitiveType.isPrimitive(null));

            assertTrue(PrimitiveType.isPrimitiveNative(PrimitiveType.INTEGER.getName()));
            assertFalse(PrimitiveType.isPrimitiveNative(PrimitiveType.INTEGER.getClassName()));
            assertFalse(PrimitiveType.isPrimitiveNative("ABC"));
            assertFalse(PrimitiveType.isPrimitiveNative(""));
            assertFalse(PrimitiveType.isPrimitiveNative(null));

            assertFalse(PrimitiveType.isPrimitiveClass(PrimitiveType.INTEGER.getName()));
            assertTrue(PrimitiveType.isPrimitiveClass(PrimitiveType.INTEGER.getClassName()));
            assertFalse(PrimitiveType.isPrimitiveClass("ABC"));
            assertFalse(PrimitiveType.isPrimitiveClass(""));
            assertFalse(PrimitiveType.isPrimitiveClass(null));
        } catch (final Exception e) {
            logger.error(e.getMessage(),e);
            fail("Excepcion inesperada");
        }
    }

    @Test
    void testIsSameType() {
        try {
            assertTrue(PrimitiveType.INTEGER.isSameType("int"));
            assertTrue(PrimitiveType.INTEGER.isSameType("java.lang.Integer"));
            assertFalse(PrimitiveType.INTEGER.isSameType("char"));
            assertFalse(PrimitiveType.INTEGER.isSameType(""));
            assertFalse(PrimitiveType.INTEGER.isSameType(null));
            assertTrue(PrimitiveType.INTEGER.isSameNativeType("int"));
            assertFalse(PrimitiveType.INTEGER.isSameNativeType("java.lang.Integer"));
            assertFalse(PrimitiveType.INTEGER.isSameClassType("int"));
            assertTrue(PrimitiveType.INTEGER.isSameClassType("java.lang.Integer"));
            assertTrue(PrimitiveType.LONG.isSameClassType("java.lang.Long"));
            assertFalse(PrimitiveType.LONG.isSameClassType("long"));
            assertTrue(PrimitiveType.LONG.isSameNativeType("long"));
        } catch (final Exception e) {
            logger.error(e.getMessage(),e);
            fail("Excepcion inesperada");
        }
    }

    @Test
    void testGet() {
        try {
            PrimitiveType type = PrimitiveType.get("char");
            assertNotNull(type);
            assertEquals(PrimitiveType.CHAR, type);
            type = PrimitiveType.getFromClass("java.lang.Boolean");
            assertNotNull(type);
            assertEquals(PrimitiveType.BOOLEAN, type);
            type = PrimitiveType.get("euro");
            assertNull(type);
            type = PrimitiveType.getFromClass("java.math.BigDecimal");
            assertNull(type);
        } catch (final Exception e) {
            logger.error(e.getMessage(),e);
            fail("Excepcion inesperada");
        }
    }

}
