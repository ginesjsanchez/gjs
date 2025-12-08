package org.gjs.java.jpa;

import org.springframework.data.jpa.repository.JpaRepository;

import lombok.Getter;

/**
 * The Class JpaSimplePKRepositoryWrapper.
 *
 * Clase de datos de la librería Gjs
 *
 * Clase que permite recubrir un repositorio JPA de una entidad con clave primaria de tipo Long.
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
 *            la entidad JPA
 *
 * @author Gjs
 * @version 1.0.0
 * @since 1.0.0
 *
 */
@Getter
public class JpaSimplePKRepositoryWrapper<T> extends JpaRepositoryWrapper<T, Long> {

    /**
     * Instantiates a new jpa simple PK repository wrapper.
     *
     * @param entity
     *            the entity
     * @param repository
     *            the repository
     */
    public JpaSimplePKRepositoryWrapper(Class<T> entity, JpaRepository<T, Long> repository) {
        super(entity, Long.class, repository);
    }

    /**
     * Instantiates a new jpa simple PK repository wrapper.
     *
     * @param entity
     *            the entity
     * @param repository
     *            the repository
     * @param dataFile
     *            the data file
     */
    public JpaSimplePKRepositoryWrapper(Class<T> entity, JpaRepository<T, Long> repository, String dataFile) {
        super(entity, Long.class, repository, dataFile);
    }

}
