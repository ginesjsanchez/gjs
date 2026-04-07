package org.gjs.java.test.mock;

import java.io.IOException;

import org.springframework.core.io.Resource;

/**
 * The Class MockSimplePKEntityService.
 *
 * Clase de datos de la librería Gjs
 *
 * Implementa un servicio de datos sencillo en memoria para cualquier clase de objetos cuya clave primaria sea un Long.
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
 * @param <PK>
 *            la clave primaria de la entidad
 * @param <F>
 *            la clase de filtrado de datos
 *
 * @author Gjs
 * @version 1.0.0
 * @since 1.0.0
 *
 */
public class MockSimplePKEntityService<T, F> extends MockEntityService<T, Long, F> {

    /**
     * Instantiates a new mock simple PK entity service.
     */
    public MockSimplePKEntityService() {
    }

    /**
     * Instantiates a new mock simple PK entity service.
     *
     * @param path
     *            the path
     */
    public MockSimplePKEntityService(String path) {
        super(path);
    }

    /**
     * Instantiates a new mock simple PK entity service.
     *
     * @param resource
     *            the resource
     * @throws IOException
     *             Signals that an I/O exception has occurred.
     */
    public MockSimplePKEntityService(Resource resource) throws IOException {
        super(resource.getFile().getAbsolutePath());
    }

}
