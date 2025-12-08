package org.gjs.java.supplier.random;

import java.io.IOException;

/**
 * The Class RandomNameSupplier.
 *
 * Clase de datos de la librería Gjs
 *
 * Generadores de nombres femeninos aleatorios.
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
public class RandomFemaleNameSupplier extends RandomSelectedFromFileSupplier {

    /**
     * Instantiates a new random female name supplier.
     *
     * @throws IOException
     *             Signals that an I/O exception has occurred.
     */
    public RandomFemaleNameSupplier() throws IOException {
        super("data/nombresH.txt");
    }

}
