package org.gjs.java.util;

import java.util.Objects;

import org.gjs.java.constant.CommonBaseConstants;

/**
 * The Class ExceptionUtil.
 *
 * Clase de utilidades generales de la librería Semilla
 *
 * Funciones de ayuda para el tratamiento de excepciones.
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
public final class ExceptionUtils {

	/**
	 * Clase no instanciable.
	 */
	private ExceptionUtils() {
		throw new IllegalStateException(CommonBaseConstants.MSG_UTILITY_CLASS);
	}

	/**
	 * Find cause of class.
	 *
	 * @param ex    the ex
	 * @param clazz the clazz
	 * @return the exception
	 */
	public static Exception findCauseOfClass(Exception ex, Class<?> clazz) {
		Exception cause = null;
		Throwable ex1 = ex;
		while (Objects.nonNull(ex1)) {
			if (ex1.getClass().getCanonicalName().equals(clazz.getCanonicalName())) {
				cause = (Exception) ex1;
				break;

			}
			ex1 = ex1.getCause();
		}
		return cause;
	}
}
