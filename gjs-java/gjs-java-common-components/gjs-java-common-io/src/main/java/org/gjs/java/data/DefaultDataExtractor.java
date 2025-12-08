package org.gjs.java.data;

import java.util.List;
import java.util.Objects;

import org.gjs.java.types.FieldInfo;
import org.gjs.java.util.ConditionUtils;
import org.gjs.java.util.ConversionUtils;
import org.gjs.java.util.ReflectionUtils;

/**
 * The Class DefaultDataExtractor.
 *
 * Clase de datos de la librería Semilla
 *
 * Extractor de datos genérico que actua sobre la clase Object.
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
public class DefaultDataExtractor extends BaseDataExtractor<Object> {

	/** The fields. */
	private List<FieldInfo> fields;

	/**
	 * Instantiates a new default data extractor.
	 *
	 * @param obj the obj
	 */
	public DefaultDataExtractor(Object obj) {
		if (Objects.nonNull(obj)) {
			fields = ReflectionUtils.getAllFields(obj.getClass());
			for (final FieldInfo field : fields) {
				super.addColumnName(field.getField().getName());
			}
		}
	}

	/*
	 * (non-Javadoc)
	 *
	 * @see org.gjs.java.data.DataExtractor#getColumnValue(java.lang.Object, int)
	 */

	@Override
	public String getColumnValue(Object obj, int column) {
		String value = null;
		if (ConditionUtils.allAreTrue(Objects.nonNull(obj), validColumn(column))) {
			final String typeName = fields.get(column).getField().getType().getName();
			final boolean isString = "java.lang.String".equals(typeName);
			value = ConversionUtils.toString(ReflectionUtils.getFieldValue(obj, fields.get(column).getField()));
			if (isString) {
				value = String.format("\"%s\"", value);
			}
		}
		return value;
	}

}
