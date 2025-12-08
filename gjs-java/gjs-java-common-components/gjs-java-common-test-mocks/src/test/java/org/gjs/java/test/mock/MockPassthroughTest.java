package org.gjs.java.test.mock;

import static org.junit.jupiter.api.Assertions.assertFalse;
import static org.junit.jupiter.api.Assertions.assertTrue;

import org.gjs.java.test.BaseUnitTest;
import org.junit.jupiter.api.Test;

class MockPassthroughTest extends BaseUnitTest<MockPassthrough> {

    static class MockSamplePassthrough extends MockPassthrough {

        public void execute() {
            super.check();
        }
    }

    @Test
    void testMockPassthrough1() {
        final MockSamplePassthrough mockSamplePassthrough = new MockSamplePassthrough();
        mockSamplePassthrough.init();
        assertFalse(mockSamplePassthrough.isChecked());
        mockSamplePassthrough.execute();
        assertTrue(mockSamplePassthrough.isChecked());
    }
}
