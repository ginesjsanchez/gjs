package org.gjs.java.common.data;

import static org.junit.jupiter.api.Assertions.assertEquals;
import static org.junit.jupiter.api.Assertions.assertFalse;
import static org.junit.jupiter.api.Assertions.assertNotNull;
import static org.junit.jupiter.api.Assertions.assertNull;
import static org.junit.jupiter.api.Assertions.assertTrue;
import static org.junit.jupiter.api.Assertions.fail;

import java.io.FileReader;
import java.io.FileWriter;
import java.nio.file.Path;
import java.util.ArrayList;
import java.util.List;

import org.apache.commons.lang3.exception.ExceptionUtils;
import org.junit.jupiter.api.Test;
import org.gjs.java.common.data.SheetDataStreamer;
import org.gjs.java.test.BaseUnitTest;

public class SheetDataStreamerTest extends BaseUnitTest<SheetDataStreamer> {

    @Test
    void testSheetDataStreamer1() {
        try {
            final Path filePath = currentDir.resolve("data/ejemploSheet1.csv");
            final FileReader fileReader = new FileReader(filePath.toFile());
            final SheetDataStreamer streamer = new SheetDataStreamer(',', fileReader);
            assertTrue(streamer.isValid());
            assertNotNull(streamer.getColumnNames());
            assertEquals(5, streamer.getColumnNames().size());
            assertEquals(streamer.columns(), streamer.getColumnNames().size());

            final String[] HEADER_EXPECTED1 = { "columna1", "columna 2", "columna3", "columna4", "col umna5" };

            final String[][] EXPECTED1 =
                    { { "valor1", "1", "0.25", "true", "AB C" }, { "valor2", "2", "", "false", null },
                            { "valor3,4", "3", "-2.01", "true", "" }, { "valor4", "4", "1.1", "false", "abc" } };

            for (int i = 0; i < streamer.columns(); i = i + 1) {
                final String column = streamer.getColumnName(i);
                assertNotNull(column);
                assertEquals(HEADER_EXPECTED1[i], column);
            }

            assertNull(streamer.getColumnName(streamer.columns()));

            assertNotNull(streamer.getData());
            assertEquals(5, streamer.getData().rows());
            assertEquals(4, streamer.rows());

            for (int i = 0; i < streamer.rows(); i = i + 1) {
                final List<String> row = streamer.getRow(i);
                assertNotNull(row);
                assertEquals(streamer.columns(), row.size());
                for (int j = 0; j < streamer.columns(); j = j + 1) {
                    assertEquals(EXPECTED1[i][j], streamer.getValue(i, j));
                }
            }

            assertNull(streamer.getRow(streamer.rows()));

            for (int i = 0; i < streamer.rows(); i = i + 1) {
                for (int j = 0; j < streamer.columns(); j = j + 1) {
                    assertEquals(EXPECTED1[i][j], streamer.getValue(i, j));
                }
            }

            assertNull(streamer.getValue(streamer.rows(), streamer.columns()));
            assertNull(streamer.getValue(streamer.rows(), 0));
            assertNull(streamer.getValue(0, streamer.columns()));

            streamer.clear();
            assertEquals(0, streamer.rows());
            assertEquals(0, streamer.columns());
            assertNotNull(streamer.getColumnNames());
            assertEquals(0, streamer.getColumnNames().size());
            assertNull(streamer.getRow(0));

        } catch (final Exception e) {
            logger.error(ExceptionUtils.getStackTrace(e));
            fail("Se ha producido un error");
        }
    }

    @Test
    void testSheetDataStreamer2() {
        try {
            final Path filePath = currentDir.resolve("data/ejemploSheet2.csv");
            final FileReader fileReader = new FileReader(filePath.toFile());
            final SheetDataStreamer streamer = new SheetDataStreamer(',', fileReader);
            assertFalse(streamer.isValid());
            assertNotNull(streamer.getColumnNames());
            assertEquals(5, streamer.getColumnNames().size());
            assertEquals(streamer.columns(), streamer.getColumnNames().size());
            assertNotNull(streamer.getData());
            assertEquals(4, streamer.getData().rows());
            assertEquals(3, streamer.rows());

        } catch (final Exception e) {
            logger.error(ExceptionUtils.getStackTrace(e));
            fail("Se ha producido un error");
        }
    }

