package org.gjs.java.dto;

/**
 * The Class EntidadPkStringDto.
 *
 * Clase abtracta de datos de la librería Semilla
 *
 * Clase base para ser extendida por todos los DTO que representan una entida de la base de datos con clave primaria
 * cadena.
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
 */

public abstract class EntityPkStringDto extends EntityDto<String> {

    /** The Constant serialVersionUID. */
    private static final long serialVersionUID = 4273754468033325080L;

    /**
     * Instantiates a new entidad pk string dto.
     */
    public EntityPkStringDto() {
        // No hace nada
    }

    /**
     * Instantiates a new entidad pk string dto.
     *
     * @param other
     *            the other
     */
    public EntityPkStringDto(EntityPkStringDto other) {
        super(other);
    }

    /**
     * Instantiates a new entidad pk string dto.
     *
     * @param id
     *            the id
     */
    public EntityPkStringDto(String id) {
        super(id);
    }

}
