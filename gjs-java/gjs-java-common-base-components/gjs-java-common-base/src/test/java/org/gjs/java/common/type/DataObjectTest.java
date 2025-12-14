package org.gjs.java.common.type;

import static org.junit.jupiter.api.Assertions.assertEquals;
import static org.junit.jupiter.api.Assertions.assertFalse;
import static org.junit.jupiter.api.Assertions.assertNotEquals;
import static org.junit.jupiter.api.Assertions.assertNotNull;
import static org.junit.jupiter.api.Assertions.assertNull;
import static org.junit.jupiter.api.Assertions.assertTrue;

import java.math.BigDecimal;
import java.util.HashMap;
import java.util.Map;

import org.gjs.java.common.type.DataObject;
import org.gjs.java.test.BaseClassTest;
import org.gjs.java.test.samples.pojos.SampleBoolean;
import org.gjs.java.test.samples.pojos.SamplePojo;
import org.junit.jupiter.api.Test;

class DataObjectTest extends BaseClassTest<DataObject> {

	@Test
	void testDataObject1() {
		final DataObject dataObject = new DataObject();
		logger.info("Object={}", dataObject.toString());
		assertEquals(0, dataObject.numFields());
		assertNotNull(dataObject.getFields());
		assertEquals(0, dataObject.getFields().size());
		assertNull(dataObject.getValue("field1"));
		assertFalse(dataObject.hasField("field1"));
		assertEquals("DataObject []", dataObject.toString());

		dataObject.setValue("field1", null);
		logger.info("Object={}", dataObject.toString());
		assertEquals(1, dataObject.numFields());
		assertNotNull(dataObject.getFields());
		assertEquals(1, dataObject.getFields().size());
		assertNull(dataObject.getValue("field1"));
		assertEquals("DataObject [field1=null]", dataObject.toString());

		dataObject.setValue("field1", "value1");
		logger.info("Object={}", dataObject.toString());
		assertEquals(1, dataObject.numFields());
		assertNotNull(dataObject.getFields());
		assertEquals(1, dataObject.getFields().size());
		assertNotNull(dataObject.getValue("field1"));
		assertNull(dataObject.getValue("field2"));
		assertTrue(dataObject.hasField("field1"));
		assertFalse(dataObject.hasField("field2"));
		assertEquals("value1", dataObject.getValue("field1"));
		assertEquals("DataObject [field1=value1]", dataObject.toString());

		dataObject.setValue("field2", BigDecimal.ZERO);
		logger.info("Object={}", dataObject.toString());
		assertEquals(2, dataObject.numFields());
		assertNotNull(dataObject.getFields());
		assertEquals(2, dataObject.getFields().size());
		assertNotNull(dataObject.getValue("field1"));
		assertEquals("value1", dataObject.getValue("field1"));
		assertNotNull(dataObject.getValue("field2"));
		assertTrue(dataObject.hasField("field1"));
		assertTrue(dataObject.hasField("field2"));
		assertEquals(BigDecimal.ZERO, dataObject.getValue("field2"));
		assertEquals("DataObject [field1=value1, field2=0]", dataObject.toString());

		dataObject.nullify();
		logger.info("Object={}", dataObject.toString());
		assertEquals(2, dataObject.numFields());
		assertNotNull(dataObject.getFields());
		assertEquals(2, dataObject.getFields().size());
		assertNull(dataObject.getValue("field1"));
		assertNull(dataObject.getValue("field2"));
		assertTrue(dataObject.hasField("field1"));
		assertTrue(dataObject.hasField("field2"));
		assertEquals("DataObject [field1=null, field2=null]", dataObject.toString());

		dataObject.clear();
		logger.info("Object={}", dataObject.toString());
		assertEquals(0, dataObject.numFields());
		assertNotNull(dataObject.getFields());
		assertEquals(0, dataObject.getFields().size());
		assertNull(dataObject.getValue("field1"));
		assertFalse(dataObject.hasField("field1"));
		assertFalse(dataObject.hasField("field2"));
		assertEquals("DataObject []", dataObject.toString());
	}

