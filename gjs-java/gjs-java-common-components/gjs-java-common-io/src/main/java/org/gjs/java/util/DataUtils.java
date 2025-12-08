package org.gjs.java.util;

import java.io.ByteArrayOutputStream;
import java.io.OutputStreamWriter;
import java.util.List;
import java.util.Map;
import java.util.Objects;
import java.util.Set;
import java.util.TreeSet;

import org.gjs.java.constant.CommonBaseConstants;
import org.gjs.java.data.DefaultDataExtractor;
import org.gjs.java.data.SheetDataStreamer;
import org.slf4j.Logger;
import org.slf4j.LoggerFactory;

/**
 * The Class DataUtil.
 *
 * Clase de utilidades generales de la librería Semilla
 *
 * Algunas funciones relacionadas con la interpretación y la generación de
 * ficheros CSV que se sacaron de sus clases originales para evitar la
 * duplicación de código.
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
public final class DataUtils {

	/** The Constant logger. */
	private static final Logger logger = LoggerFactory.getLogger(DataUtils.class);

	/**
	 * Clase no instanciable.
	 */
	private DataUtils() {
		throw new IllegalStateException(CommonBaseConstants.MSG_UTILITY_CLASS);
	}

	/**
	 * Make csv.
	 *
	 * Retorna un CSV con las columnas indicadas en listColums extraidas de cada
	 * objeto de la lista listData. Los nombres de columnas han de coincidir con
	 * atributos de los objetos.
	 *
	 * @param <E>         the element type
	 * @param listData    the list data
	 * @param listColumns the list columns
	 * @return the byte[]
	 */
	public static <E> byte[] makeCsv(List<E> listData, List<String> listColumns) {
		final SheetDataStreamer streamer = new SheetDataStreamer(',');
		if (!org.apache.commons.collections4.CollectionUtils.isEmpty(listColumns)) {
			for (final String column : listColumns) {
				streamer.addColumnName(column);
			}
			if (!org.apache.commons.collections4.CollectionUtils.isEmpty(listData)) {
				extractData(streamer, listData, listColumns);
			}
		}
		final ByteArrayOutputStream outputStream = new ByteArrayOutputStream();
		final OutputStreamWriter writer = new OutputStreamWriter(outputStream);
		streamer.save(writer);
		return outputStream.toByteArray();
	}

	/**
	 * Extract data.
	 *
	 * @param <E>         the element type
	 * @param streamer    the streamer
	 * @param listData    the list data
	 * @param listColumns the list columns
	 */
	private static <E> void extractData(SheetDataStreamer streamer, List<E> listData, List<String> listColumns) {
		DefaultDataExtractor extractor = null;
		for (int i = 0; i < listData.size(); i = i + 1) {
			final E entity = listData.get(i);
			if (Objects.isNull(extractor)) {
				extractor = new DefaultDataExtractor(entity);
				logger.debug("makeCsv", "Creado extractor de datos para la clase",
						entity.getClass().getCanonicalName());
			}
			for (int j = 0; j < listColumns.size(); j = j + 1) {
				final String value = extractor.getColumnValue(entity, listColumns.get(j));
				logger.debug("makeCsv",
						String.format("Registro %s; Columna %s(%s): Valor=%s", i, j, listColumns.get(j), value));
				streamer.setValue(i, j, value);
			}
		}

	}

	/**
	 * Make csv.
	 *
	 * Retorna un CSV con las columnas indicadas en listColums extraidas de cada
	 * mapa de valores de la lista listData. Los nombres de columnas han de
	 * coincidir con las claves de los mapas de valores. El parámtro
	 * setStringColumns indica las columnas de entre las incluidas en listColumns
	 * que son de tipo cadena.
	 *
	 * @param listData         the list data
	 * @param listColumns      the list columns
	 * @param setStringColumns the set string columns
	 * @return the byte[]
	 */
	public static byte[] makeCsv(List<Map<String, String>> listData, List<String> listColumns,
			Set<String> setStringColumns) {
		final SheetDataStreamer streamer = new SheetDataStreamer(',');
		if (!org.apache.commons.collections4.CollectionUtils.isEmpty(listColumns)) {
			for (final String column : listColumns) {
				streamer.addColumnName(column);
			}
			if (!org.apache.commons.collections4.CollectionUtils.isEmpty(listData)) {
				if (Objects.isNull(setStringColumns)) {
					setStringColumns = new TreeSet<>();
				}
				extractDataFromMapObjects(streamer, listData, listColumns, setStringColumns);
			}
		}
		final ByteArrayOutputStream outputStream = new ByteArrayOutputStream();
		final OutputStreamWriter writer = new OutputStreamWriter(outputStream);
		streamer.save(writer);
		return outputStream.toByteArray();
	}

	/**
	 * Extract data from map objects.
	 *
	 * @param streamer         the streamer
	 * @param listData         the list data
	 * @param listColumns      the list columns
	 * @param setStringColumns the set string columns
	 */
	private static void extractDataFromMapObjects(SheetDataStreamer streamer, List<Map<String, String>> listData,
			List<String> listColumns, Set<String> setStringColumns) {
		for (int i = 0; i < listData.size(); i = i + 1) {
			final Map<String, String> entity = listData.get(i);
			for (int j = 0; j < listColumns.size(); j = j + 1) {
				String value = entity.get(listColumns.get(j));
				if (setStringColumns.contains(listColumns.get(j))) {
					value = String.format("\"%s\"", value);
				}
				logger.debug("makeCsv",
						String.format("Registro %s; Columna %s(%s): Valor=%s", i, j, listColumns.get(j), value));
				streamer.setValue(i, j, value);
			}
		}
	}

}
