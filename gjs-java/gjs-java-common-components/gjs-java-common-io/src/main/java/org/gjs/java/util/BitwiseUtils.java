package org.gjs.java.util;

import org.gjs.java.constant.CommonBaseConstants;

/**
 * The Class BitwiseUtil.
 *
 * Clase de utilidades generales de la librería Semilla
 *
 * Funciones de manejo de enteros como mapa de bits.
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
public final class BitwiseUtils {

    /**
     * Instantiates a new bitwise util.
     */
    private BitwiseUtils() {
        throw new IllegalStateException(CommonBaseConstants.MSG_UTILITY_CLASS);
    }

    /**
     * Checks if is sets the.
     *
     * @param value
     *            the value
     * @param pos
     *            the pos
     * @return true, if is sets the
     */
    public static boolean isSet(int value, int pos) {
        boolean res = false;
        if (pos >= 0) {
            final int mask = 1 << pos;
            res = (value & mask) > 0;
        }
        return res;
    }

}
