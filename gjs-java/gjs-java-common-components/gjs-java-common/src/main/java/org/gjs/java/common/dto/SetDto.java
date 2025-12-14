package org.gjs.java.common.dto;

import java.util.Set;
import java.util.TreeSet;

import lombok.Getter;
import lombok.Setter;

/**
 * The Class SetDto.
 *
 * Clase de datos de la librería Gjs
 *
 * Clase DTO genérica para almacenar un conjunto de otros DTO del tipo que sean.
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
@Getter
@Setter
public class SetDto extends BaseDto {

    /** The Constant serialVersionUID. */
    private static final long serialVersionUID = 4127095647545500940L;

    /** The contenido. */
    private final Set<BaseDto> contenido = new TreeSet<>();

}