	@Test
	void testDataObject2() {
		final SamplePojo sample = new SamplePojo();
		sample.setId(1);
		sample.setNombre("Nombre");
		final DataObject dataObject = new DataObject(sample);
		logger.info("Object={}", dataObject.toString());
		assertEquals(2, dataObject.numFields());
		assertTrue(dataObject.hasField("id"));
		assertTrue(dataObject.hasField("nombre"));
		assertNotNull(dataObject.getValue("id"));
		assertNotNull(dataObject.getValue("nombre"));
		assertEquals(Long.valueOf(1), dataObject.getValue("id"));
		assertEquals("Nombre", dataObject.getValue("nombre"));
		assertEquals("DataObject [id=1, nombre=Nombre]", dataObject.toString());

		final SamplePojo restored = (SamplePojo) dataObject.toObject(SamplePojo.class.getCanonicalName());
		assertNotNull(restored);
		assertEquals(sample.getId(), restored.getId());
		assertEquals(sample.getNombre(), restored.getNombre());
	}

	@Test
	void testDataObject3() {
		final DataObject dataObject1 = new DataObject();
		dataObject1.setValue("field1", null);
		dataObject1.setValue("field2", "AYE");
		dataObject1.setValue("field3", BigDecimal.ONE);
		final DataObject dataObject2 = null;
		final DataObject dataObject3 = new DataObject();
		final DataObject dataObject4 = new DataObject();
		dataObject4.setValue("field1", null);
		dataObject4.setValue("field2", "AYE");
		final DataObject dataObject5 = new DataObject();
		dataObject5.setValue("fieldX", null);
		dataObject5.setValue("fieldY", "AYE");
		dataObject5.setValue("fieldZ", BigDecimal.ONE);
		final DataObject dataObject6 = new DataObject();
		dataObject6.setValue("field1", Long.valueOf(1));
		dataObject6.setValue("field2", "AYE");
		dataObject6.setValue("field3", BigDecimal.ONE);
		final DataObject dataObject7 = new DataObject();
		dataObject7.setValue("field1", null);
		dataObject7.setValue("field2", "AYE");
		dataObject7.setValue("field3", BigDecimal.ONE);

		assertNotNull(dataObject1.hashCode());
		assertNotNull(dataObject3.hashCode());
		assertNotNull(dataObject4.hashCode());
		assertNotNull(dataObject5.hashCode());
		assertNotNull(dataObject6.hashCode());
		assertNotNull(dataObject7.hashCode());
		assertNotEquals(dataObject1, "CADENA");
		assertNotEquals(dataObject1, dataObject2);
		assertNotEquals(dataObject1, dataObject3);
		assertNotEquals(dataObject1, dataObject4);
		assertNotEquals(dataObject1, dataObject5);
		assertNotEquals(dataObject1, dataObject6);
		assertEquals(dataObject1, dataObject7);
		assertNotEquals(dataObject1.hashCode(), dataObject3.hashCode());
		assertNotEquals(dataObject1.hashCode(), dataObject4.hashCode());
		assertNotEquals(dataObject1.hashCode(), dataObject5.hashCode());
		assertNotEquals(dataObject1.hashCode(), dataObject6.hashCode());
		assertEquals(dataObject1.hashCode(), dataObject7.hashCode());
	}

	@Test
	void testDataObject4() {
		final DataObject dataObject = new DataObject();
		SamplePojo sample = (SamplePojo) dataObject.toObject(SamplePojo.class.getCanonicalName());
		assertNotNull(sample);
		assertEquals(0, sample.getId());
		assertNull(sample.getNombre());

		dataObject.setValue("id", 1);
		dataObject.setValue("nombre", "Test");
		sample = (SamplePojo) dataObject.toObject(SamplePojo.class.getCanonicalName());
		assertNotNull(sample);
		assertEquals(1, sample.getId());
		assertNotNull(sample.getNombre());
		assertEquals("Test", sample.getNombre());
	}

