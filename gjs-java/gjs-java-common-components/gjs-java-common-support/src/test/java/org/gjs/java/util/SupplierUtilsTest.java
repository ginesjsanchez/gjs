package org.gjs.java.util;

import static org.junit.jupiter.api.Assertions.assertEquals;
import static org.junit.jupiter.api.Assertions.assertNotNull;
import static org.junit.jupiter.api.Assertions.assertNull;
import static org.junit.jupiter.api.Assertions.assertTrue;

import java.util.Collection;
import java.util.Objects;

import org.gjs.java.enums.ManagedType;
import org.gjs.java.enums.PrimitiveType;
import org.gjs.java.test.BaseClassTest;
import org.junit.jupiter.api.Test;

class SupplierUtilsTest extends BaseClassTest<SupplierUtils> {

	@Test
	void testGeneratePrimitiveValue() {
		String type = null;
		Object value = SupplierUtils.generatePrimitiveValue(type);
		assertNull(value);
		type = "";
		value = SupplierUtils.generatePrimitiveValue(type);
		assertNull(value);
		type = "java.lang.Object";
		value = SupplierUtils.generatePrimitiveValue(type);
		assertNull(value);
		for (final PrimitiveType primitiveType : PrimitiveType.values()) {
			value = SupplierUtils.generatePrimitiveValue(primitiveType.getClassName());
			assertNotNull(value);
			assertEquals(primitiveType.getDefaultObject().getClass(), value.getClass());
		}
	}

	@Test
	void testGenerateEmptyPrimitiveValue() {
		String type = null;
		Object value = SupplierUtils.generateEmptyPrimitiveValue(type);
		assertNull(value);
		type = "";
		value = SupplierUtils.generateEmptyPrimitiveValue(type);
		assertNull(value);
		type = "java.lang.Object";
		value = SupplierUtils.generateEmptyPrimitiveValue(type);
		assertNull(value);
		for (final PrimitiveType primitiveType : PrimitiveType.values()) {
			value = SupplierUtils.generateEmptyPrimitiveValue(primitiveType.getClassName());
			assertNotNull(value);
			assertEquals(primitiveType.getDefaultObject().getClass(), value.getClass());
		}
	}

	@Test
	void testGenerateArrayPrimitiveValue() {
		String type = null;
		Object[] value = SupplierUtils.generateArrayPrimitiveValue(type);
		assertNull(value);
		type = "";
		value = SupplierUtils.generateArrayPrimitiveValue(type);
		assertNull(value);
		type = "java.lang.Object";
		value = SupplierUtils.generateArrayPrimitiveValue(type);
		assertNull(value);
		for (final PrimitiveType primitiveType : PrimitiveType.values()) {
			value = SupplierUtils.generateArrayPrimitiveValue(primitiveType.getClassName());
			assertNotNull(value);
			assertTrue(value.length > 0, String.format("Array de longitud 0: tipo %s", primitiveType.getClassName()));
			for (final Object obj : value) {
				assertNotNull(obj);
			}
			assertEquals(primitiveType.getDefaultObject().getClass(), value[0].getClass());
		}
	}

	@Test
	void testGenerateEmptyArrayPrimitiveValue() {
		String type = null;
		Object[] value = SupplierUtils.generateEmptyArrayPrimitiveValue(type);
		assertNull(value);
		type = "";
		value = SupplierUtils.generateEmptyArrayPrimitiveValue(type);
		assertNull(value);
		type = "java.lang.Object";
		value = SupplierUtils.generateEmptyArrayPrimitiveValue(type);
		assertNull(value);
		for (final PrimitiveType primitiveType : PrimitiveType.values()) {
			value = SupplierUtils.generateEmptyArrayPrimitiveValue(primitiveType.getClassName());
			assertNotNull(value);
			assertTrue(value.length == 0);
			assertEquals(primitiveType.getDefaultObject().getClass().getCanonicalName(),
					value.getClass().getCanonicalName().replace("[]", ""));
		}
	}

	@Test
	void testGenerateArrayPrimitiveNativeValue() {
		String type = null;
		Object value = SupplierUtils.generateArrayPrimitiveNativeValue(type);
		assertNull(value);
		type = "";
		value = SupplierUtils.generateArrayPrimitiveNativeValue(type);
		assertNull(value);
		type = "noexiste";
		value = SupplierUtils.generateArrayPrimitiveNativeValue(type);
		assertNull(value);
		for (final PrimitiveType primitiveType : PrimitiveType.values()) {
			value = SupplierUtils.generateArrayPrimitiveNativeValue(primitiveType.getName());
			assertNotNull(value);
			assertTrue(value.getClass().isArray());
			assertEquals(primitiveType.getName(), value.getClass().getCanonicalName().replace("[]", ""));
		}
	}

