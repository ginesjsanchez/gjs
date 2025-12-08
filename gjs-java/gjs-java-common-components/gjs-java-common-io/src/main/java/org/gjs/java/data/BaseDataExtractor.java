package org.gjs.java.data;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

import org.apache.commons.lang3.StringUtils;
import org.gjs.java.util.ConditionUtils;
import org.slf4j.Logger;
import org.slf4j.LoggerFactory;

/**
 * The Class BaseDataExtractor.
 *
 * Clase abstracta de datos de la librería Semilla
 *
 * Clase abstracta usada como base para implementar un extractor de datos
 * singular.
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
 * @param <T> la clase de datos del extractor
 *
 * @author Semilla
 * @version 4.0.0
 * @since 3.0.0
 *
 */
public abstract class BaseDataExtractor<T> implements DataExtractor<T> {

	/** The Constant logger. */
	protected Logger logger;

	/** The column names. */
	private final List<String> columnNames;

	/**
	 * Instantiates a new base data extractor.
	 */
	public BaseDataExtractor() {
		logger = LoggerFactory.getLogger(getClass());
		columnNames = new ArrayList<>();
	}

	/**
	 * Instantiates a new base data extractor.
	 *
	 * @param columnName the column name
	 */
	public BaseDataExtractor(String... columnName) {
		logger = LoggerFactory.getLogger(getClass());
		columnNames = Arrays.asList(columnName);
	}

	/*
	 * (non-Javadoc)
	 *
	 * @see org.gjs.java.data.DataExtractor#columns()
	 */

	@Override
	public int columns() {
		return columnNames.size();
	}

	/**
	 * Gets the column names.
	 *
	 * @return the column names
	 */
	public List<String> getColumnNames() {
		return columnNames;
	}

	/*
	 * (non-Javadoc)
	 *
	 * @see org.gjs.java.data.DataExtractor#getColumnName(int)
	 */

	@Override
	public String getColumnName(int column) {
		String name = null;
		if (validColumn(column)) {
			name = columnNames.get(column);
		}
		return name;
	}

	/**
	 * Sets the column name.
	 *
	 * @param column the column
	 * @param name   the name
	 */
	public void setColumnName(int column, String name) {
		if (ConditionUtils.allAreTrue(validColumn(column), !StringUtils.isAllBlank(name), !StringUtils.isBlank(name))) {
			columnNames.set(column, name.trim());
		}
	}

	/**
	 * Adds the column name.
	 *
	 * @param name the name
	 */
	public void addColumnName(String name) {
		if (ConditionUtils.allAreTrue(!StringUtils.isAllBlank(name), !StringUtils.isBlank(name))) {
			columnNames.add(name.trim());
		}
	}

	/*
	 * (non-Javadoc)
	 *
	 * @see org.gjs.java.data.DataExtractor#getColumnValue(java.lang.Object,
	 * java.lang.String)
	 */

	@Override
	public String getColumnValue(T obj, String columnName) {
		String value = null;
		if (!StringUtils.isAllBlank(columnName)) {
			int column = -1;
			boolean found = false;
			while (ConditionUtils.allAreTrue((column < columnNames.size() - 1), !found)) {
				column = column + 1;
				found = columnNames.get(column).equals(columnName);
			}
			if (found) {
				value = getColumnValue(obj, column);
			}
		}
		return value;
	}

	/**
	 * Valid column.
	 *
	 * @param column the column
	 * @return true, if successful
	 */
	protected boolean validColumn(int column) {
		return ConditionUtils.allAreTrue((column >= 0), (column < columns()));
	}

}
