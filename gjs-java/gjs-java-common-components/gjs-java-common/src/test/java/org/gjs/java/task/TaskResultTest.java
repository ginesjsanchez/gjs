package org.gjs.java.task;

import static org.junit.jupiter.api.Assertions.assertEquals;
import static org.junit.jupiter.api.Assertions.assertFalse;
import static org.junit.jupiter.api.Assertions.assertNotNull;
import static org.junit.jupiter.api.Assertions.assertNull;
import static org.junit.jupiter.api.Assertions.assertTrue;
import static org.junit.jupiter.api.Assertions.fail;

import java.io.IOException;

import org.apache.commons.lang3.exception.ExceptionUtils;
import org.gjs.java.test.BaseUnitTest;
import org.junit.jupiter.api.Test;

class TaskResultTest extends BaseUnitTest<TaskResult> {

	@Test
	void testTaskResult1() {
		final TaskResult value = new TaskResult();
		logger.info("Object={}", value.toString());
		assertEquals(0, value.getProcessed());
		assertEquals(0, value.getCompleted());
		assertEquals(0, value.getErrors());
		assertFalse(value.isExecuted());
		assertTrue(value.isOk());
		assertFalse(value.hasErrors());
		assertNotNull(value.getName());
		assertNotNull(value.getDescription());
		assertNotNull(value.getBegin());
		assertNull(value.getEnd());
		assertEquals(0, value.getDuration());
		assertNotNull(value.toString());

		value.incrementOk();
		logger.info("Object={}", value.toString());
		assertEquals(1, value.getProcessed());
		assertEquals(1, value.getCompleted());
		assertEquals(0, value.getErrors());
		assertTrue(value.isExecuted());
		assertTrue(value.isOk());
		assertFalse(value.hasErrors());
		assertNotNull(value.getBegin());
		assertNull(value.getEnd());
		assertEquals(0, value.getDuration());
		assertNotNull(value.toString());

		value.incrementKo();
		logger.info("Object={}", value.toString());
		assertEquals(2, value.getProcessed());
		assertEquals(1, value.getCompleted());
		assertEquals(1, value.getErrors());
		assertTrue(value.isExecuted());
		assertFalse(value.isOk());
		assertTrue(value.hasErrors());
		assertNotNull(value.getBegin());
		assertNull(value.getEnd());
		assertEquals(0, value.getDuration());
		assertNotNull(value.toString());

		try {
			Thread.sleep(100);
		} catch (final InterruptedException e) {
		}
		value.endTask();
		assertNotNull(value.getBegin());
		assertNotNull(value.getEnd());
		assertTrue(value.getDuration() > 0);
	}

	@Test
	void testTaskResult2() {
		try {
			final TaskResult value = new TaskResult("Test", "Tarea de test");
			assertNotNull(value.getName());
			assertEquals("Test", value.getName());
			assertNotNull(value.getDescription());
			assertEquals("Tarea de test", value.getDescription());
			assertNotNull(value.toString());
			logger.info(value.toString());
			String report = value.toReport();
			assertNotNull(report);
			logger.info(report);

			value.incrementOk();
			value.incrementOk();
			value.incrementOk();
			value.incrementOk();
			value.incrementKo();
			report = value.toReport();
			assertNotNull(report);
			logger.info(report);

		} catch (final IOException e) {
			logger.error(ExceptionUtils.getStackTrace(e));
			fail("Ha saltado excepcion");
		}
	}
}
