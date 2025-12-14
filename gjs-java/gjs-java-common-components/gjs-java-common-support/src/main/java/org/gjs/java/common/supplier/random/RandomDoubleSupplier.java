package org.gjs.java.common.supplier.random;

/**
 * Random Double supplier.
 *
 * Clase de datos de la librería Gjs
 *
 * Generadores de reales dobles aleatorios.
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
public class RandomDoubleSupplier extends AbstractRandomSupplier<Double> {

    /** The only positives. */
    private boolean onlyPositives;

    /**
     * Instantiates a new random double supplier.
     */
    public RandomDoubleSupplier() {
        // No hace nada
    }

    /**
     * Checks if is only positives.
     *
     * @return true, if is only positives
     */
    public boolean isOnlyPositives() {
        return onlyPositives;
    }

    /**
     * Sets the only positives.
     *
     * @param onlyPositives
     *            the new only positives
     */
    public void setOnlyPositives(boolean onlyPositives) {
        this.onlyPositives = onlyPositives;
    }

    /* (non-Javadoc)
     *
     * @see org.gjs.java.test.testinggame.suppliers.Supplier#get() */

    @Override
    public Double get() {
        final Double value = random.nextDouble();
        return onlyPositives ? Math.abs(value) : value;
    }

    /* (non-Javadoc)
     *
     * @see org.gjs.java.test.objects.suppliers.Supplier#getEmpty() */

    @Override
    public Double getEmpty() {
        return Double.valueOf(0.0);
    }

    /* (non-Javadoc)
     *
     * @see org.gjs.java.test.objects.suppliers.AbstractRandomSupplier#createArray(int) */

    @Override
    protected Double[] createArray(int size) {
        return new Double[size];
    }
}
