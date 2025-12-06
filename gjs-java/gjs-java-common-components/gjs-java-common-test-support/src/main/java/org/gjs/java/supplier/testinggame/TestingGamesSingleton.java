package org.gjs.java.supplier.testinggame;

import java.util.Map;
import java.util.Map.Entry;
import java.util.Objects;
import java.util.concurrent.ConcurrentHashMap;

import org.apache.commons.lang3.ObjectUtils;
import org.gjs.java.supplier.ObjectSupplierManager;
import org.slf4j.Logger;

/**
 * The Class TestingGamesSingleton.
 *
 * Clase singleton de la librería Semilla.
 *
 * Clase singleton pensada como proveedor global de juegos de pruebas para los
 * test. Se puede utilizar directamente a través de SemillaJunitExtension.
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
public final class TestingGamesSingleton {

	/** The instance. */
	private static TestingGamesSingleton instance;

	/** The testings games. */
	private final Map<String, ObjectSupplierManager> testingsGames = new ConcurrentHashMap<>();

	/**
	 * Instantiates a new testing games singleton.
	 */
	public TestingGamesSingleton() {
		// No hace nada
	}

	/**
	 * Gets the single instance of TestingGamesSingleton.
	 *
	 * @return single instance of TestingGamesSingleton
	 */
	public static TestingGamesSingleton getInstance() {
		if (Objects.isNull(instance)) {
			instance = new TestingGamesSingleton();
		}
		return instance;
	}

	/**
	 * Adds the testing gamne.
	 *
	 * @param <T>         the generic type
	 * @param name        the name
	 * @param testingGame the testing game
	 */
	public <T extends ObjectSupplierManager> void addTestingGamne(String name, T testingGame) {
		if (ObjectUtils.allNotNull(name, testingGame)) {
			testingsGames.put(name, testingGame);
		}
	}

	/**
	 * Gets the testing game.
	 *
	 * @param <T>  the generic type
	 * @param name the name
	 * @return the testing game
	 */
	@SuppressWarnings("unchecked")
	public <T extends ObjectSupplierManager> T getTestingGame(String name) {
		T res = null;
		if (Objects.nonNull(name)) {
			res = (T) testingsGames.get(name);
		}
		return res;
	}

	/**
	 * Clear.
	 */
	public void clear() {
		testingsGames.clear();
	}

	/**
	 * Sets the logger.
	 *
	 * @param logger the new logger
	 */
	public void setLogger(Logger logger) {
		for (final Entry<String, ObjectSupplierManager> entry : testingsGames.entrySet()) {
			entry.getValue().setLogger(logger);
		}
	}

}
