package org.gjs.java.supplier.random;

/**
 * The Class RandomAlphanumericStringSupplier.
 *
 * Clase de datos de la librería Semilla
 *
 * Generadores de NIF aleatorios.
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
public class RandomNifStringSupplier extends RandomDniStringSupplier {

    /** The Constant NIF_STRING_ASOCIATION. */
    private static final String NIF_STRING_ASOCIATION = "TRWAGMYFPDXBNJZSQVHLCKE";

    /**
     * Instantiates a new random dni string supplier.
     */
    public RandomNifStringSupplier() {
        // No hace nada
    }

    /* (non-Javadoc)
     *
     * @see org.gjs.java.test.objects.suppliers.RandomNumericStringSupplier#get() */

    @Override
    public String get() {
        final String dni = super.get();
        final Integer valueDni = Integer.valueOf(dni);
        return dni.concat(String.valueOf(letterDni(valueDni)));
    }

    /**
     * Letter dni.
     *
     * @param dni
     *            the dni
     * @return the char
     */
    private char letterDni(int dni) {
        return NIF_STRING_ASOCIATION.charAt(dni % 23);
    }

}
