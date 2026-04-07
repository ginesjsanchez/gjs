package org.gjs.java.test.mock;

import java.util.Objects;

/**
 * The Class MockDatabaseSingleton.
 *
 * Clase singleton de la librería Gjs.
 *
 * Clase singleton pensada como proveedor global de una base de datos moqueada configurable para test.
 *
 * --------------------------------------------------------------------------------------------------------------------
 *
 *
 * correspondiente licencia en los activos de la
 * SES. Los programas informáticos propiedad de la SES están protegidos por la propiedad intelectual, y por tanto está
 * estrictamente prohibida su reproducción, modificación, cesión o comunicación sin la debida autorización. Queda
 * estrictamente prohibido el uso, reproducción, cesión, transformación o comunicación pública de cualquier otro tipo de
 * obra o invención protegida por la propiedad intelectual sin la debida autorización.
 *
 *  Seguridad Ministerio del Interior
 * Gobierno de España
 * --------------------------------------------------------------------------------------------------------------------
 *
 * @author Gjs
 * @version 1.0.0
 * @since 1.0.0
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
