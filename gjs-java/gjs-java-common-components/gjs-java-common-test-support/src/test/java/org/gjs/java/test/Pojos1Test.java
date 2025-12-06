package org.gjs.java.test;

import org.gjs.java.test.tester.samples.SampleSetterTester;
import org.gjs.java.test.types.Testers;
import org.junit.jupiter.api.Test;
import org.slf4j.Logger;
import org.slf4j.LoggerFactory;

class Pojos1Test extends AbstractPojosTest {

	private static final Logger logger = LoggerFactory.getLogger(Pojos1Test.class);

	public Pojos1Test() {
		super(true);
		addSpecialClassTesters("SampleSpecialSetterPojo", new Testers(new SampleSetterTester()));
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
		testPojoClasses();
	}
}
