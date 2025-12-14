package org.gjs.java.test;

import static org.junit.jupiter.api.Assertions.assertEquals;
import static org.junit.jupiter.api.Assertions.assertNotNull;
import static org.junit.jupiter.api.Assertions.assertTrue;
import static org.junit.jupiter.api.Assertions.fail;

import java.util.ArrayList;
import java.util.List;
import java.util.function.Function;

import org.apache.commons.lang3.exception.ExceptionUtils;
import org.gjs.java.common.util.ConditionUtils;
import org.gjs.java.test.mock.MockRepository;
import org.gjs.java.test.mock.MockSpecification;
import org.gjs.java.test.sample.model.SampleStringEntity;
import org.gjs.java.test.sample.model.filter.SampleEntityFilter;
import org.junit.jupiter.api.Test;
import org.springframework.data.jpa.domain.Specification;
import org.springframework.data.jpa.repository.JpaRepository;

@SuppressWarnings("rawtypes")
public class StringPKSpecificationUnitTestTest extends BaseUnitTest<StringPKSpecificationUnitTest> {

	private static class MockSampleStringEntityRepository extends MockRepository<SampleStringEntity, String> {
	}

	private static class SampleStringEntitySpecification
			extends MockSpecification<SampleStringEntity, SampleEntityFilter> {

		public SampleStringEntitySpecification(SampleEntityFilter filter) {
			super(filter);
		}
	}

	// private static SampleStringEntitySpecification specification;

	private static Specification<SampleStringEntity> newInstance(SampleEntityFilter filter) {
		return new SampleStringEntitySpecification(filter);
	}

	private static class SpecificationUnitTest extends
			StringPKSpecificationUnitTest<SampleStringEntitySpecification, SampleEntityFilter, SampleStringEntity> {

		public SpecificationUnitTest() {
			super(SampleStringEntitySpecification.class, SampleEntityFilter.class, SampleStringEntity.class);
		}

		private static final String RESOURCE_DATA_PATH = "data/sampleStringEntity.csv";

		public boolean prepared = false;
		public boolean initialized = false;
		public boolean executed = false;

		MockSampleStringEntityRepository mockRepository;

		private List<SampleEntityFilter> testFilters;
		private List<Long> testExpectedResults;

		@Override
		protected JpaRepository<SampleStringEntity, String> getRepository() {
			return mockRepository;
		}

		@Override
		protected String getResourcePath() {
			return RESOURCE_DATA_PATH;
		}

		@Override
		protected Function<SampleEntityFilter, Specification<SampleStringEntity>> getNewInstanceFunction() {
			return StringPKSpecificationUnitTestTest::newInstance;
		}

		@Override
		protected String getImmutableId(int index) {
			String res = null;
			final String[] immutableCods = getImmutableCods();
			if (ConditionUtils.allAreTrue((index >= 0), (index < immutableCods.length))) {
				res = immutableCods[index];
			}
			return res;
		}

		@Override
		protected String getNonExistentId() {
			return CODNE;
		}

		@Override
		protected List<SampleEntityFilter> getTestFilters() {
			return testFilters;
		}

		@Override
		protected List<Long> getTestExpectedResults() {
			return testExpectedResults;
		}

		@Override
		protected boolean validatorsTestResult(int testCase, SampleStringEntity element) {
			boolean res = false;
			switch (testCase) {
			case 0:
				res = element.getId().equals(getImmutableId(1));
				break;
			default:
				break;
			}
			return res;
		}

		@Override
		protected void prepareTestData() throws Exception {
			logger.info("Preparing data...");
			mockRepository = new MockSampleStringEntityRepository();

			testFilters = new ArrayList<>();
			testExpectedResults = new ArrayList<>();

			SampleEntityFilter filter = new SampleEntityFilter();
			filter.setNombre("xx");
			testFilters.add(filter);
			testExpectedResults.add(Long.valueOf(1));

			filter = new SampleEntityFilter();
			filter.setNombre("noexiste");
			testFilters.add(filter);
			testExpectedResults.add(Long.valueOf(0));
			prepared = true;
		}

		@Override
		protected void prepareAditionalTestData() throws Exception {
			logger.info("Loading additional data...");
			initialized = true;
		}

		public void test() {
			super.beforeAll();
			logger.info("Executing test...");
			super.testNewInstanceEmpty();
			super.testNewInstanceNull();
			super.testNewInstanceGeneral();
			executed = true;
			super.afterAll();
		}

	}

	@Test
	void testStringPKSpecificationUnitTest1() {
		try {
			final SpecificationUnitTest test = new SpecificationUnitTest();
			assertNotNull(test.getClazz());
			assertNotNull(test.getEntityClazz());
			assertNotNull(test.getPKClazz());
			assertEquals(SampleStringEntitySpecification.class, test.getClazz());
			assertEquals(SampleStringEntity.class, test.getEntityClazz());
			assertEquals(String.class, test.getPKClazz());
			assertTrue(test.isValid());
			test.test();
			assertTrue(test.prepared);
			assertTrue(test.initialized);
			assertTrue(test.executed);
		} catch (final Exception e) {
			logger.error(ExceptionUtils.getStackTrace(e));
			fail("Se ha producido un error");
		}
	}

}
