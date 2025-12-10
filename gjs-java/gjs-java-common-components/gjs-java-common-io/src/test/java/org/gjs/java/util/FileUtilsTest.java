package org.gjs.java.util;

import static org.junit.jupiter.api.Assertions.assertEquals;
import static org.junit.jupiter.api.Assertions.assertNotNull;
import static org.junit.jupiter.api.Assertions.assertNull;
import static org.junit.jupiter.api.Assertions.assertTrue;

import java.io.File;

import org.apache.commons.lang3.SystemUtils;
import org.gjs.java.test.BaseUnitTest;
import org.junit.jupiter.api.Test;

class FileUtilsTest extends BaseUnitTest<FileUtils> {

	@Test
	void testNormalizePath1() {
		String path = null;
		String normalized = FileUtils.normalizePath(path);
		assertNull(normalized);
		path = "";
		normalized = FileUtils.normalizePath(path);
		assertNotNull(normalized);
		assertEquals("", normalized);
		path = "/dir1/dir2/file.txt";
		normalized = FileUtils.normalizePath(path);
		assertNotNull(normalized);
		assertEquals("/dir1/dir2/file.txt", normalized);
		path = "/dir1/dir2";
		normalized = FileUtils.normalizePath(path);
		assertNotNull(normalized);
		assertEquals("/dir1/dir2", normalized);
		path = "/dir1/dir2/.";
		normalized = FileUtils.normalizePath(path);
		assertNotNull(normalized);
		assertEquals("/dir1/dir2", normalized);
		path = "C:\\dir1\\dir2\\file.txt";
		normalized = FileUtils.normalizePath(path);
		assertNotNull(normalized);
		assertEquals("/dir1/dir2/file.txt", normalized);
		path = "C:\\dir1\\dir2";
		normalized = FileUtils.normalizePath(path);
		assertNotNull(normalized);
		assertEquals("/dir1/dir2", normalized);
		path = "C:\\dir1\\dir2\\.";
		normalized = FileUtils.normalizePath(path);
		assertNotNull(normalized);
		assertEquals("/dir1/dir2", normalized);
	}

	@Test
	void testGetRelativePath1() {
		String path = null;
		String normalized = FileUtils.getRelativePath(path);
		assertNotNull(normalized);
		assertEquals(".", normalized);
		path = "";
		normalized = FileUtils.getRelativePath(path);
		assertNotNull(normalized);
		assertEquals(".", normalized);
		String endExpected;
		if (SystemUtils.IS_OS_WINDOWS) {
			path = "C:\\Program Files";
			endExpected = "/Program Files";
		} else {
			path = "/usr";
			endExpected = path;
		}
		normalized = FileUtils.getRelativePath(path);
		File currentDir = new File(".").getAbsoluteFile();
		logger.info("CURRENT {}", currentDir);
		logger.info("PATH {} TO {}", path, normalized);
		assertNotNull(normalized);
		assertTrue(normalized.startsWith("./.."));
		assertTrue(normalized.endsWith(endExpected));
		String normalizedAux = FileUtils.getRelativePath(path + File.separator + ".");
		assertNotNull(normalizedAux);
		assertEquals(normalized, normalizedAux);
	}

}
