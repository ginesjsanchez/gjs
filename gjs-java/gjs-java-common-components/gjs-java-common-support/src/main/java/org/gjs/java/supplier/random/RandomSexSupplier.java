package org.gjs.java.supplier.random;

import org.gjs.java.enums.Sexo;

/**
 * The Class RandomSexSupplier.
 *
 * Clase de datos de la librería Gjs
 *
 * Generadores de sexo aleatorios.
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
public class RandomSexSupplier extends RandomEnumSupplier<Sexo> {

    /* (non-Javadoc)
     *
     * @see org.gjs.java.test.objects.suppliers.RandomEnumSupplier#getClazz() */

    @Override
    protected Class<?> getClazz() {
        return Sexo.class;
    }

    /* (non-Javadoc)
     *
     * @see org.gjs.java.test.objects.suppliers.AbstractRandomSupplier#createArray(int) */

    @Override
    protected Sexo[] createArray(int size) {
        return new Sexo[size];
    }

}
