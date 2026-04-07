package org.gjs.java.maven.common;

import java.util.List;

import org.apache.maven.plugins.annotations.Parameter;
import org.codehaus.plexus.util.DirectoryScanner;

public abstract class GjaAbstractFileSelectionMojo extends GjsAbstractMojo {

	@Parameter
	private List<String> includes;

	@Parameter
	private List<String> excludes;

	@Parameter(defaultValue = "true")
	private boolean includeBaseDirectory;

	protected String[] includedFiles;

	@Override
	protected void additionalInitializations() {
		DirectoryScanner scanner = new DirectoryScanner();
		scanner.setBasedir(baseDirectory);

		if (includes != null && !includes.isEmpty()) {
			scanner.setIncludes(includes.toArray(new String[0]));
		} else {
			scanner.setIncludes(new String[] { "**/**" });
		}

		if (excludes != null && !excludes.isEmpty()) {
			scanner.setExcludes(excludes.toArray(new String[0]));
		}

		scanner.addDefaultExcludes();
		scanner.scan();

		includedFiles = scanner.getIncludedFiles();
	}

}
