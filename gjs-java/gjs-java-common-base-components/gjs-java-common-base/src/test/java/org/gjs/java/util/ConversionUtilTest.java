package org.gjs.java.util;

import static org.junit.jupiter.api.Assertions.assertEquals;
import static org.junit.jupiter.api.Assertions.assertFalse;
import static org.junit.jupiter.api.Assertions.assertNotNull;
import static org.junit.jupiter.api.Assertions.assertTrue;
import static org.junit.jupiter.api.Assertions.fail;

import java.util.Locale;

import org.gjs.java.exception.GjsException;
import org.gjs.java.test.BaseClassTest;
import org.junit.jupiter.api.Test;

class ConversionUtilTest extends BaseClassTest<ConversionUtils> {

	@Test
	void testLongValue1() {
		final Long value1 = Long.valueOf(7);
		final Long value2 = null;
		assertEquals(0, ConversionUtils.longValue(value2));
		assertEquals(7, ConversionUtils.longValue(value1));
	}

	@Test
	void testIntValue1() {
		final Integer value1 = Integer.valueOf(7);
		final Integer value2 = null;
		assertEquals(0, ConversionUtils.intValue(value2));
		assertEquals(7, ConversionUtils.intValue(value1));
	}

	@Test
	void testIntValue2() {
		final Short value1 = Short.valueOf((short) 7);
		final Short value2 = null;
		assertEquals(0, ConversionUtils.intValue(value2));
		assertEquals(7, ConversionUtils.intValue(value1));
	}

	@Test
	void testLongValue2() {
		final String value1 = "7";
		final String value2 = "-1";
		try {
			assertEquals(-1, ConversionUtils.longValue(value2));
			assertEquals(7, ConversionUtils.longValue(value1));
		} catch (final Exception e) {
			fail("Se ha producido una excepcion");
		}
	}

	@Test
	void testLongValue_Exception1() {
		final String value1 = "x";
		try {
			ConversionUtils.longValue(value1);
			fail("Se esperaba uns excepcion");
		} catch (final GjsException e) {

		} catch (final Exception e) {
			fail("Se ha producido una excepcion inesperada");
		}
	}

	@Test
	void testLongValue_Exception2() {
		final String value1 = null;
		try {
			ConversionUtils.longValue(value1);
			fail("Se esperaba uns excepcion");
		} catch (final GjsException e) {

		} catch (final Exception e) {
			fail("Se ha producido una excepcion inesperada");
		}
	}

	@Test
	void testPositiveLongValue1() {
		final String value1 = "7";
		final String value2 = "0";
		try {
			assertEquals(0, ConversionUtils.unsignedLongValue(value2));
			assertEquals(7, ConversionUtils.unsignedLongValue(value1));
		} catch (final Exception e) {
			fail("Se ha producido una excepcion");
		}
	}

	@Test
	void testPositiveLongValue_Exception1() {
		final String value1 = "x-1";
		try {
			ConversionUtils.unsignedLongValue(value1);
			fail("Se esperaba uns excepcion");
		} catch (final GjsException e) {

		} catch (final Exception e) {
			fail("Se ha producido una excepcion inesperada");
		}
	}

	@Test
	void testPositiveLongValue_Exception2() {
		final String value1 = null;
		try {
			ConversionUtils.unsignedLongValue(value1);
			fail("Se esperaba uns excepcion");
		} catch (final GjsException e) {

		} catch (final Exception e) {
			fail("Se ha producido una excepcion inesperada");
		}
	}

	@Test
	void testBooleanValue() {
		logger.info(" Si".trim().toUpperCase(Locale.getDefault()));
		assertTrue("SI".equals(" Si".trim().toUpperCase(Locale.getDefault())));
		assertFalse(ConversionUtils.booleanValue(null));
		assertFalse(ConversionUtils.booleanValue(""));
		assertFalse(ConversionUtils.booleanValue("xxxx"));
		assertFalse(ConversionUtils.booleanValue("No"));
		assertTrue(ConversionUtils.booleanValue(" Si"));
		assertTrue(ConversionUtils.booleanValue("1"));
		assertTrue(ConversionUtils.booleanValue("YEs"));
		assertTrue(ConversionUtils.booleanValue("true"));
		assertFalse(ConversionUtils.booleanValue("0"));
		assertFalse(ConversionUtils.booleanValue("false "));
	}

	@Test
	void testAssignValue() {
		final Long idNull = null;
		final Long id1 = Long.valueOf(1);
		final Long idDef = Long.valueOf(0);
		Long id = ConversionUtils.assignValue(id1, idDef);
		assertNotNull(id);
		assertEquals(id1, id);
		id = ConversionUtils.assignValue(idNull, idDef);
		assertNotNull(id);
		assertEquals(idDef, id);
	}

}
