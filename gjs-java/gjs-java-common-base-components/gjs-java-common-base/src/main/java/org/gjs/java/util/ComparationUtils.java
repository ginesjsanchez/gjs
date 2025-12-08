package org.gjs.java.util;

import java.math.BigInteger;
import java.text.Collator;
import java.util.Date;
import java.util.Objects;
import java.util.Set;

import org.apache.commons.lang3.ObjectUtils;
import org.gjs.java.constant.CommonBaseConstants;

/**
 * The Class ComparationUtil.
 *
 * Clase de utilidades generales de la librería Semilla
 *
 * Algunas funciones de ayuda para implementar compareTo y equals.
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
public final class ComparationUtils {

	/**
	 * Clase no instanciable.
	 */
	private ComparationUtils() {
		throw new IllegalStateException(CommonBaseConstants.MSG_UTILITY_CLASS);
	}

	/**
	 * Equals.
	 *
	 * @param <T>    the generic type
	 * @param value1 the value 1
	 * @param value2 the value 2
	 * @return true, if successful
	 */
	public static <T> boolean equals(T value1, T value2) {
		boolean res = false;
		if (Objects.nonNull(value1)) {
			res = value1.equals(value2);
		} else {
			res = Objects.isNull(value2);
		}
		return res;
	}

	/**
	 * Equals.
	 *
	 * @param <T>    the generic type
	 * @param value1 the value 1
	 * @param value2 the value 2
	 * @return true, if successful
	 */
	public static <T> boolean equals(Set<T> value1, Set<T> value2) {
		boolean res = false;
		if (ObjectUtils.allNotNull(value1, value2)) {
			if (value1.size() == value2.size()) {
				res = true;
				for (final T obj : value1) {
					if (!value2.contains(obj)) {
						res = false;
						break;
					}
				}
			}
		} else {
			res = ConditionUtils.allAreTrue(Objects.isNull(value1), Objects.isNull(value2));
		}
		return res;
	}

	/**
	 * Intersects.
	 *
	 * @param <T>    the generic type
	 * @param value1 the value 1
	 * @param value2 the value 2
	 * @return true, if successful
	 */
	public static <T> boolean intersects(Set<T> value1, Set<T> value2) {
		boolean res = false;
		if (ObjectUtils.allNotNull(value1, value2)) {
			for (final T obj : value1) {
				if (value2.contains(obj)) {
					res = true;
					break;
				}
			}
		}
		return res;
	}

	/**
	 * Compare to.
	 *
	 * @param value1 the value 1
	 * @param value2 the value 2
	 * @return compareTo
	 */
	public static int compareTo(long value1, long value2) {
		return (value1 == value2) ? 0 : (value1 < value2) ? -1 : 1;
	}

	/**
	 * Compare to.
	 *
	 * @param value1 the value 1
	 * @param value2 the value 2
	 * @return compareTo
	 */
	public static int compareTo(Long value1, Long value2) {
		if (Objects.isNull(value1)) {
			return (Objects.isNull(value2) ? 0 : -1);
		}
		if (Objects.isNull(value2)) {
			return 1;
		}
		return compareTo(value1.longValue(), value2.longValue());
	}

	/**
	 * Compare to.
	 *
	 * @param value1 the value 1
	 * @param value2 the value 2
	 * @return the int
	 */
	public static int compareTo(BigInteger value1, BigInteger value2) {
		if (Objects.isNull(value1)) {
			return (Objects.isNull(value2) ? 0 : -1);
		}
		if (Objects.isNull(value2)) {
			return 1;
		}
		return value1.compareTo(value2);
	}

	/**
	 * Compare to.
	 *
	 * @param value1 the value 1
	 * @param value2 the value 2
	 * @return compareTo
	 */
	public static int compareTo(Date value1, Date value2) {
		if (Objects.isNull(value1)) {
			return (Objects.isNull(value2) ? 0 : -1);
		}
		if (Objects.isNull(value2)) {
			return 1;
		}
		return value1.after(value2) ? 1 : value1.before(value2) ? -1 : 0;
	}

	/**
	 * Compare to.
	 *
	 * @param <T>    the generic type
	 * @param value1 the value 1
	 * @param value2 the value 2
	 * @return compareTo
	 */
	@SuppressWarnings("unchecked")
	public static <T> int compareTo(Comparable<T> value1, Comparable<T> value2) {
		if (Objects.isNull(value1)) {
			return (Objects.isNull(value2) ? 0 : -1);
		}
		if (Objects.isNull(value2)) {
			return 1;
		}
		return value1.compareTo((T) value2);
	}

	/**
	 * Compare to.
	 *
	 * @param value1 the value 1
	 * @param value2 the value 2
	 * @return the int
	 */
	public static int compareTo(String value1, String value2) {
		if (Objects.isNull(value1)) {
			return (Objects.isNull(value2) ? 0 : -1);
		}
		if (Objects.isNull(value2)) {
			return 1;
		}
		return Collator.getInstance().compare(value1, value2);
	}

}