	@Test
	void testDataObject5() {
		final DataObject dataObject = new DataObject();
		SampleBoolean sample = (SampleBoolean) dataObject.toObject(SampleBoolean.class.getCanonicalName());
		assertNotNull(sample);
		assertFalse(sample.isBool1());
		assertNull(sample.getBool2());

		dataObject.setValue("bool1", true);
		dataObject.setValue("bool2", Boolean.TRUE);
		logger.info("Object={}", sample);
		sample = (SampleBoolean) dataObject.toObject(SampleBoolean.class.getCanonicalName());
		assertNotNull(sample);
		assertTrue(sample.isBool1());
		assertNotNull(sample.getBool2());
		assertTrue(sample.getBool2());

		dataObject.setValue("bool1", false);
		dataObject.setValue("bool2", Boolean.FALSE);
		logger.info("Object={}", sample);
		sample = (SampleBoolean) dataObject.toObject(SampleBoolean.class.getCanonicalName());
		assertNotNull(sample);
		assertFalse(sample.isBool1());
		assertNotNull(sample.getBool2());
		assertFalse(sample.getBool2());

		dataObject.setValue("bool1", "true");
		dataObject.setValue("bool2", "true");
		logger.info("Object={}", sample);
		sample = (SampleBoolean) dataObject.toObject(SampleBoolean.class.getCanonicalName());
		assertNotNull(sample);
		assertTrue(sample.isBool1());
		assertNotNull(sample.getBool2());
		assertTrue(sample.getBool2());

		dataObject.setValue("bool1", "false");
		dataObject.setValue("bool2", "false");
		logger.info("Object={}", sample);
		sample = (SampleBoolean) dataObject.toObject(SampleBoolean.class.getCanonicalName());
		assertNotNull(sample);
		assertFalse(sample.isBool1());
		assertNotNull(sample.getBool2());
		assertFalse(sample.getBool2());

		dataObject.setValue("bool1", "1");
		dataObject.setValue("bool2", "1");
		logger.info("Object={}", sample);
		sample = (SampleBoolean) dataObject.toObject(SampleBoolean.class.getCanonicalName());
		assertNotNull(sample);
		assertTrue(sample.isBool1());
		assertNotNull(sample.getBool2());
		assertTrue(sample.getBool2());

		dataObject.setValue("bool1", "0");
		dataObject.setValue("bool2", "0");
		logger.info("Object={}", sample);
		sample = (SampleBoolean) dataObject.toObject(SampleBoolean.class.getCanonicalName());
		assertNotNull(sample);
		assertFalse(sample.isBool1());
		assertNotNull(sample.getBool2());
		assertFalse(sample.getBool2());
	}

	@Test
	void testDataObject6() {
		final DataObject dataObject = new DataObject();
		Long value = (Long) dataObject.toObject(Long.class.getCanonicalName());
		assertNull(value);

		dataObject.setValue("id", Long.valueOf(4));
		value = (Long) dataObject.toObject(Long.class.getCanonicalName());
		assertNotNull(value);
		assertEquals(Long.valueOf(4), value);

		dataObject.setValue("name", "Nombre");
		value = (Long) dataObject.toObject(Long.class.getCanonicalName());
	}

	@Test
	void testDataObject7() {
		Map<String, Object> values = null;
		DataObject dataObject = new DataObject(values);
		assertNotNull(dataObject.getFields());
		assertNotNull(dataObject.getValues());
		assertEquals(0, dataObject.getFields().size());
		assertEquals(dataObject.getFields().size(), dataObject.getValues().size());
		values = new HashMap<>();
		dataObject = new DataObject(values);
		assertNotNull(dataObject.getFields());
		assertNotNull(dataObject.getValues());
		assertEquals(0, dataObject.getFields().size());
		assertEquals(dataObject.getFields().size(), dataObject.getValues().size());
		values.put("field1", null);
		values.put("field2", "AYE");
		values.put("field3", BigDecimal.ONE);
		dataObject = new DataObject(values);
		assertNotNull(dataObject.getFields());
		assertNotNull(dataObject.getValues());
		assertEquals(values.size(), dataObject.getFields().size());
		assertEquals(dataObject.getFields().size(), dataObject.getValues().size());
		for (final String value : values.keySet()) {
			assertEquals(values.get(value), dataObject.getValue(value));
		}
	}

}
