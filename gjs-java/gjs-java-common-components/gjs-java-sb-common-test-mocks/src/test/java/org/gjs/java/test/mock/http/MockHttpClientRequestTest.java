package org.gjs.java.test.mock.http;

import static org.junit.jupiter.api.Assertions.assertEquals;
import static org.junit.jupiter.api.Assertions.assertNotNull;
import static org.junit.jupiter.api.Assertions.assertNull;
import static org.junit.jupiter.api.Assertions.fail;

import java.io.IOException;
import java.net.URI;

import org.apache.commons.lang3.exception.ExceptionUtils;
import org.gjs.java.test.BaseUnitTest;
import org.junit.jupiter.api.Test;
import org.springframework.http.HttpMethod;
import org.springframework.http.client.ClientHttpResponse;

public class MockHttpClientRequestTest extends BaseUnitTest<MockHttpClientRequest> {

	@Test
	void testMockClientRequest1() {
		try {
			final URI uri = new URI("http://semilla.interior.es/sample-uri");
			final HttpMethod httpMethod = HttpMethod.GET;

			final MockHttpClientRequest mock = new MockHttpClientRequest(uri, httpMethod);
			assertNotNull(mock.getURI());
			assertNotNull(mock.getMethod());
			assertNotNull(mock.getHeaders());
			assertNotNull(mock.getBody());
			assertEquals(uri, mock.getURI());
			assertEquals(httpMethod, mock.getMethod());
			final ClientHttpResponse httpResponse = mock.execute();
			assertNotNull(httpResponse);

		} catch (final Exception e) {
			logger.error(ExceptionUtils.getStackTrace(e));
			fail("Excepcion inesperada");
		}
	}

	@Test
	void testMockClientRequest2() throws IOException {
		// try {
		final MockHttpClientRequest mock = new MockHttpClientRequest();
		assertNull(mock.getURI());
		assertNull(mock.getMethod());
		assertNull(mock.getHeaders());
		assertNull(mock.getBody());

		// } catch (final Exception e) {
		// logger.error(ExceptionUtils.getStackTrace(e));
		// fail("Excepcion inesperada");
		// }
	}

}
