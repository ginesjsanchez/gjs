package org.gjs.java.files;

import static org.junit.jupiter.api.Assertions.assertEquals;
import static org.junit.jupiter.api.Assertions.assertFalse;
import static org.junit.jupiter.api.Assertions.assertNotNull;
import static org.junit.jupiter.api.Assertions.assertNull;
import static org.junit.jupiter.api.Assertions.assertTrue;
import static org.junit.jupiter.api.Assertions.fail;

import java.nio.file.Files;
import java.nio.file.Path;
import java.util.ArrayList;
import java.util.List;

import org.apache.commons.lang3.exception.ExceptionUtils;
import org.gjs.java.test.BaseUnitTest;
import org.junit.jupiter.api.Test;

public class FileLinesTest extends BaseUnitTest<FileLines> {

	@Test
	void testFileLines1() {
		try {
			final Path filePath = currentDir.resolve("data/ejemplo.txt");
			logger.info("{}", filePath.toAbsolutePath().toString().replace("\\", "\\\\"));
			final FileLines file = new FileLines(filePath.toAbsolutePath().toString());
			assertNotNull(file.getDirectory());
			assertNotNull(file.getName());
			assertNotNull(file.getPath());
			assertTrue(file.isValid());
			logger.info("Directory: {}", file.getDirectory());
			logger.info("Name     : {}", file.getName());
			logger.info("Path     : {}", file.getPath());
			assertEquals(6, file.count());
			assertNull(file.getCurrent());
			assertNotNull(file.getLines());
			assertEquals(6, file.getLines().size());
			assertTrue(file.bof());
			assertFalse(file.eof());

			file.begin();
			assertFalse(file.bof());
			assertFalse(file.eof());
			assertNotNull(file.getCurrent());
			while (!file.eof()) {
				assertNotNull(file.getCurrent());
				if (file.getCurrent().trim().length() == 0) {
					file.remove();
					file.insert("Eliminada linea");
				}
				file.next();
			}
			assertNull(file.getCurrent());
			assertTrue(file.eof());
			assertFalse(file.bof());

			file.end();
			assertFalse(file.eof());
			assertFalse(file.bof());
			while (!file.bof()) {
				assertNotNull(file.getCurrent());
				file.previous();
			}
			assertNull(file.getCurrent());
			assertTrue(file.bof());
			assertFalse(file.eof());

			final String EXPECTED = "linea1\r\n" + " linea 2\r\n" + "linea 3\r\n" + "Eliminada linea\r\n" + "linea4\r\n"
					+ "Eliminada linea\r\n";
			final Path newPath = resultsDir.resolve("modificado.txt");
			assertTrue(file.save(newPath.toAbsolutePath().toString()));
			assertEquals(EXPECTED.replace("\r\n", lineSep), Files.readString(newPath));

			file.clear();
			assertEquals(0, file.count());
			assertNull(file.getCurrent());
			assertTrue(file.bof());
			assertTrue(file.eof());

		} catch (final Exception e) {
			logger.error(ExceptionUtils.getStackTrace(e));
			fail("Se ha producido un error");
		}
	}

	@Test
	void testFileLines2() {
		try {
			final Path filePath = currentDir.resolve("data/vacio.txt");
			logger.info("{}", filePath.toAbsolutePath().toString().replace("\\", "\\\\"));
			final FileLines file = new FileLines(filePath.toAbsolutePath().toString());
			assertNotNull(file.getDirectory());
			assertNotNull(file.getName());
			assertNotNull(file.getPath());
			assertTrue(file.isValid());
			logger.info("Directory: {}", file.getDirectory());
			logger.info("Name     : {}", file.getName());
			logger.info("Path     : {}", file.getPath());
			assertEquals(0, file.count());
			assertNull(file.getCurrent());
			assertNotNull(file.getLines());
			assertEquals(0, file.getLines().size());
			assertTrue(file.bof());
			assertTrue(file.eof());

		} catch (final Exception e) {
			logger.error(ExceptionUtils.getStackTrace(e));
			fail("Se ha producido un error");
		}
	}

	@Test
	void testFileLines3() {
		try {
			final Path filePath = currentDir.resolve("data/vacio2.txt");
			logger.info("{}", filePath.toAbsolutePath().toString().replace("\\", "\\\\"));
			final FileLines file = new FileLines();
			assertNull(file.getDirectory());
			assertNull(file.getName());
			assertNull(file.getPath());
			assertFalse(file.isValid());
			assertEquals(0, file.count());
			assertNull(file.getCurrent());
			assertNotNull(file.getLines());
			assertEquals(0, file.getLines().size());
			assertTrue(file.bof());
			assertTrue(file.eof());

			final List<String> lines = new ArrayList<>();
			file.setLines(lines);
			assertEquals(0, file.count());
			assertNull(file.getCurrent());
			assertNotNull(file.getLines());
			assertEquals(0, file.getLines().size());
			assertTrue(file.bof());
			assertTrue(file.eof());

			lines.add("Line 1");
			lines.add("Line 2");
			file.setLines(lines);
			assertEquals(2, file.count());
			assertNull(file.getCurrent());
			assertNotNull(file.getLines());
			assertEquals(2, file.getLines().size());
			file.begin();
			assertNotNull(file.getCurrent());
			assertFalse(file.bof());
			assertFalse(file.eof());
			file.previous();
			assertNull(file.getCurrent());
			assertTrue(file.bof());
			assertFalse(file.eof());
			file.next();
			assertNotNull(file.getCurrent());
			assertFalse(file.bof());
			assertFalse(file.eof());
			file.next();
			assertNotNull(file.getCurrent());
			assertFalse(file.bof());
			assertFalse(file.eof());
			file.next();
			assertNull(file.getCurrent());
			assertFalse(file.bof());
			assertTrue(file.eof());
			file.next();
			assertFalse(file.bof());
			assertTrue(file.eof());
			file.previous();
			assertFalse(file.bof());
			assertFalse(file.eof());
			file.previous();
			assertNotNull(file.getCurrent());
			assertFalse(file.bof());
			assertFalse(file.eof());
			file.end();
			assertNotNull(file.getCurrent());
			assertFalse(file.bof());
			assertFalse(file.eof());
			file.next();
			assertNull(file.getCurrent());
			assertFalse(file.bof());
			assertTrue(file.eof());

		} catch (final Exception e) {
			logger.error(ExceptionUtils.getStackTrace(e));
			fail("Se ha producido un error");
		}
	}

