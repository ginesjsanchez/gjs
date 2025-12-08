package org.gjs.java.singleton;

import static org.junit.jupiter.api.Assertions.assertEquals;
import static org.junit.jupiter.api.Assertions.assertNotNull;
import static org.junit.jupiter.api.Assertions.assertNull;
import static org.junit.jupiter.api.Assertions.fail;

import java.util.Locale;

import org.apache.commons.lang3.exception.ExceptionUtils;
import org.gjs.java.constant.CommonBaseConstants;
import org.gjs.java.test.BaseUnitTest;
import org.gjs.java.util.BundleUtils;
import org.junit.jupiter.api.MethodOrderer.OrderAnnotation;
import org.junit.jupiter.api.Order;
import org.junit.jupiter.api.Test;
import org.junit.jupiter.api.TestMethodOrder;

@TestMethodOrder(OrderAnnotation.class)
class GlobalBundleManagerTest extends BaseUnitTest<GlobalBundleManager> {

	@Order(1)
	@Test
	void testGlobalBundleManager1() {
		try {
			final GlobalBundleManager bundleManager = GlobalBundleManager.getInstance();
			String res = bundleManager.getMessage("key");
			assertNull(res);
			res = bundleManager.getErrorMessage("key");
			assertNull(res);
			bundleManager.addMessageBundle("literalsApp");
			bundleManager.addErrorBundle("errorsApp");
			res = bundleManager.getMessage("key");
			assertNull(res);
			res = bundleManager.getErrorMessage("key");
			assertNull(res);
			res = bundleManager.getMessage(null);
			assertNull(res);
			res = bundleManager.getErrorMessage(null);
			assertNull(res);
			res = bundleManager.getMessage("traza.usuario.bloquear");
			assertNotNull(res);
			assertEquals("Bloquear usuario", res);
			final String param = "Gandalf";
			res = bundleManager.getMessage("traza.insertar", param);
			assertNotNull(res);
			assertEquals(String.format("Crear %s", param), res);
			res = bundleManager.getErrorMessage("auth-0001");
			assertEquals("El usuario no esta autorizado a realizar la operacion", res);
			res = BundleUtils.getErrorMessage("vali-0000", "id");
			assertNotNull(res);
			assertEquals("El campo id es obligatorio", res);
		} catch (final Exception e) {
			logger.error(ExceptionUtils.getStackTrace(e.getCause()));
			fail("Recibida excepcion: " + e.getMessage());
		}
	}

	@Order(2)
	@Test
	void testGlobalBundleManager2() {
		try {
			String res = GlobalBundleManager.getSafetyErrorMessage("key");
			assertNotNull(res);
			assertEquals(CommonBaseConstants.MSG_UNKNOWN_ERROR, res);
			res = GlobalBundleManager.getSafetyErrorMessage("auth-0001");
			assertNotNull(res);
			assertEquals("El usuario no esta autorizado a realizar la operacion", res);
			res = GlobalBundleManager.getSafetyErrorMessage("vali-0000", "id");
			assertNotNull(res);
			assertEquals("El campo id es obligatorio", res);
		} catch (final Exception e) {
			logger.error(ExceptionUtils.getStackTrace(e.getCause()));
			fail("Recibida excepcion: " + e.getMessage());
		}
	}

	@Order(3)
	@Test
	void testGlobalBundleManager3() {
		try {
			String res = GlobalBundleManager.getSafetyMessage("key");
			assertNotNull(res);
			assertEquals(CommonBaseConstants.MSG_UNKNOWN_ERROR, res);
			res = GlobalBundleManager.getSafetyMessage("traza.usuario.bloquear");
			assertNotNull(res);
			assertEquals("Bloquear usuario", res);
			final String param = "Gandalf";
			res = GlobalBundleManager.getSafetyMessage("traza.insertar", param);
			assertNotNull(res);
			assertEquals(String.format("Crear %s", param), res);
		} catch (final Exception e) {
			logger.error(ExceptionUtils.getStackTrace(e.getCause()));
			fail("Recibida excepcion: " + e.getMessage());
		}
	}

	@Order(4)
	@Test
	void testGlobalBundleManager4() {
		try {
			final Locale locale = null;
			String res = GlobalBundleManager.getSafetyMessage(locale, "key");
			assertNotNull(res);
			assertEquals(CommonBaseConstants.MSG_UNKNOWN_ERROR, res);
			res = GlobalBundleManager.getSafetyMessage(locale, "traza.usuario.bloquear");
			assertNotNull(res);
			assertEquals("Bloquear usuario", res);
			final String param = "Gandalf";
			res = GlobalBundleManager.getSafetyMessage(locale, "traza.insertar", param);
			assertNotNull(res);
			assertEquals(String.format("Crear %s", param), res);
		} catch (final Exception e) {
			logger.error(ExceptionUtils.getStackTrace(e.getCause()));
			fail("Recibida excepcion: " + e.getMessage());
		}
	}

