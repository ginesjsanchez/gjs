package org.gjs.java.test.tester;

import org.gjs.java.log.LogManager;

import com.openpojo.reflection.PojoClass;
import com.openpojo.validation.affirm.Affirm;
import com.openpojo.validation.test.Tester;

/**
 * The Class BaseTester.
 *
 * Clase abstracta de datos de la librería Semilla
 *
 * Clase abstracta base para implementar tester customizados.
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
public abstract class BaseTester extends LogManager implements Tester {

	/** The stop on error. */
	private final boolean stopOnError;

	/**
	 * Instantiates a new base tester.
	 */
	protected BaseTester() {
		stopOnError = true;
	}

	/**
	 * Instantiates a new base tester.
	 *
	 * @param stopOnError the stop on error
	 */
	protected BaseTester(boolean stopOnError) {
		this.stopOnError = stopOnError;
	}

	/**
	 * Checks if is stop on error.
	 *
	 * @return true, if is stop on error
	 */
	protected boolean isStopOnError() {
		return this.stopOnError;
	}

	/**
	 * Can run.
	 *
	 * @param pojoClass the pojo class
	 * @return true, if successful
	 */
	protected abstract boolean canRun(PojoClass pojoClass);

	/**
	 * Run test.
	 *
	 * @param pojoClass the pojo class
	 */
	protected abstract void runTest(PojoClass pojoClass);

	/*
	 * (non-Javadoc)
	 *
	 * @see
	 * com.openpojo.validation.test.Tester#run(com.openpojo.reflection.PojoClass)
	 */

	@Override
	public void run(PojoClass pojoClass) {
		if (canRun(pojoClass)) {
			runTest(pojoClass);
		}
	}

	/**
	 * Affirm true.
	 *
	 * @param message   the message
	 * @param condition the condition
	 */
	protected void affirmTrue(final String message, final boolean condition) {
		try {
			Affirm.affirmTrue(message, condition);
		} catch (final AssertionError e) {
			if (stopOnError) {
				throw e;
			}
			error(message);
		}

	}

	/**
	 * Affirm false.
	 *
	 * @param message   the message
	 * @param condition the condition
	 */
	protected void affirmFalse(final String message, final boolean condition) {
		try {
			Affirm.affirmFalse(message, condition);
		} catch (final AssertionError e) {
			if (stopOnError) {
				throw e;
			}
			error(message);
		}

	}

	/**
	 * Affirm not null.
	 *
	 * @param message the message
	 * @param object  the object
	 */
	protected void affirmNotNull(final String message, final Object object) {
		try {
			Affirm.affirmNotNull(message, object);
		} catch (final AssertionError e) {
			if (stopOnError) {
				throw e;
			}
			error(message);
		}

	}

	/**
	 * Affirm null.
	 *
	 * @param message the message
	 * @param object  the object
	 */
	protected void affirmNull(final String message, final Object object) {
		try {
			Affirm.affirmNull(message, object);
		} catch (final AssertionError e) {
			if (stopOnError) {
				throw e;
			}
			error(message);
		}

	}

	/**
	 * Affirm equals.
	 *
	 * @param message  the message
	 * @param expected the expected
	 * @param actual   the actual
	 */
	protected void affirmEquals(final String message, final Object expected, final Object actual) {
		try {
			Affirm.affirmEquals(message, expected, actual);
		} catch (final AssertionError e) {
			if (stopOnError) {
				throw e;
			}
			error(message);
		}

	}

	/**
	 * Affirm same.
	 *
	 * @param message the message
	 * @param first   the first
	 * @param second  the second
	 */
	protected void affirmSame(final String message, final Object first, final Object second) {
		try {
			Affirm.affirmSame(message, first, second);
		} catch (final AssertionError e) {
			if (stopOnError) {
				throw e;
			}
			error(message);
		}

	}

}
