package org.gjs.java.common.log;

import static org.junit.jupiter.api.Assertions.assertEquals;
import static org.junit.jupiter.api.Assertions.assertNotNull;

import java.math.BigDecimal;

import org.gjs.java.test.BaseClassTest;
import org.gjs.java.test.samples.dto.SampleEntityDto;
import org.junit.jupiter.api.Test;
import org.slf4j.Logger;

public class BaseLoggerTest extends BaseClassTest<BaseLogger> {

	private static class TestLogger extends BaseLogger {

	}

	@Test
	public void testGetLogger1() {
		final TestLogger test = new TestLogger();
		Logger logger = test.getLogger();
		assertNotNull(logger);
		assertEquals(TestLogger.class.getCanonicalName(), logger.getName());
	}

	@Test
	public void testFormatLog1() {
		final TestLogger test = new TestLogger();
		test.logTrace("metodo", "test0");
		test.logDebug("metodo", "test1");
		test.logInfo("metodo", "test2");
		test.logWarn("metodo", "test3");
		test.logError("metodo", "test4");
		test.logError("metodo", new RuntimeException("Error test"));
		test.logControlledError("metodo", new RuntimeException("Error test"));

		test.logFormattedTrace("metodo", "Valor=%s", "test0");
		test.logFormattedDebug("metodo", "Valor=%s", "test1");
		test.logFormattedInfo("metodo", "Valor=%s", "test2");
		test.logFormattedWarn("metodo", "Valor=%s", "test3");
		test.logFormattedError("metodo", "Valor=%s", "test4");

	}

	@Test
	public void testFormatLog2() {
		final TestLogger test = new TestLogger();
		SampleEntityDto dto = new SampleEntityDto();
		final Object obj1 = dto;
		final Object obj2 = BigDecimal.TEN;
		final Object obj3 = 1L;
		final String format = "Param1=%s Param2=%s param3=%s";
		logger.info("Caso 1:");
		test.logFormattedInfo("metodo", format, obj1, obj2, obj3);
		logger.info("Caso 2:");
		test.logFormattedInfo("metodo", format, obj1);
		logger.info("Caso 3:");
		test.logFormattedInfo("metodo", format, obj1, obj2, obj3, dto);
		logger.info("Caso 4:");
		test.logFormattedInfo("metodo", format);
	}

	@Test
	public void testFormatLog3() {
		final TestLogger test = new TestLogger();
		SampleEntityDto dto = new SampleEntityDto();
		final Object obj1 = dto;
		final Object obj2 = BigDecimal.TEN;
		final Object obj3 = 1L;
		final String format = "Param1={} Param2={} param3={}";
		logger.info("Caso 1:");
		test.logFormattedInfo("metodo", format, obj1, obj2, obj3);
		logger.info("Caso 2:");
		test.logFormattedInfo("metodo", format, obj1);
		logger.info("Caso 3:");
		test.logFormattedInfo("metodo", format, obj1, obj2, obj3, dto);
		logger.info("Caso 4:");
		test.logFormattedInfo("metodo", format);
	}

}
