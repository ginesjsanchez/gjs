package org.gjs.java.test.mock;

import org.springframework.data.jpa.domain.Specification;

import jakarta.persistence.criteria.CriteriaBuilder;
import jakarta.persistence.criteria.CriteriaQuery;
import jakarta.persistence.criteria.Predicate;
import jakarta.persistence.criteria.Root;

/**
 * The Class MockSpecification.
 *
 * Clase de datos de la librería Semilla
 *
 * Implementa un mock de una specification JPA para cualquier clase de objetos.
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
 * @param <E>
 *            la clase de la entidad
 * @param <F>
 *            la clase de filtrado de datos
 *
 * @author Semilla
 * @version 4.0.0
 * @since 3.0.0
 *
 */
public class MockSpecification<E, F> implements Specification<E> {

    /** The Constant serialVersionUID. */
    private static final long serialVersionUID = -7984377625040899124L;

    /** The filter. */
    protected transient F filter;

    /**
     * Instantiates a new mock specification.
     */
    public MockSpecification() {
    }

    /**
     * Instantiates a new mock specification.
     *
     * @param filter
     *            the filter
     */
    public MockSpecification(F filter) {
        setFilter(filter);
    }

    /**
     * Gets the filter.
     *
     * @return the filter
     */
    public F getFilter() {
        return filter;
    }

    /**
     * Sets the filter.
     *
     * @param filter
     *            the new filter
     */
    public void setFilter(F filter) {
        this.filter = filter;
    }

    /* (non-Javadoc)
     *
     * @see org.springframework.data.jpa.domain.Specification#toPredicate(jakarta.persistence.criteria.Root,
     * jakarta.persistence.criteria.CriteriaQuery, jakarta.persistence.criteria.CriteriaBuilder) */

    @Override
    public Predicate toPredicate(Root<E> root, CriteriaQuery<?> query, CriteriaBuilder criteriaBuilder) {
        return null;
    }

}
