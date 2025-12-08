package org.gjs.java.supplier.random;

import java.time.Instant;
import java.time.LocalDateTime;
import java.util.Date;
import java.util.TimeZone;

/**
 * Random Date supplier.
 *
 * Clase de datos de la librería Gjs
 *
 * Generadores de LocalDateTime aleatorias.
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
public class RandomLocalDateTimeSupplier extends AbstractRandomSupplier<LocalDateTime> {

    /** The date supplier. */
    private final RandomDateSupplier dateSupplier;

    /**
     * Instantiates a new random date supplier.
     */
    public RandomLocalDateTimeSupplier() {
        dateSupplier = new RandomDateSupplier();
    }

    /**
     * Instantiates a new random date supplier.
     *
     * @param dateRange
     *            the date range
     * @param onlyFuture
     *            the only future
     */
    public RandomLocalDateTimeSupplier(int dateRange, boolean onlyFuture) {
        dateSupplier = new RandomDateSupplier(dateRange, onlyFuture);
    }

    /* (non-Javadoc)
     *
     * @see org.gjs.java.test.testinggame.suppliers.Supplier#get() */

    @Override
    public LocalDateTime get() {
        final Date date = dateSupplier.get();
        return LocalDateTime.ofInstant(Instant.ofEpochMilli(date.getTime()), TimeZone.getDefault().toZoneId());
    }

    /* (non-Javadoc)
     *
     * @see org.gjs.java.test.objects.suppliers.Supplier#getEmpty() */

    @Override
    public LocalDateTime getEmpty() {
        return null;
    }

    /* (non-Javadoc)
     *
     * @see org.gjs.java.test.objects.suppliers.AbstractRandomSupplier#createArray(int) */

    @Override
    protected LocalDateTime[] createArray(int size) {
        return new LocalDateTime[size];
    }

}
