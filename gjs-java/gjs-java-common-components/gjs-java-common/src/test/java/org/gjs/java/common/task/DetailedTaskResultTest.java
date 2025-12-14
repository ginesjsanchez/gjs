package org.gjs.java.common.task;

import static org.junit.jupiter.api.Assertions.assertEquals;
import static org.junit.jupiter.api.Assertions.assertFalse;
import static org.junit.jupiter.api.Assertions.assertNotNull;
import static org.junit.jupiter.api.Assertions.assertNull;
import static org.junit.jupiter.api.Assertions.assertTrue;
import static org.junit.jupiter.api.Assertions.fail;

import java.io.IOException;

import org.apache.commons.lang3.exception.ExceptionUtils;
import org.gjs.java.common.task.DetailedTaskResult;
import org.gjs.java.test.BaseUnitTest;
import org.gjs.java.test.samples.dto.SampleEntityDto;
import org.gjs.java.test.samples.testinggame.DtoTestingGame;
import org.gjs.java.test.supplier.testinggame.TestingGamesSingleton;
import org.junit.jupiter.api.Test;

class DetailedTaskResultTest extends BaseUnitTest<DetailedTaskResult> {

	@Test
	void testDetailedTaskResult1() {
		final DetailedTaskResult value = new DetailedTaskResult();
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

		SampleEntityDto dto = ((DtoTestingGame) TestingGamesSingleton.getInstance().getTestingGame("dtos"))
				.getSampleEntityDto();
		value.incrementOk(dto);
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

		dto = ((DtoTestingGame) TestingGamesSingleton.getInstance().getTestingGame("dtos")).getSampleEntityDto();
		value.incrementKo(dto);
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
	void testDetailedTaskResult2() {
		try {
			final DetailedTaskResult value = new DetailedTaskResult("Test", "Tarea de test");
			assertNotNull(value.getName());
			assertEquals("Test", value.getName());
			assertNotNull(value.getDescription());
			assertEquals("Tarea de test", value.getDescription());
			assertNotNull(value.toString());
			logger.info(value.toString());
			String report = value.toReport();
			assertNotNull(report);
			logger.info(report);

			SampleEntityDto dto = ((DtoTestingGame) TestingGamesSingleton.getInstance().getTestingGame("dtos"))
					.getSampleEntityDto();
			value.incrementOk(dto);
			dto = ((DtoTestingGame) TestingGamesSingleton.getInstance().getTestingGame("dtos")).getSampleEntityDto();
			value.incrementOk(dto);
			dto = ((DtoTestingGame) TestingGamesSingleton.getInstance().getTestingGame("dtos")).getSampleEntityDto();
			value.incrementOk(dto);
			dto = ((DtoTestingGame) TestingGamesSingleton.getInstance().getTestingGame("dtos")).getSampleEntityDto();
			value.incrementOk(dto);
			dto = ((DtoTestingGame) TestingGamesSingleton.getInstance().getTestingGame("dtos")).getSampleEntityDto();
			value.incrementKo(dto);
			dto = ((DtoTestingGame) TestingGamesSingleton.getInstance().getTestingGame("dtos")).getSampleEntityDto();
			report = value.toReport();
			assertNotNull(report);
			logger.info(report);

		} catch (final IOException e) {
			logger.error(ExceptionUtils.getStackTrace(e));
			fail("Ha saltado excepcion");
		}
	}

	@Test
	void testDetailedTaskResult3() {
		try {
			final DetailedTaskResult value = new DetailedTaskResult("Test", "Tarea de test");
			assertNotNull(value.getName());
			assertEquals("Test", value.getName());
			assertNotNull(value.getDescription());
			assertEquals("Tarea de test", value.getDescription());
			assertNotNull(value.toString());
			logger.info(value.toString());
			String report = value.toReport();
			assertNotNull(report);
			logger.info(report);

			SampleEntityDto dto = ((DtoTestingGame) TestingGamesSingleton.getInstance().getTestingGame("dtos"))
					.getSampleEntityDto();
			String text = String.format("Registro %s", dto.getNombre());
			value.incrementOk(text);
			dto = ((DtoTestingGame) TestingGamesSingleton.getInstance().getTestingGame("dtos")).getSampleEntityDto();
			text = String.format("Registro %s", dto.getNombre());
			value.incrementOk(text);
			dto = ((DtoTestingGame) TestingGamesSingleton.getInstance().getTestingGame("dtos")).getSampleEntityDto();
			text = String.format("Registro %s", dto.getNombre());
			value.incrementOk(text);
			dto = ((DtoTestingGame) TestingGamesSingleton.getInstance().getTestingGame("dtos")).getSampleEntityDto();
			text = String.format("Registro %s", dto.getNombre());
			value.incrementOk(text);
			dto = ((DtoTestingGame) TestingGamesSingleton.getInstance().getTestingGame("dtos")).getSampleEntityDto();
			text = String.format("Registro %s", dto.getNombre());
			value.incrementKo(text);

			value.addDetailNewLine();
			value.addDetail("Informacion Adicional");
			report = value.toReport();
			assertNotNull(report);
			logger.info(report);

		} catch (final IOException e) {
			logger.error(ExceptionUtils.getStackTrace(e));
			fail("Ha saltado excepcion");
		}
	}
}
