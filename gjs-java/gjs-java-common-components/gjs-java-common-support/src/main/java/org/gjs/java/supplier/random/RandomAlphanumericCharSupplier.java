package org.gjs.java.supplier.random;

import org.apache.commons.lang3.RandomStringUtils;

/**
 * The Class RandomAlphanumericCharSupplier.
 *
 * Clase de datos de la librería Gjs
 *
 * Generadores de carácteres aleatorios.
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
public class RandomAlphanumericCharSupplier extends AbstractRandomSupplier<Character> {

    /**
     * Instantiates a new random alphanumeric char supplier.
     */
    public RandomAlphanumericCharSupplier() {
        // No hace nada
    }

    /* (non-Javadoc)
     *
     * @see org.gjs.java.test.testinggame.suppliers.Supplier#get() */

    @Override
    public Character get() {
        return RandomStringUtils.secure().nextAlphanumeric(1).charAt(0);
    }

    /* (non-Javadoc)
     *
     * @see org.gjs.java.test.objects.suppliers.Supplier#getEmpty() */

    @Override
    public Character getEmpty() {
        return Character.valueOf('\0');
    }

    /* (non-Javadoc)
     *
     * @see org.gjs.java.test.objects.suppliers.AbstractRandomSupplier#createArray(int) */

    @Override
    protected Character[] createArray(int size) {
        return new Character[size];
    }
}
