package org.gjs.java.util;

import java.io.IOException;
import java.util.Locale;
import java.util.Objects;

import org.apache.commons.lang3.ObjectUtils;
import org.apache.commons.lang3.StringUtils;
import org.gjs.java.constant.CommonBaseConstants;
import org.springframework.core.io.ClassPathResource;

/**
 * The Class ResourceUtil.
 *
 * Clase de utilidades generales de la librería Semilla
 *
 * Algunas funciones de ayuda para localizar ficheros de recursos multi-idioma
 * de maneras transparente.
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
public final class ResourceUtils {

	/** The Constant RESOURCE_PATH_FORMAT. */
	private static final String RESOURCE_PATH_FORMAT = "%s/%s.%s";

	/** The Constant RESOURCE_NAME_FORMAT. */
	private static final String RESOURCE_NAME_FORMAT = "%s-%s";

	/**
	 * Clase no instanciable.
	 */
	private ResourceUtils() {
		throw new IllegalStateException(CommonBaseConstants.MSG_UTILITY_CLASS);
	}

	/**
	 * Gets the resource path.
	 *
	 * @param kind the kind
	 * @param name the name
	 * @param type the type
	 * @return the resource path
	 */
	public static String getResourcePath(String kind, String name, String type) {
		return getResourcePath(kind, name, type, null);
	}

	/**
	 * Gets the resource path.
	 *
	 * @param kind   the kind
	 * @param name   the name
	 * @param type   the type
	 * @param locale the locale
	 * @return the resource path
	 */
	public static String getResourcePath(String kind, String name, String type, Locale locale) {
		return getResourcePath(kind, name, type, locale, null);
	}

	/**
	 * Gets the resource path.
	 *
	 * @param kind    the kind
	 * @param name    the name
	 * @param type    the type
	 * @param locale  the locale
	 * @param profile the profile
	 * @return the resource path
	 */
	public static String getResourcePath(String kind, String name, String type, Locale locale, String profile) {
		String path = null;
		if (ObjectUtils.allNotNull(kind, name, type)) {
			if (!isDefaultLocale(locale)) {
				name = String.format(RESOURCE_NAME_FORMAT, name, locale.toString());
			}
			if (Objects.nonNull(profile)) {
				name = String.format(RESOURCE_NAME_FORMAT, name, profile);
			}
			path = String.format(RESOURCE_PATH_FORMAT, kind, name, type);
		}
		return path;
	}

	/**
	 * Exists resource.
	 *
	 * @param path the path
	 * @return true, if successful
	 */
	public static boolean existsResource(String path) {
		boolean res = false;
		if (!StringUtils.isAllBlank(path)) {
			try {
				res = new ClassPathResource(path).getFile().exists();
			} catch (final IOException e) {
				// Nada
			}
		}
		return res;
	}

	/**
	 * First existing resource.
	 *
	 * @param paths the paths
	 * @return the string
	 */
	public static String firstExistingResource(String... paths) {
		String res = null;
		for (final String path : paths) {
			if (existsResource(path)) {
				res = path;
				break;
			}
		}
		return res;
	}

	/**
	 * Checks if is default locale.
	 *
	 * @param locale the locale
	 * @return true, if is default locale
	 */
	private static boolean isDefaultLocale(Locale locale) {
		boolean res = true;
		if (Objects.nonNull(locale)) {
			res = CommonBaseConstants.DEFAULT_LOCALE.equals(locale);
			if (ConditionUtils.allAreTrue(!res, StringUtils.isEmpty(locale.getCountry()))) {
				res = CommonBaseConstants.DEFAULT_LOCALE.getLanguage().equals(locale.getLanguage());
			}
		}
		return res;
	}
}
