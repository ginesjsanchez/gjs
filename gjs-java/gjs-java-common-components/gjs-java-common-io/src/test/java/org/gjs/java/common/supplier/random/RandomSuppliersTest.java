package org.gjs.java.common.supplier.random;

import static org.junit.jupiter.api.Assertions.assertNotNull;
import static org.junit.jupiter.api.Assertions.assertTrue;
import static org.junit.jupiter.api.Assertions.fail;

import java.util.Arrays;
import java.util.Set;
import java.util.TreeSet;

import org.apache.commons.lang3.exception.ExceptionUtils;
import org.gjs.java.test.AbstractClassTest;
import org.junit.jupiter.api.Test;

class RandomSuppliersTest extends AbstractClassTest {

	@Override
	protected Class<?> getClazz() {
		return AbstractRandomSupplier.class;
	}

	@Test
	void testRandomSelectedFromFileSupplier() {
		// final Path filePath = currentDir.resolve("data/nombres.txt");
		// logger.info("{}", filePath.toAbsolutePath().toString().replace("\\",
		// "\\\\"));
		final String[] options = { "Juan", "Hermes", "Antonio", "Raimundo", "Dagoberto" };
		final Set<String> setOptions = new TreeSet<>(Arrays.asList(options));

		try {

			final RandomSelectedFromFileSupplier supplier = new RandomSelectedFromFileSupplier("data/nombres.txt");
			for (int i = 0; i < 20; i = i + 1) {
				final String value = supplier.get();
				assertNotNull(value);
				logger.debug("Valor generado={}", value);
				assertTrue(setOptions.contains(value));
			}

		} catch (final Exception e) {
			logger.error(ExceptionUtils.getStackTrace(e));
			fail("Excepcion inesperada");
		}
	}

	@Test
	void testRandomNameSupplier() {
		try {
			final RandomNameSupplier supplier = new RandomNameSupplier();
			for (int i = 0; i < 100; i = i + 1) {
				final String value = supplier.get();
				assertNotNull(value);
				logger.debug("Valor generado={}", value);
			}

		} catch (final Exception e) {
			logger.error(ExceptionUtils.getStackTrace(e));
			fail("Excepcion inesperada");
		}
	}

	@Test
	void testRandomSurnameSupplier() {
		try {
			final RandomSurnameSupplier supplier = new RandomSurnameSupplier();
			for (int i = 0; i < 100; i = i + 1) {
				final String value = supplier.get();
				assertNotNull(value);
				logger.debug("Valor generado={}", value);
			}

		} catch (final Exception e) {
			logger.error(ExceptionUtils.getStackTrace(e));
			fail("Excepcion inesperada");
		}
	}

}
