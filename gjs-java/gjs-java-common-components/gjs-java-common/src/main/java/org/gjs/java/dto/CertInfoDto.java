package org.gjs.java.dto;

import java.io.Serializable;
import java.util.Objects;

import org.apache.commons.lang3.builder.ToStringBuilder;
import org.apache.commons.lang3.builder.ToStringStyle;
import org.gjs.java.util.ConditionUtils;

import com.fasterxml.jackson.annotation.JsonIgnore;

import lombok.Getter;
import lombok.Setter;

/**
 * The Class CertInfoDto.
 *
 * Clase de datos de la librería Semilla
 *
 * Clase DTO que almacena información de un certificado.
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
public class CertInfoDto implements Serializable {

	/** The Constant serialVersionUID. */
	private static final long serialVersionUID = -8454782696124997635L;

	/** The nombre. */
	private String nombre;

	/** The apellido 1. */
	private String apellido1;

	/** The apellido 2. */
	private String apellido2;

	/** The documento. */
	private String documento;

	/** The representante. */
	private CertInfoDto representante;

	/**
	 * Instantiates a new cert info dto.
	 */
	public CertInfoDto() {
		// No hace nada
	}

	/**
	 * Instantiates a new cert info dto.
	 *
	 * @param other the other
	 */
	public CertInfoDto(CertInfoDto other) {
		if (Objects.nonNull(other)) {
			this.nombre = other.nombre;
			this.apellido1 = other.apellido1;
			this.apellido2 = other.apellido2;
			this.documento = other.documento;
			if (Objects.nonNull(other.representante)) {
				this.representante = new CertInfoDto(other.representante);
			}
		}
	}

	/**
	 * Checks for representante.
	 *
	 * @return true, if successful
	 */
	public boolean hasRepresentante() {
		return Objects.nonNull(representante);
	}

	/**
	 * Gets the documento persona.
	 *
	 * @return the documento persona
	 */
	@JsonIgnore
	public String getDocumentoPersona() {
		return hasRepresentante() ? representante.documento : documento;
	}

	/*
	 * (non-Javadoc)
	 *
	 * @see java.lang.Object#hashCode()
	 */

	@Override
	public int hashCode() {
		return Objects.hash(apellido1, apellido2, documento, nombre);
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
		if (!(obj instanceof final CertInfoDto other)) {
			return false;
		}
		return ConditionUtils.allAreTrue(Objects.equals(apellido1, other.apellido1),
				Objects.equals(apellido2, other.apellido2), Objects.equals(documento, other.documento),
				Objects.equals(nombre, other.nombre), Objects.equals(representante, other.representante));
	}

	/*
	 * (non-Javadoc)
	 *
	 * @see java.lang.Object#toString()
	 */

	@Override
	public String toString() {
		return new ToStringBuilder(this, ToStringStyle.SHORT_PREFIX_STYLE).append("nombre", nombre)
				.append("apellido1", apellido1).append("apellido2", apellido2).append("documento", documento)
				.append("representante", representante).toString();
	}

}
