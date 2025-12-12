package org.gjs.java.dto;

import java.util.Objects;

import org.apache.commons.lang3.builder.ToStringBuilder;
import org.apache.commons.lang3.builder.ToStringStyle;

import lombok.Getter;
import lombok.Setter;

/**
 * The Class SpRequestDto.
 *
 * Clase de datos de la librería Semilla
 *
 * Clase DTO para almacenar los datos de un requerimiento al Service Provider.
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
@Getter
@Setter
public class SpRequestDto {

    /** The saml response. */
    private String samlResponse;

    /** The relay state. */
    private String relayState;

    /**
     * Instantiates a new sp request dto.
     */
    public SpRequestDto() {
        // No hace nada
    }

    /**
     * Instantiates a new sp request dto.
     *
     * @param samlResponse
     *            the saml response
     * @param relayState
     *            the relay state
     */
    public SpRequestDto(String samlResponse, String relayState) {
        this.samlResponse = samlResponse;
        this.relayState = relayState;
    }

    /* (non-Javadoc)
     *
     * @see java.lang.Object#hashCode() */

    @Override
    public int hashCode() {
        return Objects.hash(relayState, samlResponse);
    }

    /* (non-Javadoc)
     *
     * @see java.lang.Object#equals(java.lang.Object) */

    @Override
    public boolean equals(Object obj) {
        if (this == obj) {
            return true;
        }
        if (!(obj instanceof final SpRequestDto other)) {
            return false;
        }
        return Objects.equals(relayState, other.relayState) && Objects.equals(samlResponse, other.samlResponse);
    }

    /* (non-Javadoc)
     *
     * @see java.lang.Object#toString() */

    @Override
    public String toString() {
        return new ToStringBuilder(this, ToStringStyle.SHORT_PREFIX_STYLE).append("samlResponse", samlResponse)
                .append("relayState", relayState).toString();
    }

}
