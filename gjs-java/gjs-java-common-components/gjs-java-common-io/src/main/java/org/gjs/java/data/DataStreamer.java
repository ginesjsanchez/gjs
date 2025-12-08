package org.gjs.java.data;

import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.Objects;

import org.slf4j.Logger;
import org.slf4j.LoggerFactory;

/**
 * The Class DataReader.
 *
 * Clase abstracta de datos de la librería Semilla
 *
 * Clase abstracta que facilita el trabajo con una pareja
 * InputStreamWriter/OutputStreamWriter para propiciar la entrada y salida
 * general de datos
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
public abstract class DataStreamer {

	/** The Constant logger. */
	protected Logger logger;

	/**
	 * Instantiates a new reader plain.
	 */
	public DataStreamer() {
		logger = LoggerFactory.getLogger(getClass());
	}

	/**
	 * Load.
	 *
	 * @param reader the reader
	 * @return true, if successful
	 */
	public boolean load(InputStreamReader reader) {
		boolean res = false;
		if (Objects.nonNull(reader)) {
			init();
			res = loadContent(reader);
		}
		return res;
	}

	/**
	 * Save.
	 *
	 * @param writer the writer
	 * @return true, if successful
	 */
	public boolean save(OutputStreamWriter writer) {
		boolean res = false;
		if (Objects.nonNull(writer)) {
			res = saveContent(writer);
		}
		return (res);
	}

	/**
	 * Clear.
	 */
	public void clear() {
		init();
	}

	/**
	 * Inits the.
	 */
	protected abstract void init();

	/**
	 * Load.
	 *
	 * @param reader the reader
	 * @return true, if successful
	 */
	protected abstract boolean loadContent(InputStreamReader reader);

	/**
	 * Save content.
	 *
	 * @param writer the writer
	 * @return true, if successful
	 */
	protected abstract boolean saveContent(OutputStreamWriter writer);

}
