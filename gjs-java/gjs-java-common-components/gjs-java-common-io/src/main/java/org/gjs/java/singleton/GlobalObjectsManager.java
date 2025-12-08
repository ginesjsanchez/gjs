package org.gjs.java.singleton;

import java.util.ArrayList;
import java.util.List;
import java.util.Map;
import java.util.Map.Entry;
import java.util.Objects;
import java.util.concurrent.ConcurrentHashMap;
import java.util.concurrent.locks.Lock;
import java.util.concurrent.locks.ReentrantLock;

import org.apache.commons.lang3.StringUtils;
import org.gjs.java.util.ConditionUtils;

/**
 * The Class GlobalObjectsManager.
 *
 * Clase global singleton de la librería Semilla
 *
 * Clase singleton destinada a gestionar un pool de objetos cualesquiera para
 * ser compartidos por todos los componentes de la librerúia y la aplicación.
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
public class GlobalObjectsManager {

	/** The class lock. */
	private static final Lock CLASS_LOCK = new ReentrantLock();

	/** The instance. */
	private static GlobalObjectsManager instance;

	/** The map objects. */
	private final Map<String, Object> mapObjects;

	/**
	 * Instantiates a new global objects manager.
	 */
	public GlobalObjectsManager() {
		mapObjects = new ConcurrentHashMap<>();
	}

	/**
	 * Gets the single instance of GlobalObjectsManager.
	 *
	 * @return single instance of GlobalObjectsManager
	 */
	public static GlobalObjectsManager getInstance() {
		try {
			CLASS_LOCK.lock();
			if (instance == null) {
				instance = new GlobalObjectsManager();
			}
		} finally {
			CLASS_LOCK.unlock();
		}
		return instance;
	}

	/**
	 * Save.
	 *
	 * @param key   the key
	 * @param value the value
	 */
	public void save(String key, Object value) {
		if (ConditionUtils.allAreTrue(!StringUtils.isAllBlank(key), Objects.nonNull(value))) {
			mapObjects.put(key, value);
		}
	}

	/**
	 * Load.
	 *
	 * @param key the key
	 * @return the object
	 */
	public Object load(String key) {
		Object res = null;
		if (!StringUtils.isAllBlank(key)) {
			res = mapObjects.get(key);
		}
		return res;
	}

	/**
	 * Removes the.
	 *
	 * @param key the key
	 */
	public void remove(String key) {
		if (!StringUtils.isAllBlank(key)) {
			mapObjects.remove(key);
		}
	}

	/**
	 * get keys.
	 *
	 * @param clazz the clazz
	 * @return the list
	 */
	public List<String> getKeys(Class<?> clazz) {
		final List<String> res = new ArrayList<>();
		for (final Entry<String, Object> entry : mapObjects.entrySet()) {
			if (entry.getValue().getClass().getCanonicalName().equals(clazz.getCanonicalName())) {
				res.add(entry.getKey());
			}
		}
		return res;
	}

	/**
	 * Load all.
	 *
	 * @param clazz the clazz
	 * @return the list
	 */
	public List<Object> loadAll(Class<?> clazz) {
		final List<Object> res = new ArrayList<>();
		for (final Object value : mapObjects.values()) {
			if (value.getClass().getCanonicalName().equals(clazz.getCanonicalName())) {
				res.add(value);
			}
		}
		return res;
	}

	/**
	 * Clear.
	 */
	public void clear() {
		mapObjects.clear();
	}

}
