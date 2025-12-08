package org.gjs.java.test;

import org.gjs.java.test.mock.MockModelDataManager;

/**
 * The Class BaseDataServiceUnitTest.
 *
 * Clase abtracta funcional de la librería Gjs
 *
 * Clase base genérica para implementar los tests unitarios de los servicios de la librería Gjs
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
 * @param <T>
 *            clase a testear
 * @param <D>
 *            clase mock de la base de datos
 */
public abstract class BaseDataServiceUnitTest<T, D extends MockModelDataManager> extends AbstractDataObjectUnitTest<T> {

    /** The mock database. */
    // Mocks
    protected D mockDatabase;

    /**
     * Instantiates a new abstract data object unit test.
     */
    public BaseDataServiceUnitTest() {
    }

    /**
     * Instantiates a new abstract data object unit test.
     *
     * @param testClazz
     *            the test clazz
     */
    public BaseDataServiceUnitTest(Class<T> testClazz) {
        super(testClazz);
    }

    /**
     * Creates the mock database.
     *
     * @return the d
     * @throws Exception
     *             the exception
     */
    protected abstract D createMockDatabase() throws Exception;

    /* (non-Javadoc)
     *
     * @see org.gjs.java.test.AbstractDataObjectUnitTest#loadTestData() */

    @Override
    protected long loadTestData() throws Exception {
        mockDatabase = createMockDatabase();
        return getExpected().length;
    }

}
