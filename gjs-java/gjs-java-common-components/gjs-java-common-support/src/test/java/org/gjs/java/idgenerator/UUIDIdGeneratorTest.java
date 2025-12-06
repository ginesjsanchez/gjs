package org.gjs.java.idgenerator;

import static org.junit.jupiter.api.Assertions.assertEquals;
import static org.junit.jupiter.api.Assertions.assertFalse;
import static org.junit.jupiter.api.Assertions.assertNotNull;

import java.util.Set;
import java.util.TreeSet;

import org.gjs.java.test.BaseClassTest;
import org.junit.jupiter.api.Test;

class UUIDIdGeneratorTest extends BaseClassTest<UUIDIdGenerator> {

	@Test
	void testSequenceIdGenerator() {
		final UUIDIdGenerator generator = new UUIDIdGenerator();
		String value = generator.generate();
		assertNotNull(value);
		assertEquals(36, value.length());
		final Set<String> setGenerated = new TreeSet<>();
		for (int i = 0; i < 50; i = i + 1) {
			value = generator.generate();
			assertNotNull(value);
			assertEquals(36, value.length());
			assertFalse(setGenerated.contains(value));
		}
	}

}
