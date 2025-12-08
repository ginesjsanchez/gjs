package org.gjs.java.test;

import java.lang.reflect.ParameterizedType;
import java.util.Objects;

/**
 * The Class BaseIntegrationTest.
 *
 * Clase funcional de la librería Gjs
 *
 * Clase base para todos los test de integración de la librería Gjs
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
 * @param <T>
 *            la clase a testear
 *
 * @author Gjs
 * @version 1.0.0
 * @since 1.0.0
 *
 */
public class BaseIntegrationTest<T> extends AbstractClassTest {

    /** The test clazz. */
    private final Class<T> testClazz;

    /**
     * Instantiates a new base unit test.
     */
    @SuppressWarnings("unchecked")
    public BaseIntegrationTest() {
        testClazz = (Class<T>) ((ParameterizedType) getClass().getGenericSuperclass()).getActualTypeArguments()[0];
    }

    /**
     * Instantiates a new base unit test.
     *
     * @param testClazz
     *            the test clazz
     */
    public BaseIntegrationTest(Class<T> testClazz) {
        this.testClazz = testClazz;
    }

    /* (non-Javadoc)
     *
     * @see org.gjs.java.test.AbstractUnitTest#getClazz() */

    @Override
    protected Class<?> getClazz() {
        return testClazz;
    }

    /**
     * Checks if is valid.
     *
     * @return true, if is valid
     */
    public boolean isValid() {
        return Objects.nonNull(testClazz);
    }
}
