package org.gjs.java.common.util;

import java.io.File;
import java.util.Objects;

import org.apache.commons.io.FilenameUtils;
import org.gjs.java.common.constant.CommonBaseConstants;

/**
 * The Class FileUtils.
 */
public final class FileUtils {

	/**
	 * Clase no instanciable.
	 */
	private FileUtils() {
		throw new IllegalStateException(CommonBaseConstants.MSG_UTILITY_CLASS);
	}

	/**
	 * Normalize path.
	 *
	 * @param path the path
	 * @return the string
	 */
	public static String normalizePath(String path) {
		String normalized = path;
		if (!org.apache.commons.lang3.StringUtils.isEmpty(path)) {
			String unixPath = FilenameUtils.separatorsToUnix(new File(path).getAbsolutePath());
			String[] parts = unixPath.split(":");
			normalized = parts[parts.length - 1];
			if (normalized.endsWith("/.")) {
				normalized = normalized.substring(0, normalized.length() - 2);
			}
		}
		return normalized;
	}

	/**
	 * Gets the relative path.
	 *
	 * @param absolutePath the absolute path
	 * @return the relative path
	 */
	public static String getRelativePath(String absolutePath) {
		StringBuilder sb = new StringBuilder();
		sb.append('.');
		if (!org.apache.commons.lang3.StringUtils.isEmpty(absolutePath)) {
			File initialPath = new File(absolutePath);
			File currentDir = new File(".").getAbsoluteFile().getParentFile();
			while (Objects.nonNull(currentDir.getParentFile())) {
				sb.append("/..");
				currentDir = currentDir.getParentFile();
			}
			sb.append(normalizePath(initialPath.getAbsolutePath()));
		}
		return sb.toString();
	}
}
