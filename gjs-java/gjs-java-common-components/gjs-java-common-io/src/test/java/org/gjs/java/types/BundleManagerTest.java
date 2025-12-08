package org.gjs.java.types;

import static org.junit.jupiter.api.Assertions.assertEquals;
import static org.junit.jupiter.api.Assertions.assertFalse;
import static org.junit.jupiter.api.Assertions.assertNotNull;
import static org.junit.jupiter.api.Assertions.assertNull;
import static org.junit.jupiter.api.Assertions.assertTrue;
import static org.junit.jupiter.api.Assertions.fail;

import java.util.Locale;
import java.util.ResourceBundle;

import org.apache.commons.lang3.exception.ExceptionUtils;
import org.gjs.java.constant.CommonIoConstants;
import org.gjs.java.test.BaseClassTest;
import org.gjs.java.util.MDCUtils;
import org.junit.jupiter.api.Test;

class BundleManagerTest extends BaseClassTest<BundleManager> {

	@Test
	void testBundleManager1() {
		try {
			final BundleManager bundleManager = new BundleManager();
			final ResourceBundle bundle = ResourceBundle.getBundle("literals");
			assertFalse(bundleManager.isMultilanguage());
			String res = bundleManager.getMessage("key");
			assertNull(res);
			bundleManager.addBundle(bundle);
			assertFalse(bundleManager.isMultilanguage());
			res = bundleManager.getMessage(null);
			assertNull(res);
			res = bundleManager.getMessage("key");
			assertNull(res);
			res = bundleManager.getMessage("traza.usuario.bloquear");
			assertNotNull(res);
			assertEquals("Bloquear usuario", res);
		} catch (final Exception e) {
			fail("Recibida excepcion: " + e.getMessage());
		}
	}

	@Test
	void testBundleManager2() {
		try {
			final BundleManager bundleManager = new BundleManager();
			bundleManager.addBundle("literals");
			bundleManager.addBundle("literalsApp");
			assertFalse(bundleManager.isMultilanguage());
			String res = bundleManager.getMessage("key");
			assertNull(res);
			final String param = "Gandalf";
			res = bundleManager.getMessage("traza.insertar", param);
			assertNotNull(res);
			assertEquals(String.format("Crear %s", param), res);
			res = bundleManager.getMessage("app.welcome", param);
			assertNotNull(res);
			assertEquals("Hola mundo!", res);
			res = bundleManager.getMessage("traza.ejemplo", "mensaje", 2);
			assertNotNull(res);
			assertEquals("Este mensaje no tiene 2 indices", res);
		} catch (final Exception e) {
			logger.error(ExceptionUtils.getStackTrace(e));
			fail("Recibida excepcion");
		}
	}

	@Test
	void testBundleManager3() {
		try {
			final BundleManager bundleManager = new BundleManager();
			bundleManager.addBundle("literals");
			bundleManager.addBundle("literalsApp");
			assertFalse(bundleManager.isMultilanguage());
			bundleManager.addBundle("literals-en");
			bundleManager.addBundle("literalsApp-en");
			bundleManager.addBundle("literals-en_US");
			bundleManager.addBundle("literalsApp-en_US");
			assertTrue(bundleManager.isMultilanguage());
			String res = bundleManager.getMessage("key");
			assertNull(res);
			res = bundleManager.getMessage(null);
			assertNull(res);
			res = bundleManager.getMessage("key");
			assertNull(res);
			res = bundleManager.getMessage("traza.usuario.bloquear");
			assertNotNull(res);
			assertEquals("Bloquear usuario", res);
			res = bundleManager.getMessage("app.welcome");
			assertNotNull(res);
			assertEquals("Hola mundo!", res);
			res = bundleManager.getMessage(Locale.ENGLISH, null);
			assertNull(res);
			res = bundleManager.getMessage(Locale.ENGLISH, "key");
			assertNull(res);
			res = bundleManager.getMessage(Locale.ENGLISH, "traza.usuario.bloquear");
			assertNotNull(res);
			assertEquals("Block user", res);
			res = bundleManager.getMessage(Locale.ENGLISH, "app.welcome");
			assertNotNull(res);
			assertEquals("Hello world!", res);
			res = bundleManager.getMessage(Locale.US, null);
			assertNull(res);
			res = bundleManager.getMessage(Locale.US, "key");
			assertNull(res);
			res = bundleManager.getMessage(Locale.US, "traza.usuario.bloquear");
			assertNotNull(res);
			assertEquals("Kill user", res);
			res = bundleManager.getMessage(Locale.US, "app.welcome");
			assertNotNull(res);
			assertEquals("Hello world!!!", res);
			res = bundleManager.getMessage(Locale.FRENCH, null);
			assertNull(res);
			res = bundleManager.getMessage(Locale.FRENCH, "key");
			assertNull(res);
			res = bundleManager.getMessage(Locale.FRENCH, "traza.usuario.bloquear");
			assertNotNull(res);
			assertEquals("Bloquear usuario", res);
			res = bundleManager.getMessage(Locale.FRENCH, "app.welcome");
			assertNotNull(res);
			assertEquals("Hola mundo!", res);
		} catch (final Exception e) {
			fail("Recibida excepcion: " + e.getMessage());
		}
	}

	@Test
	void testBundleManager4() {
		try {
			MDCUtils.save(CommonIoConstants.MDC_LOCALE, Locale.ENGLISH);
			logger.info("LOCALE={}", MDCUtils.load(CommonIoConstants.MDC_LOCALE));
			final BundleManager bundleManager = new BundleManager();
			bundleManager.addBundle("literals");
			bundleManager.addBundle("literalsApp");
			assertFalse(bundleManager.isMultilanguage());
			bundleManager.addBundle("literals-en");
			bundleManager.addBundle("literalsApp-en");
			bundleManager.addBundle("literals-en_US");
			bundleManager.addBundle("literalsApp-en_US");
			assertTrue(bundleManager.isMultilanguage());
			String res = bundleManager.getMessage(null);
			assertNull(res);
			res = bundleManager.getMessage("key");
			assertNull(res);
			res = bundleManager.getMessage("traza.usuario.bloquear");
			assertNotNull(res);
			assertEquals("Block user", res);
			res = bundleManager.getMessage("app.welcome");
			assertNotNull(res);
			assertEquals("Hello world!", res);
			res = bundleManager.getMessage(null, "key");
			assertNull(res);
			res = bundleManager.getMessage(null, "traza.usuario.bloquear");
			assertNotNull(res);
			assertEquals("Bloquear usuario", res);
			res = bundleManager.getMessage(null, "app.welcome");
			assertNotNull(res);
			assertEquals("Hola mundo!", res);
		} catch (final Exception e) {
			fail("Recibida excepcion: " + e.getMessage());
		}
	}

}
