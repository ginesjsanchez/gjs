package org.gjs.java.supplier.random;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collection;
import java.util.List;
import java.util.Objects;

import org.gjs.java.util.ConditionUtils;

/**
 * The Class RandomNullableObjectSupplier.
 *
 * Clase abstracta de datos de la librería Gjs
 *
 * Clase abstracta base para selectores aleatorios de valores sacados de un conjunto.
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
 *            la clase de datos a generar
 *
 * @author Gjs
 * @version 1.0.0
 * @since 1.0.0
 *
 */
public abstract class RandomSelectedObjectSupplier<T> extends RandomNullableObjectSupplier<T> {

    /** The options. */
    private List<T> options;

    /** The index supplier. */
    private RandomIntegerSupplier indexSupplier;

    /**
     * Instantiates a new random selected object supplier.
     */
    public RandomSelectedObjectSupplier() {
        this.options = new ArrayList<>();
        indexSupplier = new RandomIntegerSupplier(Integer.valueOf(0), Integer.valueOf(-1));
    }

    /**
     * Instantiates a new random selected object supplier.
     *
     * @param options
     *            the options
     */
    @SafeVarargs
    public RandomSelectedObjectSupplier(T... options) {
        this(options, true);
    }

    /**
     * Instantiates a new random selected object supplier.
     *
     * @param options
     *            the options
     */
    public RandomSelectedObjectSupplier(Collection<T> options) {
        this(options, true);
    }

    /**
     * Instantiates a new random selected object supplier.
     *
     * @param options
     *            the options
     * @param nullable
     *            the nullable
     */
    public RandomSelectedObjectSupplier(T[] options, boolean nullable) {
        this(Arrays.asList(options), nullable);
    }

    /**
     * Instantiates a new random selected object supplier.
     *
     * @param options
     *            the options
     * @param nullable
     *            the nullable
     */
    public RandomSelectedObjectSupplier(Collection<T> options, boolean nullable) {
        super(nullable);
        this.options = new ArrayList<>();
        indexSupplier = new RandomIntegerSupplier(Integer.valueOf(0), Integer.valueOf(0));
        setOptions(options);
    }

    /**
     * Sets the options.
     *
     * @param options
     *            the new options
     */
    @SuppressWarnings("unchecked")
    protected void setOptions(T... options) {
        setOptions(Arrays.asList(options));
    }

    /**
     * Sets the options.
     *
     * @param options
     *            the new options
     */
    protected void setOptions(Collection<T> options) {
        this.options.clear();
        if (Objects.nonNull(options)) {
            this.options.addAll(options);
            indexSupplier.setMaxValue(this.options.size() - 1);
        } else {
            indexSupplier.setMaxValue(-1);
        }
    }

    /* (non-Javadoc)
     *
     * @see org.gjs.java.test.objects.suppliers.Supplier#get() */

    @Override
    public T get() {
        if (ConditionUtils.oneIsTrue(ConditionUtils.allAreTrue(isNullable(), mustBeNull()), options.isEmpty())) {
            return null;
        }
        final int index = indexSupplier.get();
        return options.get(index);
    }

}
