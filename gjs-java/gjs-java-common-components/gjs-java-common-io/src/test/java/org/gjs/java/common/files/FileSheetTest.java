package org.gjs.java.common.files;

import static org.junit.jupiter.api.Assertions.assertEquals;
import static org.junit.jupiter.api.Assertions.assertFalse;
import static org.junit.jupiter.api.Assertions.assertNotNull;
import static org.junit.jupiter.api.Assertions.assertNull;
import static org.junit.jupiter.api.Assertions.assertTrue;
import static org.junit.jupiter.api.Assertions.fail;

import java.nio.file.Path;
import java.util.ArrayList;
import java.util.List;

import org.apache.commons.lang3.exception.ExceptionUtils;
import org.junit.jupiter.api.Test;
import org.gjs.java.common.files.FileSheet;
import org.gjs.java.test.BaseUnitTest;

public class FileSheetTest extends BaseUnitTest<FileSheet> {

    @Test
    void testFileSheet1() {
        try {
            final Path filePath = currentDir.resolve("data/ejemploSheet1.csv");
            logger.info("{}", filePath.toAbsolutePath().toString().replace("\\", "\\\\"));
            final FileSheet file = new FileSheet(',', filePath.toAbsolutePath().toString());
            assertTrue(file.isValid());
            assertNotNull(file.getColumnNames());
            assertEquals(5, file.getColumnNames().size());
            assertEquals(file.columns(), file.getColumnNames().size());

            final String[] HEADER_EXPECTED1 = { "columna1", "columna 2", "columna3", "columna4", "col umna5" };
            final String[] HEADER_EXPECTED2 = { "columna1", "columna 2", "CAMBIADO", "columna4", "col umna5" };

            final String[][] EXPECTED1 =
                    { { "valor1", "1", "0.25", "true", "AB C" }, { "valor2", "2", "", "false", null },
                            { "valor3,4", "3", "-2.01", "true", "" }, { "valor4", "4", "1.1", "false", "abc" } };
            final String[][] EXPECTED2 =
                    { { "valor1", "1", "0.25", "true", "AB C" }, { "CAMBIADO", "2", "", "false", null },
                            { "valor3,4", null, "", "true", "" }, { "valor4", "4", "1.1", "false", "abc" } };

            for (int i = 0; i < file.columns(); i = i + 1) {
                final String column = file.getColumnName(i);
                assertNotNull(column);
                assertEquals(HEADER_EXPECTED1[i], column);
            }

            assertNull(file.getColumnName(file.columns()));

            assertNotNull(file.getDatos());
            assertEquals(5, file.getDatos().rows());
            assertEquals(4, file.rows());

            for (int i = 0; i < file.rows(); i = i + 1) {
                final List<String> row = file.getRow(i);
                assertNotNull(row);
                assertEquals(file.columns(), row.size());
                for (int j = 0; j < file.columns(); j = j + 1) {
                    assertEquals(EXPECTED1[i][j], file.getValue(i, j));
                }
            }

            assertNull(file.getRow(file.rows()));

            for (int i = 0; i < file.rows(); i = i + 1) {
                for (int j = 0; j < file.columns(); j = j + 1) {
                    assertEquals(EXPECTED1[i][j], file.getValue(i, j));
                }
            }

            assertNull(file.getValue(file.rows(), file.columns()));
            assertNull(file.getValue(file.rows(), 0));
            assertNull(file.getValue(0, file.columns()));

            file.setColumnName(0, "");
            file.setColumnName(2, "CAMBIADO");
            for (int i = 0; i < file.columns(); i = i + 1) {
                final String column = file.getColumnName(i);
                assertNotNull(column);
                assertEquals(HEADER_EXPECTED2[i], column);
            }

            file.setValue(1, 0, "CAMBIADO");
            file.setValue(2, 1, null);
            file.setValue(2, 2, "");
            for (int i = 0; i < file.rows(); i = i + 1) {
                for (int j = 0; j < file.columns(); j = j + 1) {
                    assertEquals(EXPECTED2[i][j], file.getValue(i, j));
                }
            }

            file.clearData();
            assertEquals(0, file.rows());
            assertEquals(5, file.columns());
            assertNotNull(file.getColumnNames());
            assertEquals(5, file.getColumnNames().size());
            assertNull(file.getRow(0));

            file.clear();
            assertEquals(0, file.rows());
            assertEquals(0, file.columns());
            assertNotNull(file.getColumnNames());
            assertEquals(0, file.getColumnNames().size());
            assertNull(file.getRow(0));

        } catch (final Exception e) {
            logger.error(ExceptionUtils.getStackTrace(e));
            fail("Se ha producido un error");
        }
    }

