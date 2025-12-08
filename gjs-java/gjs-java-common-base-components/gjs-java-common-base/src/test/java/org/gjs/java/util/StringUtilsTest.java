package org.gjs.java.util;

import static org.junit.jupiter.api.Assertions.assertEquals;
import static org.junit.jupiter.api.Assertions.assertFalse;
import static org.junit.jupiter.api.Assertions.assertNotNull;
import static org.junit.jupiter.api.Assertions.assertNull;
import static org.junit.jupiter.api.Assertions.assertTrue;

import org.gjs.java.constant.CommonBaseConstants;
import org.gjs.java.test.BaseClassTest;
import org.junit.jupiter.api.Test;

class StringUtilsTest extends BaseClassTest<StringUtils> {

	@Test
	void testConcatenate() {
		final String nullParam = null;
		String res = StringUtils.concatenate(nullParam);
		assertNotNull(res);
		assertEquals("", res);
		res = StringUtils.concatenate("");
		assertNotNull(res);
		assertEquals("", res);
		res = StringUtils.concatenate("Hello", "", " ", "wo", "rld", "", "!");
		assertNotNull(res);
		assertEquals("Hello world!", res);
	}

	@Test
	void testConcatenateWithSeparator() {
		String res = StringUtils.concatenateWithSeparator(null, (String) null);
		assertNotNull(res);
		assertEquals("", res);
		res = StringUtils.concatenateWithSeparator(null, "");
		assertNotNull(res);
		assertEquals("", res);
		res = StringUtils.concatenateWithSeparator("", "");
		assertNotNull(res);
		assertEquals("", res);
		res = StringUtils.concatenateWithSeparator(":", "");
		assertNotNull(res);
		assertEquals("", res);
		res = StringUtils.concatenateWithSeparator(":", "", "");
		assertNotNull(res);
		assertEquals(":", res);
		res = StringUtils.concatenateWithSeparator(", ", "A", "B", "C");
		assertNotNull(res);
		assertEquals("A, B, C", res);
	}

	@Test
	void testNvl() {
		String res = StringUtils.nvl(null);
		assertNotNull(res);
		assertEquals(CommonBaseConstants.NULL_VALUE, res);
		res = StringUtils.nvl("value");
		assertNotNull(res);
		assertEquals("value", res);
	}

	@Test
	void testSecureNvl() {
		String res = StringUtils.secureNvl(null);
		assertNotNull(res);
		assertEquals(CommonBaseConstants.NULL_VALUE, res);
		res = StringUtils.secureNvl("value");
		assertNotNull(res);
		assertEquals(CommonBaseConstants.INFORMED_VALUE, res);
	}

	@Test
	void testIsSame() {
		final String value1 = null;
		final String value2 = "Anonimo";
		final String value3 = "Anónimo";
		final String value4 = "Ànónîmö";
		final String value5 = "Otroval";

		assertFalse(StringUtils.isSame(value1, value2));
		assertFalse(StringUtils.isSame(value2, value1));
		assertTrue(StringUtils.isSame(value2, value3));
		assertTrue(StringUtils.isSame(value2, value4));
		assertTrue(StringUtils.isSame(value3, value4));
		assertFalse(StringUtils.isSame(value2, value5));
	}

	@Test
	void testCapitalizeAllWords() {
		String text = null;
		String capitalized = StringUtils.capitalizeAllWords(text);
		assertNull(capitalized);
		text = "";
		capitalized = StringUtils.capitalizeAllWords(text);
		assertNotNull(capitalized);
		assertEquals("", capitalized);
		text = "  ";
		capitalized = StringUtils.capitalizeAllWords(text);
		assertNotNull(capitalized);
		assertEquals("  ", capitalized);
		text = "abc";
		capitalized = StringUtils.capitalizeAllWords(text);
		assertNotNull(capitalized);
		assertEquals("Abc", capitalized);
		text = "ABC";
		capitalized = StringUtils.capitalizeAllWords(text);
		assertNotNull(capitalized);
		assertEquals("Abc", capitalized);
		text = "ABC dfg";
		capitalized = StringUtils.capitalizeAllWords(text);
		assertNotNull(capitalized);
		assertEquals("Abc Dfg", capitalized);
	}

}