	@Order(5)
	@Test
	void testGlobalBundleManager5() {
		try {
			final GlobalBundleManager bundleManager = GlobalBundleManager.getInstance();
			bundleManager.addMessageBundle("literalsApp");
			bundleManager.addErrorBundle("errorsApp");
			bundleManager.addMessageBundle("literals-en");
			bundleManager.addErrorBundle("errors-en");
			bundleManager.addMessageBundle("literalsApp-en");
			bundleManager.addErrorBundle("errorsApp-en");
			bundleManager.addMessageBundle("literals-en_US");
			bundleManager.addErrorBundle("errors-en_US");
			bundleManager.addMessageBundle("literalsApp-en_US");
			bundleManager.addErrorBundle("errorsApp-en_US");
			final Locale locale = null;
			String res = bundleManager.getMessage(locale, "key");
			assertNull(res);
			res = bundleManager.getErrorMessage(locale, "key");
			assertNull(res);
			res = bundleManager.getMessage(locale, null);
			assertNull(res);
			res = bundleManager.getErrorMessage(locale, null);
			assertNull(res);
			res = bundleManager.getMessage(locale, "traza.usuario.bloquear");
			assertNotNull(res);
			assertEquals("Bloquear usuario", res);
			final String param = "Gandalf";
			res = bundleManager.getMessage(locale, "traza.insertar", param);
			assertNotNull(res);
			assertEquals(String.format("Crear %s", param), res);
			res = bundleManager.getErrorMessage(locale, "auth-0001");
			assertEquals("El usuario no esta autorizado a realizar la operacion", res);
			res = GlobalBundleManager.getSafetyErrorMessage(locale, "key");
			assertNotNull(res);
			assertEquals(CommonBaseConstants.MSG_UNKNOWN_ERROR, res);
			res = GlobalBundleManager.getSafetyErrorMessage(locale, "auth-0001");
			assertNotNull(res);
			assertEquals("El usuario no esta autorizado a realizar la operacion", res);
			res = GlobalBundleManager.getSafetyErrorMessage(locale, "vali-0000", "id");
			assertNotNull(res);
			assertEquals("El campo id es obligatorio", res);
		} catch (final Exception e) {
			logger.error(ExceptionUtils.getStackTrace(e.getCause()));
			fail("Recibida excepcion: " + e.getMessage());
		}
	}

	@Order(6)
	@Test
	void testGlobalBundleManager6() {
		try {
			final GlobalBundleManager bundleManager = GlobalBundleManager.getInstance();
			bundleManager.addMessageBundle("literalsApp");
			bundleManager.addErrorBundle("errorsApp");
			bundleManager.addMessageBundle("literals-en");
			bundleManager.addErrorBundle("errors-en");
			bundleManager.addMessageBundle("literalsApp-en");
			bundleManager.addErrorBundle("errorsApp-en");
			bundleManager.addMessageBundle("literals-en_US");
			bundleManager.addErrorBundle("errors-en_US");
			bundleManager.addMessageBundle("literalsApp-en_US");
			bundleManager.addErrorBundle("errorsApp-en_US");
			final Locale locale = Locale.FRENCH;
			String res = bundleManager.getMessage(locale, "key");
			assertNull(res);
			res = bundleManager.getErrorMessage(locale, "key");
			assertNull(res);
			res = bundleManager.getMessage(locale, null);
			assertNull(res);
			res = bundleManager.getErrorMessage(locale, null);
			assertNull(res);
			res = bundleManager.getMessage(locale, "traza.usuario.bloquear");
			assertNotNull(res);
			assertEquals("Bloquear usuario", res);
			final String param = "Gandalf";
			res = bundleManager.getMessage(locale, "traza.insertar", param);
			assertNotNull(res);
			assertEquals(String.format("Crear %s", param), res);
			res = bundleManager.getErrorMessage(locale, "auth-0001");
			assertEquals("El usuario no esta autorizado a realizar la operacion", res);
			res = GlobalBundleManager.getSafetyErrorMessage(locale, "key");
			assertNotNull(res);
			assertEquals(CommonBaseConstants.MSG_UNKNOWN_ERROR, res);
			res = GlobalBundleManager.getSafetyErrorMessage(locale, "auth-0001");
			assertNotNull(res);
			assertEquals("El usuario no esta autorizado a realizar la operacion", res);
			res = GlobalBundleManager.getSafetyErrorMessage(locale, "vali-0000", "id");
			assertNotNull(res);
			assertEquals("El campo id es obligatorio", res);
		} catch (final Exception e) {
			logger.error(ExceptionUtils.getStackTrace(e.getCause()));
			fail("Recibida excepcion: " + e.getMessage());
		}
	}

