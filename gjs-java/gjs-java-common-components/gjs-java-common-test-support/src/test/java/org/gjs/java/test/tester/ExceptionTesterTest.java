package org.gjs.java.test.tester;

import org.gjs.java.test.AbstractTesterUnitTest;
import org.gjs.java.test.samples.pojos.SamplePojo;

public class ExceptionTesterTest extends AbstractTesterUnitTest<ExceptionTester> {

	private final String PACKAGE_TEST_OK = "org.gjs.java.test.samples.exception";
	private final String PACKAGE_TEST_KO = "org.gjs.java.test.samples.exception.error";

	@Override
	protected String getPackageToTestOk() {
		return PACKAGE_TEST_OK;
	}

	@Override
	protected String getPackageToTestKo() {
		return PACKAGE_TEST_KO;
	}

	@Override
	protected BaseTester createTester(boolean stopOnError) {
		final ExceptionTester tester = new ExceptionTester(stopOnError);
		tester.addSpecialParameter(SamplePojo.class.getCanonicalName(), new SamplePojo(1, "Test"));
		return tester;
	}

}
