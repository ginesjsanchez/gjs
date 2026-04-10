package org.gjs.maven.plugins.pyz;

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
@Mojo(name = "pyz-package", defaultPhase = LifecyclePhase.PACKAGE, threadSafe = true)
public class PyzMojo extends GjsAbstractMojo {

	/** Flag to easily skip all checks. */
	@Parameter(property = "pyz.skip", defaultValue = "false")
	private boolean skip = false;

	/**
	 * Flag to fail the build if at least one check fails.
	 */
	@Parameter(property = "pyz.fail", defaultValue = "true")
	private boolean fail = true;

	@Parameter
	private List<String> includes;

	@Parameter
	private List<String> excludes;

	@Parameter(defaultValue = "true")
	private boolean includeBaseDirectory;

	@Override
	protected String getGoalName() {
		return "pyz-package";
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
		// TODO
	}
}
