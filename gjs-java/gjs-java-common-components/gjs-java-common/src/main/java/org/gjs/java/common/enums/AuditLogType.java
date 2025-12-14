package org.gjs.java.common.enums;

/**
 * The Enum AuditLogType.
 *
 * Enumerado de la librería Gjs
 *
 * Contiene los tipos de registro de auditoría que se escriben en el log. Se una en la auditoría por aspectos.
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
 * @author Gjs
 * @version 4.0.0
 * @since 3.0.0
 *
 */
public enum AuditLogType {

    /** The begin. */
    BEGIN("INI"),
    /** The end. */
    END("FIN"),
    /** The returns. */
    RETURNS("RET"),
    /** The throws. */
    THROWS("EXC"),
    /** The time warn. */
    TIME_WARN("TMW");

    /** The literal. */
    private String literal;

    /**
     * Instantiates a new audit log type.
     *
     * @param literal
     *            the literal
     */
    AuditLogType(String literal) {
        this.literal = literal;
    }

    /* (non-Javadoc)
     *
     * @see java.lang.Enum#toString() */

    @Override
    public String toString() {
        return literal;
    }
}
