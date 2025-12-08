package org.gjs.java.util;

import static org.junit.jupiter.api.Assertions.assertEquals;
import static org.junit.jupiter.api.Assertions.assertFalse;
import static org.junit.jupiter.api.Assertions.assertNotEquals;
import static org.junit.jupiter.api.Assertions.assertNotNull;
import static org.junit.jupiter.api.Assertions.assertNull;
import static org.junit.jupiter.api.Assertions.assertTrue;

import java.util.Locale;

import org.apache.commons.lang3.LocaleUtils;
import org.gjs.java.constant.CommonBaseConstants;
import org.gjs.java.constant.CommonSupportConstants;
import org.gjs.java.test.BaseClassTest;
import org.junit.jupiter.api.Test;

class ResourceUtilsTest extends BaseClassTest<ResourceUtils> {

	@Test
	void testGetResourcePath1() {
		String kind = null;
		String name = null;
		String type = null;
		Locale locale = null;
		String path = ResourceUtils.getResourcePath(kind, name, type, locale);
		assertNull(path);

		kind = CommonSupportConstants.RESOURCE_MAIL_TEMPLATE;
		name = "alta";
		type = "txt";
		locale = null;
		path = ResourceUtils.getResourcePath(kind, name, type, locale);
		assertNotNull(path);
		String expected = String.format("%s/%s.%s", kind, name, type);
		assertEquals(expected, path);
		path = ResourceUtils.getResourcePath(kind, name, type);
		assertNotNull(path);
		assertEquals(expected, path);

		kind = CommonSupportConstants.RESOURCE_MAIL_TEMPLATE;
		name = "alta";
		type = "txt";
		locale = CommonBaseConstants.DEFAULT_LOCALE;
		path = ResourceUtils.getResourcePath(kind, name, type, locale);
		assertNotNull(path);
		expected = String.format("%s/%s.%s", kind, name, type);
		assertEquals(expected, path);
		path = ResourceUtils.getResourcePath(kind, name, type);
		assertNotNull(path);
		assertEquals(expected, path);

		kind = CommonSupportConstants.RESOURCE_MAIL_TEMPLATE;
		name = "alta";
		type = "txt";
		locale = Locale.ENGLISH;
		path = ResourceUtils.getResourcePath(kind, name, type, locale);
		assertNotNull(path);
		expected = String.format("%s/%s-en.%s", kind, name, type);
		assertEquals(expected, path);
	}

	@Test
	void testGetResourcePath2() {
		final String kind = CommonSupportConstants.RESOURCE_MAIL_TEMPLATE;
		final String name = "alta";
		final String type = "txt";
		Locale locale = LocaleUtils.toLocale("es");
		final String path1 = ResourceUtils.getResourcePath(kind, name, type, locale);
		assertNotNull(path1);
		String expected = String.format("%s/%s.%s", kind, name, type);
		assertEquals(expected, path1);
		locale = LocaleUtils.toLocale("es_ES");
		final String path2 = ResourceUtils.getResourcePath(kind, name, type, locale);
		assertNotNull(path2);
		assertEquals(path1, path2);
		locale = LocaleUtils.toLocale("es_PR");
		final String path3 = ResourceUtils.getResourcePath(kind, name, type, locale);
		assertNotNull(path3);
		assertNotEquals(path1, path3);
		expected = String.format("%s/%s-es_PR.%s", kind, name, type);
		assertEquals(expected, path3);
	}

	@Test
	void testGetResourcePath3() {
		final String kind = CommonSupportConstants.RESOURCE_MAIL_TEMPLATE;
		final String name = "alta";
		final String type = "txt";
		final Locale locale = Locale.of("es");
		String profile = "dev";
		String path1 = ResourceUtils.getResourcePath(kind, name, type, locale, profile);
		assertNotNull(path1);
		String expected = String.format("%s/%s-%s.%s", kind, name, profile, type, profile);
		assertEquals(expected, path1);
		profile = "pre";
		path1 = ResourceUtils.getResourcePath(kind, name, type, locale, profile);
		assertNotNull(path1);
		expected = String.format("%s/%s-%s.%s", kind, name, profile, type, profile);
		assertEquals(expected, path1);
		profile = "pro";
		path1 = ResourceUtils.getResourcePath(kind, name, type, locale, profile);
		assertNotNull(path1);
		expected = String.format("%s/%s-%s.%s", kind, name, profile, type, profile);
		assertEquals(expected, path1);
	}

	@Test
	void testExistsResource1() {
		String path = "mail/avisoApertura.txt";
		assertTrue(ResourceUtils.existsResource(path));
		path = "mail/Alta.txt";
		assertFalse(ResourceUtils.existsResource(path));
		path = "";
		assertFalse(ResourceUtils.existsResource(path));
		path = null;
		assertFalse(ResourceUtils.existsResource(path));
	}

	@Test
	void testFirstExistingResource1() {
		String path1 = "mail/avisoApertura.txt";
		assertEquals(path1, ResourceUtils.firstExistingResource(path1));
		path1 = "mail/Alta.txt";
		assertNull(ResourceUtils.firstExistingResource(path1));
		path1 = "";
		assertNull(ResourceUtils.firstExistingResource(path1));
		path1 = null;
		assertNull(ResourceUtils.firstExistingResource(path1));
		final String path0 = "mail/avisoApertura-dev.txt";
		final String path2 = "erorres.properties";
		assertEquals(path1, ResourceUtils.firstExistingResource(path0, path1, path2));
	}

}
