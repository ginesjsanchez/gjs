package org.gjs.java.jpql;

/**
 * The Class ThereAreNoneDto.
 *
 * Clase de datos de la librería Semilla
 *
 * Clase DTO para facilitar la transformación de una condición sobre un count(*) en booleano. En JPQL eso sería
 * inmediato, y bastaría incluir un Select count(*) = 0 en la consulta, pero en Oracle, y más con la transformación a
 * Booleano de Java la cosa se complica: para no complicarse la vida customizando el OracleExtendedDialect utilizamos
 * DTO especiales para transformar el resultado.
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
public final class ThereAreNoneDto extends BooleanJpqlResultDto {

    /**
     * Instantiates a new there are none dto.
     *
     * @param count
     *            the count
     */
    public ThereAreNoneDto(long count) {
        if (count == 0) {
            value = Boolean.TRUE;
        } else {
            value = Boolean.FALSE;
        }
    }

}