    @Test
    void testFileSheet2() {
        try {
            final Path filePath = currentDir.resolve("data/ejemploSheet2.csv");
            logger.info("{}", filePath.toAbsolutePath().toString().replace("\\", "\\\\"));
            final FileSheet file = new FileSheet(',', filePath.toAbsolutePath().toString());
            assertFalse(file.isValid());
            assertNotNull(file.getColumnNames());
            assertEquals(5, file.getColumnNames().size());
            assertEquals(file.columns(), file.getColumnNames().size());
            assertNotNull(file.getDatos());
            assertEquals(4, file.getDatos().rows());
            assertEquals(3, file.rows());

        } catch (final Exception e) {
            logger.error(ExceptionUtils.getStackTrace(e));
            fail("Se ha producido un error");
        }
    }

    @Test
    void testFileSheet3() {
        try {
            final Path filePath = currentDir.resolve("data/vacio.txt");
            logger.info("{}", filePath.toAbsolutePath().toString().replace("\\", "\\\\"));
            final FileSheet file = new FileSheet(',', filePath.toAbsolutePath().toString());
            assertFalse(file.isValid());
            assertNotNull(file.getColumnNames());
            assertEquals(0, file.columns());
            assertNotNull(file.getDatos());
            assertEquals(0, file.getDatos().rows());
            assertEquals(0, file.rows());

            file.addRow("valor1", "valor2");
            assertEquals(0, file.columns());
            assertEquals(0, file.rows());

            file.setColumnNames("Col1", "Col2", "Col3");
            assertEquals(3, file.columns());
            assertEquals(0, file.rows());

            file.addRow("valor1", "valor2");
            assertEquals(3, file.columns());
            assertEquals(0, file.rows());

            file.addRow("valor1", "valor2", "valor3");
            assertEquals(3, file.columns());
            assertEquals(1, file.rows());

        } catch (final Exception e) {
            logger.error(ExceptionUtils.getStackTrace(e));
            fail("Se ha producido un error");
        }
    }

    @Test
    void testFileSheet4() {
        try {
            final FileSheet file = new FileSheet();
            assertFalse(file.isValid());
            assertNotNull(file.getColumnNames());
            assertEquals(0, file.columns());
            assertNotNull(file.getDatos());
            assertEquals(0, file.getDatos().rows());
            assertEquals(0, file.rows());
        } catch (final Exception e) {
            logger.error(ExceptionUtils.getStackTrace(e));
            fail("Se ha producido un error");
        }
    }

    @Test
    void testFileSheet5() {
        try {
            final FileSheet file = new FileSheet(',');
            assertFalse(file.isValid());
            assertNotNull(file.getColumnNames());
            assertEquals(0, file.columns());
            assertNotNull(file.getDatos());
            assertEquals(0, file.getDatos().rows());
            assertEquals(0, file.rows());
        } catch (final Exception e) {
            logger.error(ExceptionUtils.getStackTrace(e));
            fail("Se ha producido un error");
        }
    }

