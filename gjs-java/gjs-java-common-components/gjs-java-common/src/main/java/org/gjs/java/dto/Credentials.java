package org.gjs.java.dto;

import java.io.Serializable;
import java.util.Objects;

import org.apache.commons.lang3.builder.ToStringBuilder;
import org.apache.commons.lang3.builder.ToStringStyle;
import org.gjs.java.util.ConditionUtils;

import lombok.Getter;
import lombok.Setter;

/**
 * The Class Credentials.
 *
 * Clase de datos de la librería Semilla
 *
 * Clase para almacenar datos de credenciales de usuario.
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
public class Credentials implements Serializable {

	/**
	 *
	 */
	private static final long serialVersionUID = -4638043376071570861L;

	/** The login. */
	private String login;

	/** The password. */
	private String password;

	/** The key. */
	private String key;

	/**
	 * Instantiates a new credentials.
	 */
	public Credentials() {
		// No hace nada
	}

	/**
	 * Instantiates a new credentials.
	 *
	 * @param login    the login
	 * @param password the password
	 */
	public Credentials(String login, String password) {
		this.login = login;
		this.password = password;
	}

	/**
	 * Instantiates a new credentials.
	 *
	 * @param login    the login
	 * @param password the password
	 * @param key      the key
	 */
	public Credentials(String login, String password, String key) {
		this.login = login;
		this.password = password;
		this.key = key;
	}

	/*
	 * (non-Javadoc)
	 *
	 * @see java.lang.Object#hashCode()
	 */

	@Override
	public int hashCode() {
		return Objects.hash(key, login, password);
	}

	/*
	 * (non-Javadoc)
	 *
	 * @see java.lang.Object#equals(java.lang.Object)
	 */

	@Override
	public boolean equals(Object obj) {
		if (this == obj) {
			return true;
		}
		if (!(obj instanceof final Credentials other)) {
			return false;
		}
		return ConditionUtils.allAreTrue(Objects.equals(key, other.key), Objects.equals(login, other.login),
				Objects.equals(password, other.password));
	}

	/*
	 * (non-Javadoc)
	 *
	 * @see java.lang.Object#toString()
	 */

	@Override
	public String toString() {
		return new ToStringBuilder(this, ToStringStyle.SHORT_PREFIX_STYLE).append("login", login)
				.append("password", Objects.nonNull(password) ? "XXX" : "null")
				.append("key", Objects.nonNull(key) ? "XXX" : "null").toString();
	}

}
