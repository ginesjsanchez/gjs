package org.gjs.java.types;

import static org.junit.jupiter.api.Assertions.assertEquals;
import static org.junit.jupiter.api.Assertions.assertFalse;
import static org.junit.jupiter.api.Assertions.assertNotNull;
import static org.junit.jupiter.api.Assertions.assertNull;
import static org.junit.jupiter.api.Assertions.assertTrue;

import org.junit.jupiter.api.Test;

import org.gjs.java.test.BaseClassTest;

class WrappedObjectTest extends BaseClassTest<WrappedObject> {

    @Test
    void testWrappedObjectEmpty() {
        final WrappedObject wrapped = WrappedObject.empty();
        assertNotNull(wrapped);
        assertNull(wrapped.get());
        assertTrue(wrapped.isEmpty());
        assertFalse(wrapped.isPresent());
        assertNotNull(wrapped.toString());
        assertEquals(0, wrapped.hashCode());
        assertTrue(wrapped.equals(wrapped));
        assertTrue(wrapped.equals(WrappedObject.empty()));
        assertTrue(wrapped.equals(null));
        assertFalse(wrapped.equals(new Object()));
        assertFalse(wrapped.isCompatible(null));
        assertFalse(wrapped.isCompatible(new Object()));
    }

    @SuppressWarnings("unlikely-arg-type")
    @Test
    void testWrappedObject1() {
        final String value = "Value";
        final String valueComp1 = "Value";
        final String valueComp2 = "ValueX";
        final WrappedObject wrapped = WrappedObject.of(value);
        assertNotNull(wrapped);
        assertNotNull(wrapped.get());
        assertFalse(wrapped.isEmpty());
        assertTrue(wrapped.isPresent());
        assertNotNull(wrapped.toString());
        assertTrue(wrapped.hashCode() > 0);
        assertTrue(wrapped.equals(wrapped));
        assertFalse(wrapped.equals(null));
        assertFalse(wrapped.equals(new Object()));
        assertFalse(wrapped.equals(new String()));
        assertTrue(wrapped.equals(valueComp1));
        assertFalse(wrapped.equals(valueComp2));
        assertTrue(wrapped.equals(WrappedObject.of(valueComp1)));
        assertFalse(wrapped.equals(WrappedObject.of(valueComp2)));
        assertFalse(wrapped.equals(WrappedObject.of(new Object())));
        assertFalse(wrapped.isCompatible(null));
        assertFalse(wrapped.isCompatible(new Object()));
        assertTrue(wrapped.isCompatible(new String()));
        assertTrue(wrapped.isCompatible(valueComp2));
        assertTrue(wrapped.isCompatible(WrappedObject.of(valueComp2)));
        assertFalse(wrapped.isCompatible(WrappedObject.of(new Object())));
    }

    @Test
    void testWrappedObject3() {
        final String value1 = "Value1";
        final String value2 = "Value2";
        final WrappedObject wrapped = WrappedObject.of(value1);
        assertNotNull(wrapped);
        assertNotNull(wrapped.get());
        assertEquals(value1, wrapped.get());
        wrapped.set(value2);
        assertNotNull(wrapped);
        assertNotNull(wrapped.get());
        assertEquals(value2, wrapped.get());
    }

}
