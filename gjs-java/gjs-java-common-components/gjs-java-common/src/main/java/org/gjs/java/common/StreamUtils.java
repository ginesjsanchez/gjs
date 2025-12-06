package org.gjs.java.common;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collection;
import java.util.List;
import java.util.Objects;

import org.apache.commons.lang3.ObjectUtils;
import org.gjs.java.types.Matrix;
import org.slf4j.Logger;
import org.slf4j.LoggerFactory;

/**
 * The Class StreamUtils.
 *
 * Clase de utilidades generales de la librería Semilla
 *
 * Contiene algunas funciones que relacionadas con la lectura de entradas de
 * texto como líneas o como matrices de datos separados por algún carácter, que
 * se necesitaba sacar de sus clases de origen para evitar la duplicación de
 * código.
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
public final class StreamUtils {

	/** The Constant logger. */
	private static final Logger logger = LoggerFactory.getLogger(StreamUtils.class);

	/**
	 * Clase no instanciable.
	 */
	private StreamUtils() {
		throw new IllegalStateException("Clase no instanciable");
	}

	/**
	 * Read lines.
	 *
	 * @param reader the reader
	 * @param data   the data
	 * @throws IOException Signals that an I/O exception has occurred.
	 */
	public static void readLines(InputStreamReader reader, Collection<String> data) throws IOException {
		if (ObjectUtils.allNotNull(reader, data)) {
			try (final BufferedReader br = new BufferedReader(reader)) {
				String line = br.readLine();
				while (Objects.nonNull(line)) {
					data.add(line);
					line = br.readLine();
				}
			} catch (final IOException e) {
				logger.error(e.getMessage());
				throw e;
			}
		}
	}

	/**
	 * Read data.
	 *
	 * @param reader    the reader
	 * @param data      the data
	 * @param separator the separator
	 * @throws IOException Signals that an I/O exception has occurred.
	 */
	public static void readData(InputStreamReader reader, Matrix<String> data, char separator) throws IOException {
		if (ObjectUtils.allNotNull(reader, data)) {
			try (final BufferedReader br = new BufferedReader(reader)) {
				String line = br.readLine();
				while (Objects.nonNull(line)) {
					line = line.trim();
					if (line.length() > 0) {
						final List<String> values = split(line, separator);
						data.addRow(values);
					}
					line = br.readLine();
				}
			} catch (final IOException e) {
				logger.error(e.getMessage());
				throw e;
			}
		}
	}

	/**
	 * Split.
	 *
	 * @param line      the line
	 * @param separator the separator
	 * @return the array list
	 */
	private static ArrayList<String> split(String line, char separator) {
		final ArrayList<String> fields = new ArrayList<>();
		int pos = 0;
		boolean string = false;
		boolean postString = false;
		boolean lastSeparator = false;
		final StringBuilder field = new StringBuilder();
		while (pos < line.length()) {
			final char c = line.charAt(pos);
			if (postString) {
				postString = (c != separator);
			} else if (string) {
				if (c == '\"') {
					string = false;
					postString = true;
					fields.add(field.toString());
					field.setLength(0);
				} else {
					field.append(c);
				}
			} else if (c == '\"') {
				string = true;
			} else if (c == separator) {
				fields.add(formatValue(field.toString()));
				field.setLength(0);
			} else {
				field.append(c);
			}
			lastSeparator = (c == separator);
			pos = pos + 1;
		}
		if (lastSeparator) {
			fields.add("");
		} else if (field.length() > 0) {
			fields.add(formatValue(field.toString()));
		}
		return fields;
	}

	/**
	 * Format value.
	 *
	 * @param value the value
	 * @return the string
	 */
	private static String formatValue(String value) {
		if ("null".equals(value)) {
			return null;
		}
		return value;
	}

}
