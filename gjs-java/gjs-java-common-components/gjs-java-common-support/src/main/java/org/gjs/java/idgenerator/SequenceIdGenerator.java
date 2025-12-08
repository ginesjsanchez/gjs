package org.gjs.java.idgenerator;

/**
 * The Class SequenceIdGenerator.
 *
 * Clase de datos de la librería Gjs
 *
 * Generador de identificadores enteros secuencial.
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
public class SequenceIdGenerator implements IdGenerator<Long> {

    /** The last. */
    private Long last = Long.valueOf(0);

    /* (non-Javadoc)
     *
     * @see org.gjs.java.test.mock.IdGenerator#generate() */

    @Override
    public Long generate() {
        last = last + 1;
        return last;
    }

}
