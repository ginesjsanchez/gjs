package org.gjs.java.test;

import static org.junit.jupiter.api.Assertions.assertEquals;
import static org.junit.jupiter.api.Assertions.assertNotNull;
import static org.junit.jupiter.api.Assertions.assertTrue;
import static org.junit.jupiter.api.Assertions.fail;

import java.util.Objects;

import org.apache.commons.lang3.ArrayUtils;
import org.apache.commons.lang3.exception.ExceptionUtils;
import org.gjs.java.common.util.ConditionUtils;
import org.gjs.java.test.mock.MockRepository;
import org.gjs.java.test.sample.dao.SampleEntityRepository;
import org.gjs.java.test.sample.model.SampleEntity;
import org.junit.jupiter.api.Test;
import org.springframework.data.jpa.repository.JpaRepository;

@SuppressWarnings("rawtypes")
public class BaseRepositoryUnitTestTest extends BaseUnitTest<BaseRepositoryUnitTest> {

	private static class MockSampleEntityRepository extends MockRepository<SampleEntity, Long> {
	}

	private static class SampleEntityRepositoryUnitTest
			extends BaseRepositoryUnitTest<SampleEntity, Long, SampleEntityRepository> {

		public SampleEntityRepositoryUnitTest() {
			super(SampleEntityRepository.class, SampleEntity.class, Long.class);
		}

		private static final String RESOURCE_DATA_PATH = "data/sampleEntity.csv";

		public boolean prepared = false;
		public boolean initialized = false;
		public boolean executed = false;

		MockSampleEntityRepository mockRepository;

		@Override
		protected JpaRepository<SampleEntity, Long> getRepository() {
			return mockRepository;
		}

		@Override
		protected String getResourcePath() {
			return RESOURCE_DATA_PATH;
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
		protected boolean isExpected(Long id) {
			boolean res = false;
			if (Objects.nonNull(id)) {
				res = ArrayUtils.contains(getExpected(), id);
			}
			return res;
		}

		@Override
		protected void prepareTestData() throws Exception {
			logger.info("Preparing data...");
			mockRepository = new MockSampleEntityRepository();
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
			super.testFindAll();
			super.testFindById();
			executed = true;
			super.afterAll();
		}

	}

	@Test
	void testBaseRepositoryUnitTest() {
		try {
			final SampleEntityRepositoryUnitTest test = new SampleEntityRepositoryUnitTest();
			assertNotNull(test.getClazz());
			assertNotNull(test.getEntityClazz());
			assertNotNull(test.getPKClazz());
			assertEquals(SampleEntityRepository.class, test.getClazz());
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
