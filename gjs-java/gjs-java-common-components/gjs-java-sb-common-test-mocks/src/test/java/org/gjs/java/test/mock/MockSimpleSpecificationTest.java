package org.gjs.java.test.mock;

import static org.junit.jupiter.api.Assertions.assertEquals;
import static org.junit.jupiter.api.Assertions.assertNotNull;
import static org.junit.jupiter.api.Assertions.assertNull;

import org.gjs.java.test.BaseUnitTest;
import org.gjs.java.test.samples.pojos.SamplePojo;
import org.junit.jupiter.api.Test;

@SuppressWarnings("rawtypes")
class MockSimpleSpecificationTest extends BaseUnitTest<MockSpecification> {

    static class MockSampleSpecification extends MockSimpleSpecification<SamplePojo> {

        /**
         *
         */
        private static final long serialVersionUID = 1L;

        public MockSampleSpecification() {
        }

        public MockSampleSpecification(SamplePojo filter) {
            super(filter);
        }
    }

    @Test
    void testMockSimpleSpecification1() {
        final MockSampleSpecification mockSampleSpecification = new MockSampleSpecification();
        assertNull(mockSampleSpecification.getFilter());
        assertNull(mockSampleSpecification.toPredicate(null, null, null));

        final SamplePojo sample = new SamplePojo(1, "Sample1");
        mockSampleSpecification.setFilter(sample);
        assertNotNull(mockSampleSpecification.getFilter());
        assertEquals(sample, mockSampleSpecification.getFilter());

    }

    @Test
    void testMockSimpleSpecification2() {
        final SamplePojo sample = new SamplePojo(1, "Sample1");
        final MockSampleSpecification mockSampleSpecification = new MockSampleSpecification(sample);
        assertNull(mockSampleSpecification.toPredicate(null, null, null));
        assertNotNull(mockSampleSpecification.getFilter());
        assertEquals(sample, mockSampleSpecification.getFilter());

    }

}
