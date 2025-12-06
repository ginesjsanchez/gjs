package org.gjs.java.jpa;

import org.springframework.data.jpa.repository.JpaRepository;

import lombok.Getter;

/**
 * The Class JpaStringPKRepositoryWrapper.
 *
 * Clase de datos de la librería Semilla
 *
 * Clase que permite recubrir un repositorio JPA de una entidad con clave primaria de tipo Long.
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
 * @param <T>
 *            la entidad JPA
 *
 * @author Semilla
 * @version 4.0.0
 * @since 3.0.0
 *
 */
@Getter
public class JpaStringPKRepositoryWrapper<T> extends JpaRepositoryWrapper<T, String> {

    /**
     * Instantiates a new jpa simple PK repository wrapper.
     *
     * @param entity
     *            the entity
     * @param repository
     *            the repository
     */
    public JpaStringPKRepositoryWrapper(Class<T> entity, JpaRepository<T, String> repository) {
        super(entity, String.class, repository);
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
    public JpaStringPKRepositoryWrapper(Class<T> entity, JpaRepository<T, String> repository, String dataFile) {
        super(entity, String.class, repository, dataFile);
    }

}
