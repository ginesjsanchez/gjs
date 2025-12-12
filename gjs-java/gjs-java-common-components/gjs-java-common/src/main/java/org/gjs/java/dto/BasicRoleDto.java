package org.gjs.java.dto;

import java.util.Objects;

import org.apache.commons.lang3.StringUtils;
import org.apache.commons.lang3.builder.ToStringBuilder;
import org.apache.commons.lang3.builder.ToStringStyle;

import lombok.Getter;
import lombok.Setter;

/**
 * The Class RolDto.
 *
 * Clase de datos de la librería Semilla
 *
 * Clase DTO para almacenar los datos de un rol.
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
public class BasicRoleDto implements Comparable<BasicRoleDto> {

	/** The nombre. */
	protected String name;

	/**
	 * Instantiates a new rol dto.
	 */
	public BasicRoleDto() {
		// No hace nada
	}

	/**
	 * Instantiates a new rol dto.
	 *
	 * @param id the id
	 */
	public BasicRoleDto(String name) {
		this.name = name;
	}

	/*
	 * (non-Javadoc)
	 *
	 * @see es.mir.semilla.util.dto.EntidadDto#equals(java.lang.Object)
	 */

	@Override
	public boolean equals(Object obj) {
		if (this == obj) {
			return true;
		}
		if (!(obj instanceof final BasicRoleDto other)) {
			return false;
		}
		return (compareTo(other) == 0);
	}

	/*
	 * (non-Javadoc)
	 *
	 * @see es.mir.semilla.util.dto.EntidadDto#hashCode()
	 */

	@Override
	public int hashCode() {
		final int prime = 31;
		int result = super.hashCode();
		result = prime * result + Objects.hash(name);
		return result;
	}

	/*
	 * (non-Javadoc)
	 *
	 * @see es.mir.semilla.util.dto.EntidadDto#compareTo(es.mir.semilla.util.dto.
	 * EntidadDto)
	 */

	@Override
	public int compareTo(BasicRoleDto o) {
		int res = -1;
		if (Objects.nonNull(o)) {
			res = StringUtils.compare(name, o.getName());
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
		return new ToStringBuilder(this, ToStringStyle.SHORT_PREFIX_STYLE).append("name", name).toString();
	}
}
