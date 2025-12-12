package org.gjs.java.dto;

import static org.junit.jupiter.api.Assertions.assertEquals;
import static org.junit.jupiter.api.Assertions.assertFalse;
import static org.junit.jupiter.api.Assertions.assertNotNull;
import static org.junit.jupiter.api.Assertions.assertNull;
import static org.junit.jupiter.api.Assertions.assertTrue;

import org.gjs.java.test.BaseUnitTest;
import org.junit.jupiter.api.Test;

public class EntityDtoTest extends BaseUnitTest<AuditDto> {

	@SuppressWarnings("serial")
	static class EntitySampleLongDto extends EntityPkLongDto {

		public EntitySampleLongDto() {
		}

		public EntitySampleLongDto(EntitySampleLongDto other) {
			super(other);
		}

		public EntitySampleLongDto(Long id) {
			super(id);
		}
	}

	@SuppressWarnings("serial")
	static class EntitySampleStringDto extends EntityPkStringDto {

		public EntitySampleStringDto() {
		}

		public EntitySampleStringDto(EntitySampleStringDto other) {
			super(other);
		}

		public EntitySampleStringDto(String id) {
			super(id);
		}
	}

	@Test
	void testEntityPkLongDto1() {
		final EntitySampleLongDto dto1 = new EntitySampleLongDto();
		assertNull(dto1.getId());
		assertNotNull(dto1.getEntityName());
		assertEquals("EntitySampleLong", dto1.getEntityName());
		assertFalse(dto1.isValid());
		assertFalse(dto1.hasId());
		assertNotNull(dto1.toString());
		dto1.setId(Long.valueOf(0));
		assertNotNull(dto1.getId());
		assertFalse(dto1.isValid());
		assertFalse(dto1.hasId());
		dto1.setId(Long.valueOf(-1));
		assertNotNull(dto1.getId());
		assertFalse(dto1.isValid());
		assertFalse(dto1.hasId());
		dto1.setId(Long.valueOf(1));
		assertNotNull(dto1.getId());
		assertTrue(dto1.isValid());
		assertTrue(dto1.hasId());
	}

	@Test
	void testEntityPkLongDto2() {
		final EntitySampleLongDto dto0 = new EntitySampleLongDto();
		final EntitySampleLongDto dto1 = new EntitySampleLongDto(Long.valueOf(1));
		final EntitySampleLongDto dto2 = new EntitySampleLongDto(Long.valueOf(2));
		final EntitySampleLongDto dto3 = new EntitySampleLongDto(dto2);
		assertFalse(dto1.equals(null));
		assertEquals(1, dto1.compareTo(null));
		assertTrue(dto1.equals(dto1));
		assertEquals(0, dto1.compareTo(dto1));
		assertFalse(dto1.equals(dto0));
		assertEquals(1, dto1.compareTo(dto0));
		assertFalse(dto0.equals(dto1));
		assertEquals(-1, dto0.compareTo(dto1));
		assertFalse(dto1.equals(dto2));
		assertEquals(-1, dto1.compareTo(dto2));
		assertFalse(dto2.equals(dto1));
		assertEquals(1, dto2.compareTo(dto1));
		assertTrue(dto2.equals(dto3));
		assertEquals(0, dto2.compareTo(dto3));
	}

	@Test
	void testEntityPkStringDto1() {
		final EntitySampleStringDto dto1 = new EntitySampleStringDto();
		assertNull(dto1.getId());
		assertNotNull(dto1.getEntityName());
		assertEquals("EntitySampleString", dto1.getEntityName());
		assertFalse(dto1.isValid());
		assertFalse(dto1.hasId());
		assertNotNull(dto1.toString());
		dto1.setId("");
		assertNotNull(dto1.getId());
		assertFalse(dto1.isValid());
		assertFalse(dto1.hasId());
		dto1.setId("  ");
		assertNotNull(dto1.getId());
		assertFalse(dto1.isValid());
		assertFalse(dto1.hasId());
		dto1.setId("Cod1");
		assertNotNull(dto1.getId());
		assertTrue(dto1.isValid());
		assertTrue(dto1.hasId());
	}

	@Test
	void testEntityPkStringDto2() {
		final EntitySampleStringDto dto0 = new EntitySampleStringDto();
		final EntitySampleStringDto dto1 = new EntitySampleStringDto("Cod1");
		final EntitySampleStringDto dto2 = new EntitySampleStringDto("Cod2");
		final EntitySampleStringDto dto3 = new EntitySampleStringDto(dto2);
		assertFalse(dto1.equals(null));
		assertEquals(1, dto1.compareTo(null));
		assertTrue(dto1.equals(dto1));
		assertEquals(0, dto1.compareTo(dto1));
		assertFalse(dto1.equals(dto0));
		assertEquals(1, dto1.compareTo(dto0));
		assertFalse(dto0.equals(dto1));
		assertEquals(-1, dto0.compareTo(dto1));
		assertFalse(dto1.equals(dto2));
		assertEquals(-1, dto1.compareTo(dto2));
		assertFalse(dto2.equals(dto1));
		assertEquals(1, dto2.compareTo(dto1));
		assertTrue(dto2.equals(dto3));
		assertEquals(0, dto2.compareTo(dto3));
	}

}
