package org.gjs.java.task;

import java.io.IOException;
import java.util.ArrayList;
import java.util.List;

import org.apache.commons.lang3.builder.ToStringBuilder;
import org.apache.commons.lang3.builder.ToStringStyle;
import org.gjs.java.contant.CommonConstants;
import org.gjs.java.types.DocumentTemplate;

import lombok.Getter;

/**
 * The Class MultiTaskResult.
 *
 * Clase de datos de la librería Semilla
 *
 * Clase que almacena los resultados de una tarea multi-tarea, es decir, una
 * tarea que puede agrupar varias tareas. Está pensada para obtener el
 * resultados de los jobs que incorporan varias tareas.
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
public class MultiTaskResult extends TaskResult {

	/** The tasks. */
	private final List<TaskResult> tasks = new ArrayList<>();

	/**
	 * Instantiates a new task result.
	 *
	 */
	public MultiTaskResult() {
		this(CommonConstants.JOB_ANONYMOUS);
	}

	/**
	 * Instantiates a new task result.
	 *
	 * @param name the name
	 */
	public MultiTaskResult(String name) {
		this(name, "informes/jobMultiTarea.txt");
	}

	/**
	 * Instantiates a new task result.
	 *
	 * @param name           the name
	 * @param reportTemplate the report template
	 */
	public MultiTaskResult(String name, String reportTemplate) {
		super(name, reportTemplate);
	}

	/**
	 * Adds the task.
	 *
	 * @param taskResult the task result
	 */
	public void addTask(TaskResult taskResult) {
		taskResult.endTask();
		tasks.add(taskResult);
	}

	/**
	 * To report.
	 *
	 * @return the string
	 * @throws IOException Signals that an I/O exception has occurred.
	 */
	@Override
	public String toReport() throws IOException {
		final String content = prepareContent();
		final DocumentTemplate document = prepareReport();
		document.setField("content", content);
		return document.generateDocument();
	}

	/**
	 * Prepare content.
	 *
	 * @return the string
	 * @throws IOException Signals that an I/O exception has occurred.
	 */
	private String prepareContent() throws IOException {
		final StringBuilder sb = new StringBuilder();
		for (final TaskResult task : tasks) {
			sb.append(task.toReport()).append("\n\n");
		}
		return sb.toString();
	}

	/*
	 * (non-Javadoc)
	 *
	 * @see java.lang.Object#toString()
	 */

	@Override
	public String toString() {
		return new ToStringBuilder(this, ToStringStyle.SHORT_PREFIX_STYLE).append("name", name).append("begin", begin)
				.append("end", end).append("duration", duration).append("reportTemplate", reportTemplate).toString();
	}

}
