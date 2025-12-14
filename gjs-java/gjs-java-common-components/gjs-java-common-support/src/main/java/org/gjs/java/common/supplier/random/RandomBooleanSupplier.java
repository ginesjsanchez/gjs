package org.gjs.java.common.supplier.random;

/**
 * The Class RandomBooleanSupplier.
 *
 * Clase de datos de la librería Gjs
 *
 * Generadores de booleanos aleatorios.
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
public class RandomBooleanSupplier extends AbstractRandomSupplier<Boolean> {

    /**
     * Instantiates a new random Boolean supplier.
     */
    public RandomBooleanSupplier() {
        // No hace nada
    }

    /* (non-Javadoc)
     *
     * @see org.gjs.java.test.testinggame.suppliers.Supplier#get() */

    @Override
    public Boolean get() {
        return random.nextBoolean();
    }

    /* (non-Javadoc)
     *
     * @see org.gjs.java.test.objects.suppliers.Supplier#getEmpty() */

    @Override
    public Boolean getEmpty() {
        return Boolean.FALSE;
    }

    /* (non-Javadoc)
     *
     * @see org.gjs.java.test.objects.suppliers.AbstractRandomSupplier#createArray(int) */

    @Override
    protected Boolean[] createArray(int size) {
        return new Boolean[size];
    }
}
