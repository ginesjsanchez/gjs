package org.gjs.java.test.mock;

import java.util.Objects;

/**
 * The Class MockDatabaseSingleton.
 *
 * Clase singleton de la librería Semilla.
 *
 * Clase singleton pensada como proveedor global de una base de datos moqueada configurable para test.
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
public class MockDatabaseSingleton extends MockModelDataManager {

    /** The instance. */
    private static MockDatabaseSingleton instance;

    /**
     * Instantiates a new mock database singleton.
     */
    public MockDatabaseSingleton() {
        // No hace nada
    }

    /**
     * Gets the single instance of MockDatabaseSingleton.
     *
     * @return single instance of MockDatabaseSingleton
     */
    public static MockDatabaseSingleton getInstance() {
        if (Objects.isNull(instance)) {
            instance = new MockDatabaseSingleton();
        }
        return instance;
    }

}
