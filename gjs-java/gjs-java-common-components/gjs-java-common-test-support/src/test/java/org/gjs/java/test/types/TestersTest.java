package org.gjs.java.test.types;

import static org.junit.jupiter.api.Assertions.assertNotNull;
import static org.junit.jupiter.api.Assertions.fail;

import org.apache.commons.lang3.exception.ExceptionUtils;
import org.gjs.java.test.BaseUnitTest;
import org.junit.jupiter.api.Test;

public class TestersTest extends BaseUnitTest<Testers> {

	@Test
	void testTesters1() {
		try {
			final Testers testers = new Testers();
			assertNotNull(testers.getSetterTester());
		} catch (final Exception e) {
			logger.error(ExceptionUtils.getStackTrace(e));
			fail("Se ha producido un error");
		}
	}

}
