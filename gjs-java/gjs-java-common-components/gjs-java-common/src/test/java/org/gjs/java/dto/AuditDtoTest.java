package org.gjs.java.dto;

import static org.junit.jupiter.api.Assertions.assertEquals;
import static org.junit.jupiter.api.Assertions.assertFalse;
import static org.junit.jupiter.api.Assertions.assertNotNull;
import static org.junit.jupiter.api.Assertions.assertNull;
import static org.junit.jupiter.api.Assertions.assertTrue;

import org.gjs.java.test.BaseUnitTest;
import org.junit.jupiter.api.Test;

public class AuditDtoTest extends BaseUnitTest<AuditDto> {

	@Test
	void testAuditDto1() {
		final AuditDto auditDto = new AuditDto();
		assertNull(auditDto.getModule());
		assertNull(auditDto.getPrimitive());
		assertEquals(0, auditDto.getStartTime());
		assertEquals(0, auditDto.getEndTime());
		assertEquals(0, auditDto.getTime());
		assertFalse(auditDto.isOk());
		assertNull(auditDto.getThrowed());
		logger.info(auditDto.toString());

		auditDto.init("modulo", "metodo");
		assertNotNull(auditDto.getModule());
		assertNotNull(auditDto.getPrimitive());
		assertEquals("modulo", auditDto.getModule());
		assertEquals("metodo", auditDto.getPrimitive());
		assertTrue(auditDto.getStartTime() > 0);
		assertEquals(0, auditDto.getEndTime());
		assertFalse(auditDto.isOk());
		assertNull(auditDto.getThrowed());
		logger.info(auditDto.toString());

		try {
			Thread.sleep(1000);
		} catch (final InterruptedException e) {
		}

		auditDto.end();
		assertNotNull(auditDto.getModule());
		assertNotNull(auditDto.getPrimitive());
		assertEquals("modulo", auditDto.getModule());
		assertEquals("metodo", auditDto.getPrimitive());
		assertTrue(auditDto.getStartTime() > 0);
		assertTrue(auditDto.getEndTime() > 0);
		assertTrue(auditDto.getTime() > 0);
		assertTrue(auditDto.isOk());
		assertNull(auditDto.getThrowed());
		logger.info(auditDto.toString());
	}

	@Test
	void testAuditDto2() {
		final AuditDto auditDto = new AuditDto("modulo", "metodo");
		assertNotNull(auditDto.getModule());
		assertNotNull(auditDto.getPrimitive());
		assertEquals("modulo", auditDto.getModule());
		assertEquals("metodo", auditDto.getPrimitive());
		assertTrue(auditDto.getStartTime() > 0);
		assertEquals(0, auditDto.getEndTime());
		assertFalse(auditDto.isOk());
		assertNull(auditDto.getThrowed());
		logger.info(auditDto.toString());

		try {
			Thread.sleep(1000);
		} catch (final InterruptedException e) {
		}
		auditDto.setThrowed(new RuntimeException("Test"));
		auditDto.end();
		assertNotNull(auditDto.getModule());
		assertNotNull(auditDto.getPrimitive());
		assertEquals("modulo", auditDto.getModule());
		assertEquals("metodo", auditDto.getPrimitive());
		assertTrue(auditDto.getStartTime() > 0);
		assertTrue(auditDto.getEndTime() > 0);
		assertTrue(auditDto.getTime() > 0);
		assertFalse(auditDto.isOk());
		assertNotNull(auditDto.getThrowed());
		logger.info(auditDto.toString());
	}

}
