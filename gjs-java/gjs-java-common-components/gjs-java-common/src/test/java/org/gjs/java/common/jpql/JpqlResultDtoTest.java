package org.gjs.java.common.jpql;

import static org.junit.jupiter.api.Assertions.assertFalse;
import static org.junit.jupiter.api.Assertions.assertTrue;

import org.gjs.java.common.jpql.JpqlResultDto;
import org.gjs.java.common.jpql.ThereAreNoneDto;
import org.gjs.java.common.jpql.ThereIsAnyDto;
import org.gjs.java.common.jpql.ThereIsTrueDto;
import org.gjs.java.test.BaseUnitTest;
import org.junit.jupiter.api.Test;

@SuppressWarnings("rawtypes")
public class JpqlResultDtoTest extends BaseUnitTest<JpqlResultDto> {

	@Test
	void testBooleanJpqlResultDto() {
		ThereAreNoneDto dto1 = new ThereAreNoneDto(0);
		assertTrue(dto1.getValue());
		dto1 = new ThereAreNoneDto(1);
		assertFalse(dto1.getValue());
		dto1 = new ThereAreNoneDto(-1);
		assertFalse(dto1.getValue());

		ThereIsAnyDto dto2 = new ThereIsAnyDto(0);
		assertFalse(dto2.getValue());
		dto2 = new ThereIsAnyDto(1);
		assertTrue(dto2.getValue());
		dto2 = new ThereIsAnyDto(-1);
		assertFalse(dto2.getValue());

		ThereIsTrueDto dto3 = new ThereIsTrueDto(0);
		assertFalse(dto3.getValue());
		dto3 = new ThereIsTrueDto(1);
		assertTrue(dto3.getValue());
		dto3 = new ThereIsTrueDto(-1);
		assertFalse(dto3.getValue());
		dto3 = new ThereIsTrueDto(true);
		assertTrue(dto3.getValue());
		dto3 = new ThereIsTrueDto(false);
		assertFalse(dto3.getValue());
	}

}
