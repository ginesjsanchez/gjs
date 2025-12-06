package org.gjs.java.test.mock;

/**
 * The Class MockSpecification.
 *
 * Clase de datos de la librería Semilla
 *
 * Implementa un mock de una specification JPA para cualquier clase de objetos que no utilice una clase diferente para
 * definir los filtros.
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
 *
 * @author Semilla
 * @version 4.0.0
 * @since 3.0.0
 *
 */
public class MockSimpleSpecification<E> extends MockSpecification<E, E> {

    /** The Constant serialVersionUID. */
    private static final long serialVersionUID = 1364199251310514936L;

    /**
     * Instantiates a new mock specification.
     */
    public MockSimpleSpecification() {
    }

    /**
     * Instantiates a new mock specification.
     *
     * @param filter
     *            the filter
     */
    public MockSimpleSpecification(E filter) {
        super(filter);
    }

}
