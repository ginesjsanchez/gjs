package org.gjs.java.common.task;

import static org.junit.jupiter.api.Assertions.assertEquals;
import static org.junit.jupiter.api.Assertions.assertNotNull;
import static org.junit.jupiter.api.Assertions.assertNull;
import static org.junit.jupiter.api.Assertions.assertTrue;
import static org.junit.jupiter.api.Assertions.fail;

import java.io.IOException;

import org.apache.commons.lang3.exception.ExceptionUtils;
import org.gjs.java.common.task.MultiTaskResult;
import org.gjs.java.common.task.TaskResult;
import org.gjs.java.test.BaseUnitTest;
import org.junit.jupiter.api.Test;

class MultiTaskResultTest extends BaseUnitTest<MultiTaskResult> {

	@Test
	void testMultiTaskResult1() {
		try {
			final MultiTaskResult value = new MultiTaskResult();
			logger.info("Object={}", value.toString());
			assertNotNull(value.getName());
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
			assertNotNull(value.toString());

			final String report = value.toReport();
			assertNotNull(report);
			logger.info(report);

		} catch (final IOException e) {
			logger.error(ExceptionUtils.getStackTrace(e));
			fail("Ha saltado excepcion");
		}
	}

	@Test
	void testMultiTaskResult2() {
		try {
			final MultiTaskResult value = new MultiTaskResult();

			final TaskResult value1 = new TaskResult("Tarea 1", "Tarea de test 1");
			value1.incrementOk();
			value1.incrementKo();

			final TaskResult value2 = new TaskResult("Tarea 2", "Tarea de test 2");
			value2.incrementOk();
			value2.incrementOk();
			value2.incrementOk();
			value2.incrementOk();
			value2.incrementKo();

			value.addTask(value1);
			value.addTask(value2);

			final String report = value.toReport();
			assertNotNull(report);
			logger.info(report);
		} catch (final IOException e) {
			logger.error(ExceptionUtils.getStackTrace(e));
			fail("Ha saltado excepcion");
		}
	}
}
