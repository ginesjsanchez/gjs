package org.gjs.java.task;

import java.io.IOException;

import org.apache.commons.lang3.builder.ToStringBuilder;
import org.apache.commons.lang3.builder.ToStringStyle;
import org.gjs.java.contant.CommonConstants;
import org.gjs.java.types.DocumentTemplate;
import org.gjs.java.util.ConversionUtils;

/**
 * The Class DetailedTaskResult.
 *
 * Clase de datos de la librería Semilla
 *
 * Clase que almacena los resultados de una tarea con mayor detalle en el que se
 * puede guardar la información de cada registro e informaciones adiconales.
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
public class DetailedTaskResult extends TaskResult {

	/** The detail. */
	protected StringBuilder detail = new StringBuilder();

	/**
	 * Instantiates a new task result.
	 *
	 */
	public DetailedTaskResult() {
	}

	/**
	 * Instantiates a new task result.
	 *
	 * @param name        the name
	 * @param description the description
	 */
	public DetailedTaskResult(String name, String description) {
		super(name, description, "informes/jobDetallado.txt");
	}

	/**
	 * Instantiates a new task result.
	 *
	 * @param name           the name
	 * @param description    the description
	 * @param reportTemplate the report template
	 */
	public DetailedTaskResult(String name, String description, String reportTemplate) {
		super(name, description, reportTemplate);
	}

	/**
	 * Increment ok.
	 *
	 * @param data the data
	 */
	public void incrementOk(Object data) {
		incrementOk();
		detail.append(String.format("%s: %s\n", CommonConstants.DEFAULT_OK_RESPONSE, ConversionUtils.toString(data)));
	}

	/**
	 * Increment ok.
	 *
	 * @param data the data
	 */
	public void incrementOk(String data) {
		incrementOk();
		detail.append(String.format("%s: %s\n", CommonConstants.DEFAULT_OK_RESPONSE, data));
	}

	/**
	 * Increment ko.
	 *
	 * @param data the data
	 */
	public void incrementKo(Object data) {
		incrementKo();
		detail.append(String.format("%s: %s\n", CommonConstants.DEFAULT_KO_RESPONSE, ConversionUtils.toString(data)));
	}

	/**
	 * Increment ko.
	 *
	 * @param data the data
	 */
	public void incrementKo(String data) {
		incrementKo();
		detail.append(String.format("%s: %s\n", CommonConstants.DEFAULT_KO_RESPONSE, data));
	}

	/**
	 * Increment.
	 *
	 * @param ok   the ok
	 * @param data the data
	 */
	public void increment(boolean ok, Object data) {
		increment(ok);
		detail.append(String.format("%s: %s\n",
				(ok ? CommonConstants.DEFAULT_OK_RESPONSE : CommonConstants.DEFAULT_KO_RESPONSE),
				ConversionUtils.toString(data)));
	}

	/**
	 * Increment.
	 *
	 * @param ok   the ok
	 * @param data the data
	 */
	public void increment(boolean ok, String data) {
		increment(ok);
		detail.append(String.format("%s: %s\n",
				(ok ? CommonConstants.DEFAULT_OK_RESPONSE : CommonConstants.DEFAULT_KO_RESPONSE), data));
	}

	/**
	 * Adds the detail new line.
	 */
	public void addDetailNewLine() {
		detail.append('\n');
	}

	/**
	 * Adds the detail.
	 *
	 * @param text the text
	 */
	public void addDetail(String text) {
		detail.append(String.format("%s\n", text));
	}

	/**
	 * To report.
	 *
	 * @return the string
	 * @throws IOException Signals that an I/O exception has occurred.
	 */
	@Override
	public String toReport() throws IOException {
		final DocumentTemplate document = prepareReport();
		return document.generateDocument();
	}

	/**
	 * Prepare report.
	 *
	 * @return the document template
	 * @throws IOException Signals that an I/O exception has occurred.
	 */
	@Override
	protected DocumentTemplate prepareReport() throws IOException {
		final DocumentTemplate document = super.prepareReport();
		document.setField("processed", ConversionUtils.toString(processed));
		document.setField("completed", ConversionUtils.toString(completed));
		document.setField("errors", ConversionUtils.toString(errors));
		document.setField("content", detail.toString());
		return document;
	}

	/*
	 * (non-Javadoc)
	 *
	 * @see java.lang.Object#toString()
	 */

	@Override
	public String toString() {
		return new ToStringBuilder(this, ToStringStyle.SHORT_PREFIX_STYLE).append("name", name).append("begin", begin)
				.append("end", end).append("duration", duration).append("reportTemplate", reportTemplate)
				.append("processed", processed).append("errors", errors).append("completed", completed).toString();
	}

}
