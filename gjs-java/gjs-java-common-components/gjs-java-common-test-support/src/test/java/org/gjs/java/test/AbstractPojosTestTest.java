package org.gjs.java.test;

import static org.junit.jupiter.api.Assertions.fail;

import org.apache.commons.lang3.exception.ExceptionUtils;
import org.junit.jupiter.api.Test;
import org.slf4j.Logger;
import org.slf4j.LoggerFactory;

public class AbstractPojosTestTest extends BaseUnitTest<AbstractPojosTest> {

	private class PojosTest extends AbstractPojosTest {

		private final Logger logger = LoggerFactory.getLogger(PojosTest.class);

		@Override
		protected Logger getLogger() {
			return logger;
		}

		@Override
		protected String getPojoPackage() {
			return "es.mir.semill.util.test.pojos";
		}

		public void test() {
			super.testPojoClasses();
		}
	}

	@Test
	void testAbstractPojosTest() {
		try {
			final PojosTest pojosTests = new PojosTest();
			pojosTests.test();
		} catch (final Exception e) {
			logger.error(ExceptionUtils.getStackTrace(e));
			fail("Se ha producido un error");
		}
	}

}
