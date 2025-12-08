package org.gjs.java.data;

import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;

import org.apache.commons.lang3.StringUtils;
import org.gjs.java.types.DataObject;
import org.gjs.java.util.ConditionUtils;
import org.gjs.java.util.NormalizationUtils;

/**
 * * The Class ObjectsDataReader.
 *
 * Clase de datos de la librería Semilla
 *
 * Facilita el manejo de la entrada y salida por stremers de un texto plano
 * visto como una secuencia de objetos con sus atributos.
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

public class ObjectsDataReader extends SheetDataStreamer {

	/** The objects. */
	private List<DataObject> objects;

	/**
	 * Instantiates a new reader objects.
	 */
	public ObjectsDataReader() {
	}

	/**
	 * Instantiates a new reader objects.
	 *
	 * @param separator the separator
	 */
	public ObjectsDataReader(char separator) {
		super(separator);
	}

	/**
	 * Instantiates a new reader objects.
	 *
	 * @param reader the reader
	 */
	public ObjectsDataReader(InputStreamReader reader) {
		super(reader);
	}

	/**
	 * Instantiates a new reader objects.
	 *
	 * @param separator the separator
	 * @param reader    the reader
	 */
	public ObjectsDataReader(char separator, InputStreamReader reader) {
		super(separator, reader);
	}

	/*
	 * (non-Javadoc)
	 *
	 * @see org.gjs.java.files.FileSheet#init()
	 */

	@Override
	public void init() {
		super.init();
		objects = new ArrayList<>();
	}

	/*
	 * (non-Javadoc)
	 *
	 * @see org.gjs.java.files.FileSheet#loadContent(java.lang.String)
	 */

	@Override
	protected boolean loadContent(InputStreamReader reader) {
		final boolean res = super.loadContent(reader);
		if (ConditionUtils.allAreTrue(super.isValid(), columnsAreValid())) {
			for (int row = 0; row < super.rows(); row = row + 1) {
				final DataObject data = new DataObject();
				for (int col = 0; col < super.columns(); col = col + 1) {
					final String attribute = NormalizationUtils.normalizeAttributeName(super.getColumnName(col));
					data.setValue(attribute, super.getValue(row, col));
				}
				objects.add(data);
			}
		}
		return (res);
	}

	/*
	 * (non-Javadoc)
	 *
	 * @see org.gjs.java.files.FileSheet#isValid()
	 */

	@Override
	public boolean isValid() {
		return ConditionUtils.allAreTrue(super.isValid(), columnsAreValid(), (objects.size() == super.rows()));
	}

	/**
	 * Count.
	 *
	 * @return the int
	 */
	public int count() {
		return objects.size();
	}

	/**
	 * Attributes.
	 *
	 * @return the int
	 */
	public int attributes() {
		return super.columns();
	}

	/**
	 * Gets the attribute.
	 *
	 * @param column the column
	 * @return the attribute
	 */
	public String getAttribute(int column) {
		return NormalizationUtils.normalizeAttributeName(super.getColumnName(column));
	}

	/**
	 * Gets the objects.
	 *
	 * @return the objects
	 */
	public List<DataObject> getObjects() {
		return objects;
	}

	/**
	 * Gets the object.
	 *
	 * @param row the row
	 * @return the object
	 */
	public DataObject getObject(int row) {
		DataObject data = null;
		if (validRow(row)) {
			data = objects.get(row);
		}
		return data;
	}

	/**
	 * Valid row.
	 *
	 * @param row the row
	 * @return true, if successful
	 */
	private boolean validRow(int row) {
		return ConditionUtils.allAreTrue((row >= 0), (row < objects.size()));
	}

	/**
	 * Columns are valid.
	 *
	 * @return true, if successful
	 */
	private boolean columnsAreValid() {
		boolean res = true;
		for (int col = 0; col < super.columns(); col = col + 1) {
			final String attribute = NormalizationUtils.normalizeAttributeName(super.getColumnName(col));
			if (StringUtils.isAllBlank(attribute)) {
				res = false;
				break;
			}
		}
		return res;
	}
}
