package org.gjs.java.test.mock;

import static org.junit.jupiter.api.Assertions.assertEquals;
import static org.junit.jupiter.api.Assertions.assertNotNull;
import static org.junit.jupiter.api.Assertions.assertNull;

import org.gjs.java.test.BaseUnitTest;
import org.gjs.java.test.samples.pojos.SamplePojo;
import org.gjs.java.test.samples.pojos.SamplePojoFilter;
import org.junit.jupiter.api.Test;

@SuppressWarnings("rawtypes")
class MockSpecificationTest extends BaseUnitTest<MockSpecification> {

	static class MockSampleSpecification extends MockSpecification<SamplePojo, SamplePojoFilter> {

		/**
		 *
		 */
		private static final long serialVersionUID = 1L;

		public MockSampleSpecification() {
		}

		public MockSampleSpecification(SamplePojoFilter filter) {
			super(filter);
		}
	}

	@Test
	void testMockSpecification1() {
		final MockSampleSpecification mockSampleSpecification = new MockSampleSpecification();
		assertNull(mockSampleSpecification.getFilter());
		assertNull(mockSampleSpecification.toPredicate(null, null, null));

		final SamplePojoFilter sample = new SamplePojoFilter();
		sample.setNombre("Sample1");
		mockSampleSpecification.setFilter(sample);
		assertNotNull(mockSampleSpecification.getFilter());
		assertEquals(sample, mockSampleSpecification.getFilter());

	}

	@Test
	void testMockSpecification2() {
		final SamplePojoFilter sample = new SamplePojoFilter();
		sample.setNombre("Sample1");
		final MockSampleSpecification mockSampleSpecification = new MockSampleSpecification(sample);
		assertNull(mockSampleSpecification.toPredicate(null, null, null));
		assertNotNull(mockSampleSpecification.getFilter());
		assertEquals(sample, mockSampleSpecification.getFilter());

	}

}
