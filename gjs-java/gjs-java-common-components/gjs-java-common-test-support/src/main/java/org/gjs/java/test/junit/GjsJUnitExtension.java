package org.gjs.java.test.junit;

import java.util.MissingResourceException;
import java.util.ResourceBundle;

import org.gjs.java.common.ClazzUtils;
import org.gjs.java.supplier.ObjectSupplierManager;
import org.gjs.java.supplier.testinggame.TestingGamesSingleton;
import org.junit.jupiter.api.extension.BeforeAllCallback;
import org.junit.jupiter.api.extension.ExtensionContext;
import org.mockito.junit.jupiter.MockitoExtension;
import org.slf4j.Logger;
import org.slf4j.LoggerFactory;

/**
 * The Class SemillaJUnitExtension.
 *
 * Clase de la librería Semilla.
 *
 * Extensión de Junit que permite cargar automáticamente los
 * ObjectSupplierManager que proveen de juegos de pruebas aleatorios que se
 * indiquen en el fichero testinggames.properties.
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
public class GjsJUnitExtension extends MockitoExtension implements BeforeAllCallback, AutoCloseable {

	/** The Constant PROPERTIES_FILE. */
	private static final String PROPERTIES_FILE = "testinggames";

	/** The Constant logger. */
	private static final Logger logger = LoggerFactory.getLogger(GjsJUnitExtension.class);

	/** The started. */
	private static boolean started;

	/*
	 * (non-Javadoc)
	 *
	 * @see
	 * org.junit.jupiter.api.extension.BeforeAllCallback#beforeAll(org.junit.jupiter
	 * .api.extension.ExtensionContext)
	 */

	@Override
	public void beforeAll(ExtensionContext context) {
		if (!started) {
			started = true;
			try {
				final ResourceBundle rb = ResourceBundle.getBundle(PROPERTIES_FILE);
				for (final String testinggame : rb.keySet()) {
					final ObjectSupplierManager objestSupplierManager = (ObjectSupplierManager) ClazzUtils
							.createInstance(rb.getString(testinggame), logger);
					logger.debug("Adding testing game {} : {}", testinggame, objestSupplierManager);
					TestingGamesSingleton.getInstance().addTestingGamne(testinggame, objestSupplierManager);
				}
			} catch (final MissingResourceException e) {
				// Do nothing
			}
		}
	}

	/*
	 * (non-Javadoc)
	 *
	 * @see
	 * org.junit.jupiter.api.extension.ExtensionContext.Store.CloseableResource#
	 * close()
	 */

	@Override
	public void close() {
		TestingGamesSingleton.getInstance().clear();
	}
}
