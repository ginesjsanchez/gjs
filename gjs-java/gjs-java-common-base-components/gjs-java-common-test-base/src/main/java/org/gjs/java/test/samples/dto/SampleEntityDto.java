package org.gjs.java.test.samples.dto;

import java.util.Date;

import lombok.Getter;
import lombok.Setter;

@Getter
@Setter
public class SampleEntityDto {

	private Long id;
	private String nombre;
	private String descripcion;
	private Date fechaAlta;
	private Date fechaBaja;
	private Boolean activo;

	public SampleEntityDto() {
	}

	@Override
	public String toString() {
		return "SampleEntityDto [ id=" + id + ", nombre=" + nombre + ", descripcion=" + descripcion + ", fechaAlta="
				+ fechaAlta + ", fechaBaja=" + fechaBaja + ", activo=" + activo + "]";
	}

}
