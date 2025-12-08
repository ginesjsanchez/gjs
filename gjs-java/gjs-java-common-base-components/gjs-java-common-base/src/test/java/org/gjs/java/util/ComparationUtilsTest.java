package org.gjs.java.util;

import static org.junit.jupiter.api.Assertions.assertEquals;
import static org.junit.jupiter.api.Assertions.assertFalse;
import static org.junit.jupiter.api.Assertions.assertTrue;

import java.math.BigDecimal;
import java.math.BigInteger;
import java.util.Date;
import java.util.Set;
import java.util.TreeSet;

import org.gjs.java.test.BaseClassTest;
import org.junit.jupiter.api.Test;

class ComparationUtilsTest extends BaseClassTest<ComparationUtils> {

	@Test
	void testEquals1() {
		Long value1 = null;
		Long value2 = null;
		assertTrue(ComparationUtils.equals(value1, value2));
		value1 = Long.valueOf(7);
		assertFalse(ComparationUtils.equals(value1, value2));
		value2 = Long.valueOf(1);
		assertFalse(ComparationUtils.equals(value1, value2));
		value2 = Long.valueOf(7);
		assertTrue(ComparationUtils.equals(value1, value2));
		value1 = null;
		assertFalse(ComparationUtils.equals(value1, value2));
	}

	@Test
	void testEquals2() {
		Set<Long> value1 = null;
		Set<Long> value2 = null;
		assertTrue(ComparationUtils.equals(value1, value2));
		value1 = new TreeSet<>();
		assertFalse(ComparationUtils.equals(value1, value2));
		value2 = new TreeSet<>();
		assertTrue(ComparationUtils.equals(value1, value2));
		value1.add(Long.valueOf(7));
		assertFalse(ComparationUtils.equals(value1, value2));
		value2.add(Long.valueOf(1));
		assertFalse(ComparationUtils.equals(value1, value2));
		value1.add(Long.valueOf(1));
		value2.add(Long.valueOf(7));
		assertTrue(ComparationUtils.equals(value1, value2));
		value1 = null;
		assertFalse(ComparationUtils.equals(value1, value2));
	}

	@Test
	void testIntersects() {
		Set<Long> value1 = null;
		Set<Long> value2 = null;
		assertFalse(ComparationUtils.intersects(value1, value2));
		value1 = new TreeSet<>();
		assertFalse(ComparationUtils.intersects(value1, value2));
		value2 = new TreeSet<>();
		assertFalse(ComparationUtils.intersects(value1, value2));
		value1.add(Long.valueOf(7));
		assertFalse(ComparationUtils.intersects(value1, value2));
		value2.add(Long.valueOf(1));
		assertFalse(ComparationUtils.intersects(value1, value2));
		value1.add(Long.valueOf(1));
		assertTrue(ComparationUtils.intersects(value1, value2));
		value1 = null;
		assertFalse(ComparationUtils.intersects(value1, value2));
	}

	@Test
	void testCompareTo_long() {
		assertEquals(0, ComparationUtils.compareTo(7, 7));
		assertEquals(1, ComparationUtils.compareTo(7, 1));
		assertEquals(-1, ComparationUtils.compareTo(1, 7));
	}

	@Test
	void testCompareTo_Long() {
		final Long value1 = Long.valueOf(7);
		final Long value2 = Long.valueOf(1);
		assertEquals(0, ComparationUtils.compareTo((Long) null, (Long) null));
		assertEquals(1, ComparationUtils.compareTo(value1, null));
		assertEquals(-1, ComparationUtils.compareTo(null, value1));
		assertEquals(0, ComparationUtils.compareTo(value1, value1));
		assertEquals(1, ComparationUtils.compareTo(value1, value2));
		assertEquals(-1, ComparationUtils.compareTo(value2, value1));
	}

	@Test
	void testCompareTo_BigInteger() {
		final BigInteger value1 = new BigInteger("7");
		final BigInteger value2 = new BigInteger("1");
		assertEquals(0, ComparationUtils.compareTo((Long) null, (Long) null));
		assertEquals(1, ComparationUtils.compareTo(value1, null));
		assertEquals(-1, ComparationUtils.compareTo(null, value1));
		assertEquals(0, ComparationUtils.compareTo(value1, value1));
		assertEquals(1, ComparationUtils.compareTo(value1, value2));
		assertEquals(-1, ComparationUtils.compareTo(value2, value1));
	}

	@Test
	void testCompareTo_Date() {
		final Date yesterday = DateUtils.yesterday();
		final Date now = new Date();
		assertEquals(0, ComparationUtils.compareTo((Date) null, (Date) null));
		assertEquals(1, ComparationUtils.compareTo(now, null));
		assertEquals(-1, ComparationUtils.compareTo(null, now));
		assertEquals(0, ComparationUtils.compareTo(now, now));
		assertEquals(1, ComparationUtils.compareTo(now, yesterday));
		assertEquals(-1, ComparationUtils.compareTo(yesterday, now));
	}

	@Test
	void testCompareTo_BigDecimal() {
		final BigDecimal value1 = new BigDecimal(7);
		final BigDecimal value2 = new BigDecimal(1);
		assertEquals(0, ComparationUtils.compareTo((BigDecimal) null, (BigDecimal) null));
		assertEquals(1, ComparationUtils.compareTo(value1, null));
		assertEquals(-1, ComparationUtils.compareTo(null, value1));
		assertEquals(0, ComparationUtils.compareTo(value1, value1));
		assertEquals(1, ComparationUtils.compareTo(value1, value2));
		assertEquals(-1, ComparationUtils.compareTo(value2, value1));
	}

	@Test
	void testCompareTo_String() {
		final String value1 = "ABC";
		final String value2 = "A";
		assertEquals(0, ComparationUtils.compareTo((String) null, (String) null));
		assertEquals(1, ComparationUtils.compareTo(value1, null));
		assertEquals(-1, ComparationUtils.compareTo(null, value1));
		assertEquals(0, ComparationUtils.compareTo(value1, value1));
		assertTrue(ComparationUtils.compareTo(value1, value2) > 0);
		assertTrue(ComparationUtils.compareTo(value2, value1) < 0);
	}

}
