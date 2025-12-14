package org.gjs.java.common.dto;

import static org.junit.jupiter.api.Assertions.assertEquals;
import static org.junit.jupiter.api.Assertions.assertFalse;
import static org.junit.jupiter.api.Assertions.assertNotNull;
import static org.junit.jupiter.api.Assertions.assertNull;
import static org.junit.jupiter.api.Assertions.assertTrue;
import static org.junit.jupiter.api.Assertions.fail;

import java.util.Date;

import org.gjs.java.common.dto.GenericDto;
import org.gjs.java.test.BaseUnitTest;
import org.junit.jupiter.api.Test;

class GenericDtoTest extends BaseUnitTest<GenericDto> {

	@Test
	void testGenericDto1() {
		try {
			final GenericDto genericDto = new GenericDto();
			assertEquals(0, genericDto.size());
			assertNull(genericDto.getField(0));
			assertNotNull(genericDto.toString());
			assertFalse(genericDto.equals(null));
			assertTrue(genericDto.equals(genericDto));
		} catch (final Exception e) {
			fail("Recibida excepcion: " + e.getMessage());
		}
	}

	@Test
	void testGenericDto2() {
		try {
			final GenericDto genericDto1 = new GenericDto(Long.valueOf(0), "Texto1");
			final GenericDto genericDto2 = new GenericDto(Long.valueOf(0), "Texto1", new Date());
			assertEquals(2, genericDto1.size());
			assertEquals(3, genericDto2.size());
			assertNotNull(genericDto1.getField(0));
			assertNotNull(genericDto1.getField(1));
			assertEquals((long) 0, genericDto1.getField(0));
			assertEquals("Texto1", genericDto1.getField(1));
			assertNotNull(genericDto2.getField(0));
			assertNotNull(genericDto2.getField(1));
			assertNotNull(genericDto2.getField(2));
			assertNotNull(genericDto1.toString());
			assertFalse(genericDto1.equals(genericDto2));
			assertTrue(genericDto2.equals(genericDto2));
		} catch (final Exception e) {
			fail("Recibida excepcion: " + e.getMessage());
		}
	}

}
