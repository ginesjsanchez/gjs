package org.gjs.java.data;

import static org.junit.jupiter.api.Assertions.assertFalse;
import static org.junit.jupiter.api.Assertions.assertTrue;
import static org.junit.jupiter.api.Assertions.fail;

import java.io.FileReader;
import java.io.FileWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.nio.file.Path;

import org.apache.commons.lang3.exception.ExceptionUtils;
import org.junit.jupiter.api.Test;

import org.gjs.java.test.BaseUnitTest;
import lombok.Getter;
import lombok.Setter;

public class DataStreamerTest extends BaseUnitTest<DataStreamer> {

    @Getter
    @Setter
    private static class DataStreamerSample extends DataStreamer {

        private boolean initialized = false;

        public DataStreamerSample() {
        }

        @Override
        protected void init() {
            initialized = true;
        }

        @Override
        protected boolean loadContent(InputStreamReader reader) {
            return true;
        }

        @Override
        protected boolean saveContent(OutputStreamWriter writer) {
            return true;
        }

    }

    @Test
    void testDataStreamer() {
        try {
            final DataStreamerSample streamer = new DataStreamerSample();
            assertFalse(streamer.isInitialized());
            assertFalse(streamer.load(null));
            assertFalse(streamer.isInitialized());

            final Path readPath = currentDir.resolve("data/ejemplo.csv");
            final FileReader fileReader = new FileReader(readPath.toFile());
            final Path savePath = resultsDir.resolve("ejemploOut.csv");
            final FileWriter fileWriter = new FileWriter(savePath.toFile());

            assertTrue(streamer.load(fileReader));
            assertTrue(streamer.isInitialized());
            assertTrue(streamer.save(fileWriter));
            assertTrue(savePath.toFile().exists());

            streamer.setInitialized(false);
            streamer.clear();
            assertTrue(streamer.isInitialized());

        } catch (final Exception e) {
            logger.error(ExceptionUtils.getStackTrace(e));
            fail("Se ha producido un error");
        }
    }

}
