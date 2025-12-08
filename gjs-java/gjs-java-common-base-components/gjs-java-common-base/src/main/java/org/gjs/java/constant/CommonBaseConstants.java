package org.gjs.java.constant;

import java.util.Locale;

import org.apache.commons.lang3.LocaleUtils;

public final class CommonBaseConstants {

	public static final String MSG_UTILITY_CLASS = "Non-instantable utility class";

	public static final String MSG_UNKNOWN_ERROR = "Unknown error";

	/** The Constant NULL_VALUE. */
	public static final String NULL_VALUE = "NUL";

	/** The Constant INFORMED_VALUE. */
	public static final String INFORMED_VALUE = "XXX";

	/** The Constant DEFAULT_LOCALE . */
	public static final Locale DEFAULT_LOCALE = LocaleUtils.toLocale("es_ES");

	private CommonBaseConstants() {
		throw new IllegalStateException(MSG_UTILITY_CLASS);
	}

}
