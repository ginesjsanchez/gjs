package org.gjs.java.common.type;

import static org.junit.jupiter.api.Assertions.assertEquals;
import static org.junit.jupiter.api.Assertions.assertFalse;
import static org.junit.jupiter.api.Assertions.assertNotNull;
import static org.junit.jupiter.api.Assertions.assertNull;
import static org.junit.jupiter.api.Assertions.assertTrue;

import org.gjs.java.common.type.Pair;
import org.gjs.java.test.BaseUnitTest;
import org.junit.jupiter.api.Test;

@SuppressWarnings("rawtypes")
class PairTest extends BaseUnitTest<Pair> {

	@Test
	void testPair() {
		final Pair<Long, String> value1 = Pair.of(null, null);
		logger.info("Object={}", value1.toString());
		assertNull(value1.getFirst());
		assertNull(value1.getSecond());
		assertTrue(value1.hashCode() == 0);

		final Pair<Long, String> value2 = Pair.of(Long.valueOf(2), "Value2");
		logger.info("Object={}", value2.toString());
		assertNotNull(value2.getFirst());
		assertNotNull(value2.getSecond());
		assertEquals(2, value2.getFirst());
		assertEquals("Value2", value2.getSecond());
		assertTrue(value2.hashCode() != 0);

		assertFalse(value1.equals(value2));
		assertFalse(value2.equals(value1));
		assertFalse(value1.equals(null));
		assertFalse(value2.equals(null));

		value1.setFirst(Long.valueOf(1));
		value1.setSecond("Value1");
		logger.info("Object={}", value1.toString());
		assertNotNull(value1.getFirst());
		assertNotNull(value1.getSecond());
		assertEquals(1, value1.getFirst());
		assertEquals("Value1", value1.getSecond());

		assertFalse(value1.equals(value2));
		assertFalse(value2.equals(value1));
		value2.setFirst(Long.valueOf(1));
		assertFalse(value1.equals(value2));
		assertFalse(value2.equals(value1));
		value2.setSecond("Value1");
		assertTrue(value1.equals(value2));
		assertTrue(value2.equals(value1));

	}

}
