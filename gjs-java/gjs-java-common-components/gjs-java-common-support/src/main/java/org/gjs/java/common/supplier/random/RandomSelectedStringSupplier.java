package org.gjs.java.common.supplier.random;

import java.util.Arrays;
import java.util.Collection;

/**
 * The Class RandomAlphanumericStringSupplier.
 *
 * Clase de datos de la librería Gjs
 *
 * Selectores aleatorios de cadenas sacadas de un conjunto.
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
 * @author Gjs
 * @version 1.0.0
 * @since 1.0.0
 *
 */
public class RandomSelectedStringSupplier extends RandomSelectedObjectSupplier<String> {

    /**
     * Instantiates a new random selected string supplier.
     */
    public RandomSelectedStringSupplier() {
    }

    /**
     * Instantiates a new random selected string supplier.
     *
     * @param options
     *            the options
     */
    public RandomSelectedStringSupplier(String... options) {
        this(options, true);
    }

    /**
     * Instantiates a new random selected string supplier.
     *
     * @param options
     *            the options
     */
    public RandomSelectedStringSupplier(Collection<String> options) {
        this(options, true);
    }

    /**
     * Instantiates a new random selected string supplier.
     *
     * @param options
     *            the options
     * @param nullable
     *            the nullable
     */
    public RandomSelectedStringSupplier(String[] options, boolean nullable) {
        this(Arrays.asList(options), nullable);
    }

    /**
     * Instantiates a new random selected string supplier.
     *
     * @param options
     *            the options
     * @param nullable
     *            the nullable
     */
    public RandomSelectedStringSupplier(Collection<String> options, boolean nullable) {
        super(options, nullable);
    }

    /* (non-Javadoc)
     *
     * @see org.gjs.java.test.objects.suppliers.AbstractRandomSupplier#createArray(int) */

    @Override
    protected String[] createArray(int size) {
        return new String[size];
    }
}
