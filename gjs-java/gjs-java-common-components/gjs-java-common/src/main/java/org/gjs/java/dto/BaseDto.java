package org.gjs.java.dto;

import java.io.Serializable;

import com.fasterxml.jackson.annotation.JsonIgnore;
import com.fasterxml.jackson.annotation.JsonInclude;

/**
 * The Class BaseDto.
 *
 * Clase de datos de la librería Semilla
 *
 * Clase base para ser extendida por todos los DTO.
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
@SuppressWarnings("serial")
@JsonInclude(JsonInclude.Include.NON_EMPTY)
public class BaseDto implements Serializable {

	/**
	 * Checks if is valid.
	 *
	 * @return true, if is valid
	 */
	// @CopiarAtributosConf(ignorar = true)
	@JsonIgnore
	public boolean isValid() {
		return true;
	}

}
