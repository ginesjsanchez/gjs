package org.gjs.java.dto;

import java.util.Calendar;
import java.util.Objects;

import com.fasterxml.jackson.annotation.JsonIgnore;

import org.apache.commons.lang3.builder.ToStringBuilder;
import org.apache.commons.lang3.builder.ToStringStyle;

import lombok.Getter;
import lombok.Setter;

/**
 * The Class AuditDto.
 *
 * Clase de datos de la librería Semilla
 *
 * Clase DTO para almacenar la información para la auditoria de tiempos de un método.
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
public class AuditDto extends BaseDto {

    /** The Constant serialVersionUID. */
    private static final long serialVersionUID = 765227491514794314L;

    /**
     * Gets the module.
     *
     * @return the module
     */
    @Getter
    private String module;

    /**
     * Gets the primitive.
     *
     * @return the primitive
     */
    @Getter
    private String primitive;

    /**
     * Gets the start time.
     *
     * @return the start time
     */
    @Getter
    private long startTime;

    /**
     * Gets the end time.
     *
     * @return the end time
     */
    @Getter
    private long endTime;

    /**
     * Checks if is ok.
     *
     * @return true, if is ok
     */
    @Getter
    private boolean ok;

    /**
     * Gets the throwed.
     *
     * @return the throwed
     */
    @Getter

    /**
     * Sets the throwed.
     *
     * @param throwed
     *            the new throwed
     */
    @Setter
    private Throwable throwed;

    /**
     * Instantiates a new audit dto.
     */
    public AuditDto() {
        // No hace nada
    }

    /**
     * Instantiates a new audit dto.
     *
     * @param module
     *            the module
     * @param primitive
     *            the primitive
     */
    public AuditDto(String module, String primitive) {
        init(module, primitive);
    }

    /**
     * Gets the key.
     *
     * @return the key
     */
    @JsonIgnore
    public String getKey() {
        return String.format("%s:%s:%s", module, primitive, Thread.currentThread().getName());
    }

    /**
     * Gets the common key.
     *
     * @return the key
     */
    @JsonIgnore
    public String getCommonKey() {
        return String.format("%s:%s", module, primitive);
    }

    /**
     * Gets the time.
     *
     * @return the time
     */
    @JsonIgnore
    public long getTime() {
        return endTime - startTime;
    }

    /**
     * Inits the.
     *
     * @param module
     *            the module
     * @param primitive
     *            the primitive
     */
    public void init(String module, String primitive) {
        this.module = module;
        this.primitive = primitive;
        this.startTime = Calendar.getInstance().getTimeInMillis();
        this.endTime = 0;
        this.ok = false;
        this.throwed = null;
    }

    /**
     * Begin.
     */
    public void begin() {
        this.startTime = Calendar.getInstance().getTimeInMillis();
    }

    /**
     * End.
     */
    public void end() {
        this.endTime = Calendar.getInstance().getTimeInMillis();
        this.ok = Objects.isNull(this.throwed);
    }

    /* (non-Javadoc)
     *
     * @see java.lang.Object#toString() */

    @Override
    public String toString() {
        return new ToStringBuilder(this, ToStringStyle.SHORT_PREFIX_STYLE).append("module", module)
                .append("primitive", primitive).append("startTime", startTime).append("endTime", endTime)
                .append("ok", ok).append("throwed", throwed).toString();
    }

    /* (non-Javadoc)
     *
     * @see java.lang.Object#hashCode() */

    @Override
    public int hashCode() {
        return Objects.hash(module, primitive);
    }

    /* (non-Javadoc)
     *
     * @see java.lang.Object#equals(java.lang.Object) */

    @Override
    public boolean equals(Object obj) {
        if (this == obj) {
            return true;
        }
        if (!(obj instanceof final AuditDto other)) {
            return false;
        }
        return Objects.equals(module, other.module) && Objects.equals(primitive, other.primitive);
    }

}
