package org.gjs.java.test.tester;

import org.slf4j.Logger;

import com.openpojo.reflection.PojoClass;

/**
 * The Class BaseFieldTester.
 *
 * Clase abstracta de datos de la librería Semilla
 *
 * Clase abstracta base para implementar tester customizados sobre atributos.
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
public abstract class BaseFieldTester extends BaseTester {

	/** The tester name. */
	protected String testerName;

	/** The class name. */
	protected String className;

	/** The fields tested. */
	private int fieldsTested;

	/** The total fields. */
	private int totalFields;

	/**
	 * Instantiates a new base field tester.
	 *
	 * @param logger     the logger
	 * @param testerName the tester name
	 */
	protected BaseFieldTester(Logger logger, String testerName) {
		this.testerName = testerName;
		setLogger(logger);
	}

	/**
	 * Instantiates a new base field tester.
	 *
	 * @param logger      the logger
	 * @param testerName  the tester name
	 * @param stopOnError the stop on error
	 */
	protected BaseFieldTester(Logger logger, String testerName, boolean stopOnError) {
		super(stopOnError);
		this.testerName = testerName;
		setLogger(logger);
	}

	/*
	 * (non-Javadoc)
	 *
	 * @see
	 * org.gjs.java.test.tester.BaseTester#canRun(com.openpojo.reflection.PojoClass)
	 */

	@Override
	protected boolean canRun(PojoClass pojoClass) {
		return true;
	}

	/**
	 * Begin class.
	 *
	 * @param className   the class name
	 * @param totalFields the total fields
	 */
	protected void beginClass(String className, int totalFields) {
		this.className = className;
		this.fieldsTested = 0;
		this.totalFields = totalFields;
		info("{} Tester for class {}", this.testerName, this.className);
	}

	/**
	 * Field processed.
	 */
	protected void fieldProcessed() {
		fieldsTested = fieldsTested + 1;
	}

	/**
	 * End class.
	 */
	protected void endClass() {
		info("Class {}: fields tested{}/{}", className, fieldsTested, totalFields);
	}

}
