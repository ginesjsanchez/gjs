package org.gjs.java.test.util;

import java.util.List;
import java.util.Objects;

import org.apache.commons.collections4.CollectionUtils;
import org.apache.commons.lang3.StringUtils;
import org.gjs.java.common.ConditionUtils;

import com.openpojo.validation.Validator;
import com.openpojo.validation.ValidatorBuilder;
import com.openpojo.validation.test.Tester;

/**
 * The Class PojoUtils.
 *
 * Clase de utilidades generales de la librería Semilla
 *
 * Algunas funciones de ayuda para la implementación de los test Pojos
 * automatizados.
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
public final class PojoUtils {

	/**
	 * Clase no instanciable.
	 */
	private PojoUtils() {
		throw new IllegalStateException("Utility class");
	}

	/**
	 * Test pojo.
	 *
	 * @param tester        the tester
	 * @param packageToTest the package to test
	 */
	public static void testPojo(Tester tester, String packageToTest) {
		if (ConditionUtils.allAreTrue(Objects.nonNull(tester), !StringUtils.isAllBlank(packageToTest))) {
			final Validator validator = ValidatorBuilder.create().with(tester).build();
			validator.validate(packageToTest);
		}
	}

	/**
	 * Test pojo.
	 *
	 * @param testers       the testers
	 * @param packageToTest the package to test
	 */
	public static void testPojo(List<Tester> testers, String packageToTest) {
		if (ConditionUtils.allAreTrue(!CollectionUtils.isEmpty(testers), !StringUtils.isAllBlank(packageToTest))) {
			ValidatorBuilder validatorBuilder = ValidatorBuilder.create();
			for (final Tester tester : testers) {
				validatorBuilder = validatorBuilder.with(tester);
			}
			final Validator validator = validatorBuilder.build();
			validator.validate(packageToTest);
		}
	}

}
