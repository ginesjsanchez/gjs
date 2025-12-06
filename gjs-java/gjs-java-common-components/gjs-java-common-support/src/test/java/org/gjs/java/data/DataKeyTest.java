package org.gjs.java.data;

import static org.junit.jupiter.api.Assertions.assertEquals;
import static org.junit.jupiter.api.Assertions.assertFalse;
import static org.junit.jupiter.api.Assertions.assertNotNull;
import static org.junit.jupiter.api.Assertions.assertNull;
import static org.junit.jupiter.api.Assertions.assertTrue;

import org.gjs.java.test.BaseClassTest;
import org.junit.jupiter.api.Test;

class DataKeyTest extends BaseClassTest<DataKey> {

	@Test
	void testDataKey1() {
		final DataKey key = new DataKey();
		assertEquals(0, key.countFields());
		assertNotNull(key.getFields());
		assertEquals(0, key.getFields().size());
		assertNull(key.getField(0));
		assertEquals("Key=[]", key.toString());
		key.addField("field1");
		assertEquals(1, key.countFields());
		assertNotNull(key.getFields());
		assertEquals(1, key.getFields().size());
		assertTrue(key.existsField("field1"));
		assertFalse(key.existsField("fieldX"));
		assertFalse(key.existsField(null));
		assertNotNull(key.getField(0));
		assertEquals("field1", key.getField(0));
		assertEquals("Key=[field1]", key.toString());
		key.addField(null);
		assertEquals(1, key.countFields());
		key.addField("field1");
		assertEquals(1, key.countFields());
		key.addField("field2");
		assertEquals(2, key.countFields());
		assertNotNull(key.getField(0));
		assertEquals("field1", key.getField(0));
		assertNotNull(key.getField(1));
		assertEquals("field2", key.getField(1));
		assertEquals("Key=[field1, field2]", key.toString());

		key.clear();
		assertEquals(0, key.countFields());
		assertNotNull(key.getFields());
		assertEquals(0, key.getFields().size());
	}

	@Test
	void testDataKey2() {
		final DataKey key = new DataKey("field1", "field2");
		assertEquals(2, key.countFields());
		assertNotNull(key.getField(0));
		assertEquals("field1", key.getField(0));
		assertNotNull(key.getField(1));
		assertEquals("field2", key.getField(1));
		assertEquals("Key=[field1, field2]", key.toString());
	}

	@SuppressWarnings("unlikely-arg-type")
	@Test
	void testDataKey3() {
		final DataKey key0 = null;
		final DataKey key1 = new DataKey("field1", "field2");
		final DataKey key2 = new DataKey("field1");
		final DataKey key3 = new DataKey("field2", "field1");
		final String key4 = "aye";
		assertTrue(key1.equals(key1));
		assertFalse(key1.equals(key0));
		assertTrue(key1.equals(key3));
		assertFalse(key1.equals(key4));
		assertFalse(key2.equals(key1));

		assertTrue(key1.hashCode() != 0);
	}

}
