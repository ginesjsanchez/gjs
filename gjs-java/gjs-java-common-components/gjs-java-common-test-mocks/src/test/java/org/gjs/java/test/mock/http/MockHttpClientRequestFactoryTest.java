package org.gjs.java.test.mock.http;

import static org.junit.jupiter.api.Assertions.assertEquals;
import static org.junit.jupiter.api.Assertions.assertNotNull;
import static org.junit.jupiter.api.Assertions.fail;

import java.net.URI;

import org.apache.commons.lang3.exception.ExceptionUtils;
import org.gjs.java.test.BaseUnitTest;
import org.junit.jupiter.api.Test;
import org.springframework.http.HttpMethod;
import org.springframework.http.client.ClientHttpRequest;

public class MockHttpClientRequestFactoryTest extends BaseUnitTest<MockHttpClientRequestFactory> {

	@Test
	void testMockClientRequestFactory1() {
		try {
			final URI uri = new URI("http://semilla.interior.es/sample-uri");
			final HttpMethod httpMethod = HttpMethod.GET;

			final MockHttpClientRequestFactory mock = new MockHttpClientRequestFactory();
			final ClientHttpRequest httpRequest = mock.createRequest(uri, httpMethod);
			assertNotNull(httpRequest);
			assertNotNull(httpRequest.getURI());
			assertNotNull(httpRequest.getMethod());
			assertNotNull(httpRequest.getHeaders());
			assertNotNull(httpRequest.getBody());
			assertEquals(uri, httpRequest.getURI());
			assertEquals(httpMethod, httpRequest.getMethod());

		} catch (final Exception e) {
			logger.error(ExceptionUtils.getStackTrace(e));
			fail("Excepcion inesperada");
		}
	}

}
