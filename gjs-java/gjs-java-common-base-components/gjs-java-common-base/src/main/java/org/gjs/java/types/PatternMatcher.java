package org.gjs.java.types;

import java.util.regex.Pattern;

import org.apache.commons.lang3.ObjectUtils;
import org.gjs.java.constant.CommonBaseConstants;

/**
 * The Class PatternMatcher.
 *
 * Clase de utilidades generales de la librería Semilla
 *
 * Algunas funciones de ayuda para el uso de expresiones regulares.
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
public final class PatternMatcher {

	/** The Constant EMAIL_PATTERN. */
	/* The RFC 5322 official e-mail pattern */
	private static final String EMAIL_PATTERN = "^[a-zA-Z0-9_!#$%&'*+/=?`{|}~^.-]+@[a-zA-Z0-9.-]+$";

	/**
	 * Clase no instanciable.
	 */
	private PatternMatcher() {
		throw new IllegalStateException(CommonBaseConstants.MSG_UTILITY_CLASS);
	}

	/**
	 * Pattern matches.
	 *
	 * @param value        the value
	 * @param regexPattern the regex pattern
	 * @return true, if successful
	 */
	public static boolean patternMatches(String value, String regexPattern) {
		boolean res = false;
		if (ObjectUtils.allNotNull(value, regexPattern)) {
			res = Pattern.compile(regexPattern).matcher(value).matches();
		}
		return res;
	}

	/**
	 * Checks if is valid email.
	 *
	 * @param value the value
	 * @return true, if is valid email
	 */
	public static boolean isValidEmail(String value) {
		return patternMatches(value, EMAIL_PATTERN);
	}
}
