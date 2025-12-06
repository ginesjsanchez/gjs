package org.gjs.java.supplier.random;

import java.time.LocalDate;

/**
 * Random Date supplier.
 *
 * Clase de datos de la librería Semilla
 *
 * Generadores de LocalDate aleatorias.
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
 * @author Semilla
 * @version 4.0.0
 * @since 3.0.0
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
