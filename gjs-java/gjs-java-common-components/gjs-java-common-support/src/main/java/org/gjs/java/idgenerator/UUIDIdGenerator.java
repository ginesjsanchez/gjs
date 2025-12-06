package org.gjs.java.idgenerator;

import java.util.UUID;

/**
 * The Class UUIDIdGenerator.
 *
 * Clase de datos de la librería Semilla
 *
 * Generador de identificadores cadena UUID.
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
public class UUIDIdGenerator implements IdGenerator<String> {

    /* (non-Javadoc)
     *
     * @see org.gjs.java.test.mock.IdGenerator#generate() */

    @Override
    public String generate() {
        return UUID.randomUUID().toString();
    }

}
