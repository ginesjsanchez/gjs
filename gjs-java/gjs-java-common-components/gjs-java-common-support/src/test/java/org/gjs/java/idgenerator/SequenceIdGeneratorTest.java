package org.gjs.java.idgenerator;

import static org.junit.jupiter.api.Assertions.assertEquals;
import static org.junit.jupiter.api.Assertions.assertNotNull;

import org.gjs.java.test.BaseClassTest;
import org.junit.jupiter.api.Test;

class SequenceIdGeneratorTest extends BaseClassTest<SequenceIdGenerator> {

	@Test
	void testSequenceIdGenerator() {
		final SequenceIdGenerator generator = new SequenceIdGenerator();
		Long value = generator.generate();
		assertNotNull(value);
		assertEquals(1, value);
		value = generator.generate();
		assertNotNull(value);
		assertEquals(2, value);
	}

}
