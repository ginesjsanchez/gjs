package org.gjs.java.test;

import org.junit.jupiter.api.Test;
import org.slf4j.Logger;
import org.slf4j.LoggerFactory;

class Pojos2Test extends AbstractPojosTest {

	private static final Logger logger = LoggerFactory.getLogger(Pojos2Test.class);

	public Pojos2Test() {
	}

	/**
	 * @return logger
	 */
	@Override
	protected Logger getLogger() {
		return logger;
	}

	/**
	 * @return package to test
	 */
	@Override
	protected String getPojoPackage() {
		return "org.gjs.java.test.samples.pojos";
	}

	/**
	 *
	 */
	@Test
	void testPojos() {
		testPojoClasses("SampleSpecialSetterPojo");
	}
}
