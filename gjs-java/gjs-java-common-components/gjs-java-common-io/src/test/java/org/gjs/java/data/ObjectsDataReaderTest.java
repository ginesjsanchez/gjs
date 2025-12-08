package org.gjs.java.data;

import static org.junit.jupiter.api.Assertions.assertEquals;
import static org.junit.jupiter.api.Assertions.assertNotNull;
import static org.junit.jupiter.api.Assertions.assertTrue;
import static org.junit.jupiter.api.Assertions.fail;

import java.io.FileReader;
import java.nio.file.Path;

import org.apache.commons.lang3.exception.ExceptionUtils;
import org.junit.jupiter.api.Test;

import org.gjs.java.test.BaseUnitTest;

public class ObjectsDataReaderTest extends BaseUnitTest<ObjectsDataReader> {

    @Test
    void testObjectsDataReader1() {
        try {
            final Path filePath = currentDir.resolve("data/ejemploSheet1.csv");
            final FileReader fileReader = new FileReader(filePath.toFile());
            final ObjectsDataReader streamer = new ObjectsDataReader(',', fileReader);
            assertTrue(streamer.isValid());
            assertNotNull(streamer.getColumnNames());
            assertEquals(5, streamer.getColumnNames().size());
            assertEquals(streamer.columns(), streamer.getColumnNames().size());

            assertNotNull(streamer.getObjects());
            assertEquals(4, streamer.rows());
            assertEquals(4, streamer.getObjects().size());

            for (int i = 0; i < streamer.rows(); i = i + 1) {
                final Object obj = streamer.getObject(i);
                assertNotNull(obj);
                logger.info("Object {}: {}", i, obj);
            }

            streamer.clear();
            assertEquals(0, streamer.rows());
            assertEquals(0, streamer.getObjects().size());

        } catch (final Exception e) {
            logger.error(ExceptionUtils.getStackTrace(e));
            fail("Se ha producido un error");
        }
    }

}
