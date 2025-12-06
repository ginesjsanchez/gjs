package org.gjs.java.supplier;

/**
 * The Class GenericObjectSupplier.
 *
 * Clase de datos de la librería Semilla
 *
 * Generador de objetos genéricos de tipo Object.
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
public class GenericObjectSupplier extends AbstractObjectSupplier<Object> {

    /**
     * Instantiates a new generic object supplier.
     *
     * @param className
     *            the class name
     */
    public GenericObjectSupplier(String className) {
        super(className);
        super.setInformAllFields(true);
        super.setInformCollections(true);
    }

    /* (non-Javadoc)
     *
     * @see org.gjs.java.test.objects.suppliers.AbstractRandomSupplier#createArray(int) */

    @Override
    protected Object[] createArray(int size) {
        return new Object[size];
    }

}
