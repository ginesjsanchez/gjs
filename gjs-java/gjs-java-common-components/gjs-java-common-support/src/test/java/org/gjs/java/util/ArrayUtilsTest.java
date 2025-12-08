package org.gjs.java.util;

import static org.junit.jupiter.api.Assertions.assertEquals;
import static org.junit.jupiter.api.Assertions.assertFalse;
import static org.junit.jupiter.api.Assertions.assertNotNull;
import static org.junit.jupiter.api.Assertions.assertNull;
import static org.junit.jupiter.api.Assertions.assertTrue;

import java.util.Objects;

import org.gjs.java.test.BaseClassTest;
import org.junit.jupiter.api.Test;

class ArrayUtilsTest extends BaseClassTest<ArrayUtils> {

    @Test
    void testResize1() {
        Long[] array = null;
        Long[] newArray = ArrayUtils.resize(array, 1);
        assertNull(newArray);

        array = new Long[0];
        newArray = ArrayUtils.resize(array, 1);
        assertNotNull(newArray);
        assertEquals(1, newArray.length);
        assertNull(newArray[0]);

        array = new Long[1];
        newArray = ArrayUtils.resize(array, 1);
        assertNotNull(newArray);
        assertEquals(1, newArray.length);
        assertNull(newArray[0]);

        array = new Long[1];
        array[0] = Long.valueOf(0);
        newArray = ArrayUtils.resize(array, 1);
        assertNotNull(newArray);
        assertEquals(1, newArray.length);
        for (int i = 0; i < Integer.min(array.length, newArray.length); i = i + 1) {
            assertNotNull(newArray[i]);
            assertEquals(array[i], newArray[i]);
        }
        for (int i = array.length; i < newArray.length; i = i + 1) {
            assertNull(newArray[i]);
        }

        array = new Long[4];
        array[0] = Long.valueOf(0);
        array[1] = Long.valueOf(1);
        array[2] = null;
        array[3] = Long.valueOf(3);
        newArray = ArrayUtils.resize(array, 5);
        assertNotNull(newArray);
        assertEquals(5, newArray.length);
        for (int i = 0; i < Integer.min(array.length, newArray.length); i = i + 1) {
            if (Objects.isNull(array[i])) {
                assertNull(newArray[i]);
            } else {
                assertNotNull(newArray[i]);
                assertEquals(array[i], newArray[i]);
            }
        }
        for (int i = array.length; i < newArray.length; i = i + 1) {
            assertNull(newArray[i]);
        }

        newArray = ArrayUtils.resize(array, 3);
        assertNotNull(newArray);
        assertEquals(3, newArray.length);
        for (int i = 0; i < Integer.min(array.length, newArray.length); i = i + 1) {
            if (Objects.isNull(array[i])) {
                assertNull(newArray[i]);
            } else {
                assertNotNull(newArray[i]);
                assertEquals(array[i], newArray[i]);
            }
        }
        for (int i = array.length; i < newArray.length; i = i + 1) {
            assertNull(newArray[i]);
        }
    }

    @Test
    void testResize2() {
        Object objArray = Long.valueOf(1);
        Long[] newArray = ArrayUtils.resize(objArray, 1);
        assertNull(newArray);

        final Long[] array = new Long[1];
        array[0] = Long.valueOf(0);
        objArray = array;
        newArray = ArrayUtils.resize(objArray, 1);
        assertNotNull(newArray);
        assertEquals(1, newArray.length);
        for (int i = 0; i < Integer.min(array.length, newArray.length); i = i + 1) {
            assertNotNull(newArray[i]);
            assertEquals(array[i], newArray[i]);
        }
        for (int i = array.length; i < newArray.length; i = i + 1) {
            assertNull(newArray[i]);
        }
    }

    @Test
    void testResize3() {
        short[] array = null;
        short[] newArray = ArrayUtils.resize(array, 1);
        assertNull(newArray);

        array = new short[1];
        array[0] = 0;
        newArray = ArrayUtils.resize(array, 2);
        assertNotNull(newArray);
        assertEquals(2, newArray.length);
        for (int i = 0; i < Integer.min(array.length, newArray.length); i = i + 1) {
            assertEquals(array[i], newArray[i]);
        }
        for (int i = array.length; i < newArray.length; i = i + 1) {
            assertEquals(0, newArray[i]);
        }
    }