	@Test
	void testFileLines4() {
		try {
			final Path filePath = currentDir.resolve("data/vacio3.txt");
			logger.info("{}", filePath.toAbsolutePath().toString().replace("\\", "\\\\"));
			final FileLines file = new FileLines(filePath.toAbsolutePath().toFile().getParent(),
					filePath.toAbsolutePath().toFile().getName());
			assertNotNull(file.getDirectory());
			assertNotNull(file.getName());
			assertNotNull(file.getPath());
			assertFalse(file.isValid());
			assertFalse(file.exists());
			logger.info("Directory: {}", file.getDirectory());
			logger.info("Name     : {}", file.getName());
			logger.info("Path     : {}", file.getPath());
			assertEquals(0, file.count());
			assertNull(file.getCurrent());
			assertNull(file.getLines());
			assertTrue(file.bof());
			assertTrue(file.eof());

			final List<String> lines = new ArrayList<>();
			lines.add("Line 1 X");
			lines.add("Line 2 Y");
			lines.add("Line 3 Z");
			lines.add("Line 4 K");
			file.setLines(lines);
			assertTrue(file.isValid());
			assertFalse(file.exists());
			assertEquals(4, file.count());
			file.end();
			assertFalse(file.bof());
			assertFalse(file.eof());

			assertFalse(file.find("KK"));
			assertFalse(file.bof());
			assertTrue(file.eof());
			assertTrue(file.find("Y"));
			assertFalse(file.bof());
			assertFalse(file.eof());
			assertEquals(lines.get(1), file.getCurrent());
			assertFalse(file.findNext("Y"));
			assertFalse(file.bof());
			assertTrue(file.eof());

			assertTrue(file.find("Line"));
			assertFalse(file.bof());
			assertFalse(file.eof());
			assertEquals(lines.get(0), file.getCurrent());
			assertTrue(file.findNext("Line"));
			assertFalse(file.bof());
			assertFalse(file.eof());
			assertEquals(lines.get(1), file.getCurrent());
			assertTrue(file.findNext("Line"));
			assertFalse(file.bof());
			assertFalse(file.eof());
			assertEquals(lines.get(2), file.getCurrent());
			assertTrue(file.findNext("Line"));
			assertFalse(file.bof());
			assertFalse(file.eof());
			assertEquals(lines.get(3), file.getCurrent());
			assertFalse(file.findNext("Line"));
			assertFalse(file.bof());
			assertTrue(file.eof());

		} catch (final Exception e) {
			logger.error(ExceptionUtils.getStackTrace(e));
			fail("Se ha producido un error");
		}
	}

	@Test
	void testFileLines5() {
		try {
			final Path filePath = currentDir.resolve("data/vacio2.txt");
			logger.info("{}", filePath.toAbsolutePath().toString().replace("\\", "\\\\"));
			final FileLines file = new FileLines(filePath);
			assertNotNull(file.getDirectory());
			assertNotNull(file.getName());
			assertNotNull(file.getPath());
			assertFalse(file.isValid());
			assertFalse(file.exists());
			assertEquals(0, file.count());
			assertNull(file.getCurrent());
			assertNull(file.getLines());
			assertTrue(file.bof());
			assertTrue(file.eof());
		} catch (final Exception e) {
			logger.error(ExceptionUtils.getStackTrace(e));
			fail("Se ha producido un error");
		}
	}

	@Test
	void testFileLines6() {
		try {
			final Path filePath = currentDir.resolve("data/ejemplo.txt");
			logger.info("{}", filePath.toAbsolutePath().toString().replace("\\", "\\\\"));
			final FileLines file = new FileLines(filePath.toAbsolutePath().toString());
			assertNotNull(file.getDirectory());
			assertNotNull(file.getName());
			assertNotNull(file.getPath());
			assertTrue(file.isValid());
			assertEquals(6, file.count());
			assertNull(file.getCurrent());
			assertNotNull(file.getLines());
			assertEquals(6, file.getLines().size());
			assertTrue(file.bof());
			assertFalse(file.eof());

			for (final String line : file) {
				logger.info(line);
			}
			assertTrue(file.bof());
			assertFalse(file.eof());

			file.clear();
			assertEquals(0, file.count());
			assertNull(file.getCurrent());
			assertTrue(file.bof());
			assertTrue(file.eof());
			for (final String line : file) {
				logger.info(line);
			}

		} catch (final Exception e) {
			logger.error(ExceptionUtils.getStackTrace(e));
			fail("Se ha producido un error");
		}
	}

}
