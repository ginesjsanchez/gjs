package org.gjs.java.files;

import static org.junit.jupiter.api.Assertions.assertFalse;
import static org.junit.jupiter.api.Assertions.assertNotNull;
import static org.junit.jupiter.api.Assertions.assertNull;
import static org.junit.jupiter.api.Assertions.assertTrue;
import static org.junit.jupiter.api.Assertions.fail;

import java.io.File;
import java.nio.file.Path;

import org.apache.commons.lang3.exception.ExceptionUtils;
import org.gjs.java.test.BaseUnitTest;
import org.junit.jupiter.api.Test;

public class FilePlainTest extends BaseUnitTest<FilePlain> {

	private static class FileSample extends FilePlain {

		public FileSample() {
		}

		public FileSample(String path) {
			super(path);
		}

		public FileSample(String directory, String file) {
			super(directory, file);
		}

		public FileSample(File file) {
			super(file);
		}

		public FileSample(Path path) {
			super(path);
		}

		@Override
		protected void init() {
		}

		@Override
		protected boolean loadContent(String path) {
			return true;
		}

		@Override
		protected boolean saveContent(String path) {
			return true;
		}

	}

	@Test
	void testFilePlain1() {
		try {
			final Path filePath = currentDir.resolve("data/ejemplo.txt");
			logger.info("{}", filePath.toAbsolutePath().toString().replace("\\", "\\\\"));
			final FilePlain file = new FileSample();
			assertNull(file.getDirectory());
			assertNull(file.getName());
			assertNull(file.getPath());
			assertFalse(file.isValid());
			file.setPath(filePath.toAbsolutePath().toString().replace("\\", "\\\\"));
			assertNotNull(file.getDirectory());
			assertNotNull(file.getName());
			assertNotNull(file.getPath());
			assertTrue(file.isValid());
			logger.info("Directory: {}", file.getDirectory());
			logger.info("Name     : {}", file.getName());
			logger.info("Path     : {}", file.getPath());

		} catch (final Exception e) {
			logger.error(ExceptionUtils.getStackTrace(e));
			fail("Se ha producido un error");
		}
	}

	@Test
	void testFilePlain2() {
		try {
			final Path fileErr = currentDir.resolve("data/nohalugar.txt");
			final Path filePath = currentDir.resolve("data/ejemplo.txt");
			logger.info("{}", fileErr.toAbsolutePath().toString().replace("\\", "\\\\"));
			logger.info("{}", filePath.toAbsolutePath().toString().replace("\\", "\\\\"));
			FilePlain file = new FileSample(fileErr.toAbsolutePath().toString().replace("\\", "\\\\"));
			assertNotNull(file.getDirectory());
			assertNotNull(file.getName());
			assertNotNull(file.getPath());
			logger.info("Directory: {}", file.getDirectory());
			logger.info("Name : {}", file.getName());
			logger.info("Path : {}", file.getPath());
			assertTrue(file.isValid());
			assertFalse(file.exists());
			file = new FileSample(filePath.toAbsolutePath().getParent().toString().replace("\\", "\\\\"),
					filePath.toAbsolutePath().getFileName().toString());
			assertNotNull(file.getDirectory());
			assertNotNull(file.getName());
			assertNotNull(file.getPath());
			logger.info("Directory: {}", file.getDirectory());
			logger.info("Name : {}", file.getName());
			logger.info("Path : {}", file.getPath());
			assertTrue(file.isValid());
			assertTrue(file.exists());

		} catch (final Exception e) {
			logger.error(ExceptionUtils.getStackTrace(e));
			fail("Se ha producido un error");
		}
	}

