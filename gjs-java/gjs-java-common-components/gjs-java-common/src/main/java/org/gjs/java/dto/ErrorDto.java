package org.gjs.java.dto;

import java.util.Objects;

import org.apache.commons.lang3.ArrayUtils;
import org.apache.commons.lang3.builder.ToStringBuilder;
import org.apache.commons.lang3.builder.ToStringStyle;
import org.apache.commons.lang3.exception.ExceptionUtils;
import org.gjs.java.exception.GjsException;
import org.gjs.java.singleton.GlobalBundleManager;
import org.gjs.java.util.ComparationUtils;
import org.slf4j.Logger;
import org.slf4j.LoggerFactory;

import com.fasterxml.jackson.annotation.JsonInclude;
import com.fasterxml.jackson.annotation.JsonProperty;

import lombok.Getter;
import lombok.Setter;

/**
 * The Class ErrorDto.
 *
 * Clase de datos de la librería Semilla
 *
 * Clase que contiene la información de un error.
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
@Getter
@Setter
@JsonInclude(JsonInclude.Include.NON_NULL)
public class ErrorDto extends BaseDto implements Comparable<ErrorDto> {

	/** The Constant serialVersionUID. */
	private static final long serialVersionUID = -4209318144944693335L;

	/** The Constant logger. */
	private static final Logger logger = LoggerFactory.getLogger(ErrorDto.class);

	/** The code. */
	@JsonProperty(required = true, index = 1)
	private String code;

	/** The message. */
	@JsonProperty(required = true, index = 2)
	private String message;

	/** The details. */
	@JsonProperty(required = false, index = 3)
	private String details;

	/**
	 * Instantiates a new error dto.
	 */
	public ErrorDto() {
		// No hace nada
	}

	/**
	 * Instantiates a new error dto.
	 *
	 * @param code the code
	 */
	public ErrorDto(String code) {
		this.code = code;
		findMessage();
	}

	/**
	 * Instantiates a new error dto.
	 *
	 * @param code   the code
	 * @param params the params
	 */
	public ErrorDto(String code, Object... params) {
		this.code = code;
		findMessage(params);
	}

	/**
	 * Instantiates a new error dto.
	 *
	 * @param code    the code
	 * @param message the message
	 */
	public ErrorDto(String code, String message) {
		this.code = code;
		this.message = message;
	}

	/**
	 * Find message.
	 *
	 * @param params the params
	 */
	private void findMessage(Object... params) {
		try {
			if (ArrayUtils.getLength(params) == 0) {
				this.message = GlobalBundleManager.getInstance().getErrorMessage(this.code);
			} else {
				this.message = GlobalBundleManager.getInstance().getErrorMessage(this.code, params);
			}
		} catch (final GjsException e) {
			logger.error(ExceptionUtils.getStackTrace(e.getCause()));
		}
		this.message = Objects.requireNonNullElse(this.message,
				String.format("<Mensaje para %s no encontrado>", this.code));
	}

	/*
	 * (non-Javadoc)
	 *
	 * @see java.lang.Object#hashCode()
	 */

	@Override
	public int hashCode() {
		return Objects.hash(code);
	}

	/*
	 * (non-Javadoc)
	 *
	 * @see java.lang.Object#equals(java.lang.Object)
	 */

	@Override
	public boolean equals(Object obj) {
		if (this == obj) {
			return true;
		}
		if (!(obj instanceof final ErrorDto other)) {
			return false;
		}
		return Objects.equals(code, other.code);
	}

	/*
	 * (non-Javadoc)
	 *
	 * @see java.lang.Comparable#compareTo(java.lang.Object)
	 */

	@Override
	public int compareTo(ErrorDto obj) {
		int res = -1;
		if (Objects.nonNull(obj)) {
			res = ComparationUtils.compareTo(code, obj.getCode());
		}
		return res;
	}

	/*
	 * (non-Javadoc)
	 *
	 * @see java.lang.Object#toString()
	 */

	@Override
	public String toString() {
		return new ToStringBuilder(this, ToStringStyle.SHORT_PREFIX_STYLE).append("code", code)
				.append("message", message).toString();
	}

}
