package org.gjs.java.test.tester;

import org.gjs.java.test.AbstractTesterUnitTest;

public class EqualsTesterTest extends AbstractTesterUnitTest<EqualsTester> {

    private final String PACKAGE_TEST_OK = "org.gjs.java.test.samples.pojos";
    private final String PACKAGE_TEST_KO = "org.gjs.java.test.samples.pojos.error";

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
        return new EqualsTester(stopOnError);
    }

}
