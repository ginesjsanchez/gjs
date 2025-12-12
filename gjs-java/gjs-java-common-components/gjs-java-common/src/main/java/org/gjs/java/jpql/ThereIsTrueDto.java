package org.gjs.java.jpql;

/**
 * The Class ThereIsTrueDto.
 *
 * Clase de datos de la librería Semilla
 *
 * Clase DTO para facilitar la transformación de una condición sobre un flag.
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
public final class ThereIsTrueDto extends BooleanJpqlResultDto {

    /**
     * Instantiates a new there is any dto.
     *
     * @param count
     *            the count
     */
    public ThereIsTrueDto(long count) {
        if (count > 0) {
            value = Boolean.TRUE;
        } else {
            value = Boolean.FALSE;
        }
    }

    /**
     * Instantiates a new there is true dto.
     *
     * @param val
     *            the val
     */
    public ThereIsTrueDto(boolean val) {
        if (val) {
            value = Boolean.TRUE;
        } else {
            value = Boolean.FALSE;
        }
    }

}
