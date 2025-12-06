package org.gjs.java.test;

import static org.junit.jupiter.api.Assertions.assertEquals;
import static org.junit.jupiter.api.Assertions.assertNotNull;
import static org.junit.jupiter.api.Assertions.assertTrue;
import static org.junit.jupiter.api.Assertions.fail;

import org.apache.commons.lang3.exception.ExceptionUtils;
import org.gjs.java.test.samples.pojos.SamplePojo;
import org.junit.jupiter.api.Test;

@SuppressWarnings("rawtypes")
public class AbstractDataObjectUnitTestTest extends BaseUnitTest<AbstractDataObjectUnitTest> {

	private static class DataObjectUnitTest1 extends AbstractDataObjectUnitTest<SamplePojo> {

		public boolean initialized = false;
		public boolean executed = false;

		@Override
		protected long loadTestData() throws Exception {
			logger.info("Loading data...");
			initialized = true;
			return super.getExpected().length;
		}

		public void test() {
			super.beforeAll();
			logger.info("Executing test...");
			executed = true;
			super.afterAll();
		}

	}

	private static class DataObjectUnitTest2 extends AbstractDataObjectUnitTest<SamplePojo> {

		public boolean initialized = false;
		public boolean executed = false;

		public DataObjectUnitTest2() {
			super(SamplePojo.class);
		}

		@Override
		protected long loadTestData() throws Exception {
			logger.info("Loading data...");
			initialized = true;
			return super.getExpected().length;
		}

		public void test() {
			super.beforeAll();
			logger.info("Executing test...");
			executed = true;
			super.afterAll();
		}

	}

	private static class DataObjectUnitTest3 extends AbstractDataObjectUnitTest<SamplePojo> {

		public boolean initialized = false;
		public boolean executed = false;

		public DataObjectUnitTest3() {
			super(SamplePojo.class);
			super.defineExpectedIds(Long.valueOf(10), Long.valueOf(11), Long.valueOf(12), Long.valueOf(13));
			super.defineExpectedCods("C1", "C2", "C3", "C4");
		}

		public Long getID1() {
			return ID1;
		}

		public Long getID2() {
			return ID2;
		}

		public Long getIDU1() {
			return IDU1;
		}

		public Long getIDD1() {
			return IDD1;
		}

		public String getCOD1() {
			return COD1;
		}

		public String getCOD2() {
			return COD2;
		}

		public String getCODU1() {
			return CODU1;
		}

		public String getCODD1() {
			return CODD1;
		}

		@Override
		public Long[] getImmutableIds() {
			return super.getImmutableIds();
		}

		@Override
		public String[] getImmutableCods() {
			return super.getImmutableCods();
		}

		@Override
		protected long loadTestData() throws Exception {
			logger.info("Loading data...");
			initialized = true;
			return super.getExpected().length;
		}

		public void test() {
			super.beforeAll();
			logger.info("Executing test...");
			executed = true;
			super.afterAll();
		}

	}

	private static class DataObjectUnitTest4 extends AbstractDataObjectUnitTest<SamplePojo> {

		public boolean initialized = false;
		public boolean executed = false;

		public DataObjectUnitTest4() {
			super(SamplePojo.class);
			super.defineExpectedIds(Long.valueOf(10), Long.valueOf(11), Long.valueOf(12), Long.valueOf(13),
					Long.valueOf(21), Long.valueOf(34));
			super.defineExpectedCods("C1", "C2", "C3", "C4", "C21", "C34");
		}

		@Override
		protected long loadTestData() throws Exception {
			logger.info("Loading data...");
			initialized = true;
			return super.getExpected().length;
		}

		public void test() {
			super.beforeAll();
			logger.info("Executing test...");
			executed = true;
			super.afterAll();
		}

	}

	private static class DataObjectUnitTest5 extends AbstractDataObjectUnitTest<SamplePojo> {

		public boolean initialized = false;
		public boolean executed = false;

		public DataObjectUnitTest5() {
			super(SamplePojo.class);
			super.defineExpectedMaxId(Long.valueOf(17));
		}

		@Override
		protected long loadTestData() throws Exception {
			logger.info("Loading data...");
			initialized = true;
			return super.getExpected().length;
		}

		public void test() {
			super.beforeAll();
			logger.info("Executing test...");
			executed = true;
			super.afterAll();
		}

	}

	@Test
	void testAbstractDataObjectUnitTest1() {
		try {
			final DataObjectUnitTest1 test = new DataObjectUnitTest1();
			assertNotNull(test.getClazz());
			assertEquals(SamplePojo.class, test.getClazz());
			test.test();
			assertTrue(test.initialized);
			assertTrue(test.executed);
		} catch (final Exception e) {
			logger.error(ExceptionUtils.getStackTrace(e));
			fail("Se ha producido un error");
		}
	}

