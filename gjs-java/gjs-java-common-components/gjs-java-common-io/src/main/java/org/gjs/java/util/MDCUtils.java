package org.gjs.java.util;

import java.util.Objects;

import org.apache.commons.lang3.StringUtils;
import org.gjs.java.constant.CommonBaseConstants;
import org.slf4j.MDC;

/**
 * The Class MDCUtil.
 *
 * Clase de utilidades generales de la librería Semilla
 *
 * Algunas funciones de ayuda para manejarse con la MDC de Apache.
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
public final class MDCUtils {

    /**
     * Clase no instanciable.
     */
    private MDCUtils() {
        throw new IllegalStateException(CommonBaseConstants.MSG_UTILITY_CLASS);
    }

    /**
     * Save.
     *
     * @param key
     *            the key
     * @param value
     *            the value
     */
    public static void save(String key, String value) {
        if (ConditionUtils.allAreTrue(!StringUtils.isAllBlank(key), Objects.nonNull(value))) {
            MDC.put(key, value);
        }
    }

    /**
     * Save.
     *
     * @param key
     *            the key
     * @param value
     *            the value
     */
    public static void save(String key, Object value) {
        if (ConditionUtils.allAreTrue(!StringUtils.isAllBlank(key), Objects.nonNull(value))) {
            MDC.put(key, JsonUtils.safeObjectToJson(value));
        }
    }

    /**
     * Load.
     *
     * @param key
     *            the key
     * @return the string
     */
    public static String load(String key) {
        String res = null;
        if (!StringUtils.isAllBlank(key)) {
            res = MDC.get(key);
        }
        return res;
    }

    /**
     * Load.
     *
     * @param key
     *            the key
     * @param clazz
     *            the clazz
     * @return the object
     */
    public static Object load(String key, Class<?> clazz) {
        Object res = null;
        if (!StringUtils.isAllBlank(key)) {
            res = JsonUtils.safeJsonToObject(MDC.get(key), clazz);
        }
        return res;
    }

    /**
     * Removes the.
     *
     * @param key
     *            the key
     */
    public static void remove(String key) {
        if (!StringUtils.isAllBlank(key)) {
            MDC.remove(key);
        }
    }

    /**
     * Clear.
     */
    public static void clear() {
        MDC.clear();
    }

}
