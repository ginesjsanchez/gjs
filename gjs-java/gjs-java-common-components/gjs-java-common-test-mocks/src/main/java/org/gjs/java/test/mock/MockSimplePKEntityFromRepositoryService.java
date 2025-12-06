package org.gjs.java.test.mock;

import java.util.Objects;

/**
 * The Class MockSimplePKEntityFromRepositoryService.
 *
 * Clase de la libreria Semilla Implementa un repositorio JPA de datos sencillo en memoria para cualquier clase de
 * objetos.
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
 * @param <DTO>
 *            the generic type
 * @param <E>
 *            the element type
 * @param <FDTO>
 *            the generic type
 *
 * @author Semilla
 * @version 4.0.0
 * @since 3.0.0
 *
 */
public abstract class MockSimplePKEntityFromRepositoryService<DTO, E, FDTO>
        extends MockEntityFromRepositoryService<DTO, Long, E, Long, FDTO> {

    /** The mock repository. */
    protected MockEntityDataManager<E, Long> mockRepository;

    /**
     * Instantiates a new mock simple PK entity from repository service.
     */
    public MockSimplePKEntityFromRepositoryService() {
    }

    /**
     * Instantiates a new mock simple PK entity from repository service.
     *
     * @param mockRepository
     *            the mock repository
     */
    public MockSimplePKEntityFromRepositoryService(MockEntityDataManager<E, Long> mockRepository) {
        this.mockRepository = mockRepository;
        if (Objects.nonNull(mockRepository)) {
            for (final E entity : mockRepository.getAll()) {
                super.put(entityToDto(entity));
            }
        }
    }

    /* (non-Javadoc)
     *
     * @see org.gjs.java.test.mock.MockEntityDataManager#getPKClazz() */

    @Override
    protected Class<?> getPKClazz() {
        return Long.class;
    }

}
