package org.gjs.java.util;

import static org.junit.jupiter.api.Assertions.assertEquals;
import static org.junit.jupiter.api.Assertions.assertNotNull;
import static org.junit.jupiter.api.Assertions.assertNull;
import static org.junit.jupiter.api.Assertions.fail;

import java.util.ResourceBundle;

import org.gjs.java.constant.CommonBaseConstants;
import org.gjs.java.constant.CommonIoConstants;
import org.gjs.java.test.BaseUnitTest;
import org.junit.jupiter.api.Test;

class BundleUtilsTest extends BaseUnitTest<BundleUtils> {

	@Override
	protected void initialize() throws Exception {
		MDCUtils.save(CommonIoConstants.MDC_LOCALE, CommonBaseConstants.DEFAULT_LOCALE);
		logger.info("LOCALE={}", MDCUtils.load(CommonIoConstants.MDC_LOCALE));
	}

	@Test
	void testGetLocalePart() {
		String bundle = null;
		String locale = BundleUtils.getLocalePart(bundle);
		assertNull(locale);
		bundle = "";
		locale = BundleUtils.getLocalePart(bundle);
		assertNull(locale);
		bundle = "bundle";
		locale = BundleUtils.getLocalePart(bundle);
		assertNull(locale);
		bundle = "bundle-en";
		locale = BundleUtils.getLocalePart(bundle);
		assertNotNull(locale);
		assertEquals("en", locale);
		bundle = "bundle-en_US";
		locale = BundleUtils.getLocalePart(bundle);
		assertNotNull(locale);
		assertEquals("en_US", locale);
		bundle = "bundle-app-en_US";
		locale = BundleUtils.getLocalePart(bundle);
		assertNotNull(locale);
		assertEquals("en_US", locale);
	}

	@Test
	void testGetMessage1() {
		try {
			final ResourceBundle bundle = ResourceBundle.getBundle("literals");
			String res = BundleUtils.getMessage((ResourceBundle) null, null);
			assertNotNull(res);
			assertEquals("!null!", res);
			res = BundleUtils.getMessage((ResourceBundle) null, "key");
			assertNotNull(res);
			assertEquals("!key!", res);
			res = BundleUtils.getMessage(bundle, "key");
			assertNotNull(res);
			assertEquals("!key!", res);
			res = BundleUtils.getMessage(bundle, "traza.usuario.bloquear");
			assertNotNull(res);
			assertEquals("Bloquear usuario", res);
		} catch (final Exception e) {
			fail("Recibida excepcion: " + e.getMessage());
		}
	}

	@Test
	void testGetMessage2() {
		try {
			final ResourceBundle bundle = ResourceBundle.getBundle("literals");
			final String param = "Gandalf";
			String res = BundleUtils.getMessage((ResourceBundle) null, (String) null, param);
			assertNotNull(res);
			assertEquals("!null!", res);
			res = BundleUtils.getMessage((ResourceBundle) null, "key", param);
			assertNotNull(res);
			assertEquals("!key!", res);
			res = BundleUtils.getMessage(bundle, "key", param);
			assertNotNull(res);
			assertEquals("!key!", res);
			res = BundleUtils.getMessage(bundle, "traza.insertar", param);
			assertNotNull(res);
			assertEquals(String.format("Crear %s", param), res);
		} catch (final Exception e) {
			fail("Recibida excepcion: " + e.getMessage());
		}
	}

	@Test
	void testGetMessage3() {
		try {
			String res = BundleUtils.getMessage(null);
			assertNotNull(res);
			assertEquals("!null!", res);
			res = BundleUtils.getMessage("key");
			assertNotNull(res);
			assertEquals("!key!", res);
			res = BundleUtils.getMessage("key");
			assertNotNull(res);
			assertEquals("!key!", res);
			res = BundleUtils.getMessage("traza.usuario.bloquear");
			assertNotNull(res);
			assertEquals("Bloquear usuario", res);
		} catch (final Exception e) {
			fail("Recibida excepcion: " + e.getMessage());
		}
	}

	@Test
	void testGetErrorMessage1() {
		try {
			String res = BundleUtils.getErrorMessage(null);
			assertNotNull(res);
			assertEquals("!null!", res);
			res = BundleUtils.getErrorMessage("key");
			assertNotNull(res);
			assertEquals("!key!", res);
			res = BundleUtils.getErrorMessage("key");
			assertNotNull(res);
			assertEquals("!key!", res);
			res = BundleUtils.getErrorMessage("auth-0001");
			assertNotNull(res);
			assertEquals("El usuario no esta autorizado a realizar la operacion", res);
			res = BundleUtils.getErrorMessage("vali-0000", "id");
			assertNotNull(res);
			assertEquals("El campo id es obligatorio", res);
		} catch (final Exception e) {
			fail("Recibida excepcion: " + e.getMessage());
		}
	}

}
