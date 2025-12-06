package org.gjs.java.log;

import java.util.Objects;

import org.apache.commons.lang3.exception.ExceptionUtils;
import org.slf4j.Logger;

/**
 * The Class LogManager.
 *
 * Clase de datos de la librería Semilla
 *
 * Clase base para incorporar el logger a otras clases que puedan necesitarlo.
 *
 * --------------------------------------------------------------------------------------------------------------------
 * Este software es propiedad del Ministerio del Interior CETSE - 2025
 *
 * Queda estrictamente prohibido el uso de programas informáticos sin la
 * correspondiente licencia en los activos de la SES. Los programas informáticos
 * propiedad de la SES están protegidos por la propiedad intelectual, y por
 * tanto está estrictamente prohibida su reproducción, modificación, cesión o
 * comunicación sin la debida autorización. Queda estrictamente prohibido el
 * uso, reproducción, cesión, transformación o comunicación pública de cualquier
 * otro tipo de obra o invención protegida por la propiedad intelectual sin la
 * debida autorización.
 *
 * Subdirección General de Sistemas de la Información y Comunicaciones para la
 * Seguridad Ministerio del Interior Gobierno de España
 * --------------------------------------------------------------------------------------------------------------------
 *
 * @author Semilla
 * @version 4.0.0
 * @since 3.0.0
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
