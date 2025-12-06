package org.gjs.java.test;

import static org.junit.jupiter.api.Assertions.assertEquals;
import static org.junit.jupiter.api.Assertions.assertNotNull;
import static org.junit.jupiter.api.Assertions.assertTrue;
import static org.junit.jupiter.api.Assertions.fail;

import java.util.ArrayList;
import java.util.List;
import java.util.function.Function;

import org.apache.commons.lang3.exception.ExceptionUtils;
import org.gjs.java.common.ConditionUtils;
import org.gjs.java.test.mock.MockRepository;
import org.gjs.java.test.mock.MockSpecification;
import org.gjs.java.test.sample.model.SampleEntity;
import org.gjs.java.test.sample.model.filter.SampleEntityFilter;
import org.junit.jupiter.api.Test;
import org.springframework.data.jpa.domain.Specification;
import org.springframework.data.jpa.repository.JpaRepository;

@SuppressWarnings("rawtypes")
public class BaseSpecificationUnitTestTest extends BaseUnitTest<BaseSpecificationUnitTest> {

    private static class MockSampleEntityRepository extends MockRepository<SampleEntity, Long> {
    }

    private static class SampleEntitySpecification extends MockSpecification<SampleEntity, SampleEntityFilter> {

        /**
         *
         */
        private static final long serialVersionUID = 1L;

        public SampleEntitySpecification(SampleEntityFilter filter) {
            super(filter);
        }
    }

    // private static SampleEntitySpecification specification;

    private static Specification<SampleEntity> newInstance(SampleEntityFilter filter) {
        return new SampleEntitySpecification(filter);
    }

    private static class SpecificationUnitTest
            extends BaseSpecificationUnitTest<SampleEntitySpecification, SampleEntityFilter, SampleEntity, Long> {

        public SpecificationUnitTest() {
            super(SampleEntitySpecification.class, SampleEntityFilter.class, SampleEntity.class, Long.class);
        }

        private static final String RESOURCE_DATA_PATH = "data/sampleEntity.csv";

        public boolean prepared = false;
        public boolean initialized = false;
        public boolean executed = false;

        MockSampleEntityRepository mockRepository;

        private List<SampleEntityFilter> testFilters;
        private List<Long> testExpectedResults;

        @Override
        protected Class<?> getClazz() {
            return SampleEntitySpecification.class;
        }

        @Override
        protected JpaRepository<SampleEntity, Long> getRepository() {
            return mockRepository;
        }

        @Override
        protected String getResourcePath() {
            return RESOURCE_DATA_PATH;
        }

        @Override
        protected Function<SampleEntityFilter, Specification<SampleEntity>> getNewInstanceFunction() {
            return BaseSpecificationUnitTestTest::newInstance;
        }

        @Override
        protected Long getImmutableId(int index) {
            Long res = null;
            final Long[] immutableIds = getImmutableIds();
            if (ConditionUtils.allAreTrue((index >= 0), (index < immutableIds.length))) {
                res = immutableIds[index];
            }
            return res;
        }

        @Override
        protected Long getNonExistentId() {
            return IDNE;
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
        protected boolean validatorsTestResult(int testCase, SampleEntity element) {
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
            mockRepository = new MockSampleEntityRepository();

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
    void testBaseSpecificationUnitTest1() {
        try {
            final SpecificationUnitTest test = new SpecificationUnitTest();
            assertNotNull(test.getClazz());
            assertNotNull(test.getEntityClazz());
            assertNotNull(test.getPKClazz());
            assertEquals(SampleEntitySpecification.class, test.getClazz());
            assertEquals(SampleEntity.class, test.getEntityClazz());
            assertEquals(Long.class, test.getPKClazz());
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