	@Test
	void testGenerateEmptyArrayPrimitiveNativeValue() {
		String type = null;
		Object value = SupplierUtils.generateEmptyArrayPrimitiveNativeValue(type);
		assertNull(value);
		type = "";
		value = SupplierUtils.generateEmptyArrayPrimitiveNativeValue(type);
		assertNull(value);
		type = "java.lang.Object";
		value = SupplierUtils.generateEmptyArrayPrimitiveNativeValue(type);
		assertNull(value);
		for (final PrimitiveType primitiveType : PrimitiveType.values()) {
			value = SupplierUtils.generateEmptyArrayPrimitiveNativeValue(primitiveType.getName());
			assertNotNull(value);
			assertTrue(value.getClass().isArray());
			assertEquals(primitiveType.getName(), value.getClass().getCanonicalName().replace("[]", ""));
		}
	}

	@Test
	void testGenerateListPrimitiveValue() {
		String type = null;
		Collection<?> value = SupplierUtils.generateListPrimitiveValue(type);
		assertNull(value);
		type = "";
		value = SupplierUtils.generateListPrimitiveValue(type);
		assertNull(value);
		type = "java.lang.Object";
		value = SupplierUtils.generateListPrimitiveValue(type);
		assertNull(value);
		for (final PrimitiveType primitiveType : PrimitiveType.values()) {
			value = SupplierUtils.generateListPrimitiveValue(primitiveType.getClassName());
			assertNotNull(value);
			assertTrue(value.size() > 0);
			for (final Object obj : value) {
				assertNotNull(obj);
				assertEquals(primitiveType.getDefaultObject().getClass(), obj.getClass());
			}
		}
	}

	@Test
	void testGenerateSetPrimitiveValue() {
		String type = null;
		Collection<?> value = SupplierUtils.generateSetPrimitiveValue(type);
		assertNull(value);
		type = "";
		value = SupplierUtils.generateSetPrimitiveValue(type);
		assertNull(value);
		type = "java.lang.Object";
		value = SupplierUtils.generateSetPrimitiveValue(type);
		assertNull(value);
		for (final PrimitiveType primitiveType : PrimitiveType.values()) {
			value = SupplierUtils.generateSetPrimitiveValue(primitiveType.getClassName());
			assertNotNull(value);
			assertTrue(value.size() > 0);
			for (final Object obj : value) {
				assertNotNull(obj);
				assertEquals(primitiveType.getDefaultObject().getClass(), obj.getClass());
			}
		}
	}

	@Test
	void testGenerateCollectionPrimitiveValue() {
		String type = null;
		String collectionType = null;
		Collection<?> value = SupplierUtils.generateCollectionPrimitiveValue(collectionType, type);
		assertNull(value);
		type = "";
		value = SupplierUtils.generateCollectionPrimitiveValue(collectionType, type);
		assertNull(value);
		type = "java.lang.Object";
		value = SupplierUtils.generateCollectionPrimitiveValue(collectionType, type);
		assertNull(value);
		type = "java.lang.Long";
		value = SupplierUtils.generateCollectionPrimitiveValue(collectionType, type);
		assertNull(value);
		collectionType = "";
		value = SupplierUtils.generateCollectionPrimitiveValue(collectionType, type);
		assertNull(value);
		collectionType = "java.util.Collection";
		value = SupplierUtils.generateCollectionPrimitiveValue(collectionType, type);
		assertNull(value);
		collectionType = "java.util.List";
		value = SupplierUtils.generateCollectionPrimitiveValue(collectionType, type);
		assertNotNull(value);
		collectionType = "java.util.Set";
		value = SupplierUtils.generateCollectionPrimitiveValue(collectionType, type);
		assertNotNull(value);
	}

	@Test
	void testGenerateManagedValue() {
		String type = null;
		Object value = SupplierUtils.generateManagedValue(type);
		assertNull(value);
		type = "";
		value = SupplierUtils.generateManagedValue(type);
		assertNull(value);
		type = "java.lang.Object";
		value = SupplierUtils.generateManagedValue(type);
		assertNull(value);
		for (final ManagedType managedType : ManagedType.values()) {
			logger.debug("Generando valor de tipo {}", managedType);
			value = SupplierUtils.generateManagedValue(managedType.getClassName());
			assertNotNull(value);
			assertEquals(managedType.getDefaultObject().getClass(), value.getClass());
		}
	}

	@Test
	void testGenerateEmptyManagedValue() {
		String type = null;
		Object value = SupplierUtils.generateEmptyManagedValue(type);
		assertNull(value);
		type = "";
		value = SupplierUtils.generateEmptyManagedValue(type);
		assertNull(value);
		type = "java.lang.Object";
		value = SupplierUtils.generateEmptyManagedValue(type);
		assertNull(value);
		for (final ManagedType managedType : ManagedType.values()) {
			logger.debug("Generando valor vacio de tipo {}", managedType);
			value = SupplierUtils.generateEmptyManagedValue(managedType.getClassName());
			if (Objects.nonNull(value)) {
				assertEquals(managedType.getDefaultObject().getClass(), value.getClass());
			}
		}
	}

