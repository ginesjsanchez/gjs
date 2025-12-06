package org.gjs.java.common;

import static org.junit.jupiter.api.Assertions.assertFalse;
import static org.junit.jupiter.api.Assertions.assertTrue;

import java.util.ArrayList;
import java.util.Collection;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.Set;
import java.util.TreeSet;

import org.junit.jupiter.api.Test;

import org.gjs.java.test.BaseClassTest;

class CollectionUtilsTest extends BaseClassTest<CollectionUtils> {

    @Test
    void testGetIsCollection() {
        assertTrue(CollectionUtils.isCollection(Collection.class));
        assertTrue(CollectionUtils.isCollection(List.class));
        assertTrue(CollectionUtils.isCollection(Set.class));
        assertTrue(CollectionUtils.isCollection(Map.class));
        assertTrue(CollectionUtils.isCollection(ArrayList.class));
        assertTrue(CollectionUtils.isCollection(TreeSet.class));
        assertTrue(CollectionUtils.isCollection(HashMap.class));
        assertFalse(CollectionUtils.isCollection(Object.class));
    }

    @Test
    void testGetIsList() {
        assertFalse(CollectionUtils.isList(Collection.class));
        assertTrue(CollectionUtils.isList(List.class));
        assertFalse(CollectionUtils.isList(Set.class));
        assertFalse(CollectionUtils.isList(Map.class));
        assertTrue(CollectionUtils.isList(ArrayList.class));
        assertFalse(CollectionUtils.isList(TreeSet.class));
        assertFalse(CollectionUtils.isList(HashMap.class));
        assertFalse(CollectionUtils.isList(Object.class));
    }

    @Test
    void testGetIsSet() {
        assertFalse(CollectionUtils.isSet(Collection.class));
        assertFalse(CollectionUtils.isSet(List.class));
        assertTrue(CollectionUtils.isSet(Set.class));
        assertFalse(CollectionUtils.isSet(Map.class));
        assertFalse(CollectionUtils.isSet(ArrayList.class));
        assertTrue(CollectionUtils.isSet(TreeSet.class));
        assertFalse(CollectionUtils.isSet(HashMap.class));
        assertFalse(CollectionUtils.isSet(Object.class));
    }

    @Test
    void testGetIsMap() {
        assertFalse(CollectionUtils.isMap(Collection.class));
        assertFalse(CollectionUtils.isMap(List.class));
        assertFalse(CollectionUtils.isMap(Set.class));
        assertTrue(CollectionUtils.isMap(Map.class));
        assertFalse(CollectionUtils.isMap(ArrayList.class));
        assertFalse(CollectionUtils.isMap(TreeSet.class));
        assertTrue(CollectionUtils.isMap(HashMap.class));
        assertFalse(CollectionUtils.isMap(Object.class));
    }

}