    @Test
    void testSheetDataStreamer3() {
        try {
            final Path savePath1 = resultsDir.resolve("nuevoSheetSaved1.csv");
            final FileWriter fileWriter1 = new FileWriter(savePath1.toFile());
            final Path savePath2 = resultsDir.resolve("nuevoSheetSaved2.csv");
            final FileWriter fileWriter2 = new FileWriter(savePath2.toFile());
            final SheetDataStreamer streamer = new SheetDataStreamer(',');
            assertFalse(streamer.isValid());
            assertNotNull(streamer.getColumnNames());
            assertEquals(0, streamer.getColumnNames().size());
            assertEquals(0, streamer.columns());
            assertEquals(0, streamer.rows());

            streamer.addColumnName("COLUMNA1");
            assertEquals(1, streamer.getColumnNames().size());
            assertEquals(1, streamer.columns());
            assertEquals(0, streamer.rows());
            streamer.addColumnName("COLUMNA2");
            assertEquals(2, streamer.getColumnNames().size());
            assertEquals(2, streamer.columns());
            assertEquals(0, streamer.rows());

            streamer.setStringColumns(0, 1);
            streamer.save(fileWriter1);
            assertTrue(savePath1.toFile().exists());

            streamer.getData().addRow("Valor11", "Valor12");
            streamer.getData().addRow("Valor21");
            streamer.getData().addRow("Valor31", "Valor32", "Valor33");
            assertEquals(2, streamer.getColumnNames().size());
            assertEquals(2, streamer.columns());
            assertEquals(3, streamer.rows());
            streamer.save(fileWriter2);
            assertTrue(savePath2.toFile().exists());

        } catch (final Exception e) {
            logger.error(ExceptionUtils.getStackTrace(e));
            fail("Se ha producido un error");
        }
    }

    @Test
    void testSheetDataStreamer4() {
        try {
            final Path filePath = currentDir.resolve("data/ejemploSheet2.csv");
            final FileReader fileReader = new FileReader(filePath.toFile());
            final Path savePath = resultsDir.resolve("ejemploSheet2Saved.csv");
            final FileWriter fileWriter = new FileWriter(savePath.toFile());
            final SheetDataStreamer streamer = new SheetDataStreamer(',', fileReader);
            assertFalse(streamer.isValid());
            assertNotNull(streamer.getColumnNames());
            assertEquals(5, streamer.getColumnNames().size());
            assertEquals(streamer.columns(), streamer.getColumnNames().size());
            assertNotNull(streamer.getData());
            assertEquals(4, streamer.getData().rows());
            assertEquals(3, streamer.rows());
            streamer.setStringColumns(0, 4);
            streamer.save(fileWriter);
            assertTrue(savePath.toFile().exists());

        } catch (final Exception e) {
            logger.error(ExceptionUtils.getStackTrace(e));
            fail("Se ha producido un error");
        }
    }

    @Test
    void testSheetDataStreamer5() {
        try {
            final Path savePath1 = resultsDir.resolve("nuevoSheetSaved3.csv");
            final FileWriter fileWriter1 = new FileWriter(savePath1.toFile());
            final SheetDataStreamer streamer = new SheetDataStreamer(',');
            streamer.addColumnName("COLUMNA1");
            streamer.addColumnName("COLUMNA2");
            streamer.setStringColumns(0, 1);

            assertEquals(0, streamer.rows());
            streamer.setRow(2, "Valor11", "Valor12");
            assertEquals(3, streamer.rows());
            streamer.addRow("Valor21");
            assertEquals(4, streamer.rows());
            final List<String> values = new ArrayList<>();
            streamer.addRow(values);
            assertEquals(5, streamer.rows());
            streamer.setRow(7, values);
            assertEquals(5, streamer.rows());
            values.add("Valor31");
            values.add("Valor32");
            values.add("Valor33");
            streamer.addRow(values);
            assertEquals(6, streamer.rows());
            streamer.setRow(5, values);
            assertEquals(6, streamer.rows());
            streamer.setValue(0, 0, "VALOR00");
            streamer.setValue(1, 1, "VALOR11");
            assertEquals(2, streamer.getColumnNames().size());
            assertEquals(2, streamer.columns());
            assertEquals(6, streamer.rows());
            streamer.save(fileWriter1);
            assertTrue(savePath1.toFile().exists());

        } catch (final Exception e) {
            logger.error(ExceptionUtils.getStackTrace(e));
            fail("Se ha producido un error");
        }
    }

}
