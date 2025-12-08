package org.gjs.java.log;

import java.util.Objects;

import org.apache.commons.lang3.exception.ExceptionUtils;
import org.slf4j.Logger;

// TODO: Auto-generated Javadoc
/**
 * The Class LogManager.
 *
 * Clase de datos de la librería Gjs
 *
 * Clase base para incorporar el logger a otras clases que puedan necesitarlo.
 *
 * --------------------------------------------------------------------------------------------------------------------
 *
 *
 *
 *
 *
 *
 *
 * Gj Software
 * 2025
 * 
 *
 * 
 * 
 * --------------------------------------------------------------------------------------------------------------------
 *
 * @author Gjs
 * @version 1.0.0
 * @since 1.0.0
 *
 */
public class LogManager {

	/** The logger. */
	private Logger logger;

	/**
	 * Instantiates a new log manager.
	 */
	public LogManager() {
	}

	/**
	 * Instantiates a new log manager.
	 *
	 * @param logger the logger
	 */
	public LogManager(Logger logger) {
		this.setLogger(logger);
	}

	/**
	 * Gets the logger.
	 *
	 * @return the logger
	 */
	public Logger getLogger() {
		return logger;
	}

	/**
	 * Sets the logger.
	 *
	 * @param logger the new logger
	 */
	public void setLogger(Logger logger) {
		this.logger = logger;
	}

	/**
	 * Info.
	 *
	 * @param message the message
	 */
	public void info(String message) {
		if (Objects.nonNull(logger)) {
			logger.info(message);
		}
	}

	/**
	 * Info.
	 *
	 * @param message the message
	 * @param params  the params
	 */
	public void info(String message, Object... params) {
		if (Objects.nonNull(logger)) {
			logger.info(message, params);
		}
	}

	/**
	 * Debug.
	 *
	 * @param message the message
	 */
	public void debug(String message) {
		if (Objects.nonNull(logger)) {
			logger.debug(message);
		}
	}

	/**
	 * Debug.
	 *
	 * @param message the message
	 * @param params  the params
	 */
	public void debug(String message, Object... params) {
		if (Objects.nonNull(logger)) {
			logger.debug(message, params);
		}
	}

	/**
	 * Warn.
	 *
	 * @param message the message
	 */
	public void warn(String message) {
		if (Objects.nonNull(logger)) {
			logger.warn(message);
		}
	}

	/**
	 * Warn.
	 *
	 * @param message the message
	 * @param params  the params
	 */
	public void warn(String message, Object... params) {
		if (Objects.nonNull(logger)) {
			logger.warn(message, params);
		}
	}

	/**
	 * Error.
	 *
	 * @param message the message
	 */
	public void error(String message) {
		if (Objects.nonNull(logger)) {
			logger.error(message);
		}
	}

	/**
	 * Error.
	 *
	 * @param message the message
	 * @param params  the params
	 */
	public void error(String message, Object... params) {
		if (Objects.nonNull(logger)) {
			logger.error(message, params);
		}
	}

	/**
	 * Error.
	 *
	 * @param message the message
	 * @param e       the e
	 */
	public void error(String message, Exception e) {
		if (Objects.nonNull(logger)) {
			logger.error(message, ExceptionUtils.getStackTrace(e));
		}
	}

	/**
	 * Trace.
	 *
	 * @param message the message
	 */
	public void trace(String message) {
		if (Objects.nonNull(logger)) {
			logger.trace(message);
		}
	}

	/**
	 * Trace.
	 *
	 * @param message the message
	 * @param params  the params
	 */
	public void trace(String message, Object... params) {
		if (Objects.nonNull(logger)) {
			logger.trace(message, params);
		}
	}

}
