package org.gjs.java.dto;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

import org.apache.commons.lang3.builder.ToStringBuilder;
import org.apache.commons.lang3.builder.ToStringStyle;
import org.gjs.java.util.ConditionUtils;

/**
 * The Class GenericDto.
 *
 * Clase de datos de la librería Semilla
 *
 * Esta clase esta pensada para ser utilizada en consultas JPQL genericas,
 * siendo que Hibernate no encuentra el constructor con argumentos variables y
 * por eso se incluyen constructores mas limitados, de pocos parametros, pero
 * que no serian necesarios de no ser por eso.
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
public class GenericDto extends BaseDto {

	/** The Constant serialVersionUID. */
	private static final long serialVersionUID = 659336272252905518L;

	/** The fields. */
	private final transient List<Object> fields = new ArrayList<>();

	/**
	 * The estado valoracion.
	 *
	 * @param fields the fields
	 */
	public GenericDto(Object... fields) {
		this.fields.addAll(Arrays.asList(fields));
	}

	/**
	 * Instantiates a new generic dto.
	 *
	 * @param field the field
	 */
	public GenericDto(Object field) {
		this.fields.add(field);
	}

	/**
	 * Instantiates a new generic dto.
	 *
	 * @param field1 the field 1
	 * @param field2 the field 2
	 */
	public GenericDto(Object field1, Object field2) {
		this.fields.add(field1);
		this.fields.add(field2);
	}

	/**
	 * Instantiates a new generic dto.
	 *
	 * @param field1 the field 1
	 * @param field2 the field 2
	 * @param field3 the field 3
	 */
	public GenericDto(Object field1, Object field2, Object field3) {
		this.fields.add(field1);
		this.fields.add(field2);
		this.fields.add(field3);
	}

	/**
	 * Gets the field.
	 *
	 * @param index the index
	 * @return the field
	 */
	public Object getField(int index) {
		Object res = null;
		if (ConditionUtils.allAreTrue((index >= 0), (index < fields.size()))) {
			res = fields.get(index);
		}
		return res;
	}

	/**
	 * Size.
	 *
	 * @return the int
	 */
	public int size() {
		return fields.size();
	}

	/*
	 * (non-Javadoc)
	 *
	 * @see es.mir.dravy.util.dto.EntidadModeloDto#hashCode()
	 */

	@Override
	public int hashCode() {
		final int prime = 31;
		int result = 1;
		for (final Object field : fields) {
			result = prime * result + field.hashCode();
		}
		return result;
	}

	/*
	 * (non-Javadoc)
	 *
	 * @see es.mir.dravy.util.dto.EntidadModeloDto#equals(java.lang.Object)
	 */

	@Override
	public boolean equals(Object obj) {
		if (this == obj) {
			return true;
		}
		if (!(obj instanceof final GenericDto castOther)) {
			return false;
		}
		boolean result = (fields.size() == castOther.size());
		int i = 0;
		while (ConditionUtils.allAreTrue(result, (i < fields.size()))) {
			result = fields.get(i).equals(castOther.getField(i));
			i = i + 1;
		}
		return result;
	}

	/*
	 * (non-Javadoc)
	 *
	 * @see es.mir.dravy.util.dto.EntidadModeloDto#toString()
	 */

	@Override
	public String toString() {
		return new ToStringBuilder(this, ToStringStyle.SHORT_PREFIX_STYLE)
				.append("fields", org.springframework.util.StringUtils.collectionToCommaDelimitedString(fields))
				.toString();
	}

}
