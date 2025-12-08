package org.gjs.java.util;

import java.util.Random;

import org.gjs.java.constant.CommonBaseConstants;

/**
 * The Class RandomUtil.
 *
 * Clase de utilidades generales de la librería Semilla
 *
 * Función para generar claves aleatorias.
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
public final class RandomUtils {

    /**
     * Clase no instanciable.
     */
    private RandomUtils() {
        throw new IllegalStateException(CommonBaseConstants.MSG_UTILITY_CLASS);
    }

    /**
     * Generate password.
     *
     * @return the string
     */
    public static String generatePassword() {
        final Random random = new Random();
        final int length = 8 + random.nextInt(10);
        final StringBuilder sb = new StringBuilder();
        final boolean[] types = { false, false, false };
        for (int i = 0; i < length; i = i + 1) {
            final int type = random.nextInt(3);
            types[type] = true;
            final char c = generateChar(type, random);
            sb.append(c);
        }
        for (int type = 0; type <= 2; type = type + 1) {
            if (!types[type]) {
                final char c = generateChar(type, random);
                sb.append(c);
            }
        }
        return sb.toString();
    }

    /**
     * Generate char.
     *
     * @param type
     *            the type
     * @param random
     *            the random
     * @return the char
     */
    private static char generateChar(int type, Random random) {
        if (type == 0) {
            return (char) (48 + random.nextInt(10));
        }
        if (type == 1) {
            return (char) (65 + random.nextInt(26));
        }
        return (char) (97 + random.nextInt(26));
    }
}
