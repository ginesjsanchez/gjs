package org.gjs.java.dto;

import java.util.Objects;

import org.apache.commons.lang3.StringUtils;
import org.apache.commons.lang3.builder.ToStringBuilder;
import org.apache.commons.lang3.builder.ToStringStyle;
import org.gjs.java.contant.CommonConstants;

import lombok.Getter;
import lombok.Setter;

/**
 * The Class PaginationDto.
 *
 * Clase de datos de la librería Semilla
 *
 * Clase DTO para almacenar los datos de paginación.
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
 *
 */
@Getter
@Setter
public class PaginationDto extends BaseDto {

	/** The Constant serialVersionUID. */
	private static final long serialVersionUID = 3743040832207020322L;

	/** The page number. */
	private Integer pageNumber;

	/** The page size. */
	private Integer pageSize;

	/** The order. */
	private String order;

	/** The direction. */
	private Integer direction;

	/**
	 * Instantiates a new pagination dto.
	 */
	public PaginationDto() {
		// No hace nada
	}

	/**
	 * Instantiates a new pagination dto.
	 *
	 * @param pageNumber the page number
	 * @param pageSize   the page size
	 * @param order      the order
	 * @param direction  the direction
	 */
	public PaginationDto(Integer pageNumber, Integer pageSize, String order, Integer direction) {
		setPageNumber(pageNumber);
		setPageSize(pageSize);
		setOrder(order);
		setDirection(direction);
	}

	/**
	 * Sets the order.
	 *
	 * @param order the new order
	 */
	public void setOrder(String order) {
		this.order = Objects.requireNonNullElse(StringUtils.trim(order), "id");
	}

	/**
	 * Sets the page number.
	 *
	 * @param pageNumber the new page number
	 */
	public void setPageNumber(Integer pageNumber) {
		this.pageNumber = Objects.requireNonNullElse(pageNumber, Integer.valueOf(0));
	}

	/**
	 * Sets the page size.
	 *
	 * @param pageSize the new page size
	 */
	public void setPageSize(Integer pageSize) {
		this.pageSize = Objects.requireNonNullElse(pageSize, CommonConstants.DEFAULT_PAGE_SIZE);
	}

	/**
	 * Sets the direction.
	 *
	 * @param direction the new direction
	 */
	public void setDirection(Integer direction) {
		this.direction = Objects.requireNonNullElse(direction, Integer.valueOf(1));
	}

	/*
	 * (non-Javadoc)
	 *
	 * @see java.lang.Object#toString()
	 */

	@Override
	public String toString() {
		return new ToStringBuilder(this, ToStringStyle.SHORT_PREFIX_STYLE).append("pageNumber", pageNumber)
				.append("pageSize", pageSize).append("order", order).append("direction", direction).toString();
	}

}
