package org.gjs.java.test;

import org.gjs.java.util.ConditionUtils;
import org.springframework.data.jpa.repository.JpaRepository;

/**
 * The Class StringPKRepositoryUnitTest.
 *
 * Clase funcional de la librería Gjs
 *
 * Clase base para todos los test unitarios de repositorios JPA con clave de tipo String de la librería Gjs
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
 * @param <JPA>
 *            el repositorio JPA
 * @param <E>
 *            la entidad JPA
 *
 * @author Gjs
 * @version 1.0.0
 * @since 1.0.0
 *
 */
public abstract class StringPKRepositoryUnitTest<E, JPA extends JpaRepository<E, String>>
        extends BaseRepositoryUnitTest<E, String, JPA> {

    /**
     * Instantiates a new simple PK repository unit test.
     *
     * @param testClazz
     *            the test clazz
     * @param entityClazz
     *            the entity clazz
     */
    public StringPKRepositoryUnitTest(Class<JPA> testClazz, Class<E> entityClazz) {
        super(testClazz, entityClazz, String.class);
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
     * @see org.gjs.java.test.BaseRepositoryUnitTest#isExpected(java.lang.Object) */

    @Override
    protected boolean isExpected(String id) {
        return isCodExpected(id);
    }

}
