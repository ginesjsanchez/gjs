package org.gjs.java.common.supplier.random;

import static org.junit.jupiter.api.Assertions.assertEquals;
import static org.junit.jupiter.api.Assertions.assertNotNull;
import static org.junit.jupiter.api.Assertions.assertTrue;

import org.checkerframework.checker.nullness.qual.Nullable;
import org.gjs.java.common.supplier.random.AbstractRandomSupplier;
import org.gjs.java.test.AbstractClassTest;
import org.junit.jupiter.api.Test;
import org.slf4j.LoggerFactory;

class AbstractRandomSupplierTest extends AbstractClassTest {

	@Override
	protected Class<?> getClazz() {
		return AbstractRandomSupplier.class;
	}

	private static class ExampleRandomSupplier extends AbstractRandomSupplier<Object> {

		public ExampleRandomSupplier() {
			super.setLogger(LoggerFactory.getLogger(AbstractRandomSupplierTest.class));
		}

		@Override
		public @Nullable Object get() {
			return new Object();
		}

		@Override
		public @Nullable Object getEmpty() {
			return new Object();
		}

		@Override
		protected Object[] createArray(int size) {
			return new Object[size];
		}

	}

	@Test
	void testAbstractRandomSupplier1() {
		final ExampleRandomSupplier supplier = new ExampleRandomSupplier();
		assertEquals(1, supplier.getMinSizeArrays());
		assertEquals(5, supplier.getMaxSizeArrays());
		assertNotNull(supplier.getLogger());

		supplier.setMinSizeArrays(-1);
		assertEquals(1, supplier.getMinSizeArrays());
		supplier.setMinSizeArrays(0);
		assertEquals(0, supplier.getMinSizeArrays());
		supplier.setMinSizeArrays(1);
		assertEquals(1, supplier.getMinSizeArrays());
		supplier.setMinSizeArrays(6);
		assertEquals(1, supplier.getMinSizeArrays());
		supplier.setMinSizeArrays(5);
		assertEquals(5, supplier.getMinSizeArrays());
		supplier.setMaxSizeArrays(0);
		assertEquals(5, supplier.getMaxSizeArrays());
		supplier.setMaxSizeArrays(10);
		assertEquals(10, supplier.getMaxSizeArrays());
		supplier.setMinSizeArrays(1);
		assertEquals(1, supplier.getMinSizeArrays());

		assertNotNull(supplier.get());
		assertNotNull(supplier.getEmpty());
		assertNotNull(supplier.getNullius());
		Object[] array = supplier.getArray();
		assertNotNull(array);
		assertTrue(array.length >= supplier.getMinSizeArrays());
		assertTrue(array.length <= supplier.getMaxSizeArrays());
		array = supplier.getEmptyArray();
		assertNotNull(array);
		assertEquals(0, array.length);
	}

	@Test
	void testAbstractRandomSupplier2() {
		final ExampleRandomSupplier supplier = new ExampleRandomSupplier();
		assertEquals(1, supplier.getMinSizeArrays());
		assertEquals(5, supplier.getMaxSizeArrays());
		for (int i = 0; i < 1000; i = i + 1) {
			final Object[] array = supplier.getArray();
			assertNotNull(array);
			assertTrue(array.length >= supplier.getMinSizeArrays());
			assertTrue(array.length <= supplier.getMaxSizeArrays());
		}
	}

}
