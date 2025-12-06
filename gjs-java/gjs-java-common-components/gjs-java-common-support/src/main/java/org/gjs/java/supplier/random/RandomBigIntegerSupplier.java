package org.gjs.java.supplier.random;

import java.math.BigInteger;

/**
 * The Class RandomBigIntegerSupplier.
 *
 * Clase de datos de la librería Semilla
 *
 * Generadores de BigInteger aleatorios.
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
public class RandomBigIntegerSupplier extends AbstractRandomSupplier<BigInteger> {

    /** The double supplier. */
    private final RandomLongSupplier longSupplier = new RandomLongSupplier();

    /**
     * Instantiates a new random BigInteger supplier.
     */
    public RandomBigIntegerSupplier() {
        // No hace nada
    }

    /* (non-Javadoc)
     *
     * @see org.gjs.java.test.testinggame.suppliers.Supplier#get() */

    @Override
    public BigInteger get() {
        return BigInteger.valueOf(longSupplier.get());
    }

    /* (non-Javadoc)
     *
     * @see org.gjs.java.test.objects.suppliers.Supplier#getEmpty() */

    @Override
    public BigInteger getEmpty() {
        return null;
    }

    /* (non-Javadoc)
     *
     * @see org.gjs.java.test.objects.suppliers.AbstractRandomSupplier#createArray(int) */

    @Override
    protected BigInteger[] createArray(int size) {
        return new BigInteger[size];
    }
}
