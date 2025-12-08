package org.gjs.java.util;

import static org.junit.jupiter.api.Assertions.assertFalse;
import static org.junit.jupiter.api.Assertions.assertTrue;

import org.gjs.java.test.BaseUnitTest;
import org.junit.jupiter.api.Test;

public class BitwiseUtilsTest extends BaseUnitTest<BitwiseUtils> {

	@Test
	public void testIsSet1() {
		int value = 0;
		int pos = -1;
		assertFalse(BitwiseUtils.isSet(value, pos));
		for (pos = 0; pos < 32; pos = pos + 1) {
			assertFalse(BitwiseUtils.isSet(value, pos));
		}
		value = 1;
		pos = 0;
		assertTrue(BitwiseUtils.isSet(value, pos));
		pos = 1;
		assertFalse(BitwiseUtils.isSet(value, pos));
		value = 13;
		pos = 0;
		assertTrue(BitwiseUtils.isSet(value, pos));
		pos = 1;
		assertFalse(BitwiseUtils.isSet(value, pos));
		pos = 2;
		assertTrue(BitwiseUtils.isSet(value, pos));
		pos = 3;
		assertTrue(BitwiseUtils.isSet(value, pos));
		pos = 4;
		assertFalse(BitwiseUtils.isSet(value, pos));
	}

}
