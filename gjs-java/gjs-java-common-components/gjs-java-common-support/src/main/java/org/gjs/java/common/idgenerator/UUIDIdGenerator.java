package org.gjs.java.common.idgenerator;

import java.util.UUID;

/**
 * The Class UUIDIdGenerator.
 *
 * Clase de datos de la librería Gjs
 *
 * Generador de identificadores cadena UUID.
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
public class UUIDIdGenerator implements IdGenerator<String> {

    /* (non-Javadoc)
     *
     * @see org.gjs.java.test.mock.IdGenerator#generate() */

    @Override
    public String generate() {
        return UUID.randomUUID().toString();
    }

}
