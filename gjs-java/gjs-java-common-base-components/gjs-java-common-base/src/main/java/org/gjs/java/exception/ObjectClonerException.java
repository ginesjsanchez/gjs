package org.gjs.java.exception;

/**
 * The Class ObjectClonerException.
 *
 * Excepción de la librería Gjs
 *
 * Excepción generada por las utilidades de clonación de objetos utilizadas para la automatización de test de la
 * librería Gjs.
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
public class ObjectClonerException extends RuntimeException {

    /** The Constant serialVersionUID. */
    private static final long serialVersionUID = -4225619350455794258L;

    /**
     * Instantiates a new object cloner exception.
     *
     * @param message
     *            the message
     */
    public ObjectClonerException(String message) {
        super(message);
    }

    /**
     * Instantiates a new object cloner exception.
     *
     * @param message
     *            the message
     * @param e
     *            the e
     */
    public ObjectClonerException(String message, Exception e) {
        super(message, e);
    }

}