	@Test
	void testFilePlain3() {
		try {
			final Path filePath = currentDir.resolve("data/ejemplo.txt");
			logger.info("{}", filePath.toAbsolutePath().toString().replace("\\", "\\\\"));
			final FilePlain file = new FileSample(filePath.toFile());
			assertNotNull(file.getDirectory());
			assertNotNull(file.getName());
			assertNotNull(file.getPath());
			assertTrue(file.isValid());
			logger.info("Directory: {}", file.getDirectory());
			logger.info("Name     : {}", file.getName());
			logger.info("Path     : {}", file.getPath());
			file.clear();
			assertNotNull(file.getDirectory());
			assertNotNull(file.getName());
			assertNotNull(file.getPath());
			assertTrue(file.isValid());
			assertTrue(file.load());
			assertTrue(file.save());
			file.newFile();
			assertNotNull(file.getDirectory());
			assertNotNull(file.getName());
			assertNotNull(file.getPath());
			assertTrue(file.isValid());

		} catch (final Exception e) {
			logger.error(ExceptionUtils.getStackTrace(e));
			fail("Se ha producido un error");
		}
	}

	@Test
	void testFilePlain4() {
		try {
			final Path filePath = currentDir.resolve("data/ejemplo.txt");
			logger.info("{}", filePath.toAbsolutePath().toString().replace("\\", "\\\\"));
			final FilePlain file = new FileSample(filePath);
			assertNotNull(file.getDirectory());
			assertNotNull(file.getName());
			assertNotNull(file.getPath());
			assertTrue(file.isValid());
			logger.info("Directory: {}", file.getDirectory());
			logger.info("Name     : {}", file.getName());
			logger.info("Path     : {}", file.getPath());
			file.clear();
			assertNotNull(file.getDirectory());
			assertNotNull(file.getName());
			assertNotNull(file.getPath());
			assertTrue(file.isValid());
			assertTrue(file.load());
			assertTrue(file.save());
			file.newFile();
			assertNotNull(file.getDirectory());
			assertNotNull(file.getName());
			assertNotNull(file.getPath());
			assertTrue(file.isValid());

		} catch (final Exception e) {
			logger.error(ExceptionUtils.getStackTrace(e));
			fail("Se ha producido un error");
		}
	}

	@Test
	void testFilePlain5() {
		try {
			final Path filePath = currentDir.resolve("data/noexiste.aye");
			final FilePlain file = new FileSample(filePath);
			assertNotNull(file.getDirectory());
			assertNotNull(file.getName());
			assertNotNull(file.getPath());
			assertTrue(file.isValid());
			assertFalse(file.exists());
		} catch (final Exception e) {
			logger.error(ExceptionUtils.getStackTrace(e));
			fail("Se ha producido un error");
		}
	}

	@Test
	void testFilePlain_Exception1() {
		try {
			final Path filePath = null;
			@SuppressWarnings("unused")
			final FilePlain file = new FileSample(filePath);
			fail("No deberia llegar hasta aqui");

		} catch (final RuntimeException e) {
			assertNotNull(e.getMessage());
			logger.error(e.getMessage());
		} catch (final Exception e) {
			logger.error(ExceptionUtils.getStackTrace(e));
			fail("Se ha producido un error");
		}
	}

	@Test
	void testFilePlain_Exception2() {
		try {
			@SuppressWarnings("unused")
			final FilePlain file = new FileSample("");
			fail("No deberia llegar hasta aqui");

		} catch (final RuntimeException e) {
			assertNotNull(e.getMessage());
			logger.error(e.getMessage());
		} catch (final Exception e) {
			logger.error(ExceptionUtils.getStackTrace(e));
			fail("Se ha producido un error");
		}
	}

	@Test
	void testFilePlain_Exception3() {
		try {
			@SuppressWarnings("unused")
			final FilePlain file = new FileSample("_/·inv \0lido&&/fi??.a*+");
			fail("No deberia llegar hasta aqui");

		} catch (final RuntimeException e) {
			assertNotNull(e.getMessage());
			logger.error(e.getMessage());
		} catch (final Exception e) {
			logger.error(ExceptionUtils.getStackTrace(e));
			fail("Se ha producido un error");
		}
	}

}
