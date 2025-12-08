package org.gjs.java.types;

import static org.junit.jupiter.api.Assertions.assertEquals;
import static org.junit.jupiter.api.Assertions.assertNotNull;
import static org.junit.jupiter.api.Assertions.assertNull;

import java.util.ArrayList;
import java.util.List;

import org.junit.jupiter.api.Test;

import org.gjs.java.test.BaseClassTest;

@SuppressWarnings("rawtypes")
class MatrixTest extends BaseClassTest<Matrix> {

    @Test
    void testMatrix1() {
        final Matrix<String> matrix = new Matrix<>();
        assertEquals(0, matrix.rows());
        matrix.addRow("valor00", "valor01", "valor02");
        matrix.addRow("valor10", "valor11");
        matrix.addRow();
        final int[] expected = { 3, 2, 0 };
        assertEquals(3, matrix.rows());

        for (int i = 0; i < matrix.rows(); i = i + 1) {
            final List<String> row = matrix.getRow(i);
            assertNotNull(row);
            assertEquals(expected[i], matrix.columns(i));
            assertEquals(expected[i], row.size());
            for (int j = 0; j < row.size(); j = j + 1) {
                assertNotNull(matrix.getValue(i, j));
            }
        }
        assertNull(matrix.getValue(0, 5));
        assertNull(matrix.getValue(2, 5));
        assertNull(matrix.getValue(3, 1));

        matrix.setValue(1, 1, "VALORX1");
        assertEquals("VALORX1", matrix.getValue(1, 1));
        matrix.setValue(2, 1, "VALORX2");
        assertNotNull(matrix.getValue(2, 1));
        assertEquals("VALORX2", matrix.getValue(2, 1));
        assertNull(matrix.getValue(2, 0));

        matrix.setValue(4, 0, "VALORX3");
        assertEquals(5, matrix.rows());
        assertNotNull(matrix.getValue(4, 0));
        assertEquals("VALORX3", matrix.getValue(4, 0));
        assertNull(matrix.getValue(3, 0));

        matrix.setRow(2, "VALORY1", "VALORY2", "VALORY3");
        matrix.setRow(3);
        matrix.setRow(7, "X");
        assertEquals(8, matrix.rows());
        assertEquals(3, matrix.columns(2));
        assertEquals(0, matrix.columns(3));
        assertEquals(0, matrix.columns(5));
        assertEquals(0, matrix.columns(6));
        assertEquals(1, matrix.columns(7));
        assertNotNull(matrix.getValue(2, 2));
        assertEquals("VALORY3", matrix.getValue(2, 2));

        matrix.removeRow(5);
        assertEquals(7, matrix.rows());
        assertEquals(3, matrix.columns(2));
        assertEquals(0, matrix.columns(3));
        assertEquals(0, matrix.columns(5));
        assertEquals(1, matrix.columns(6));
    }

    @Test
    void testMatrix2() {
        final Matrix<String> matrix = new Matrix<>();
        assertEquals(0, matrix.rows());
        matrix.addRow();
        assertEquals(1, matrix.rows());
        ArrayList<String> row = null;
        matrix.addRow(row);
        assertEquals(1, matrix.rows());
        row = new ArrayList<>();
        matrix.addRow(row);
        assertEquals(2, matrix.rows());
    }
}
