package org.gjs.java.util;

import java.io.ByteArrayInputStream;
import java.io.InputStream;
import java.security.DigestInputStream;
import java.security.MessageDigest;

import org.gjs.java.constant.CommonBaseConstants;
import org.gjs.java.exception.GjsException;

/**
 * The Class CryptoUtil.
 *
 * Clase de utilidades generales de la librería Semilla
 *
 * Función para calcular el hash de una secuencia de bytes en base a diferentes
 * algoritmos.
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
public final class CryptoUtils {

	/**
	 * Clase no instanciable.
	 */
	private CryptoUtils() {
		throw new IllegalStateException(CommonBaseConstants.MSG_UTILITY_CLASS);
	}

	/**
	 * Hash.
	 *
	 * @param bytes     the bytes
	 * @param algorithm the algorithm: SHA, MD2, MD5, SHA-256, SHA-384...
	 * @return the string
	 * @throws GjsException the semilla util exception
	 */
	public static String hash(byte[] bytes, String algorithm) throws GjsException {
		MessageDigest messageDigest;
		try {
			messageDigest = MessageDigest.getInstance(algorithm);
		} catch (final Exception e) {
			throw new GjsException(e);
		}

		try {
			final InputStream inputStream = new ByteArrayInputStream(bytes);
			try (DigestInputStream dis = new DigestInputStream(inputStream, messageDigest)) {
				while (dis.read() != -1) {
					// empty loop to clear the data
				}
				messageDigest = dis.getMessageDigest();
			}
		} catch (

		final Exception e) {
			throw new GjsException(e);
		}
		// bytes to hex
		final StringBuilder result = new StringBuilder();
		for (final byte b : messageDigest.digest()) {
			result.append(String.format("%02x", b));
		}
		return result.toString();
	}

}