    @Test
    void testFileSheet6() {
        try {
            final Path filePath = currentDir.resolve("data/vacio.txt");
            logger.info("{}", filePath.toAbsolutePath().toString().replace("\\", "\\\\"));
            final FileSheet file = new FileSheet(filePath.toFile().toString());
            assertFalse(file.isValid());
            assertNotNull(file.getColumnNames());
            assertEquals(0, file.columns());
            assertNotNull(file.getDatos());
            assertEquals(0, file.getDatos().rows());
            assertEquals(0, file.rows());

            ArrayList<String> columns = null;
            file.setColumnNames(columns);
            assertNotNull(file.getColumnNames());
            assertEquals(0, file.columns());
            columns = new ArrayList<>();
            file.setColumnNames(columns);
            assertNotNull(file.getColumnNames());
            assertEquals(0, file.columns());
            columns.add("Col1");
            columns.add("Col2");
            file.setColumnNames(columns);
            assertNotNull(file.getColumnNames());
            assertEquals(2, file.columns());
            assertEquals(0, file.rows());
        } catch (final Exception e) {
            logger.error(ExceptionUtils.getStackTrace(e));
            fail("Se ha producido un error");
        }
    }

    @Test
    void testFileSheet7() {
        try {
            final Path filePath = currentDir.resolve("data/vacio.txt");
            logger.info("{}", filePath.toAbsolutePath().toString().replace("\\", "\\\\"));
            final FileSheet file = new FileSheet(filePath.toFile().getParent(), filePath.toFile().getName());
            assertFalse(file.isValid());
            assertNotNull(file.getColumnNames());
            assertEquals(0, file.columns());
            assertNotNull(file.getDatos());
            assertEquals(0, file.getDatos().rows());
            assertEquals(0, file.rows());

            file.setColumnNames();
            assertNotNull(file.getColumnNames());
            assertEquals(0, file.columns());

        } catch (final Exception e) {
            logger.error(ExceptionUtils.getStackTrace(e));
            fail("Se ha producido un error");
        }
    }

    @Test
    void testFileSheet8() {
        try {
            final Path filePath = currentDir.resolve("data/vacio.txt");
            logger.info("{}", filePath.toAbsolutePath().toString().replace("\\", "\\\\"));
            final FileSheet file = new FileSheet(filePath.toFile());
            assertFalse(file.isValid());
            assertNotNull(file.getColumnNames());
            assertEquals(0, file.columns());
            assertNotNull(file.getDatos());
            assertEquals(0, file.getDatos().rows());
            assertEquals(0, file.rows());
        } catch (final Exception e) {
            logger.error(ExceptionUtils.getStackTrace(e));
            fail("Se ha producido un error");
        }
    }

    @Test
    void testFileSheet9() {
        try {
            final Path filePath = currentDir.resolve("data/vacio.txt");
            logger.info("{}", filePath.toAbsolutePath().toString().replace("\\", "\\\\"));
            final FileSheet file = new FileSheet(',', filePath.toFile());
            assertFalse(file.isValid());
            assertNotNull(file.getColumnNames());
            assertEquals(0, file.columns());
            assertNotNull(file.getDatos());
            assertEquals(0, file.getDatos().rows());
            assertEquals(0, file.rows());
        } catch (final Exception e) {
            logger.error(ExceptionUtils.getStackTrace(e));
            fail("Se ha producido un error");
        }
    }

    @Test
    void testFileSheet10() {
        try {
            final Path filePath = currentDir.resolve("data/vacio.txt");
            logger.info("{}", filePath.toAbsolutePath().toString().replace("\\", "\\\\"));
            FileSheet file = new FileSheet(filePath);
            assertFalse(file.isValid());
            assertNotNull(file.getColumnNames());
            assertEquals(0, file.columns());
            assertNotNull(file.getDatos());
            assertEquals(0, file.getDatos().rows());
            assertEquals(0, file.rows());
            assertNotNull(file.getSeparator());
            assertEquals('\t', file.getSeparator());

            file = new FileSheet(',', filePath);
            assertFalse(file.isValid());
            assertNotNull(file.getColumnNames());
            assertEquals(0, file.columns());
            assertNotNull(file.getDatos());
            assertEquals(0, file.getDatos().rows());
            assertEquals(0, file.rows());
            assertNotNull(file.getSeparator());
            assertEquals(',', file.getSeparator());
        } catch (final Exception e) {
            logger.error(ExceptionUtils.getStackTrace(e));
            fail("Se ha producido un error");
        }
    }

}
