package org.gjs.java.util;

import static org.junit.jupiter.api.Assertions.assertFalse;
import static org.junit.jupiter.api.Assertions.assertTrue;

import org.junit.jupiter.api.Test;

import org.gjs.java.test.BaseClassTest;
import org.gjs.java.util.ConditionUtils;

class ConditionUtilsTest extends BaseClassTest<ConditionUtils> {

    @Test
    void testAllAreTrue() {
        assertFalse(ConditionUtils.allAreTrue(false));
        assertTrue(ConditionUtils.allAreTrue(true));
        assertTrue(ConditionUtils.allAreTrue(true, true));
        assertFalse(ConditionUtils.allAreTrue(true, false));
        assertFalse(ConditionUtils.allAreTrue(false, true));
        assertFalse(ConditionUtils.allAreTrue(false, false));
    }

    @Test
    void testOneIsTrue() {
        assertFalse(ConditionUtils.oneIsTrue(false));
        assertTrue(ConditionUtils.oneIsTrue(true));
        assertTrue(ConditionUtils.oneIsTrue(true, true));
        assertTrue(ConditionUtils.oneIsTrue(true, false));
        assertTrue(ConditionUtils.oneIsTrue(false, true));
        assertFalse(ConditionUtils.oneIsTrue(false, false));
    }

}
