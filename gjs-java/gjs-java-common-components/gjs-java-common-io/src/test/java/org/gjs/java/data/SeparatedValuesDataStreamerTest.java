package org.gjs.java.data;

import static org.junit.jupiter.api.Assertions.assertEquals;
import static org.junit.jupiter.api.Assertions.assertFalse;
import static org.junit.jupiter.api.Assertions.assertNotNull;
import static org.junit.jupiter.api.Assertions.assertTrue;
import static org.junit.jupiter.api.Assertions.fail;

import java.io.FileReader;
import java.io.FileWriter;
import java.nio.file.Path;
import java.util.List;

import org.apache.commons.io.FileUtils;
import org.apache.commons.lang3.SystemUtils;
import org.apache.commons.lang3.exception.ExceptionUtils;
import org.junit.jupiter.api.Test;

import org.gjs.java.test.BaseUnitTest;

public class SeparatedValuesDataStreamerTest extends BaseUnitTest<SeparatedValuesDataStreamer> {

    @Test
    void testSeparatedValuesDataStreamer1() {
        try {
            final SeparatedValuesDataStreamer streamer = new SeparatedValuesDataStreamer('.');
            assertEquals('.', streamer.getSeparator());
            assertNotNull(streamer.getData());
            assertEquals(0, streamer.getData().rows());
            streamer.setSeparator(',');
            assertEquals(',', streamer.getSeparator());

            final Path filePath = currentDir.resolve("data/ejemplo.csv");
            final FileReader fileReader = new FileReader(filePath.toFile());
            assertTrue(streamer.load(fileReader));
            assertNotNull(streamer.getData());
            assertEquals(4, streamer.getData().rows());

            final String[][] EXPECTED = { { "valor1", "1", "0.25", "true", "AB C" },
                    { "valor2", "2", "", "false", null }, { "valor3,4", "3", "-2.01", "true", "" },
                    { "valor4", "4", "1.1", "false", "abc" } };

            for (int i = 0; i < streamer.getData().rows(); i = i + 1) {
                final List<String> row = streamer.getData().getRow(i);
                assertNotNull(row);
                assertEquals(5, streamer.getData().columns(i));
                for (int j = 0; j < streamer.getData().columns(i); j = j + 1) {
                    assertEquals(EXPECTED[i][j], streamer.getData().getValue(i, j));
                }
            }

            streamer.clear();
            assertNotNull(streamer.getData());
            assertEquals(0, streamer.getData().rows());
        } catch (final Exception e) {
            logger.error(ExceptionUtils.getStackTrace(e));
            fail("Se ha producido un error");
        }
    }

    @Test
    void testSeparatedValuesDataStreamer2() {
        try {
            final SeparatedValuesDataStreamer streamer = new SeparatedValuesDataStreamer();
            final Path filePath = currentDir.resolve("data/vacio.txt");
            final FileReader fileReader = new FileReader(filePath.toFile());
            assertTrue(streamer.load(fileReader));
            assertNotNull(streamer.getData());
            assertEquals(0, streamer.getData().rows());
        } catch (final Exception e) {
            logger.error(ExceptionUtils.getStackTrace(e));
            fail("Se ha producido un error");
        }
    }

    @Test
    void testSeparatedValuesDataStreamer3() {
        try {
            final Path filePath = currentDir.resolve("data/ejemplo.csv");
            final FileReader fileReader = new FileReader(filePath.toFile());
            final SeparatedValuesDataStreamer streamer = new SeparatedValuesDataStreamer('\t', fileReader);
            assertEquals('\t', streamer.getSeparator());
            assertNotNull(streamer.getData());
            assertEquals(4, streamer.getData().rows());
            final String[] EXPECTED = { "valor1", "valor2", "valor3,4", "valor4" };

            for (int i = 0; i < streamer.getData().rows(); i = i + 1) {
                final List<String> row = streamer.getData().getRow(i);
                assertNotNull(row);
                assertEquals(1, streamer.getData().columns(i));
                assertEquals(EXPECTED[i], streamer.getData().getValue(i, 0));
            }
        } catch (final Exception e) {
            logger.error(ExceptionUtils.getStackTrace(e));
            fail("Se ha producido un error");
        }
    }

