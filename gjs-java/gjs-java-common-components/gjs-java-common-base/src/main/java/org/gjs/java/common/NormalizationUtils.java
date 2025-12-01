package org.gjs.java.common;

import org.apache.commons.lang3.StringUtils;

/**
 * The Class NormalizationUtils.
 *
 * Clase de utilidades generales de la librería Semilla
 *
 * Funciones de normalización de literales. Contiene la función de normalización para procesar los nom bres de atributos
 * o campos de entidades que puedan venir en los ficheros de datos que se tengan que importar.
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
public final class NormalizationUtils {

    /**
     * Clase no instanciable.
     */
    private NormalizationUtils() {
        throw new IllegalStateException("Utility class");
    }

    /**
     * Normalize attribute name.
     *
     * @param initialName
     *            the initial name
     * @return the string
     */
    public static String normalizeAttributeName(String initialName) {
        if (StringUtils.isAllBlank(initialName)) {
            return null;
        }
        final StringBuilder name = new StringBuilder();
        boolean newWord = false;
        boolean lastUpper = false;
        for (int i = 0; i < initialName.length(); i = i + 1) {
            final char c = initialName.charAt(i);
            if (newWord) {
                if (ConditionUtils.oneIsTrue(Character.isLetter(c), Character.isDigit(c))) {
                    name.append(Character.toUpperCase(c));
                    lastUpper = true;
                    newWord = false;
                }
            } else if (ConditionUtils.allAreTrue(!Character.isLetter(c), !Character.isDigit(c))) {
                newWord = true;
                lastUpper = false;
            } else if (Character.isUpperCase(c) && !lastUpper && (i > 0)) {
                name.append(c);
                lastUpper = true;
            } else {
                name.append(Character.toLowerCase(c));
                lastUpper = Character.isUpperCase(c);
            }
        }
        if (name.length() == 0) {
            return null;
        }
        return name.toString();
    }

}
