package org.gjs.java.test.exception;

/**
 * The Class DeprecatedException.
 *
 * Excepción de la librería Gjs
 *
 * Excepción generada para avisar de que se utiliza un método deprecado.
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
public class DeprecatedException extends RuntimeException {

    /**
     *
     */
    private static final long serialVersionUID = -4634775908373609845L;

    /**
     * Instantiates a new object supplier exception.
     *
     * @param method
     *            the method
     */
    public DeprecatedException(String method) {
        super(String.format("The method %s is deprecated", method));
    }

}
