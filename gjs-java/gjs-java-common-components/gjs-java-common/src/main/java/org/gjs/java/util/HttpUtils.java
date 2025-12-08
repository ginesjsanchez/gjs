package org.gjs.java.util;

import java.util.Objects;

import org.apache.commons.lang3.StringUtils;
import org.gjs.java.constant.CommonBaseConstants;

/**
 * The Class NormalizationUtil.
 *
 * Clase de utilidades generales de la librería Semilla
 *
 * Funciones auxiliares de formateo de diferentes tipos de datos.
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
public final class HttpUtils {

	/**
	 * Clase no instanciable.
	 */
	private HttpUtils() {
		throw new IllegalStateException(CommonBaseConstants.MSG_UTILITY_CLASS);
	}

	/**
	 * Format endpoint.
	 *
	 * @param endpoint    the endpoint
	 * @param projectName the project name
	 * @return the string
	 */
	public static String formatEndpoint(String endpoint, String projectName) {
		String formatted = endpoint;
		if (Objects.nonNull(formatted)) {
			formatted = formatted.replace("{", "").replace("}", "").replace(".html", "");
			if (!formatted.startsWith("/")) {
				formatted = String.format("/%s", formatted);
			}
			if (!StringUtils.isAllBlank(projectName)) {
				final String prefix = String.format("/%s", projectName);
				if (!formatted.startsWith(prefix)) {
					formatted = String.format("%s%s", prefix, formatted);
				}
			}
		}
		return formatted;
	}

}
