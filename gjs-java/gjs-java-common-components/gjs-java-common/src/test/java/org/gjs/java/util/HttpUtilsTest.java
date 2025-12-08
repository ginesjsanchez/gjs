package org.gjs.java.util;

import static org.junit.jupiter.api.Assertions.assertEquals;
import static org.junit.jupiter.api.Assertions.assertNotNull;
import static org.junit.jupiter.api.Assertions.assertNull;

import org.gjs.java.test.BaseClassTest;
import org.junit.jupiter.api.Test;

class HttpUtilsTest extends BaseClassTest<HttpUtils> {

	@Test
	void testFormatEndpoint() {
		String endpoint = null;
		String projectName = null;
		String formatted = HttpUtils.formatEndpoint(endpoint, projectName);
		assertNull(formatted);
		endpoint = "";
		formatted = HttpUtils.formatEndpoint(endpoint, projectName);
		assertNotNull(formatted);
		assertEquals("/", formatted);
		endpoint = "/rest/v1/aplicacion/id";
		formatted = HttpUtils.formatEndpoint(endpoint, projectName);
		assertNotNull(formatted);
		assertEquals(endpoint, formatted);
		endpoint = "rest/v1/aplicacion/id";
		formatted = HttpUtils.formatEndpoint(endpoint, projectName);
		assertNotNull(formatted);
		assertEquals(String.format("/%s", endpoint), formatted);
		endpoint = "/rest/v1/aplicacion/id";
		projectName = "";
		formatted = HttpUtils.formatEndpoint(endpoint, projectName);
		assertNotNull(formatted);
		assertEquals(endpoint, formatted);
		projectName = "semilla-sb-back";
		formatted = HttpUtils.formatEndpoint(endpoint, projectName);
		assertNotNull(formatted);
		assertEquals(String.format("/%s%s", projectName, endpoint), formatted);
	}

}
