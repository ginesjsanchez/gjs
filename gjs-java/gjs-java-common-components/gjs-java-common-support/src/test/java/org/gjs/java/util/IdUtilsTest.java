package org.gjs.java.util;

import static org.junit.jupiter.api.Assertions.assertFalse;
import static org.junit.jupiter.api.Assertions.assertTrue;

import java.math.BigDecimal;
import java.math.BigInteger;

import org.gjs.java.test.BaseClassTest;
import org.junit.jupiter.api.Test;

class IdUtilsTest extends BaseClassTest<IdUtils> {

	@Test
	void testIsValid() {
		assertFalse(IdUtils.isValid((Short) null));
		assertFalse(IdUtils.isValid((Integer) null));
		assertFalse(IdUtils.isValid((Long) null));
		assertFalse(IdUtils.isValid((BigDecimal) null));
		assertFalse(IdUtils.isValid((BigInteger) null));
		assertFalse(IdUtils.isValid(Short.valueOf((short) 0)));
		assertFalse(IdUtils.isValid(Integer.valueOf(0)));
		assertFalse(IdUtils.isValid(Long.valueOf(0)));
		assertFalse(IdUtils.isValid(BigDecimal.ZERO));
		assertFalse(IdUtils.isValid(BigInteger.ZERO));
		assertTrue(IdUtils.isValid(Short.valueOf((short) 1)));
		assertTrue(IdUtils.isValid(Integer.valueOf(1)));
		assertTrue(IdUtils.isValid(Long.valueOf(1)));
		assertTrue(IdUtils.isValid(BigDecimal.ONE));
		assertTrue(IdUtils.isValid(BigInteger.ONE));
	}

	@Test
	void testIsOneOf() {
		Long id = null;
		assertFalse(IdUtils.isOneOf(id));
		assertFalse(IdUtils.isOneOf(id, Long.valueOf(1)));
		id = Long.valueOf(1);
		assertFalse(IdUtils.isOneOf(id));
		assertTrue(IdUtils.isOneOf(id, Long.valueOf(1)));
		id = Long.valueOf(2);
		assertTrue(IdUtils.isOneOf(id, Long.valueOf(1), Long.valueOf(2), Long.valueOf(3)));
		id = Long.valueOf(4);
		assertFalse(IdUtils.isOneOf(id, Long.valueOf(1), Long.valueOf(2), Long.valueOf(3)));
		id = Long.valueOf(0);
		assertFalse(IdUtils.isOneOf(id, Long.valueOf(0), Long.valueOf(1), Long.valueOf(2)));
	}

	@Test
	void testIsBetween() {
		Long id = null;
		Long idMin = null;
		Long idMax = null;
		assertFalse(IdUtils.isBetween(id, idMin, idMax));
		id = Long.valueOf(1);
		assertFalse(IdUtils.isBetween(id, idMin, idMax));
		idMin = Long.valueOf(1);
		idMax = Long.valueOf(1);
		assertTrue(IdUtils.isBetween(id, idMin, idMax));
		id = Long.valueOf(2);
		idMin = Long.valueOf(0);
		idMax = Long.valueOf(10);
		assertFalse(IdUtils.isBetween(id, idMin, idMax));
		idMin = Long.valueOf(1);
		idMax = Long.valueOf(10);
		assertTrue(IdUtils.isBetween(id, idMin, idMax));
	}

}
