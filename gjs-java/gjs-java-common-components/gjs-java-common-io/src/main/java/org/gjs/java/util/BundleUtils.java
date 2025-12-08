package org.gjs.java.util;

import java.text.MessageFormat;
import java.util.MissingResourceException;
import java.util.Objects;
import java.util.ResourceBundle;

import org.apache.commons.lang3.ObjectUtils;
import org.apache.commons.lang3.StringUtils;
import org.gjs.java.constant.CommonBaseConstants;
import org.gjs.java.constant.CommonIoConstants;
import org.gjs.java.exception.GjsException;
import org.gjs.java.singleton.GlobalBundleManager;
import org.slf4j.Logger;
import org.slf4j.LoggerFactory;

/**
 * The Class BundleUtil.
 *
 * Clase de utilidades generales de la librería Semilla
 *
 * Funcionalidad de manejo de ficheros bundle de literales multi-idioma.
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
public final class BundleUtils {

	/** The logger. */
	private static Logger logger = LoggerFactory.getLogger(BundleUtils.class);

	/** The Constant BUNDLE_MSG. */
	public static final ResourceBundle MESSAGE_BUNDLE = ResourceBundle
			.getBundle(CommonIoConstants.BUNDLE_LITERALS_NAME);

	/** The Constant ERROR_BUNDLE. */
	public static final ResourceBundle ERROR_BUNDLE = ResourceBundle.getBundle(CommonIoConstants.BUNDLE_ERRORS_NAME);

	/**
	 * Clase no instanciable.
	 */
	private BundleUtils() {
		throw new IllegalStateException(CommonBaseConstants.MSG_UTILITY_CLASS);
	}

	/**
	 * Gets the locale part.
	 *
	 * @param bundleName the bundle name
	 * @return the locale part
	 */
	public static String getLocalePart(String bundleName) {
		String locale = null;
		if (!StringUtils.isAllBlank(bundleName)) {
			final String[] parts = bundleName.split("-");
			if (parts.length > 1) {
				locale = parts[parts.length - 1];
			}
		}
		return locale;
	}

	/**
	 * Gets the message.
	 *
	 * @param key the key
	 * @return the message
	 */
	public static String getMessage(String key) {
		String message = null;
		try {
			message = GlobalBundleManager.getInstance().getMessage(key);
		} catch (final GjsException e) {
			logger.error(org.apache.commons.lang3.exception.ExceptionUtils.getStackTrace(e));
		}
		return Objects.requireNonNullElse(message, String.format("!%s!", key));
	}

	/**
	 * Gets the error message.
	 *
	 * @param key the key
	 * @return the message
	 */
	public static String getErrorMessage(String key) {
		String message = null;
		try {
			message = GlobalBundleManager.getInstance().getErrorMessage(key);
		} catch (final GjsException e) {
			logger.error(org.apache.commons.lang3.exception.ExceptionUtils.getStackTrace(e));
		}
		return Objects.requireNonNullElse(message, String.format("!%s!", key));
	}

	/**
	 * Gets the message.
	 *
	 * @param key    the key
	 * @param params the params
	 * @return the message
	 */
	public static String getMessage(String key, Object... params) {
		String message = null;
		try {
			message = GlobalBundleManager.getInstance().getMessage(key, params);
		} catch (final GjsException e) {
			logger.error(org.apache.commons.lang3.exception.ExceptionUtils.getStackTrace(e));
		}
		return Objects.requireNonNullElse(message, String.format("!%s!", key));
	}

	/**
	 * Gets the error message.
	 *
	 * @param key    the key
	 * @param params the params
	 * @return the erorr message
	 */
	public static String getErrorMessage(String key, Object... params) {
		String message = null;
		try {
			message = GlobalBundleManager.getInstance().getErrorMessage(key, params);
		} catch (final GjsException e) {
			logger.error(org.apache.commons.lang3.exception.ExceptionUtils.getStackTrace(e));
		}
		return Objects.requireNonNullElse(message, String.format("!%s!", key));
	}

	/**
	 * Gets the message.
	 *
	 * @param bundle the bundle
	 * @param key    the key
	 * @return the message
	 */
	public static String getMessage(ResourceBundle bundle, String key) {
		String message = null;

		if (ObjectUtils.allNotNull(bundle, key)) {
			try {
				message = bundle.getString(key);
			} catch (final MissingResourceException e) {
				message = '!' + key + '!';
			}
		} else {
			message = '!' + key + '!';
		}

		return message;
	}

	/**
	 * Gets the message.
	 *
	 * @param bundle the bundle
	 * @param key    the key
	 * @param params the params
	 * @return the message
	 */
	public static String getMessage(ResourceBundle bundle, String key, Object... params) {
		String message;

		if (ObjectUtils.allNotNull(bundle, key)) {
			try {
				message = MessageFormat.format(bundle.getString(key), params);
			} catch (final MissingResourceException e) {
				message = '!' + key + '!';
			}
		} else {
			message = '!' + key + '!';
		}

		return message;
	}

}
