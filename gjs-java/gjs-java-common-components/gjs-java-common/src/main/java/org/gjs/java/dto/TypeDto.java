package org.gjs.java.dto;

import org.apache.commons.lang3.builder.ToStringBuilder;
import org.apache.commons.lang3.builder.ToStringStyle;

import com.fasterxml.jackson.annotation.JsonProperty;

import lombok.Getter;
import lombok.Setter;

/**
 * The Class TypeDto.
 *
 * Clase de datos de la librería Semilla
 *
 * Clase DTO para almacenar los datos de un tipo genérico de cualquier cosa.
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
public class TypeDto extends BaseDto {

	/** The Constant serialVersionUID. */
	private static final long serialVersionUID = -4211879294171610447L;

	/** The nombre. */
	private String nombre;

	/** The descripcion. */
	private String descripcion;

	/** The valor. */
	@JsonProperty(required = false)
	private Integer valor;

	/**
	 * Instantiates a new tipo dto.
	 */
	public TypeDto() {
		// No hace nada
	}

	/**
	 * Instantiates a new tipo dto.
	 *
	 * @param nombre      the nombre
	 * @param valor       the valor
	 * @param descripcion the descripcion
	 */
	public TypeDto(String nombre, Integer valor, String descripcion) {
		this.nombre = nombre;
		this.descripcion = descripcion;
		this.valor = valor;
	}

	/**
	 * Instantiates a new tipo dto.
	 *
	 * @param nombre      the nombre
	 * @param descripcion the descripcion
	 */
	public TypeDto(String nombre, String descripcion) {
		this.nombre = nombre;
		this.descripcion = descripcion;
	}

	/*
	 * (non-Javadoc)
	 *
	 * @see java.lang.Object#toString()
	 */

	@Override
	public String toString() {
		return new ToStringBuilder(this, ToStringStyle.SHORT_PREFIX_STYLE).append("nombre", nombre)
				.append("valor", valor).append("descripcion", descripcion).toString();
	}

}
