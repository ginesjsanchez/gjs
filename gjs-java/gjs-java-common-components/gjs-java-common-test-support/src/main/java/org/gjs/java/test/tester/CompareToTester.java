package org.gjs.java.test.tester;

import org.apache.commons.lang3.exception.ExceptionUtils;
import org.gjs.java.common.ReflectionUtils;
import org.gjs.java.supplier.GenericObjectSupplier;
import org.slf4j.Logger;
import org.slf4j.LoggerFactory;

import com.openpojo.reflection.PojoClass;

/**
 * The Class CompareToTester.
 *
 * Clase de datos de la librería Semilla
 *
 * Tester de métodos compareTo.
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
public class CompareToTester extends BaseMethodTester {

	/** The Constant logger. */
	private static final Logger logger = LoggerFactory.getLogger(CompareToTester.class);

	/** The Constant TEST_METHOD. */
	private static final String TEST_METHOD = "compareTo";

	/**
	 * Instantiates a new compare to tester.
	 */
	public CompareToTester() {
		super(logger);
	}

	/**
	 * Instantiates a new compare to tester.
	 *
	 * @param stopOnError the stop on error
	 */
	public CompareToTester(boolean stopOnError) {
		super(logger, stopOnError);
	}

	/*
	 * (non-Javadoc)
	 *
	 * @see org.gjs.java.test.tester.BaseMethodTester#getTestMethod()
	 */

	@Override
	public String getTestMethod() {
		return TEST_METHOD;
	}

	/*
	 * (non-Javadoc)
	 *
	 * @see
	 * com.openpojo.validation.test.Tester#run(com.openpojo.reflection.PojoClass)
	 */

	@SuppressWarnings("unchecked")
	@Override
	public void runTest(PojoClass pojoClass) {
		final String className = pojoClass.getClazz().getCanonicalName();
		final GenericObjectSupplier supplier = new GenericObjectSupplier(className);
		supplier.setInformAllFields(true);
		supplier.setLogger(logger);
		final Object instance1 = supplier.get();
		if (instance1 instanceof Comparable) {
			logger.info("CompareToTester: Class={}", className);
			final Comparable<Object> comparable = ((Comparable<Object>) instance1);
			final Object instance2 = supplier.get();
			final Object instanceClon = ReflectionUtils.clone(instance1);
			final Object other = supplier.getNullius();
			final Object instanceEmpty = supplier.getEmpty();
			final Comparable<Object> comparableEmpty = ((Comparable<Object>) instanceEmpty);
			logger.debug("** COMPARETO INSTANCE1={}", instance1);
			logger.debug("** COMPARETO INSTANCE2={}", instance2);
			logger.debug("** COMPARETO INSTANCECLON={}", instanceClon);
			logger.debug("** COMPARETO NULLIUS={}", other);
			logger.debug("** COMPARETO INSTANCEEMPTY={}", instanceEmpty);
			final Object nullObj = null;
			try {
				affirmTrue(String.format("Class=[%s] 'compareTo()' same object", className),
						comparable.compareTo(instance1) == 0);
				affirmTrue(String.format("Class=[%s] 'compareTo()' cloned object", className),
						comparable.compareTo(instanceClon) == 0);
				if (comparable.compareTo(instance2) != 0) {
					affirmFalse(String.format("Class=[%s] 'compareTo()' different random objects", className),
							comparable.compareTo(instance2) == 0);
				}
				affirmFalse(String.format("Class=[%s] 'compareTo()' null object", className),
						comparable.compareTo(nullObj) == 0);
				affirmFalse(String.format("Class=[%s] 'compareTo()' empty object (1)", className),
						comparable.compareTo(instanceEmpty) == 0);
				affirmFalse(String.format("Class=[%s] 'compareTo()' empty object (2)", className),
						comparable.compareTo(other) == 0);
				affirmTrue(String.format("Class=[%s] 'compareTo()' empty same object", className),
						comparableEmpty.compareTo(instanceEmpty) == 0);
				affirmFalse(String.format("Class=[%s] 'compareTo()' empty and random object", className),
						comparableEmpty.compareTo(instance1) == 0);
			} catch (final Exception ex) {
				logger.error("CompareToTester: Class=[{}] Exception;\n{}", className, ex.getMessage());
				logger.error(ExceptionUtils.getStackTrace(ex));
				throw ex;
			}
		}
	}

}
