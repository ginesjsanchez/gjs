package org.gjs.java.util;

import org.apache.commons.lang3.StringUtils;

import org.gjs.java.common.ConditionUtils;

/**
 * The Class AdministrativeUtils.
 *
 * Clase de utilidades generales de la librería Semilla
 *
 * Funciones generales de validación oficial de códigos de carñacter administrativo estatal: DNI/NIF, NIE...
 *
 * --------------------------------------------------------------------------------------------------------------------
 * Este software es propiedad del Ministerio del Interior CETSE - 2025
 *
 * Queda estrictamente prohibido el uso de programas informáticos sin la correspondiente licencia en los activos de la
 * SES. Los programas informáticos propiedad de la SES están protegidos por la propiedad intelectual, y por tanto está
 * estrictamente prohibida su reproducción, modificación, cesión o comunicación sin la debida autorización. Queda
 * estrictamente prohibido el uso, reproducción, cesión, transformación o comunicación pública de cualquier otro tipo de
 * obra o invención protegida por la propiedad intelectual sin la debida autorización.
 *
 * Subdirección General de Sistemas de la Información y Comunicaciones para la Seguridad Ministerio del Interior
 * Gobierno de España
 * --------------------------------------------------------------------------------------------------------------------
 *
 * @author Semilla
 * @version 4.0.0
 * @since 3.0.0
 *
 */
public final class AdministrativeUtils {

    /** The Constant NIF_STRING_ASOCIATION. */
    private static final String NIF_STRING_ASOCIATION = "TRWAGMYFPDXBNJZSQVHLCKE";

    /** The Constant NIE_PREFIX_ASOCIATION. */
    private static final String NIE_PREFIX_ASOCIATION = "XYZ";

    /** The Constant NUMERIC_PREFIX_ASOCIATION. */
    private static final String NUMERIC_PREFIX_ASOCIATION = "012";

    /**
     * Clase no instanciable.
     */
    private AdministrativeUtils() {
        throw new IllegalStateException("Utility class");
    }

    /**
     * Validate nif.
     *
     * @param nif
     *            the nif
     * @return true, if successful
     */
    public static boolean validateNif(String nif) {
        boolean res = false;
        if (!StringUtils.isAllBlank(nif) && (nif.length() == 9)) {
            final char letter = nif.charAt(8);
            final String dni = nif.substring(0, 8);
            if (StringUtils.isNumeric(dni)) {
                final Integer value = Integer.valueOf(dni);
                res = (NIF_STRING_ASOCIATION.charAt(value % 23) == letter);
            }
        }
        return res;
    }

    /**
     * Validate nie.
     *
     * @param nie
     *            the nie
     * @return true, if successful
     */
    public static boolean validateNie(String nie) {
        boolean res = false;
        if (!StringUtils.isAllBlank(nie) && (nie.length() == 9)) {
            final char prefix = nie.charAt(0);
            final char letter = nie.charAt(8);
            final String number = nie.substring(1, 8);
            final int index = NIE_PREFIX_ASOCIATION.indexOf(prefix);
            if (StringUtils.isNumeric(number) && (index >= 0)) {
                final String numericPart = String.valueOf(NUMERIC_PREFIX_ASOCIATION.charAt(index)).concat(number);
                final Integer value = Integer.valueOf(numericPart);
                res = (NIF_STRING_ASOCIATION.charAt(value % 23) == letter);
            }
        }
        return res;
    }

    /**
     * Validate nif nie.
     *
     * @param nif
     *            the nif
     * @return true, if successful
     */
    public static boolean validateNifNie(String nif) {
        return ConditionUtils.oneIsTrue(validateNif(nif), validateNie(nif));
    }

}
