package org.gjs.java.dto;

import org.gjs.java.singleton.GlobalBundleManager;

/**
 * The Class ErrorValidacionDto.
 *
 * Clase de datos de la librería Semilla
 *
 * Clase que contiene la información de un error de validación.
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
public class ValidationErrorDto extends ErrorDto {

	/** The Constant serialVersionUID. */
	private static final long serialVersionUID = -8286542567656189386L;

	/**
	 * Instantiates a new error validacion dto.
	 */
	public ValidationErrorDto() {
	}

	/**
	 * Instantiates a new error validacion dto.
	 *
	 * @param code the code
	 */
	public ValidationErrorDto(String code) {
		super(code);
	}

	/**
	 * Instantiates a new error validacion dto.
	 *
	 * @param code      the code
	 * @param parameter the parameter
	 */
	public ValidationErrorDto(String code, String parameter) {
		super(code, GlobalBundleManager.getSafetyErrorMessage(code, parameter));
	}

	/**
	 * Instantiates a new error validacion dto.
	 *
	 * @param code      the code
	 * @param parameter the parameter
	 * @param value     the value
	 */
	public ValidationErrorDto(String code, String parameter, String value) {
		super(code, GlobalBundleManager.getSafetyErrorMessage(code, parameter, value));
	}

}
