package org.gjs.java.supplier.random;

import java.sql.Timestamp;
import java.time.LocalDateTime;

/**
 * Random Timestamp supplier.
 *
 * Clase de datos de la librería Gjs
 *
 * Generadores de Timestamp aleatorios.
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
public class RandomTimestampSupplier extends AbstractRandomSupplier<Timestamp> {

    /** The date supplier. */
    private final RandomLocalDateTimeSupplier dateSupplier;

    /**
     * Instantiates a new random date supplier.
     */
    public RandomTimestampSupplier() {
        dateSupplier = new RandomLocalDateTimeSupplier();
    }

    /**
     * Instantiates a new random date supplier.
     *
     * @param dateRange
     *            the date range
     * @param onlyFuture
     *            the only future
     */
    public RandomTimestampSupplier(int dateRange, boolean onlyFuture) {
        dateSupplier = new RandomLocalDateTimeSupplier(dateRange, onlyFuture);
    }

    /* (non-Javadoc)
     *
     * @see org.gjs.java.test.testinggame.suppliers.Supplier#get() */

    @Override
    public Timestamp get() {
        final LocalDateTime date = dateSupplier.get();
        return Timestamp.valueOf(date);
    }

    /* (non-Javadoc)
     *
     * @see org.gjs.java.test.objects.suppliers.Supplier#getEmpty() */

    @Override
    public Timestamp getEmpty() {
        return null;
    }

    /* (non-Javadoc)
     *
     * @see org.gjs.java.test.objects.suppliers.AbstractRandomSupplier#createArray(int) */

    @Override
    protected Timestamp[] createArray(int size) {
        return new Timestamp[size];
    }

}
