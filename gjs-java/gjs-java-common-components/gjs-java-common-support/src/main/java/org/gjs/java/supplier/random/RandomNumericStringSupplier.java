package org.gjs.java.supplier.random;

import org.apache.commons.lang3.RandomStringUtils;
import org.apache.commons.lang3.StringUtils;

import org.gjs.java.common.ConditionUtils;

/**
 * The Class RandomNumericStringSupplier.
 *
 * Clase de datos de la librería Semilla
 *
 * Generadores de cadenas numéricas aleatorias.
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
public class RandomNumericStringSupplier extends RandomAlphanumericStringSupplier {

    /**
     * Instantiates a new random numeric string supplier.
     */
    public RandomNumericStringSupplier() {
    }

    /**
     * Instantiates a new random numeric string supplier.
     *
     * @param maxLength
     *            the max length
     * @param nullable
     *            the nullable
     * @param constantLength
     *            the constant length
     */
    public RandomNumericStringSupplier(int maxLength, boolean nullable, boolean constantLength) {
        super(maxLength, nullable, constantLength);
    }

    /* (non-Javadoc)
     *
     * @see org.gjs.java.test.objects.suppliers.RandomAlphanumericStringSupplier#get() */

    @Override
    public String get() {
        if (ConditionUtils.allAreTrue(isNullable(), mustBeNull())) {
            return null;
        }
        final int minLength = isConstantLength() ? getMaxLength() : 0;
        final RandomIntegerSupplier lengthSupplier = new RandomIntegerSupplier(Integer.valueOf(minLength),
                Integer.valueOf(getMaxLength()));
        return RandomStringUtils.secure().nextNumeric(lengthSupplier.get());
    }

    /* (non-Javadoc)
     *
     * @see org.gjs.java.test.objects.suppliers.RandomAlphanumericStringSupplier#getEmpty() */

    @Override
    public String getEmpty() {
        return isNullable() ? null : (isConstantLength() ? StringUtils.repeat('0', getMaxLength()) : "");
    }
}
