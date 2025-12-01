package org.gjs.java.test.samples.dto;

import java.util.Date;

import lombok.Getter;
import lombok.Setter;

@Getter
@Setter
public class SampleWithFKEntityDto {

	private Long id;
	protected String nombre;
	protected String descripcion;
	private Date fechaAlta;
	private Date fechaBaja;
	private Boolean activo;
	private SampleEntityDto sample;

	public SampleWithFKEntityDto() {
	}

	@Override
	public String toString() {
		return "SampleWithFKEntityDto [" + "id=" + id + ", activo=" + activo + ", descripcion='" + descripcion + '\''
				+ ", fechaAlta=" + fechaAlta + ", fechaBaja=" + fechaBaja + ", nombre='" + nombre + '\'' + ", sample="
				+ sample + "]";
	}
}
