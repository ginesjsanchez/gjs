package org.gjs.java.test.mock;

import java.io.IOException;

import org.springframework.core.io.Resource;

/**
 * The Class MockStringPKRepository.
 *
 * Clase de datos de la librería Gjs
 *
 * Implementa un repositorio JPA de datos sencillo en memoria para cualquier clase de objetos cuya clave primaria sea un
 * String.
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
 *            la clase de las entidad
 *
 * @author Gjs
 * @version 1.0.0
 * @since 1.0.0
 *
 */
public class MockStringPKRepository<T> extends MockRepository<T, String> {

    /**
     * Instantiates a new mock simple PK repository.
     */
    public MockStringPKRepository() {
    }

    /**
     * Instantiates a new mock simple PK repository.
     *
     * @param resource
     *            the resource
     * @throws IOException
     *             Signals that an I/O exception has occurred.
     */
    public MockStringPKRepository(Resource resource) throws IOException {
        super(resource);
    }

    /* (non-Javadoc)
     *
     * @see org.gjs.java.test.mock.MockRepository#autogenerateId() */

    @Override
    protected boolean autogenerateId() {
        return false;
    }

}