	@Test
	void testAbstractDataObjectUnitTest2() {
		try {
			final DataObjectUnitTest2 test = new DataObjectUnitTest2();
			assertNotNull(test.getClazz());
			assertEquals(SamplePojo.class, test.getClazz());
			test.test();
			assertTrue(test.initialized);
			assertTrue(test.executed);
		} catch (final Exception e) {
			logger.error(ExceptionUtils.getStackTrace(e));
			fail("Se ha producido un error");
		}
	}

	@Test
	void testAbstractDataObjectUnitTest3() {
		final DataObjectUnitTest3 test = new DataObjectUnitTest3();
		assertEquals(Long.valueOf(10), test.getID1());
		assertEquals(Long.valueOf(11), test.getID2());
		assertEquals(Long.valueOf(12), test.getIDU1());
		assertEquals(Long.valueOf(13), test.getIDD1());
		assertEquals("C1", test.getCOD1());
		assertEquals("C2", test.getCOD2());
		assertEquals("C3", test.getCODU1());
		assertEquals("C4", test.getCODD1());

		assertNotNull(test.getImmutableIds());
		assertEquals(2, test.getImmutableIds().length);
		assertNotNull(test.getImmutableIds()[0]);
		assertEquals(Long.valueOf(10), test.getImmutableIds()[0]);
		assertNotNull(test.getImmutableIds()[1]);
		assertEquals(Long.valueOf(11), test.getImmutableIds()[1]);

		assertNotNull(test.getImmutableCods());
		assertEquals(2, test.getImmutableCods().length);
		assertNotNull(test.getImmutableCods()[0]);
		assertEquals("C1", test.getImmutableCods()[0]);
		assertNotNull(test.getImmutableCods()[1]);
		assertEquals("C2", test.getImmutableCods()[1]);

		assertNotNull(test.getExpected());
		assertEquals(4, test.getExpected().length);
		assertNotNull(test.getExpected()[0]);
		assertEquals(Long.valueOf(10), test.getExpected()[0]);
		assertNotNull(test.getExpected()[1]);
		assertEquals(Long.valueOf(11), test.getExpected()[1]);
		assertNotNull(test.getExpected()[2]);
		assertEquals(Long.valueOf(12), test.getExpected()[2]);
		assertNotNull(test.getExpected()[3]);
		assertEquals(Long.valueOf(13), test.getExpected()[3]);

		assertNotNull(test.getCodsExpected());
		assertEquals(4, test.getCodsExpected().length);
		assertNotNull(test.getCodsExpected()[0]);
		assertEquals("C1", test.getCodsExpected()[0]);
		assertNotNull(test.getExpected()[1]);
		assertEquals("C2", test.getCodsExpected()[1]);
		assertNotNull(test.getExpected()[2]);
		assertEquals("C3", test.getCodsExpected()[2]);
		assertNotNull(test.getExpected()[3]);
		assertEquals("C4", test.getCodsExpected()[3]);

		try {
			test.test();
			assertTrue(test.initialized);
			assertTrue(test.executed);
		} catch (final Exception e) {
			logger.error(ExceptionUtils.getStackTrace(e));
			fail("Se ha producido un error");
		}
	}

	@Test
	void testAbstractDataObjectUnitTest4() {
		final DataObjectUnitTest4 test = new DataObjectUnitTest4();
		assertNotNull(test.getExpected());
		assertEquals(6, test.getExpected().length);
		assertEquals(Long.valueOf(10), test.getExpected()[0]);
		assertEquals(Long.valueOf(11), test.getExpected()[1]);
		assertEquals(Long.valueOf(12), test.getExpected()[2]);
		assertEquals(Long.valueOf(13), test.getExpected()[3]);
		assertEquals(Long.valueOf(21), test.getExpected()[4]);
		assertEquals(Long.valueOf(34), test.getExpected()[5]);
		assertNotNull(test.getCodsExpected());
		assertEquals(6, test.getCodsExpected().length);
		assertEquals("C1", test.getCodsExpected()[0]);
		assertEquals("C2", test.getCodsExpected()[1]);
		assertEquals("C3", test.getCodsExpected()[2]);
		assertEquals("C4", test.getCodsExpected()[3]);
		assertEquals("C21", test.getCodsExpected()[4]);
		assertEquals("C34", test.getCodsExpected()[5]);

		try {
			test.test();
			assertTrue(test.initialized);
			assertTrue(test.executed);
		} catch (final Exception e) {
			logger.error(ExceptionUtils.getStackTrace(e));
			fail("Se ha producido un error");
		}
	}

	@Test
	void testAbstractDataObjectUnitTest5() {
		final DataObjectUnitTest5 test = new DataObjectUnitTest5();
		assertNotNull(test.getExpected());
		assertEquals(17, test.getExpected().length);
		for (int i = 1; i <= 17; i = i + 1) {
			assertEquals(Long.valueOf(i), test.getExpected()[i - 1]);
		}
		try {
			test.test();
			assertTrue(test.initialized);
			assertTrue(test.executed);
		} catch (final Exception e) {
			logger.error(ExceptionUtils.getStackTrace(e));
			fail("Se ha producido un error");
		}
	}

}
