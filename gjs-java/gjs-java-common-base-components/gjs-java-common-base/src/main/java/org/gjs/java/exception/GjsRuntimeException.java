package org.gjs.java.exception;

import org.gjs.java.constant.CommonBaseConstants;

/**
 * The Class SemillaRuntimeException.
 *
 * Excepción de la librería Semilla
 *
 * Excepción generada por las clase del módulo de utilidades Hereda de
 * RuntimeException para poder ser utilizada en funciones lambda.
 *
 * --------------------------------------------------------------------------------------------------------------------
 * Este software es propiedad del Ministerio del Interior CETSE - 2025
 *
 * Queda estrictamente prohibido el uso de programas informáticos sin la
 * correspondiente licencia en los activos de la SES. Los programas informáticos
 * propiedad de la SES están protegidos por la propiedad intelectual, y por
 * tanto está estrictamente prohibida su reproducción, modificación, cesión o
 * comunicación sin la debida autorización. Queda estrictamente prohibido el
 * uso, reproducción, cesión, transformación o comunicación pública de cualquier
 * otro tipo de obra o invención protegida por la propiedad intelectual sin la
 * debida autorización.
 *
 * Subdirección General de Sistemas de la Información y Comunicaciones para la
 * Seguridad Ministerio del Interior Gobierno de España
 * --------------------------------------------------------------------------------------------------------------------
 *
 * @author Semilla
 * @version 4.0.0
 * @since 3.0.0
 *
 */
public class GjsRuntimeException extends RuntimeException {

	/** The Constant serialVersionUID. */
	private static final long serialVersionUID = -7786700707108687537L;

	/**
	 * Instantiates a new ejemplo runtime exception.
	 */
	public GjsRuntimeException() {
		super(CommonBaseConstants.MSG_UNKNOWN_ERROR);
	}

	/**
	 * Instantiates a new ejemplo runtime exception.
	 *
	 * @param e the e
	 */
	public GjsRuntimeException(Throwable e) {
		super(e);
	}

	/**
	 * Instantiates a new ejemplo runtime exception.
	 *
	 * @param message the message
	 * @param e       the e
	 */
	public GjsRuntimeException(String message, Throwable e) {
		super(message, e);
	}

}