    @Test
    void testResize4() {
        int[] array = null;
        int[] newArray = ArrayUtils.resize(array, 1);
        assertNull(newArray);

        array = new int[1];
        array[0] = 0;
        newArray = ArrayUtils.resize(array, 2);
        assertNotNull(newArray);
        assertEquals(2, newArray.length);
        for (int i = 0; i < Integer.min(array.length, newArray.length); i = i + 1) {
            assertEquals(array[i], newArray[i]);
        }
        for (int i = array.length; i < newArray.length; i = i + 1) {
            assertEquals(0, newArray[i]);
        }
    }

    @Test
    void testResize5() {
        long[] array = null;
        long[] newArray = ArrayUtils.resize(array, 1);
        assertNull(newArray);

        array = new long[1];
        array[0] = 0;
        newArray = ArrayUtils.resize(array, 2);
        assertNotNull(newArray);
        assertEquals(2, newArray.length);
        for (int i = 0; i < Integer.min(array.length, newArray.length); i = i + 1) {
            assertEquals(array[i], newArray[i]);
        }
        for (int i = array.length; i < newArray.length; i = i + 1) {
            assertEquals(0, newArray[i]);
        }
    }

    @Test
    void testResize6() {
        float[] array = null;
        float[] newArray = ArrayUtils.resize(array, 1);
        assertNull(newArray);

        array = new float[1];
        array[0] = 0;
        newArray = ArrayUtils.resize(array, 2);
        assertNotNull(newArray);
        assertEquals(2, newArray.length);
        for (int i = 0; i < Integer.min(array.length, newArray.length); i = i + 1) {
            assertEquals(array[i], newArray[i]);
        }
        for (int i = array.length; i < newArray.length; i = i + 1) {
            assertEquals(0, newArray[i]);
        }
    }

    @Test
    void testResize7() {
        double[] array = null;
        double[] newArray = ArrayUtils.resize(array, 1);
        assertNull(newArray);

        array = new double[1];
        array[0] = 0;
        newArray = ArrayUtils.resize(array, 2);
        assertNotNull(newArray);
        assertEquals(2, newArray.length);
        for (int i = 0; i < Integer.min(array.length, newArray.length); i = i + 1) {
            assertEquals(array[i], newArray[i]);
        }
        for (int i = array.length; i < newArray.length; i = i + 1) {
            assertEquals(0, newArray[i]);
        }
    }

    @Test
    void testResize8() {
        boolean[] array = null;
        boolean[] newArray = ArrayUtils.resize(array, 1);
        assertNull(newArray);

        array = new boolean[1];
        array[0] = true;
        newArray = ArrayUtils.resize(array, 2);
        assertNotNull(newArray);
        assertEquals(2, newArray.length);
        for (int i = 0; i < Integer.min(array.length, newArray.length); i = i + 1) {
            assertEquals(array[i], newArray[i]);
        }
        for (int i = array.length; i < newArray.length; i = i + 1) {
            assertEquals(false, newArray[i]);
        }
    }

    @Test
    void testResize9() {
        byte[] array = null;
        byte[] newArray = ArrayUtils.resize(array, 1);
        assertNull(newArray);

        array = new byte[1];
        array[0] = 0;
        newArray = ArrayUtils.resize(array, 2);
        assertNotNull(newArray);
        assertEquals(2, newArray.length);
        for (int i = 0; i < Integer.min(array.length, newArray.length); i = i + 1) {
            assertEquals(array[i], newArray[i]);
        }
        for (int i = array.length; i < newArray.length; i = i + 1) {
            assertEquals(0, newArray[i]);
        }
    }

    @Test
    void testResize10() {
        char[] array = null;
        char[] newArray = ArrayUtils.resize(array, 1);
        assertNull(newArray);

        array = new char[1];
        array[0] = '0';
        newArray = ArrayUtils.resize(array, 2);
        assertNotNull(newArray);
        assertEquals(2, newArray.length);
        for (int i = 0; i < Integer.min(array.length, newArray.length); i = i + 1) {
            assertEquals(array[i], newArray[i]);
        }
        for (int i = array.length; i < newArray.length; i = i + 1) {
            assertEquals(0, newArray[i]);
        }
    }

