package org.gjs.java.dto;

import java.util.Objects;

import com.fasterxml.jackson.annotation.JsonInclude;

import org.apache.commons.lang3.builder.ToStringBuilder;
import org.apache.commons.lang3.builder.ToStringStyle;

import lombok.Getter;
import lombok.Setter;

/**
 * The Class SpResponseDto.
 *
 * Clase de datos de la librería Semilla
 *
 * Clase DTO para almacenar los datos de una respuesta del Service Provider.
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
@JsonInclude(JsonInclude.Include.NON_NULL)
public class SpResponseDto {

    /** The selected idp. */
    private String selectedIdp;

    /** The relay state. */
    private String relayState;

    /** The register type. */
    private String registerType;

    /** The cert info. */
    private CertInfoDto certInfo;

    /**
     * Instantiates a new sp response dto.
     */
    public SpResponseDto() {
        // No hace nada
    }

    /* (non-Javadoc)
     *
     * @see java.lang.Object#hashCode() */

    @Override
    public int hashCode() {
        return Objects.hash(certInfo, registerType, relayState, selectedIdp);
    }

    /* (non-Javadoc)
     *
     * @see java.lang.Object#equals(java.lang.Object) */

    @Override
    public boolean equals(Object obj) {
        if (this == obj) {
            return true;
        }
        if (!(obj instanceof final SpResponseDto other)) {
            return false;
        }
        return Objects.equals(certInfo, other.certInfo) && Objects.equals(registerType, other.registerType)
                && Objects.equals(relayState, other.relayState) && Objects.equals(selectedIdp, other.selectedIdp);
    }

    /* (non-Javadoc)
     *
     * @see java.lang.Object#toString() */

    @Override
    public String toString() {
        return new ToStringBuilder(this, ToStringStyle.SHORT_PREFIX_STYLE).append("selectedIdp", selectedIdp)
                .append("relayState", relayState).append("registerType=", registerType).append("certInfo", certInfo)
                .toString();
    }

}
