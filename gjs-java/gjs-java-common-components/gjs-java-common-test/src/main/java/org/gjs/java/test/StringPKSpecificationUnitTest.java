package org.gjs.java.test;

import org.gjs.java.util.ConditionUtils;

/**
 * The Class StringPKSpecificationUnitTest.
 *
 * Clase abstracta funcional de la librería Gjs
 *
 * Clase abstracta base para todos los test unitarios de specification JPA con clave de tipo String que usen una clase
 * especial para obtener los datos de filtrado diferente de la entidad de la librería Gjs
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
 *            el repositorio JPA
 * @param <F>
 *            el filtro
 * @param <E>
 *            la entidad JPA
 *
 * @author Gjs
 * @version 1.0.0
 * @since 1.0.0
 *
 */
public abstract class StringPKSpecificationUnitTest<T, F, E> extends BaseSpecificationUnitTest<T, F, E, String> {

    /**
     * Instantiates a new simple PK specification unit test.
     *
     * @param testClazz
     *            the test clazz
     * @param filterClazz
     *            the filter clazz
     * @param entityClazz
     *            the entity clazz
     */
    public StringPKSpecificationUnitTest(Class<T> testClazz, Class<F> filterClazz, Class<E> entityClazz) {
        super(testClazz, filterClazz, entityClazz, String.class);
    }

    /* (non-Javadoc)
     *
     * @see org.gjs.java.test.AbstractRepositoryUnitTest#getImmutableId(int) */

    @Override
    protected String getImmutableId(int index) {
        String res = null;
        final String[] immutableCods = getImmutableCods();
        if (ConditionUtils.allAreTrue((index >= 0), (index < immutableCods.length))) {
            res = immutableCods[index];
        }
        return res;
    }

    /* (non-Javadoc)
     *
     * @see org.gjs.java.test.AbstractRepositoryUnitTest#getNonExistentId() */

    @Override
    protected String getNonExistentId() {
        return CODNE;
    }

    /* (non-Javadoc)
     *
     * @see org.gjs.java.test.BaseSpecificationUnitTest#isExpected(java.lang.Object) */

    @Override
    protected boolean isExpected(String id) {
        return isCodExpected(id);
    }

}
