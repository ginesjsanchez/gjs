package org.gjs.java.common.log;

import org.gjs.java.test.BaseClassTest;
import org.junit.jupiter.api.Test;

@SuppressWarnings("rawtypes")
class LoggerTest extends BaseClassTest<Logger> {

	@Test
	void testLogger1() {
		Logger logger = Logger.getLogger("org.gjs.java.common.log.test");
		logger.error(new Exception("Error test"));
		logger.error("Esto es una prueba", new Exception("Error test"));
		logger.warn(new Exception("Error test"));
		logger.warn("Esto es una prueba", new Exception("Error test"));
	}

}