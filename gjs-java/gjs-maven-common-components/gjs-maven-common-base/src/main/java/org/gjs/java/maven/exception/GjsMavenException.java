package org.gjs.java.maven.exception;

import org.apache.maven.plugin.MojoExecutionException;

/**
 * The Class GjsMavenException.
 */
public class GjsMavenException extends MojoExecutionException {


	/**
	 * Instantiates a new gjs maven exception.
	 *
	 * @param message the message
	 */
	public GjsMavenException(String message) {
		super(message);
	}

    /**
     * Instantiates a new gjs maven exception.
     *
     * @param message the message
     * @param cause the cause
     */
    public GjsMavenException(String message, Throwable cause) {
        super(message, cause);
    }

    /**
     * Instantiates a new gjs maven exception.
     *
     * @param cause the cause
     */
    public GjsMavenException(Throwable cause) {
        super(cause);
    }

}
