package org.gjs.java.test.sample.model;

import jakarta.persistence.Column;
import jakarta.persistence.Entity;
import lombok.Getter;
import lombok.Setter;

@Getter
@Setter
@Entity
public class SampleEntityWhitoutIdAnnotation {

	@Column
	private long id;

	@Column
	private String nombre;

	@Column
	private Boolean activo;

	public SampleEntityWhitoutIdAnnotation() {
	}

}
