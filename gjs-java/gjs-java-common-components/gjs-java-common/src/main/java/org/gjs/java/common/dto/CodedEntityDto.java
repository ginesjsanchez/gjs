package org.gjs.java.common.dto;

import java.util.Objects;

import org.apache.commons.lang3.builder.ToStringBuilder;
import org.apache.commons.lang3.builder.ToStringStyle;
import org.gjs.java.common.util.ConditionUtils;

import lombok.Getter;
import lombok.Setter;

/**
 * The Class CodedEntityDto.
 *
 * Clase de datos de la librería Gjs
 *
 * Clase DTO para almacenar la información de una ocurrencia de una entidad con código y nombre/descripcion.
 *
 * --------------------------------------------------------------------------------------------------------------------
 * Gj Software
 *
 * 2025 correspondiente licencia en los activos de la
 * SES. Los programas informáticos propiedad de la SES están protegidos por la propiedad intelectual, y por tanto está
 * estrictamente prohibida su reproducción, modificación, cesión o comunicación sin la debida autorización. Queda
 * estrictamente prohibido el uso, reproducción, cesión, transformación o comunicación pública de cualquier otro tipo de
 * obra o invención protegida por la propiedad intelectual sin la debida autorización.
 *
 * Seguridad Ministerio del Interior
 * Gobierno de España
 * --------------------------------------------------------------------------------------------------------------------
 *
 * @author Gjs
 * @version 4.0.0
 * @since 3.0.0
 *
 */

/**
 * Gets the name.
 *
 * @return the name
 */
@Getter

/**
 * Sets the name.
 *
 * @param name the new name
 */
@Setter
public class CodedEntityDto extends BaseDto {

	/** The Constant serialVersionUID. */
	private static final long serialVersionUID = -3034020635837109340L;

	/** The code. */
	private String code;

	/** The name. */
	private String name;

	/**
	 * Instantiates a new coded entity dto.
	 */
	public CodedEntityDto() {
		// No hace nada
	}

	/**
	 * Instantiates a new coded entity dto.
	 *
	 * @param code the code
	 * @param name the name
	 */
	public CodedEntityDto(String code, String name) {
		this.code = code;
		this.name = name;
	}

	/*
	 * (non-Javadoc)
	 *
	 * @see java.lang.Object#hashCode()
	 */

	@Override
	public int hashCode() {
		return Objects.hash(code, name);
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
		if (!(obj instanceof CodedEntityDto)) {
			return false;
		}
		final CodedEntityDto other = (CodedEntityDto) obj;
		return ConditionUtils.allAreTrue(Objects.equals(code, other.code), Objects.equals(name, other.name));
	}

	/*
	 * (non-Javadoc)
	 *
	 * @see java.lang.Object#toString()
	 */

	@Override
	public String toString() {
		return new ToStringBuilder(this, ToStringStyle.SHORT_PREFIX_STYLE).append("code", code).append("name", name)
				.toString();
	}

}
