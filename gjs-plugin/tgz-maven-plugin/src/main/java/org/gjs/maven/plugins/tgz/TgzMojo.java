package org.gjs.maven.plugins.tgz;

import java.io.File;
import java.io.FileOutputStream;
import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Path;
import java.util.List;

import org.apache.commons.compress.archivers.tar.TarArchiveEntry;
import org.apache.commons.compress.archivers.tar.TarArchiveOutputStream;
import org.apache.commons.compress.compressors.gzip.GzipCompressorOutputStream;
import org.apache.maven.plugin.logging.Log;
import org.apache.maven.plugins.annotations.LifecyclePhase;
import org.apache.maven.plugins.annotations.Mojo;
import org.apache.maven.plugins.annotations.Parameter;
import org.gjs.java.maven.common.GjsAbstractMojo;

/**
 * This goal executes the defined enforcer-rules once per module.
 */
@Mojo(name = "tgz-package", defaultPhase = LifecyclePhase.PACKAGE, threadSafe = true)
public class TgzMojo extends GjsAbstractMojo {

	/** Flag to easily skip all checks. */
	@Parameter(property = "tgz.skip", defaultValue = "false")
	private boolean skip = false;

	/**
	 * Flag to fail the build if at least one check fails.
	 */
	@Parameter(property = "tgz.fail", defaultValue = "true")
	private boolean fail = true;

	@Parameter
	private List<String> includes;

	@Parameter
	private List<String> excludes;

	@Parameter(defaultValue = "true")
	private boolean includeBaseDirectory;

	@Override
	protected String getGoalName() {
		return "tgz-package";
	}

	@Override
	protected boolean getSkip() {
		return skip;
	}

	@Override
	protected boolean getFail() {
		return fail;
	}

	@Override
	protected void goalExecution(Log log, List<String> arg0) {
		File outputFile = new File(outputDirectory, finalName + ".tar.gz");

		log.info("Creando TGZ: " + outputFile);

		try (FileOutputStream fos = new FileOutputStream(outputFile);
				GzipCompressorOutputStream gzipOut = new GzipCompressorOutputStream(fos);
				TarArchiveOutputStream tarOut = new TarArchiveOutputStream(gzipOut)) {
			tarOut.setLongFileMode(TarArchiveOutputStream.LONGFILE_GNU);

			Path basePath = baseDirectory.toPath();

			Files.walk(basePath).filter(Files::isRegularFile).forEach(path -> {
				try {
					Path relativePath = basePath.relativize(path);

					String entryName = includeBaseDirectory ? baseDirectory.getName() + "/" + relativePath
							: relativePath.toString();

					TarArchiveEntry entry = new TarArchiveEntry(path.toFile(), entryName);

					tarOut.putArchiveEntry(entry);
					Files.copy(path, tarOut);
					tarOut.closeArchiveEntry();

				} catch (IOException e) {
					throw new RuntimeException(e);
				}
			});

		} catch (Exception e) {
			throw new RuntimeException("Error creando TGZ", e);
		}
	}
}
