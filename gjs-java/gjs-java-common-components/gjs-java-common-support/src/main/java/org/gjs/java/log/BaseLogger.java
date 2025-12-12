package org.gjs.java.log;

import org.apache.commons.lang3.exception.ExceptionUtils;
import org.gjs.java.util.LogUtils;
import org.slf4j.Logger;
import org.slf4j.LoggerFactory;

import ch.qos.logback.classic.Level;

/**
 * The Class BaseLogger.
 *
 * Clase abstracta de datos de la librería Semilla
 *
 * Clase pensada para ser extendida por todas aquellas clases que necesiten
 * funcionalidad de logger. Todo y que el desarrollador puede usar el logger
 * librermente, se ofrecen funciones que formatean el registro en el log
 * siguiendo el estándar definido por la arquitectura de Semilla.
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
public class BaseLogger {

	/**
	 * The logger.
	 *
	 */
	protected final Logger logger = LoggerFactory.getLogger(getClass());

	/**
	 * Log.
	 *
	 * @param level  the level
	 * @param method the method
	 * @param infos  the infos
	 */
	protected void log(Level level, String method, Object... infos) {
		LogUtils.log(level, getClass().getCanonicalName(), method, infos);
	}

	/**
	 * Log info.
	 *
	 * @param method the method
	 * @param infos  the infos
	 */
	protected void logInfo(String method, Object... infos) {
		LogUtils.logInfo(getClass().getCanonicalName(), method, infos);
	}

	/**
	 * Log debug.
	 *
	 * @param method the method
	 * @param infos  the infos
	 */
	protected void logDebug(String method, Object... infos) {
		LogUtils.logDebug(getClass().getCanonicalName(), method, infos);
	}

	/**
	 * Log trace.
	 *
	 * @param method the method
	 * @param infos  the infos
	 */
	protected void logTrace(String method, Object... infos) {
		LogUtils.logTrace(getClass().getCanonicalName(), method, infos);
	}

	/**
	 * Log error.
	 *
	 * @param method the method
	 * @param infos  the infos
	 */
	protected void logError(String method, Object... infos) {
		LogUtils.logError(getClass().getCanonicalName(), method, infos);
	}

	/**
	 * Log error.
	 *
	 * @param method the method
	 * @param e      the e
	 */
	protected void logError(String method, Exception e) {
		LogUtils.logError(getClass().getCanonicalName(), method, ExceptionUtils.getStackTrace(e));
	}

	/**
	 * Log controlled error.
	 *
	 * @param method the method
	 * @param e      the e
	 */
	protected void logControlledError(String method, Exception e) {
		LogUtils.logError(getClass().getCanonicalName(), method, e.getMessage());
	}

	/**
	 * Log warn.
	 *
	 * @param method the method
	 * @param infos  the infos
	 */
	protected void logWarn(String method, Object... infos) {
		LogUtils.logWarn(getClass().getCanonicalName(), method, infos);
	}

	/**
	 * Log formatted.
	 *
	 * @param level  the level
	 * @param method the method
	 * @param format the format
	 * @param param  the param
	 */
	protected void logFormatted(Level level, String method, String format, Object... param) {
		LogUtils.logFormatted(level, getClass().getCanonicalName(), method, format, param);
	}

	/**
	 * Log formatted info.
	 *
	 * @param method the method
	 * @param format the format
	 * @param param  the param
	 */
	protected void logFormattedInfo(String method, String format, Object... param) {
		LogUtils.logFormattedInfo(getClass().getCanonicalName(), method, format, param);
	}

	/**
	 * Log formatted debug.
	 *
	 * @param method the method
	 * @param format the format
	 * @param param  the param
	 */
	protected void logFormattedDebug(String method, String format, Object... param) {
		LogUtils.logFormattedDebug(getClass().getCanonicalName(), method, format, param);
	}

	/**
	 * Log formatted trace.
	 *
	 * @param method the method
	 * @param format the format
	 * @param param  the param
	 */
	protected void logFormattedTrace(String method, String format, Object... param) {
		LogUtils.logFormattedTrace(getClass().getCanonicalName(), method, format, param);
	}

	/**
	 * Log formatted error.
	 *
	 * @param method the method
	 * @param format the format
	 * @param param  the param
	 */
	protected void logFormattedError(String method, String format, Object... param) {
		LogUtils.logFormattedError(getClass().getCanonicalName(), method, format, param);
	}

	/**
	 * Log formatted warn.
	 *
	 * @param method the method
	 * @param format the format
	 * @param param  the param
	 */
	protected void logFormattedWarn(String method, String format, Object... param) {
		LogUtils.logFormattedWarn(getClass().getCanonicalName(), method, format, param);
	}

}
