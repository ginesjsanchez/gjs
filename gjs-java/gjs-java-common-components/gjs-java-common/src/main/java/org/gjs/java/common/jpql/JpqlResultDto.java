package org.gjs.java.common.jpql;

import org.apache.commons.lang3.builder.ToStringBuilder;
import org.apache.commons.lang3.builder.ToStringStyle;

/**
 * The Class JpqlResultDto.
 *
 * Clase abstracta de la librería Gjs
 *
 * Clase abstracta DTO para pensada para ser implementada por clase destinadas a facilitar la transformación de datos de
 * una consulta JPQL, teniendo en cuenta que, aunque JPQL esta perfectamente integrado con Java, cuando las consultas
 * van a Oracle puede ser más duro: para no complicarse la vida customizando el OracleExtendedDialect utilizamos DTO
 * especiales para transformar el resultado.
 *
 * --------------------------------------------------------------------------------------------------------------------
 * Gj Software
 *
 * 2025 correspondiente licencia en los activos de la
 * SES. Los programas informáticos propiedad de la SES están protegidos por la propiedad intelectual, y por tanto está
 * estrictamente prohibida su reproducción, modificación, cesión o comunicación sin la debida autorización. Queda
 * estrictamente prohibido el uso, reproducción, cesión, transformación o comunicación pública de cualquier otro tipo de
 * obra o invención protegida por la propiedad intelectual sin la debida autorización.
 *
 * Seguridad Ministerio del Interior
 * Gobierno de España
 * --------------------------------------------------------------------------------------------------------------------
 *
 * @param <T>
 *            the generic type
 *            --------------------------------------------------------------------------------------------------------------------
 *
 * @author Gjs
 * @version 4.0.0
 * @since 3.0.0
 */
public class JpqlResultDto<T> {

    /** The value. */
    protected T value;

    /**
     * Gets the value.
     *
     * @return the value
     */
    public T getValue() {
        return value;
    }

    /* (non-Javadoc)
     *
     * @see java.lang.Object#toString() */

    @Override
    public String toString() {
        return new ToStringBuilder(this, ToStringStyle.SHORT_PREFIX_STYLE).append("value", value).toString();
    }

}
