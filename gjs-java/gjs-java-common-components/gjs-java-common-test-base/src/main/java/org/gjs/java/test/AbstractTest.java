package org.gjs.java.test;

import org.slf4j.LoggerFactory;
import org.slf4j.Logger;
import org.junit.jupiter.api.AfterAll;
import org.junit.jupiter.api.BeforeAll;
import org.junit.jupiter.api.TestInstance;
import org.junit.jupiter.api.TestInstance.Lifecycle;

/**
 * The Class AbstractTest.
 *
 * Clase abstracta funcional de la librería Semilla
 *
 * Clase abstracta base para todos los test de la librería Semilla
 *
 * --------------------------------------------------------------------------------------------------------------------
 * Este software es propiedad del Ministerio del Interior CETSE - 2025
 *
 * Queda estrictamente prohibido el uso de programas informáticos sin la correspondiente licencia en los activos de la
 * SES. Los programas informáticos propiedad de la SES están protegidos por la propiedad intelectual, y por tanto está
 * estrictamente prohibida su reproducción, modificación, cesión o comunicación sin la debida autorización. Queda
 * estrictamente prohibido el uso, reproducción, cesión, transformación o comunicación pública de cualquier otro tipo de
 * obra o invención protegida por la propiedad intelectual sin la debida autorización.
 *
 * Subdirección General de Sistemas de la Información y Comunicaciones para la Seguridad Ministerio del Interior
 * Gobierno de España
 * --------------------------------------------------------------------------------------------------------------------
 *
 * @author Semilla
 * @version 4.0.0
 * @since 3.0.0
 *
 */
@TestInstance(Lifecycle.PER_CLASS)
public abstract class AbstractTest {

    /** The logger. */
    protected Logger logger;

    /**
     * Prepare test.
     */
    protected abstract void prepareTest();

    /**
     * Finalize test.
     */
    protected abstract void finalizeTest();

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
    protected void beforeAll() {
        initializeLogger();
        prepareTest();
    }

    /**
     * After all.
     */
    @AfterAll
    protected void afterAll() {
        finalizeTest();
        finalizeLogger();
    }

}
