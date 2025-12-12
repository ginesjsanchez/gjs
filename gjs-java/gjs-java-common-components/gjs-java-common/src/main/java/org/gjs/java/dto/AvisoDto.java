package org.gjs.java.dto;

import java.util.Date;

import org.apache.commons.lang3.StringUtils;
import org.apache.commons.lang3.builder.ToStringBuilder;
import org.apache.commons.lang3.builder.ToStringStyle;

import lombok.Getter;
import lombok.Setter;

/**
 * The Class AvisoDto.
 *
 * Clase de datos de la librería Semilla
 *
 * Clase DTO para contener la información de un aviso.
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
public class AvisoDto extends EntityPkLongDto {

	/** The Constant serialVersionUID. */
	private static final long serialVersionUID = -6449645719040346268L;

	/** The Constant MAX_LEN_MENSAJE. */
	private static final int MAX_LEN_MENSAJE = 1024;

	/** The instancia. */
	private String instancia;

	/** The fecha hora. */
	private Date fechaHora;

	/** The mensaje. */
	private String mensaje;

	/** The causa. */
	private String causa;

	/**
	 * Instantiates a new endpoint dto.
	 */
	public AvisoDto() {
		// No hace nada
	}

	/**
	 * Instantiates a new aviso dto.
	 *
	 * @param instancia the instancia
	 * @param mensaje   the mensaje
	 * @param causa     the causa
	 */
	public AvisoDto(String instancia, String mensaje, String causa) {
		this.instancia = instancia;
		setMensaje(mensaje);
		this.causa = causa;
		this.fechaHora = new Date();
	}

	/**
	 * Sets the mensaje.
	 *
	 * @param mensaje the new mensaje
	 */
	public void setMensaje(String mensaje) {
		this.mensaje = StringUtils.abbreviate(mensaje, MAX_LEN_MENSAJE);
	}

	/*
	 * (non-Javadoc)
	 *
	 * @see es.mir.semilla.util.dto.EntidadDto#equals(java.lang.Object)
	 */

	@Override
	public boolean equals(Object o) {
		return super.equals(o);
	}

	/*
	 * (non-Javadoc)
	 *
	 * @see es.mir.semilla.util.dto.EntidadDto#hashCode()
	 */

	@Override
	public int hashCode() {
		return super.hashCode();
	}

	/*
	 * (non-Javadoc)
	 *
	 * @see java.lang.Object#toString()
	 */

	@Override
	public String toString() {
		return new ToStringBuilder(this, ToStringStyle.SHORT_PREFIX_STYLE).append("instancia", instancia)
				.append("fechaHora", fechaHora).append("mensaje", mensaje).append("causa", causa).append("id", id)
				.toString();
	}

}
