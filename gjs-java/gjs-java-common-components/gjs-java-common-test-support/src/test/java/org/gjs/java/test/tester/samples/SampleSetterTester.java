package org.gjs.java.test.tester.samples;

import org.gjs.java.test.tester.DefaultSetterTester;

public class SampleSetterTester extends DefaultSetterTester {
    @Override
    protected Object expectedValue(String fieldName, Object settedValue) {

        Object expectedValue = settedValue;
        if (fieldName.equals("nombre")) {
            expectedValue = "A";
            if (settedValue != null) {
                expectedValue = (String) expectedValue + (String) settedValue;
            }
        }
        return expectedValue;
    }

}
