package org.gjs.java.singleton;

import java.util.Locale;
import java.util.concurrent.locks.Lock;
import java.util.concurrent.locks.ReentrantLock;

import org.apache.commons.lang3.StringUtils;
import org.apache.commons.lang3.exception.ExceptionUtils;
import org.gjs.java.constant.CommonBaseConstants;
import org.gjs.java.exception.GjsException;
import org.gjs.java.types.BundleManager;
import org.gjs.java.util.BundleUtils;
import org.slf4j.Logger;
import org.slf4j.LoggerFactory;

/**
 * The Class GlobalBundleManager.
 *
 * Clase global singleton de la librería Semilla
 *
 * Clase singleton destinada a gestionar todos los bundle de literales de la
 * librería y la aplicación de forma conjunta. Los bundles se separan en
 * literales o mensajes generales y catalogo de errores.Está preparado para
 * multi-idioma. Los literale sse buscan primero en los bundle de la aplicación
 * y luego en los de Semilla de forma que en la aoplicación se podrían
 * sobrescribir los de Semilla.
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
public final class GlobalBundleManager {

	/** The Constant logger. */
	private static final Logger logger = LoggerFactory.getLogger(GlobalBundleManager.class);

	/** The class lock. */
	private static final Lock CLASS_LOCK = new ReentrantLock();

	/** The instance. */
	private static GlobalBundleManager instance;

	/** The message manager. */
	private BundleManager messageManager;

	/** The error manager. */
	private BundleManager errorManager;

	/**
	 * Instantiates a new global bundle manager.
	 *
	 * @throws GjsException the semilla util exception
	 */
	public GlobalBundleManager() throws GjsException {
		try {
			errorManager = new BundleManager();
			messageManager = new BundleManager();
			errorManager.addBundle(BundleUtils.ERROR_BUNDLE);
			messageManager.addBundle(BundleUtils.MESSAGE_BUNDLE);
		} catch (final Exception e) {
			throw new GjsException("No se ha podido inicializar el GlobalBundleManager", e);
		}
	}

	/**
	 * Gets the single instance of GlobalBundleManager.
	 *
	 * @return single instance of GlobalBundleManager
	 * @throws GjsException the semilla util exception
	 */
	public static GlobalBundleManager getInstance() throws GjsException {
		try {
			CLASS_LOCK.lock();
			if (instance == null) {
				instance = new GlobalBundleManager();
			}
		} finally {
			CLASS_LOCK.unlock();
		}
		return instance;
	}

	/**
	 * Adds the message bundle.
	 *
	 * @param bundle the bundle
	 */
	public void addMessageBundle(String bundle) {
		messageManager.addBundle(bundle);
	}

	/**
	 * Adds the error bundle.
	 *
	 * @param bundle the bundle
	 */
	public void addErrorBundle(String bundle) {
		errorManager.addBundle(bundle);
	}

	/**
	 * Gets the message.
	 *
	 * @param key the key
	 * @return the message
	 */
	public String getMessage(String key) {
		try {
			CLASS_LOCK.lock();
			return messageManager.getMessage(key);
		} finally {
			CLASS_LOCK.unlock();
		}
	}

	/**
	 * Gets the error message.
	 *
	 * @param key the key
	 * @return the error message
	 */
	public String getErrorMessage(String key) {
		try {
			CLASS_LOCK.lock();
			return errorManager.getMessage(key);
		} finally {
			CLASS_LOCK.unlock();
		}
	}

	/**
	 * Gets the message.
	 *
	 * @param key    the key
	 * @param params the params
	 * @return the message
	 */
	public String getMessage(String key, Object... params) {
		try {
			CLASS_LOCK.lock();
			return messageManager.getMessage(key, params);
		} finally {
			CLASS_LOCK.unlock();
		}
	}

	/**
	 * Gets the error message.
	 *
	 * @param key    the key
	 * @param params the params
	 * @return the error message
	 */
	public String getErrorMessage(String key, Object... params) {
		try {
			CLASS_LOCK.lock();
			return errorManager.getMessage(key, params);
		} finally {
			CLASS_LOCK.unlock();
		}
	}

	/**
	 * Gets the safety error message.
	 *
	 * @param key the key
	 * @return the safety error message
	 */
	public static String getSafetyErrorMessage(String key) {
		String message = null;
		try {
			message = getInstance().getErrorMessage(key);
		} catch (final GjsException e) {
			logger.warn(ExceptionUtils.getStackTrace(e));
		}
		if (StringUtils.isAllBlank(message)) {
			message = CommonBaseConstants.MSG_UNKNOWN_ERROR;
		}
		return message;
	}

	/**
	 * Gets the safety message.
	 *
	 * @param key    the key
	 * @param params the params
	 * @return the safety message
	 */
	public static String getSafetyMessage(String key, Object... params) {
		String message = null;
		try {
			message = getInstance().getMessage(key, params);
		} catch (final GjsException e) {
			logger.warn(ExceptionUtils.getStackTrace(e));
		}
		if (StringUtils.isAllBlank(message)) {
			message = CommonBaseConstants.MSG_UNKNOWN_ERROR;
		}
		return message;
	}

	/**
	 * Gets the safety message.
	 *
	 * @param key the key
	 * @return the safety message
	 */
	public static String getSafetyMessage(String key) {
		String message = null;
		try {
			message = getInstance().getMessage(key);
		} catch (final GjsException e) {
			logger.warn(ExceptionUtils.getStackTrace(e));
		}
		if (StringUtils.isAllBlank(message)) {
			message = CommonBaseConstants.MSG_UNKNOWN_ERROR;
		}
		return message;
	}

	/**
	 * Gets the safety error message.
	 *
	 * @param key    the key
	 * @param params the params
	 * @return the safety error message
	 */
	public static String getSafetyErrorMessage(String key, Object... params) {
		String message = null;
		try {
			message = getInstance().getErrorMessage(key, params);
		} catch (final GjsException e) {
			logger.warn(ExceptionUtils.getStackTrace(e));
		}
		if (StringUtils.isAllBlank(message)) {
			message = CommonBaseConstants.MSG_UNKNOWN_ERROR;
		}
		return message;
	}

	/**
	 * Gets the message.
	 *
	 * @param locale the locale
	 * @param key    the key
	 * @return the message
	 */
	public String getMessage(Locale locale, String key) {
		try {
			CLASS_LOCK.lock();
			return messageManager.getMessage(locale, key);
		} finally {
			CLASS_LOCK.unlock();
		}
	}

	/**
	 * Gets the error message.
	 *
	 * @param locale the locale
	 * @param key    the key
	 * @return the error message
	 */
	public String getErrorMessage(Locale locale, String key) {
		try {
			CLASS_LOCK.lock();
			return errorManager.getMessage(locale, key);
		} finally {
			CLASS_LOCK.unlock();
		}
	}

	/**
	 * Gets the message.
	 *
	 * @param locale the locale
	 * @param key    the key
	 * @param params the params
	 * @return the message
	 */
	public String getMessage(Locale locale, String key, Object... params) {
		try {
			CLASS_LOCK.lock();
			return messageManager.getMessage(locale, key, params);
		} finally {
			CLASS_LOCK.unlock();
		}
	}

	/**
	 * Gets the error message.
	 *
	 * @param locale the locale
	 * @param key    the key
	 * @param params the params
	 * @return the error message
	 */
	public String getErrorMessage(Locale locale, String key, Object... params) {
		try {
			CLASS_LOCK.lock();
			return errorManager.getMessage(locale, key, params);
		} finally {
			CLASS_LOCK.unlock();
		}
	}

	/**
	 * Gets the safety message.
	 *
	 * @param locale the locale
	 * @param key    the key
	 * @return the safety error message
	 */
	public static String getSafetyMessage(Locale locale, String key) {
		String message = null;
		try {
			message = getInstance().getMessage(locale, key);
		} catch (final GjsException e) {
			logger.warn(ExceptionUtils.getStackTrace(e));
		}
		if (StringUtils.isAllBlank(message)) {
			message = CommonBaseConstants.MSG_UNKNOWN_ERROR;
		}
		return message;
	}

	/**
	 * Gets the safety message.
	 *
	 * @param locale the locale
	 * @param key    the key
	 * @param params the params
	 * @return the safety error message
	 */
	public static String getSafetyMessage(Locale locale, String key, Object... params) {
		String message = null;
		try {
			message = getInstance().getMessage(locale, key, params);
		} catch (final GjsException e) {
			logger.warn(ExceptionUtils.getStackTrace(e));
		}
		if (StringUtils.isAllBlank(message)) {
			message = CommonBaseConstants.MSG_UNKNOWN_ERROR;
		}
		return message;
	}

	/**
	 * Gets the safety error message.
	 *
	 * @param locale the locale
	 * @param key    the key
	 * @return the safety error message
	 */
	public static String getSafetyErrorMessage(Locale locale, String key) {
		String message = null;
		try {
			message = getInstance().getErrorMessage(locale, key);
		} catch (final GjsException e) {
			logger.warn(ExceptionUtils.getStackTrace(e));
		}
		if (StringUtils.isAllBlank(message)) {
			message = CommonBaseConstants.MSG_UNKNOWN_ERROR;
		}
		return message;
	}

	/**
	 * Gets the safety error message.
	 *
	 * @param locale the locale
	 * @param key    the key
	 * @param params the params
	 * @return the safety error message
	 */
	public static String getSafetyErrorMessage(Locale locale, String key, Object... params) {
		String message = null;
		try {
			message = getInstance().getErrorMessage(locale, key, params);
		} catch (final GjsException e) {
			logger.warn(ExceptionUtils.getStackTrace(e));
		}
		if (StringUtils.isAllBlank(message)) {
			message = CommonBaseConstants.MSG_UNKNOWN_ERROR;
		}
		return message;
	}

}