	@Test
	void testGenerateArrayManagedValue() {
		String type = null;
		Object[] value = SupplierUtils.generateArrayManagedValue(type);
		assertNull(value);
		type = "";
		value = SupplierUtils.generateArrayManagedValue(type);
		assertNull(value);
		type = "java.lang.Object";
		value = SupplierUtils.generateArrayManagedValue(type);
		assertNull(value);
		for (final ManagedType managedType : ManagedType.values()) {
			value = SupplierUtils.generateArrayManagedValue(managedType.getClassName());
			assertNotNull(value, String.format("Type=%s", managedType.name()));
			assertTrue(value.length > 0, String.format("Type=%s", managedType.name()));
			for (final Object obj : value) {
				assertNotNull(obj, String.format("Type=%s", managedType.name()));
			}
			assertEquals(managedType.getDefaultObject().getClass(), value[0].getClass(),
					String.format("Type=%s", managedType.name()));
		}
	}

	@Test
	void testGenerateEmptyArrayManagedValue() {
		String type = null;
		Object[] value = SupplierUtils.generateEmptyArrayManagedValue(type);
		assertNull(value);
		type = "";
		value = SupplierUtils.generateEmptyArrayManagedValue(type);
		assertNull(value);
		type = "java.lang.Object";
		value = SupplierUtils.generateEmptyArrayManagedValue(type);
		assertNull(value);
		for (final ManagedType managedType : ManagedType.values()) {
			value = SupplierUtils.generateEmptyArrayManagedValue(managedType.getClassName());
			assertNotNull(value, String.format("Type=%s", managedType.name()));
			assertTrue(value.length == 0, String.format("Type=%s", managedType.name()));
			assertEquals(managedType.getDefaultObject().getClass().getCanonicalName(),
					value.getClass().getCanonicalName().replace("[]", ""),
					String.format("Type=%s", managedType.name()));
		}
	}

	@Test
	void testGenerateListManagedValue() {
		String type = null;
		Collection<?> value = SupplierUtils.generateListManagedValue(type);
		assertNull(value);
		type = "";
		value = SupplierUtils.generateListManagedValue(type);
		assertNull(value);
		type = "java.lang.Object";
		value = SupplierUtils.generateListManagedValue(type);
		assertNull(value);
		for (final ManagedType managedType : ManagedType.values()) {
			value = SupplierUtils.generateListManagedValue(managedType.getClassName());
			assertNotNull(value, String.format("Type=%s", managedType.name()));
			assertTrue(value.size() > 0, String.format("Type=%s", managedType.name()));
			for (final Object obj : value) {
				assertNotNull(obj);
				assertEquals(managedType.getDefaultObject().getClass(), obj.getClass(),
						String.format("Type=%s", managedType.name()));
			}
		}
	}

	@Test
	void testGenerateSetManagedValue() {
		String type = null;
		Collection<?> value = SupplierUtils.generateSetManagedValue(type);
		assertNull(value);
		type = "";
		value = SupplierUtils.generateSetManagedValue(type);
		assertNull(value);
		type = "java.lang.Object";
		value = SupplierUtils.generateSetManagedValue(type);
		assertNull(value);
		for (final ManagedType managedType : ManagedType.values()) {
			value = SupplierUtils.generateSetManagedValue(managedType.getClassName());
			assertNotNull(value);
			assertTrue(value.size() > 0);
			for (final Object obj : value) {
				assertNotNull(obj);
				assertEquals(managedType.getDefaultObject().getClass(), obj.getClass());
			}
		}
	}

	@Test
	void testGenerateCollectionManagedValue() {
		String type = null;
		String collectionType = null;
		Collection<?> value = SupplierUtils.generateCollectionManagedValue(collectionType, type);
		assertNull(value);
		type = "";
		value = SupplierUtils.generateCollectionManagedValue(collectionType, type);
		assertNull(value);
		type = "java.lang.Object";
		value = SupplierUtils.generateCollectionManagedValue(collectionType, type);
		assertNull(value);
		type = "java.math.BigDecimal";
		value = SupplierUtils.generateCollectionManagedValue(collectionType, type);
		assertNull(value);
		collectionType = "";
		value = SupplierUtils.generateCollectionManagedValue(collectionType, type);
		assertNull(value);
		collectionType = "java.util.Collection";
		value = SupplierUtils.generateCollectionManagedValue(collectionType, type);
		assertNull(value);
		collectionType = "java.util.List";
		value = SupplierUtils.generateCollectionManagedValue(collectionType, type);
		assertNotNull(value);
		collectionType = "java.util.Set";
		value = SupplierUtils.generateCollectionManagedValue(collectionType, type);
		assertNotNull(value);
	}

}
