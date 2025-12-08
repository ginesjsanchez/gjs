package org.gjs.java.dto;

import java.util.Collection;
import java.util.Objects;
import java.util.Set;
import java.util.TreeSet;

import com.fasterxml.jackson.annotation.JsonTypeInfo;

import lombok.Getter;
import lombok.Setter;

/**
 * The Class CollectionDto.
 *
 * Clase de datos de la librería Semilla
 *
 * Clase DTO genérica para almacenar una colección de objetos del tipo que sean.
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
 * @param <T>
 *            la clase de objetos
 *
 * @author Semilla
 * @version 4.0.0
 * @since 3.0.0
 *
 */
@Getter
@Setter
public class CollectionDto<T> extends BaseDto {

    /** The Constant serialVersionUID. */
    private static final long serialVersionUID = -3197941037365727105L;

    /** The contenido. */
    @JsonTypeInfo(use = JsonTypeInfo.Id.CLASS, include = JsonTypeInfo.As.PROPERTY, property = "@class")
    private final transient Set<T> contenido;

    /**
     * Instantiates a new collection dto.
     */
    public CollectionDto() {
        contenido = new TreeSet<>();
    }

    /**
     * Instantiates a new collection dto.
     *
     * @param contenido
     *            the contenido
     */
    public CollectionDto(Collection<T> contenido) {
        this();
        if (Objects.nonNull(contenido)) {
            this.contenido.addAll(contenido);
        }
    }
}
