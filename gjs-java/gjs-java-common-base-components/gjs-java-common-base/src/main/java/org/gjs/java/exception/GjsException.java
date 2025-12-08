package org.gjs.java.exception;

import org.gjs.java.constant.CommonBaseConstants;

/**
 * The Class GjsException.
 *
 * Excepción de la librería Semilla
 *
 * Clase básica que heredan todas las excepciones de Semilla.
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
public class GjsException extends Exception {

	/**
	 *
	 */
	private static final long serialVersionUID = 2182396048438886381L;

	/**
	 * Constructor de la clase.
	 *
	 */
	public GjsException() {
		super(CommonBaseConstants.MSG_UNKNOWN_ERROR);
	}

	/**
	 * Constructor de la clase.
	 *
	 * @param message El mensaje de detalle para la excepción.
	 */
	public GjsException(String message) {
		super(message);
	}

	/**
	 * Constructor de la clase.
	 *
	 * @param cause La causa de la excepción.
	 */
	public GjsException(Throwable cause) {
		super(cause);
	}

	/**
	 * Constructor de la clase.
	 *
	 * @param message El mensaje de detalle para la excepción.
	 * @param cause   La causa de la excepción.
	 */
	public GjsException(String message, Throwable cause) {
		super(message, cause);
	}

	/**
	 * Constructor de la clase.
	 *
	 * @param message            El mensaje de detalle para la excepción.
	 * @param cause              La causa de la excepción.
	 * @param enableSuppression  Si la supresión está habilitada o no.
	 * @param writableStackTrace Si el stack trace debe ser editable o no.
	 */
	public GjsException(String message, Throwable cause, boolean enableSuppression, boolean writableStackTrace) {
		super(message, cause, enableSuppression, writableStackTrace);
	}

}
