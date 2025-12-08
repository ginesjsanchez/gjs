package org.gjs.java.util;

import org.apache.commons.lang3.BooleanUtils;
import org.gjs.java.constant.CommonBaseConstants;

/**
 * The Class ConditionUtils.
 *
 * Clase de utilidades generales de la librería Gjs
 *
 * La utilidad de estos métodos es liberarnos de la ambigüedad de la llamada directa a los métodos de
 * org.apache.commons.lang3.BooleanUtils.
 *
 * --------------------------------------------------------------------------------------------------------------------
 *
 *
 * correspondiente licencia en los activos de la
 * SES. Los programas informáticos propiedad de la SES están protegidos por la propiedad intelectual, y por tanto está
 * estrictamente prohibida su reproducción, modificación, cesión o comunicación sin la debida autorización. Queda
 * estrictamente prohibido el uso, reproducción, cesión, transformación o comunicación pública de cualquier otro tipo de
 * obra o invención protegida por la propiedad intelectual sin la debida autorización.
 *
 *  Seguridad Ministerio del Interior
 * Gobierno de España
 * --------------------------------------------------------------------------------------------------------------------
 *
 * @author Gjs
 * @version 1.0.0
 * @since 1.0.0
 *
 */
public final class ConditionUtils {

    /**
     * Clase no instanciable.
     */
    private ConditionUtils() {
        throw new IllegalStateException(CommonBaseConstants.MSG_UTILITY_CLASS);
    }

    /**
     * One is true.
     *
     * @param values
     *            the values
     * @return true, if successful
     */
    public static boolean oneIsTrue(boolean... values) {
        return BooleanUtils.or(values);
    }

    /**
     * All are true.
     *
     * @param values
     *            the values
     * @return true, if successful
     */
    public static boolean allAreTrue(boolean... values) {
        return BooleanUtils.and(values);
    }

}
