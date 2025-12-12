package org.gjs.java.encoder;

import java.util.Objects;

import org.apache.commons.lang3.ObjectUtils;
import org.apache.commons.lang3.builder.ToStringBuilder;
import org.apache.commons.lang3.builder.ToStringStyle;
import org.apache.commons.lang3.exception.ExceptionUtils;
import org.slf4j.Logger;
import org.slf4j.LoggerFactory;
import org.springframework.security.crypto.password.PasswordEncoder;

/**
 * The Class SemillaPasswordEncoder.
 *
 * Clase de datos de la librería Semilla
 *
 * Implementa el PasswordEncoder oficial de Semilla.
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
public class GjsPasswordEncoder implements PasswordEncoder {

	/** The Constant logger. */
	private static final Logger logger = LoggerFactory.getLogger(GjsPasswordEncoder.class);

	/** The internal encoder. */
	private final PasswordEncoder internalEncoder;

	/**
	 * Instantiates a new semilla password encoder.
	 *
	 * @param encoder the encoder
	 */
	public GjsPasswordEncoder(PasswordEncoder encoder) {
		internalEncoder = encoder;
	}

	/*
	 * (non-Javadoc)
	 *
	 * @see
	 * org.springframework.security.crypto.password.PasswordEncoder#encode(java.lang
	 * .CharSequence)
	 */

	@Override
	public String encode(CharSequence rawPassword) {
		String encrypted = null;
		if (ObjectUtils.allNotNull(internalEncoder, rawPassword)) {
			encrypted = internalEncoder.encode(rawPassword);
		}
		return encrypted;
	}

	/*
	 * (non-Javadoc)
	 *
	 * @see
	 * org.springframework.security.crypto.password.PasswordEncoder#matches(java.
	 * lang.CharSequence, java.lang.String)
	 */

	@Override
	public boolean matches(CharSequence rawPassword, String encodedPassword) {
		boolean res = false;
		if (ObjectUtils.allNotNull(internalEncoder, rawPassword, encodedPassword)) {
			try {
				res = internalEncoder.matches(rawPassword, encodedPassword);
			} catch (final Exception e) {
				logger.warn(ExceptionUtils.getStackTrace(e));
			}
		}
		return res;
	}

	/**
	 * Checks if is valid.
	 *
	 * @return true, if is valid
	 */
	public boolean isValid() {
		boolean res = false;
		if (Objects.nonNull(internalEncoder)) {
			final String password = "t3mp0r4l";
			final String encrypted = encode(password);
			res = matches(password, encrypted);
		}
		return res;
	}

	/*
	 * (non-Javadoc)
	 *
	 * @see java.lang.Object#toString()
	 */

	@Override
	public String toString() {
		return new ToStringBuilder(this, ToStringStyle.SHORT_PREFIX_STYLE).append("internalEncoder", internalEncoder)
				.toString();
	}

}
