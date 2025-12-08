package org.gjs.java.util;

import static org.junit.jupiter.api.Assertions.assertEquals;
import static org.junit.jupiter.api.Assertions.assertNotNull;

import java.math.BigDecimal;

import org.gjs.java.test.BaseClassTest;
import org.gjs.java.test.samples.dto.SampleEntityDto;
import org.gjs.java.test.samples.type.AllPrimitivesType;
import org.junit.jupiter.api.Test;

import ch.qos.logback.classic.Level;

public class LogUtilsTest extends BaseClassTest<LogUtils> {

	@Test
	public void testFormatLog1() {
		ch.qos.logback.classic.Logger logger = (ch.qos.logback.classic.Logger) this.logger;
		String clazz = null;
		String method = null;
		String text = LogUtils.buildLogText(clazz, method);
		assertNotNull(text);
		logger.info("Log Text={}", text);
		clazz = "class";
		method = "method";
		text = LogUtils.buildLogText(clazz, method);
		assertNotNull(text);
		logger.info("Log Text={}", text);
		text = LogUtils.buildLogText(clazz, method, "prueba de log", "resultado");
		assertNotNull(text);
		logger.info("Log Text={}", text);
	}

	@Test
	public void testFormatLog2() {
		ch.qos.logback.classic.Logger logger = (ch.qos.logback.classic.Logger) this.logger;
		final String clazz = "class";
		final String method = "method";
		final String info = "prueba de log";
		final Object obj1 = new SampleEntityDto();
		final Object obj2 = BigDecimal.TEN;
		final Object obj3 = 1L;
		String text = LogUtils.buildLogText(clazz, method, info, obj1, obj2, obj3);
		assertNotNull(text);
		logger.info("Log Text={}", text);
		text = LogUtils.buildLogText(clazz, method, info, obj1);
		assertNotNull(text);
		logger.info("Log Text={}", text);
		text = LogUtils.buildLogText(clazz, method, info, obj1, obj2, obj3, new AllPrimitivesType());
		assertNotNull(text);
		logger.info("Log Text={}", text);
	}

	@Test
	public void testLog1() {
		ch.qos.logback.classic.Logger logger = (ch.qos.logback.classic.Logger) this.logger;
		String clazz = null;
		String method = null;
		LogUtils.log(logger, Level.INFO, clazz, method);
		clazz = "class";
		method = "method";
		LogUtils.log(null, Level.INFO, clazz, method);
		LogUtils.log(logger, null, clazz, method);
		LogUtils.log(logger, Level.DEBUG, clazz, method);
		LogUtils.log(logger, Level.DEBUG, clazz, method, "prueba de log", "resultado");
	}

	@Test
	public void testLog2() {
		String clazz = null;
		String method = null;
		LogUtils.log(Level.INFO, clazz, method);
		clazz = "class";
		method = "method";
		LogUtils.log(null, clazz, method);
		LogUtils.log(Level.DEBUG, clazz, method);
		LogUtils.log(Level.DEBUG, clazz, method, "prueba de log", "resultado");
	}

	@Test
	public void testLog3() {
		final String clazz = this.getClass().getCanonicalName();
		final String method = "testLog3";
		LogUtils.logTrace(clazz, method, "prueba de log", "resultado");
		LogUtils.logDebug(clazz, method, "prueba de log", "resultado");
		LogUtils.logInfo(clazz, method, "prueba de log", "resultado");
		LogUtils.logWarn(clazz, method, "prueba de log", "resultado");
		LogUtils.logError(clazz, method, "prueba de log", "resultado");
	}

	@Test
	public void testFormattedLog1() {
		ch.qos.logback.classic.Logger logger = (ch.qos.logback.classic.Logger) this.logger;
		final String clazz = "class";
		final String method = "method";
		LogUtils.logFormatted(logger, Level.DEBUG, clazz, method, null);
		LogUtils.logFormatted(logger, Level.DEBUG, clazz, method, "formateado %s");
		LogUtils.logFormatted(logger, Level.DEBUG, clazz, method, "formateado %s", "XXX");
		LogUtils.logFormatted(logger, Level.DEBUG, clazz, method, "formateado %s = %s", "XXX", "YYY");
	}

	@Test
	public void testFormattedLog2() {
		final String clazz = "class";
		final String method = "method";
		LogUtils.logFormatted(Level.DEBUG, clazz, method, "formateado %s");
		LogUtils.logFormatted(Level.DEBUG, clazz, method, "formateado %s", "XXX");
		LogUtils.logFormatted(Level.DEBUG, clazz, method, "formateado %s = %s", "XXX", "YYY");
	}

	@Test
	public void testFormattedLog3() {
		final String clazz = this.getClass().getCanonicalName();
		final String method = "testLog3";
		LogUtils.logFormattedTrace(clazz, method, "formateado %s = %s", "XXX", "YYY");
		LogUtils.logFormattedDebug(clazz, method, "formateado %s = %s", "XXX", "YYY");
		LogUtils.logFormattedInfo(clazz, method, "formateado %s = %s", "XXX", "YYY");
		LogUtils.logFormattedWarn(clazz, method, "formateado %s = %s", "XXX", "YYY");
		LogUtils.logFormattedError(clazz, method, "formateado %s = %s", "XXX", "YYY");
	}

	@Test
	public void testFormattedLog4() {
		ch.qos.logback.classic.Logger logger = (ch.qos.logback.classic.Logger) this.logger;
		final String clazz = "class";
		final String method = "method";
		final String format = "Param1=%s Param2=%s param3=%s";
		final Object obj1 = new SampleEntityDto();
		final Object obj2 = BigDecimal.TEN;
		final Object obj3 = 1L;
		logger.info("Caso 1:");
		LogUtils.logFormattedInfo(clazz, method, format, obj1, obj2, obj3);
		logger.info("Caso 2:");
		LogUtils.logFormattedInfo(clazz, method, format, obj1, obj2);
		logger.info("Caso 3:");
		LogUtils.logFormattedInfo(clazz, method, format, obj1, obj2, obj3, new AllPrimitivesType());
		logger.info("Caso 4:");
		LogUtils.logFormattedInfo(clazz, method, format, obj1);
		logger.info("Caso 5:");
		LogUtils.logFormattedInfo(clazz, method, format);
	}

	@Test
	public void testFormattedLog5() {
		ch.qos.logback.classic.Logger logger = (ch.qos.logback.classic.Logger) this.logger;
		final String clazz = "class";
		final String method = "method";
		final String format = "Param1={} Param2={} param3={}";
		final Object obj1 = new SampleEntityDto();
		final Object obj2 = BigDecimal.TEN;
		final Object obj3 = 1L;
		logger.info("Caso 1:");
		LogUtils.logFormattedInfo(clazz, method, format, obj1, obj2, obj3);
		logger.info("Caso 2:");
		LogUtils.logFormattedInfo(clazz, method, format, obj1, obj2);
		logger.info("Caso 3:");
		LogUtils.logFormattedInfo(clazz, method, format, obj1, obj2, obj3, new AllPrimitivesType());
	}

	private String sampleMethod() {
		return LogUtils.getMethodName();
	}

	@Test
	public void testGetMethodName1() {
		String name = sampleMethod();
		assertNotNull(name);
		assertEquals("sampleMethod", name);
		name = LogUtils.getMethodName();
		assertNotNull(name);
		assertEquals("testGetMethodName1", name);
	}

}
