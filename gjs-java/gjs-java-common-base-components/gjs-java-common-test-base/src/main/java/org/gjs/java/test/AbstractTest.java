package org.gjs.java.test;

import org.junit.jupiter.api.AfterAll;
import org.junit.jupiter.api.BeforeAll;
import org.junit.jupiter.api.TestInstance;
import org.junit.jupiter.api.TestInstance.Lifecycle;
import org.slf4j.Logger;
import org.slf4j.LoggerFactory;

/**
 * The Class AbstractTest.
 *
 * Clase abstracta funcional de la librería Gjs
 *
 * Clase abstracta base para todos los test de la librería Gjs
 *
 * --------------------------------------------------------------------------------------------------------------------
 *
 *
 * correspondiente licencia en los activos de la SES. Los programas informáticos
 * propiedad de la SES están protegidos por la propiedad intelectual, y por
 * tanto está estrictamente prohibida su reproducción, modificación, cesión o
 * comunicación sin la debida autorización. Queda estrictamente prohibido el
 * uso, reproducción, cesión, transformación o comunicación pública de cualquier
 * otro tipo de obra o invención protegida por la propiedad intelectual sin la
 * debida autorización.
 *
 * Seguridad Ministerio del Interior Gobierno de España
 * --------------------------------------------------------------------------------------------------------------------
 *
 * @author Gjs
 * @version 1.0.0
 * @since 1.0.0
 *
 */
@TestInstance(Lifecycle.PER_CLASS)
public abstract class AbstractTest {

	/** The logger. */
	protected Logger logger;

	/**
	 * Prepare test.
	 */
	protected abstract void prepareTest() throws Exception;

	/**
	 * Finalize test.
	 */
	protected abstract void finalizeTest() throws Exception;

	/**
	 * Initialize logger.
	 */
	protected void initializeLogger() {
		logger = LoggerFactory.getLogger(getClass());
		logger.info("INICIO Test unitario {}", getClass().getName());
	}

	/**
	 * Finalize logger.
	 */
	protected void finalizeLogger() {
		logger.info("FIN Test unitario {}", getClass().getName());
	}

	/**
	 * Before all.
	 */
	@BeforeAll
	protected void beforeAll() throws Exception {
		initializeLogger();
		prepareTest();
	}

	/**
	 * After all.
	 */
	@AfterAll
	protected void afterAll() throws Exception {
		finalizeTest();
		finalizeLogger();
	}

}
