package org.gjs.java.dto;

import org.gjs.java.util.ComparationUtils;

/**
 * The Class EntidadPkLongDto.
 *
 * Clase abtracta de datos de la librería Semilla
 *
 * Clase base para ser extendida por todos los DTO que representan una entida de
 * la base de datos con clave primaria entera.
 *
 * --------------------------------------------------------------------------------------------------------------------
 * Este software es propiedad del Ministerio del Interior CETSE - 2025
 *
 * Queda estrictamente prohibido el uso de programas informáticos sin la
 * correspondiente licencia en los activos de la SES. Los programas informáticos
 * propiedad de la SES están protegidos por la propiedad intelectual, y por
 * tanto está estrictamente prohibida su reproducción, modificación, cesión o
 * comunicación sin la debida autorización. Queda estrictamente prohibido el
 * uso, reproducción, cesión, transformación o comunicación pública de cualquier
 * otro tipo de obra o invención protegida por la propiedad intelectual sin la
 * debida autorización.
 *
 * Subdirección General de Sistemas de la Información y Comunicaciones para la
 * Seguridad Ministerio del Interior Gobierno de España
 * --------------------------------------------------------------------------------------------------------------------
 *
 * @author Semilla
 * @version 4.0.0
 * @since 3.0.0
 */
public abstract class EntityPkLongDto extends EntityDto<Long> {

	/** The Constant serialVersionUID. */
	private static final long serialVersionUID = -7274829768924889168L;

	/**
	 * Instantiates a new entidad pk long dto.
	 */
	public EntityPkLongDto() {
		// No hace nada
	}

	/**
	 * Instantiates a new entidad pk long dto.
	 *
	 * @param other the other
	 */
	public EntityPkLongDto(EntityPkLongDto other) {
		super(other);
	}

	/**
	 * Instantiates a new entidad pk long dto.
	 *
	 * @param id the id
	 */
	public EntityPkLongDto(Long id) {
		super(id);
	}

	/*
	 * (non-Javadoc)
	 *
	 * @see es.mir.semilla.util.dto.EntidadDto#validId(java.io.Serializable)
	 */

	@Override
	protected boolean validId(Long id) {
		return (id > 0);
	}

	/*
	 * (non-Javadoc)
	 *
	 * @see es.mir.semilla.util.dto.EntidadDto#compareId(java.lang.Object)
	 */

	@Override
	public int compareId(Object otherId) {
		int res = 1; // Si el objeto no es Long se considera nulo
		if (otherId instanceof Long) {
			res = ComparationUtils.compareTo(id, (Long) otherId);
		}
		return res;
	}

}
