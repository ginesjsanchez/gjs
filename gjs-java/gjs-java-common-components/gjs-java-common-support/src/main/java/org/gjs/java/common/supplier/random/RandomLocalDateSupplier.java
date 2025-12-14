package org.gjs.java.common.supplier.random;

import java.time.LocalDate;

/**
 * Random Date supplier.
 *
 * Clase de datos de la librería Gjs
 *
 * Generadores de LocalDate aleatorias.
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
public class RandomLocalDateSupplier extends AbstractRandomSupplier<LocalDate> {

    /** The local date time supplier. */
    private final RandomLocalDateTimeSupplier localDateTimeSupplier;

    /**
     * Instantiates a new random date supplier.
     */
    public RandomLocalDateSupplier() {
        localDateTimeSupplier = new RandomLocalDateTimeSupplier();
    }

    /**
     * Instantiates a new random date supplier.
     *
     * @param dateRange
     *            the date range
     * @param onlyFuture
     *            the only future
     */
    public RandomLocalDateSupplier(int dateRange, boolean onlyFuture) {
        localDateTimeSupplier = new RandomLocalDateTimeSupplier(dateRange, onlyFuture);
    }

    /* (non-Javadoc)
     *
     * @see org.gjs.java.test.testinggame.suppliers.Supplier#get() */

    @Override
    public LocalDate get() {
        return localDateTimeSupplier.get().toLocalDate();
    }

    /* (non-Javadoc)
     *
     * @see org.gjs.java.test.objects.suppliers.Supplier#getEmpty() */

    @Override
    public LocalDate getEmpty() {
        return null;
    }

    /* (non-Javadoc)
     *
     * @see org.gjs.java.test.objects.suppliers.AbstractRandomSupplier#createArray(int) */

    @Override
    protected LocalDate[] createArray(int size) {
        return new LocalDate[size];
    }

}
