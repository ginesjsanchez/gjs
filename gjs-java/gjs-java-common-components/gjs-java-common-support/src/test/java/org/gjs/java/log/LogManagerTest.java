package org.gjs.java.log;

import static org.junit.jupiter.api.Assertions.assertEquals;
import static org.junit.jupiter.api.Assertions.assertNotNull;
import static org.junit.jupiter.api.Assertions.assertNull;
import static org.junit.jupiter.api.Assertions.fail;

import org.apache.commons.lang3.exception.ExceptionUtils;
import org.gjs.java.test.BaseClassTest;
import org.junit.jupiter.api.Test;

class LogManagerTest extends BaseClassTest<LogManager> {

	@Test
	void testContructor1() {
		try {
			final LogManager logManager = new LogManager();
			assertNull(logManager.getLogger());
			logManager.trace(null);
			logManager.debug(null);
			logManager.info(null);
			logManager.warn(null);
			logManager.error(null);
			logManager.setLogger(logger);
			assertNotNull(logManager.getLogger());
			assertEquals(logger, logManager.getLogger());
			logManager.trace(null);
			logManager.debug(null);
			logManager.info(null);
			logManager.warn(null);
			logManager.error(null);

		} catch (final Exception e) {
			logger.error(ExceptionUtils.getStackTrace(e));
			fail("Excepcion inesperada");
		}
	}

	@Test
	void testContructor2() {
		try {
			final LogManager logManager = new LogManager(logger);
			assertNotNull(logManager.getLogger());
			assertEquals(logger, logManager.getLogger());
			logManager.trace("Trace");
			logManager.debug("Debug");
			logManager.info("Info");
			logManager.warn("Warn");
			logManager.error("Error");
			logManager.error("Error", new RuntimeException("Test"));

			final String value = "Value";
			logManager.trace("Trace [{}]", value);
			logManager.debug("Debug [{}]", value);
			logManager.info("Info  [{}]", value);
			logManager.warn("Warn  [{}]", value);
			logManager.error("Error [{}]", value);

		} catch (final Exception e) {
			logger.error(ExceptionUtils.getStackTrace(e));
			fail("Excepcion inesperada");
		}
	}

}