    @Test
    void testContains1() {
        Long[] array = null;
        Long value = null;
        assertFalse(ArrayUtils.contains(array, value));
        array = new Long[] {};
        value = Long.valueOf(2);
        assertFalse(ArrayUtils.contains(array, value));
        array = new Long[] { Long.valueOf(1) };
        assertFalse(ArrayUtils.contains(array, value));
        array = new Long[] { Long.valueOf(1), Long.valueOf(2), Long.valueOf(3) };
        assertTrue(ArrayUtils.contains(array, value));
        value = null;
        assertFalse(ArrayUtils.contains(array, value));
    }

    @Test
    void testContains2() {
        short[] array = null;
        final short value = (short) 2;
        assertFalse(ArrayUtils.contains(array, value));
        array = new short[] {};
        assertFalse(ArrayUtils.contains(array, value));
        array = new short[] { (short) 1 };
        assertFalse(ArrayUtils.contains(array, value));
        array = new short[] { (short) 1, (short) 2, (short) 3 };
        assertTrue(ArrayUtils.contains(array, value));
    }

    @Test
    void testContains3() {
        int[] array = null;
        final int value = 2;
        assertFalse(ArrayUtils.contains(array, value));
        array = new int[] {};
        assertFalse(ArrayUtils.contains(array, value));
        array = new int[] { 1 };
        assertFalse(ArrayUtils.contains(array, value));
        array = new int[] { 1, 2, 3 };
        assertTrue(ArrayUtils.contains(array, value));
    }

    @Test
    void testContains4() {
        long[] array = null;
        final long value = 2;
        assertFalse(ArrayUtils.contains(array, value));
        array = new long[] {};
        assertFalse(ArrayUtils.contains(array, value));
        array = new long[] { 1 };
        assertFalse(ArrayUtils.contains(array, value));
        array = new long[] { 1, 2, 3 };
        assertTrue(ArrayUtils.contains(array, value));
    }

    @Test
    void testContains5() {
        float[] array = null;
        final float value = 2;
        assertFalse(ArrayUtils.contains(array, value));
        array = new float[] {};
        assertFalse(ArrayUtils.contains(array, value));
        array = new float[] { 1 };
        assertFalse(ArrayUtils.contains(array, value));
        array = new float[] { 1, 2, 3 };
        assertTrue(ArrayUtils.contains(array, value));
    }

    @Test
    void testContains6() {
        double[] array = null;
        final double value = 2;
        assertFalse(ArrayUtils.contains(array, value));
        array = new double[] {};
        assertFalse(ArrayUtils.contains(array, value));
        array = new double[] { 1 };
        assertFalse(ArrayUtils.contains(array, value));
        array = new double[] { 1, 2, 3 };
        assertTrue(ArrayUtils.contains(array, value));
    }

    @Test
    void testContains7() {
        boolean[] array = null;
        final boolean value = true;
        assertFalse(ArrayUtils.contains(array, value));
        array = new boolean[] {};
        assertFalse(ArrayUtils.contains(array, value));
        array = new boolean[] { false };
        assertFalse(ArrayUtils.contains(array, value));
        array = new boolean[] { false, true, false };
        assertTrue(ArrayUtils.contains(array, value));
    }

    @Test
    void testContains8() {
        char[] array = null;
        final char value = 'b';
        assertFalse(ArrayUtils.contains(array, value));
        array = new char[] {};
        assertFalse(ArrayUtils.contains(array, value));
        array = new char[] { 'a' };
        assertFalse(ArrayUtils.contains(array, value));
        array = new char[] { 'a', 'b', 'c' };
        assertTrue(ArrayUtils.contains(array, value));
    }

    @Test
    void testContains9() {
        byte[] array = null;
        final byte value = (byte) 2;
        assertFalse(ArrayUtils.contains(array, value));
        array = new byte[] {};
        assertFalse(ArrayUtils.contains(array, value));
        array = new byte[] { (byte) 1 };
        assertFalse(ArrayUtils.contains(array, value));
        array = new byte[] { (byte) 1, (byte) 2, (byte) 3 };
        assertTrue(ArrayUtils.contains(array, value));
    }

}
