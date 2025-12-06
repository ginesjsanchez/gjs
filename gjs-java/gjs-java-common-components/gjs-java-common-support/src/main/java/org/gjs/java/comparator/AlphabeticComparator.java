package org.gjs.java.comparator;

import java.util.Comparator;
import java.util.Locale;
import java.util.Objects;

import org.apache.commons.lang3.StringUtils;
import org.gjs.java.common.ConditionUtils;

/**
 * The Class AlpahbeticComparator.
 *
 * Clase de datos de la librería Semilla
 *
 * Comparador para ordenar cadena de forma alfabética.
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
public class AlphabeticComparator implements Comparator<String> {

	/*
	 * (non-Javadoc)
	 *
	 * @see java.util.Comparator#compare(java.lang.Object, java.lang.Object)
	 */

	@Override
	public int compare(String o1, String o2) {
		int res = 0;
		if (ConditionUtils.oneIsTrue(Objects.nonNull(o1), Objects.nonNull(o2))) {
			if (Objects.isNull(o2)) {
				res = 1;
			} else if (Objects.isNull(o1)) {
				res = -1;
			} else {
				final String s1 = StringUtils.stripAccents(o1.toUpperCase(Locale.getDefault()));
				final String s2 = StringUtils.stripAccents(o2.toUpperCase(Locale.getDefault()));
				res = characterStringCompare(s1, s2);
			}
		}
		return res;
	}

	/**
	 * Character string compare.
	 *
	 * @param s1 the s 1
	 * @param s2 the s 2
	 * @return the int
	 */
	private int characterStringCompare(String s1, String s2) {
		int res = 0;
		final int min = Integer.min(s1.length(), s2.length());
		for (int i = 0; i < min; i = i + 1) {
			res = Character.compare(s1.charAt(i), s2.charAt(i));
			if (res != 0) {
				break;
			}
		}
		if (res == 0) {
			if (s1.length() > min) {
				res = 1;
			} else if (s2.length() > min) {
				res = -1;
			}
		}
		return res;
	}

}
