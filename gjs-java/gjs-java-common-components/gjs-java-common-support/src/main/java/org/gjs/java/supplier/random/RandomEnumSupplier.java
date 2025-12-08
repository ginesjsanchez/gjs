package org.gjs.java.supplier.random;

import java.util.List;

import org.apache.commons.lang3.EnumUtils;

/**
 * The Class RandomEnumSupplier.
 *
 * Clase abstracta de datos de la librería Gjs
 *
 * Clase abstracta para ser utilizada en la implementación de generadores de datos aletorios de tipo enumerado
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
 * @param <E>
 *            la clase de enumerado
 *
 * @author Gjs
 * @version 1.0.0
 * @since 1.0.0
 *
 */
public abstract class RandomEnumSupplier<E extends Enum<E>> extends RandomSelectedObjectSupplier<E> {

    /**
     * Instantiates a new random enum supplier.
     */
    public RandomEnumSupplier() {
        @SuppressWarnings("unchecked")
        final List<E> options = EnumUtils.getEnumList((Class<E>) getClazz());
        super.setOptions(options);
        super.setNullable(false);
    }

    /**
     * Gets the clazz.
     *
     * @return the clazz
     */
    protected abstract Class<?> getClazz();

}
