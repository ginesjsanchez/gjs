package org.gjs.java.supplier.random;

import java.util.Random;

import org.gjs.java.common.ConditionUtils;
import org.gjs.java.log.LogManager;
import org.gjs.java.supplier.GjsSupplier;
import org.slf4j.LoggerFactory;

/**
 * The class AbstractRandomSupplier.
 *
 * Clase abstracta de datos de la librería Semilla
 *
 * Clase abstracta base para los generadores de datos aleatorios de la librería.
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
 * @param <T> la clase de datos a generar
 *
 * @author Semilla
 * @version 4.0.0
 * @since 3.0.0
 *
 */
public abstract class AbstractRandomSupplier<T> extends LogManager implements GjsSupplier<T> {

	/** Random. */
	protected final Random random = new Random();

	/** The min size collections. */
	private int minSizeArrays = 1;

	/** The max size collections. */
	private int maxSizeArrays = 5;

	/**
	 * Instantiates a new abstract random supplier.
	 */
	public AbstractRandomSupplier() {
		// Default Logger
		setLogger(LoggerFactory.getLogger(getClass()));
	}

	/*
	 * (non-Javadoc)
	 *
	 * @see org.gjs.java.test.objects.suppliers.Supplier#getMinSizeArrays()
	 */

	@Override
	public int getMinSizeArrays() {
		return minSizeArrays;
	}

	/*
	 * (non-Javadoc)
	 *
	 * @see org.gjs.java.test.objects.suppliers.Supplier#setMinSizeArrays(int)
	 */

	@Override
	public void setMinSizeArrays(int minSizeArrays) {
		if (ConditionUtils.allAreTrue((minSizeArrays >= 0), (minSizeArrays <= maxSizeArrays))) {
			this.minSizeArrays = minSizeArrays;
		}
	}

	/*
	 * (non-Javadoc)
	 *
	 * @see org.gjs.java.test.objects.suppliers.Supplier#getMaxSizeArrays()
	 */

	@Override
	public int getMaxSizeArrays() {
		return maxSizeArrays;
	}

	/*
	 * (non-Javadoc)
	 *
	 * @see org.gjs.java.test.objects.suppliers.Supplier#setMaxSizeArrays(int)
	 */

	@Override
	public void setMaxSizeArrays(int maxSizeArrays) {
		if (maxSizeArrays >= minSizeArrays) {
			this.maxSizeArrays = maxSizeArrays;
		}
	}

	/**
	 * Creates the array.
	 *
	 * @param size the size
	 * @return the t[]
	 */
	protected abstract T[] createArray(int size);

	/*
	 * (non-Javadoc)
	 *
	 * @see org.gjs.java.test.objects.suppliers.Supplier#getArray()
	 */

	@Override
	public T[] getArray() {
		int size = minSizeArrays;
		if (maxSizeArrays > minSizeArrays) {
			Integer randomValue = random.nextInt();
			if (randomValue < 0) {
				randomValue = -randomValue;
			}
			size = minSizeArrays + (randomValue % (maxSizeArrays - minSizeArrays));
		}
		debug("Array size={}", size);
		final T[] array = createArray(size);
		for (int i = 0; i < size; i = i + 1) {
			final T value = get();
			array[i] = value;
		}
		return array;
	}

	/*
	 * (non-Javadoc)
	 *
	 * @see org.gjs.java.test.objects.suppliers.Supplier#getEmptyArray()
	 */

	@Override
	public T[] getEmptyArray() {
		return createArray(0);
	}

	/*
	 * (non-Javadoc)
	 *
	 * @see org.gjs.java.test.objects.suppliers.Supplier#getNullius()
	 */

	@Override
	public T getNullius() {
		return getEmpty();
	}

}
