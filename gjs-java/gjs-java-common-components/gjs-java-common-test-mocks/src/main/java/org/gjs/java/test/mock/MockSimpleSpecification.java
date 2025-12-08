package org.gjs.java.test.mock;

/**
 * The Class MockSpecification.
 *
 * Clase de datos de la librería Gjs
 *
 * Implementa un mock de una specification JPA para cualquier clase de objetos que no utilice una clase diferente para
 * definir los filtros.
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
 * @param <E>
 *            la clase de la entidad
 *
 * @author Gjs
 * @version 1.0.0
 * @since 1.0.0
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
