package org.gjs.java.dto;

import static org.junit.jupiter.api.Assertions.assertTrue;

import org.gjs.java.test.BaseClassTest;
import org.junit.jupiter.api.Test;

class BaseDtoTest extends BaseClassTest<BaseDto> {

	private class EjemploDto extends BaseDto {

		private static final long serialVersionUID = 1L;

	}

	@Test
	void testBaseDto() {
		final EjemploDto dto = new EjemploDto();
		assertTrue(dto.isValid());
	}

}
