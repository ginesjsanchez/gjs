package org.gjs.java.supplier.random;

import java.io.IOException;

/**
 * The Class RandomNameSupplier.
 *
 * Clase de datos de la librería Semilla
 *
 * Generadores de apellidos aleatorios.
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
public class RandomSurnameSupplier extends RandomSelectedFromFileSupplier {

    /**
     * Instantiates a new random surname supplier.
     *
     * @throws IOException
     *             Signals that an I/O exception has occurred.
     */
    public RandomSurnameSupplier() throws IOException {
        super("data/apellidos.txt");
    }

}