	@Order(7)
	@Test
	void testGlobalBundleManager7() {
		try {
			final GlobalBundleManager bundleManager = GlobalBundleManager.getInstance();
			bundleManager.addMessageBundle("literalsApp");
			bundleManager.addErrorBundle("errorsApp");
			bundleManager.addMessageBundle("literals-en");
			bundleManager.addErrorBundle("errors-en");
			bundleManager.addMessageBundle("literalsApp-en");
			bundleManager.addErrorBundle("errorsApp-en");
			bundleManager.addMessageBundle("literals-en_US");
			bundleManager.addErrorBundle("errors-en_US");
			bundleManager.addMessageBundle("literalsApp-en_US");
			bundleManager.addErrorBundle("errorsApp-en_US");
			final Locale locale = Locale.ENGLISH;
			String res = bundleManager.getMessage(locale, "key");
			assertNull(res);
			res = bundleManager.getErrorMessage(locale, "key");
			assertNull(res);
			res = bundleManager.getMessage(locale, null);
			assertNull(res);
			res = bundleManager.getErrorMessage(locale, null);
			assertNull(res);
			res = bundleManager.getMessage(locale, "traza.usuario.bloquear");
			assertNotNull(res);
			assertEquals("Block user", res);
			final String param = "Gandalf";
			res = bundleManager.getMessage(locale, "traza.insertar", param);
			assertNotNull(res);
			assertEquals(String.format("Create %s", param), res);
			res = bundleManager.getErrorMessage(locale, "auth-0001");
			assertEquals("The user is not authorized to perform the operation", res);
			res = GlobalBundleManager.getSafetyErrorMessage(locale, "key");
			assertNotNull(res);
			assertEquals(CommonBaseConstants.MSG_UNKNOWN_ERROR, res);
			res = GlobalBundleManager.getSafetyErrorMessage(locale, "auth-0001");
			assertNotNull(res);
			assertEquals("The user is not authorized to perform the operation", res);
			res = GlobalBundleManager.getSafetyErrorMessage(locale, "vali-0000", "id");
			assertNotNull(res);
			assertEquals("The field id is mandatory", res);
			res = GlobalBundleManager.getSafetyMessage(locale, "traza.usuario.bloquear");
			assertNotNull(res);
			assertEquals("Block user", res);
			res = GlobalBundleManager.getSafetyMessage(locale, "traza.insertar", param);
			assertNotNull(res);
			assertEquals(String.format("Create %s", param), res);
		} catch (final Exception e) {
			logger.error(ExceptionUtils.getStackTrace(e.getCause()));
			fail("Recibida excepcion: " + e.getMessage());
		}
	}

	@Order(8)
	@Test
	void testGlobalBundleManager8() {
		try {
			final GlobalBundleManager bundleManager = GlobalBundleManager.getInstance();
			bundleManager.addMessageBundle("literalsApp");
			bundleManager.addErrorBundle("errorsApp");
			bundleManager.addMessageBundle("literals-en");
			bundleManager.addErrorBundle("errors-en");
			bundleManager.addMessageBundle("literalsApp-en");
			bundleManager.addErrorBundle("errorsApp-en");
			bundleManager.addMessageBundle("literals-en_US");
			bundleManager.addErrorBundle("errors-en_US");
			bundleManager.addMessageBundle("literalsApp-en_US");
			bundleManager.addErrorBundle("errorsApp-en_US");
			final Locale locale = Locale.US;
			String res = bundleManager.getMessage(locale, "key");
			assertNull(res);
			res = bundleManager.getErrorMessage(locale, "key");
			assertNull(res);
			res = bundleManager.getMessage(locale, null);
			assertNull(res);
			res = bundleManager.getErrorMessage(locale, null);
			assertNull(res);
			res = bundleManager.getMessage(locale, "traza.usuario.bloquear");
			assertNotNull(res);
			assertEquals("Kill user", res);
			final String param = "Gandalf";
			res = bundleManager.getMessage(locale, "traza.insertar", param);
			assertNotNull(res);
			assertEquals(String.format("Create %s", param), res);
			res = bundleManager.getErrorMessage(locale, "auth-0001");
			assertEquals("This operation is forbidden", res);
			res = GlobalBundleManager.getSafetyErrorMessage(locale, "key");
			assertNotNull(res);
			assertEquals(CommonBaseConstants.MSG_UNKNOWN_ERROR, res);
			res = GlobalBundleManager.getSafetyErrorMessage(locale, "auth-0001");
			assertNotNull(res);
			assertEquals("This operation is forbidden", res);
			res = GlobalBundleManager.getSafetyErrorMessage(locale, "vali-0000", "id");
			assertNotNull(res);
			assertEquals("The field id is mandatory!", res);
		} catch (final Exception e) {
			logger.error(ExceptionUtils.getStackTrace(e.getCause()));
			fail("Recibida excepcion: " + e.getMessage());
		}
	}

}