    @Test
    void testSeparatedValuesDataStreamer4() {
        try {
            String readFilePath = "data/ejemploOk.csv";
            if (SystemUtils.IS_OS_LINUX || SystemUtils.IS_OS_UNIX) {
                readFilePath = "data/ejemploOk_UNIX.csv";
            }
            final Path readPath = currentDir.resolve(readFilePath);
            final FileReader fileReader = new FileReader(readPath.toFile());
            final Path savePath1 = resultsDir.resolve("ejemploSaved1.csv");
            final FileWriter fileWriter1 = new FileWriter(savePath1.toFile());
            final Path savePath2 = resultsDir.resolve("ejemploSaved2.csv");
            final FileWriter fileWriter2 = new FileWriter(savePath2.toFile());
            final SeparatedValuesDataStreamer streamer = new SeparatedValuesDataStreamer(',', fileReader);
            assertNotNull(streamer.getData());
            streamer.save(fileWriter1);
            assertTrue(savePath1.toFile().exists());

            streamer.setStringColumns(0, 4);
            streamer.save(fileWriter2);
            assertTrue(savePath2.toFile().exists());
            assertTrue(FileUtils.contentEquals(readPath.toFile(), savePath2.toFile()));

        } catch (final Exception e) {
            logger.error(ExceptionUtils.getStackTrace(e));
            fail("Se ha producido un error");
        }
    }

    @Test
    void testSeparatedValuesDataStreamer5() {
        try {
            final Path savePath1 = resultsDir.resolve("ejemploSaved3.csv");
            final FileWriter fileWriter1 = new FileWriter(savePath1.toFile());
            final SeparatedValuesDataStreamer streamer = new SeparatedValuesDataStreamer(',');
            assertNotNull(streamer.getData());
            assertFalse(streamer.hasHeader());
            streamer.getData().addRow("VALOR1", "1", "null", "Text1");
            streamer.getData().addRow("VALOR2", "2");
            streamer.getData().addRow("VALOR3", "1", "2.1", "Text3", "adicional");
            streamer.getData().addRow("VALOR4", "5", "3.0", "Text4");
            streamer.setStringColumns(0, 3, 4);
            streamer.save(fileWriter1);
            assertTrue(savePath1.toFile().exists());

        } catch (final Exception e) {
            logger.error(ExceptionUtils.getStackTrace(e));
            fail("Se ha producido un error");
        }
    }

    @Test
    void testSeparatedValuesDataStreamer6() {
        try {
            final Path savePath1 = resultsDir.resolve("ejemploSaved4.csv");
            final FileWriter fileWriter1 = new FileWriter(savePath1.toFile());
            final SeparatedValuesDataStreamer streamer = new SeparatedValuesDataStreamer(',');
            assertNotNull(streamer.getData());
            streamer.getData().addRow("COLUMNA1", "COLUMNA2", "COLUMNA3", "COLUMNA4");
            streamer.setHasHeader(true);
            assertTrue(streamer.hasHeader());
            streamer.getData().addRow("VALOR1", "1", "null", "Text1");
            streamer.getData().addRow("VALOR2", "2");
            streamer.getData().addRow("VALOR3", "1", "2.1", "Text3", "adicional");
            streamer.getData().addRow("VALOR4", "5", "3.0", "Text4");
            streamer.setStringColumns(0, 3, 4);
            streamer.save(fileWriter1);
            assertTrue(savePath1.toFile().exists());

        } catch (final Exception e) {
            logger.error(ExceptionUtils.getStackTrace(e));
            fail("Se ha producido un error");
        }
    }

}
