package org.gjs.java.supplier.random;

import java.io.IOException;

import org.gjs.java.enums.Sexo;

/**
 * The Class RandomNameSupplier.
 *
 * Clase de datos de la librería Semilla
 *
 * Generadores de nombres aleatorios.
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
public class RandomNameSupplier extends RandomAlphanumericStringSupplier {

    /** The sex supplier. */
    private final RandomSexSupplier sexSupplier;

    /** The male name supplier. */
    private final RandomMaleNameSupplier maleNameSupplier;

    /** The female name supplier. */
    private final RandomFemaleNameSupplier femaleNameSupplier;

    /**
     * Instantiates a new random name supplier.
     *
     * @throws IOException
     *             Signals that an I/O exception has occurred.
     */
    public RandomNameSupplier() throws IOException {
        super(50, false, false);
        sexSupplier = new RandomSexSupplier();
        maleNameSupplier = new RandomMaleNameSupplier();
        femaleNameSupplier = new RandomFemaleNameSupplier();
    }

    /* (non-Javadoc)
     *
     * @see org.gjs.java.test.objects.suppliers.RandomAlphanumericStringSupplier#get() */

    @Override
    public String get() {
        final Sexo sexo = sexSupplier.get();
        if (Sexo.VARON.equals(sexo)) {
            return maleNameSupplier.get();
        }
        return femaleNameSupplier.get();
    }

    /* (non-Javadoc)
     *
     * @see org.gjs.java.test.objects.suppliers.RandomAlphanumericStringSupplier#getEmpty() */

    @Override
    public String getEmpty() {
        return null;
    }

}
