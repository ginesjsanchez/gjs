package org.gjs.java.util;

import static org.junit.jupiter.api.Assertions.assertEquals;
import static org.junit.jupiter.api.Assertions.assertNotNull;
import static org.junit.jupiter.api.Assertions.fail;

import java.io.FileReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.nio.file.Path;
import java.util.ArrayList;
import java.util.List;

import org.apache.commons.lang3.exception.ExceptionUtils;
import org.gjs.java.test.BaseUnitTest;
import org.gjs.java.types.Matrix;
import org.gjs.java.util.StreamUtils;
import org.junit.jupiter.api.Test;

class StreamUtilsTest extends BaseUnitTest<StreamUtils> {

	@Test
	void testReadLines1() {
		final Path filePath = currentDir.resolve("data/ejemplo.txt");
		logger.info("{}", filePath.toAbsolutePath().toString().replace("\\", "\\\\"));
		final List<String> lines = new ArrayList<>();
		try {
			StreamUtils.readLines(new FileReader(filePath.toAbsolutePath().toString()), lines);
			assertEquals(6, lines.size());
			for (final String line : lines) {
				logger.info("[{}]", line);
			}
		} catch (final Exception e) {
			logger.error(ExceptionUtils.getStackTrace(e));
			fail("Se ha producido un error");
		}
	}

	@Test
	void testReadLines2() {
		final Path filePath = currentDir.resolve("data/vacio.txt");
		logger.info("{}", filePath.toAbsolutePath().toString().replace("\\", "\\\\"));
		final List<String> lines = new ArrayList<>();
		try {
			StreamUtils.readLines(new FileReader(filePath.toAbsolutePath().toString()), lines);
			assertEquals(0, lines.size());
		} catch (final Exception e) {
			logger.error(ExceptionUtils.getStackTrace(e));
			fail("Se ha producido un error");
		}
	}

	@Test
	void testReadLines3() {
		final Path filePath = currentDir.resolve("data/vacio.txt");
		logger.info("{}", filePath.toAbsolutePath().toString().replace("\\", "\\\\"));
		final List<String> lines = null;
		try {
			StreamUtils.readLines(new FileReader(filePath.toAbsolutePath().toString()), lines);
		} catch (final Exception e) {
			logger.error(ExceptionUtils.getStackTrace(e));
			fail("Se ha producido un error");
		}
	}

	@Test
	void testReadLines4() {
		final Path filePath = currentDir.resolve("data/vacio.txt");
		logger.info("{}", filePath.toAbsolutePath().toString().replace("\\", "\\\\"));
		final List<String> lines = new ArrayList<>();
		try {
			final InputStreamReader reader = null;
			StreamUtils.readLines(reader, lines);
			assertEquals(0, lines.size());
		} catch (final IOException e) {
			logger.error(ExceptionUtils.getStackTrace(e));
			fail("Se ha producido un error");
		}
	}

	@Test
	void testReadLines_Exception1() {
		final Path filePath = currentDir.resolve("data/nohalugar.txt");
		logger.info("{}", filePath.toAbsolutePath().toString().replace("\\", "\\\\"));
		final List<String> lines = new ArrayList<>();
		try {
			StreamUtils.readLines(new FileReader(filePath.toAbsolutePath().toString()), lines);
			fail("Se esperaba un error");
		} catch (final Exception e) {
			logger.error(ExceptionUtils.getStackTrace(e));
			assertNotNull(e.getMessage());
		}
	}

	@Test
	void testReadData1() {
		final Path filePath = currentDir.resolve("data/ejemplo.csv");
		logger.info("{}", filePath.toAbsolutePath().toString().replace("\\", "\\\\"));
		final Matrix<String> data = new Matrix<>();
		try {
			StreamUtils.readData(new FileReader(filePath.toAbsolutePath().toString()), data, ',');
			assertEquals(4, data.rows());

			final String[][] EXPECTED = { { "valor1", "1", "0.25", "true", "AB C" },
					{ "valor2", "2", "", "false", null }, { "valor3,4", "3", "-2.01", "true", "" },
					{ "valor4", "4", "1.1", "false", "abc" } };

			for (int i = 0; i < data.rows(); i = i + 1) {
				final List<String> row = data.getRow(i);
				assertNotNull(row);
				assertEquals(5, data.columns(i));
				for (int j = 0; j < data.columns(i); j = j + 1) {
					assertEquals(EXPECTED[i][j], data.getValue(i, j));
				}
			}
		} catch (final Exception e) {
			logger.error(ExceptionUtils.getStackTrace(e));
			fail("Se ha producido un error");
		}
	}

	@Test
	void testReadData2() {
		final Path filePath = currentDir.resolve("data/ejemplo.csv");
		logger.info("{}", filePath.toAbsolutePath().toString().replace("\\", "\\\\"));
		final Matrix<String> data = new Matrix<>();
		try {
			StreamUtils.readData(new FileReader(filePath.toAbsolutePath().toString()), data, ',');
			assertEquals(4, data.rows());

			final String[][] EXPECTED = { { "valor1", "1", "0.25", "true", "AB C" },
					{ "valor2", "2", "", "false", null }, { "valor3,4", "3", "-2.01", "true", "" },
					{ "valor4", "4", "1.1", "false", "abc" } };

			for (int i = 0; i < data.rows(); i = i + 1) {
				final List<String> row = data.getRow(i);
				assertNotNull(row);
				assertEquals(5, data.columns(i));
				for (int j = 0; j < data.columns(i); j = j + 1) {
					assertEquals(EXPECTED[i][j], data.getValue(i, j));
				}
			}
		} catch (final Exception e) {
			logger.error(ExceptionUtils.getStackTrace(e));
			fail("Se ha producido un error");
		}
	}

}
