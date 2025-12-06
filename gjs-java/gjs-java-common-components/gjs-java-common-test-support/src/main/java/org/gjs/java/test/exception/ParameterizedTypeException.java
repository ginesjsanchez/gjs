package org.gjs.java.test.exception;

/**
 * The Class ParameterizedTypeException.
 *
 * Excepción de la librería Semilla
 *
 * Excepción generada desde algunas clases base para la implementación de test automatizados cuando se asignan
 * erróneanmente clases a los tipos parámetrizados.
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
public class ParameterizedTypeException extends RuntimeException {

    /** The Constant serialVersionUID. */
    private static final long serialVersionUID = 209135194254410696L;

    /** The message template. */
    public static final String MESSAGE_TEMPLATE = "The parameterized class %s cannot be instanciated in this context";

    /**
     * Instantiates a new parameterized type exception.
     *
     * @param className
     *            the class name
     */
    public ParameterizedTypeException(String className) {
        super(String.format(MESSAGE_TEMPLATE, className));
    }

    /**
     * Instantiates a new parameterized type exception.
     *
     * @param className
     *            the class name
     * @param e
     *            the e
     */
    public ParameterizedTypeException(String className, Exception e) {
        super(String.format(MESSAGE_TEMPLATE, className), e);
    }

}
