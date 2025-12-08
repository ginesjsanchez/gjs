package org.gjs.java.test;

import org.springframework.test.annotation.Rollback;
import org.springframework.transaction.annotation.Transactional;

import jakarta.persistence.EntityManager;
import jakarta.persistence.PersistenceContext;

/**
 * The Class AbstractPersistenceUnitTest.
 *
 * Clase abstracta funcional de la librería Gjs
 *
 * Clase abstracta base para todos los test unitarios de clases que necesiten datos de un repositorio JPA de la librería
 * Gjs
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
 *
 * @author Gjs
 * @version 1.0.0
 * @since 1.0.0
 *
 */
@Transactional
@Rollback
public abstract class AbstractPersistenceUnitTest<T> extends AbstractDataObjectUnitTest<T> {

    /** The entity manager. */
    @PersistenceContext
    protected EntityManager entityManager;

    /**
     * Instantiates a new abstract persistence unit test.
     */
    public AbstractPersistenceUnitTest() {
    }

    /**
     * Instantiates a new abstract persistence unit test.
     *
     * @param testClazz
     *            the test clazz
     */
    public AbstractPersistenceUnitTest(Class<T> testClazz) {
        super(testClazz);
    }

}
