package org.gjs.java.types;

import static org.junit.jupiter.api.Assertions.assertFalse;
import static org.junit.jupiter.api.Assertions.assertTrue;

import org.gjs.java.test.BaseClassTest;
import org.junit.jupiter.api.Test;

class PatternMatcherTest extends BaseClassTest<PatternMatcher> {

	@Test
	void testIsValidEmail() {
		final String email1 = null;
		final String email2 = "";
		final String email3 = "gandalf.com";
		final String email4 = "abu.sayaf@pakistanmail.com";
		assertFalse(PatternMatcher.isValidEmail(email1));
		assertFalse(PatternMatcher.isValidEmail(email2));
		assertFalse(PatternMatcher.isValidEmail(email3));
		assertTrue(PatternMatcher.isValidEmail(email4));
	}

}
