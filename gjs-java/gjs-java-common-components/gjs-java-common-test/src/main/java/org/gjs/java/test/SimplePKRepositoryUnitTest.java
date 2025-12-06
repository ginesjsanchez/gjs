package org.gjs.java.test;

import org.gjs.java.common.ConditionUtils;
import org.springframework.data.jpa.repository.JpaRepository;

/**
 * The Class SimplePKRepositoryUnitTest.
 *
 * Clase funcional de la librería Semilla
 *
 * Clase base para todos los test unitarios de repositorios JPA con clave de tipo Long de la librería Semilla
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
 * @param <JPA>
 *            el repositorio JPA
 * @param <E>
 *            la entidad JPA
 *
 * @author Semilla
 * @version 4.0.0
 * @since 3.0.0
 *
 */
public abstract class SimplePKRepositoryUnitTest<E, JPA extends JpaRepository<E, Long>>
        extends BaseRepositoryUnitTest<E, Long, JPA> {

    /**
     * Instantiates a new simple PK repository unit test.
     *
     * @param testClazz
     *            the test clazz
     * @param entityClazz
     *            the entity clazz
     */
    public SimplePKRepositoryUnitTest(Class<JPA> testClazz, Class<E> entityClazz) {
        super(testClazz, entityClazz, Long.class);
    }

    /* (non-Javadoc)
     *
     * @see org.gjs.java.test.AbstractRepositoryUnitTest#getImmutableId(int) */

    @Override
    protected Long getImmutableId(int index) {
        Long res = null;
        final Long[] immutableIds = getImmutableIds();
        if (ConditionUtils.allAreTrue((index >= 0), (index < immutableIds.length))) {
            res = immutableIds[index];
        }
        return res;
    }

    /* (non-Javadoc)
     *
     * @see org.gjs.java.test.AbstractRepositoryUnitTest#getNonExistentId() */

    @Override
    protected Long getNonExistentId() {
        return IDNE;
    }

    /* (non-Javadoc)
     *
     * @see org.gjs.java.test.BaseRepositoryUnitTest#isExpected(java.lang.Object) */

    @Override
    protected boolean isExpected(Long id) {
        return isIdExpected(id);
    }

}
