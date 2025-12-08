package org.gjs.java.test.mock.http;

import static org.junit.jupiter.api.Assertions.assertEquals;
import static org.junit.jupiter.api.Assertions.assertNotNull;
import static org.junit.jupiter.api.Assertions.fail;

import org.apache.commons.lang3.exception.ExceptionUtils;
import org.gjs.java.test.BaseUnitTest;
import org.junit.jupiter.api.Test;
import org.springframework.http.HttpStatus;

public class MockHttpClientResponseTest extends BaseUnitTest<MockHttpClientResponse> {

	@Test
	void testMockClientResponse1() {
		try {
			final HttpStatus httpStatus = HttpStatus.OK;
			final MockHttpClientResponse mock = new MockHttpClientResponse(httpStatus);
			assertNotNull(mock.getStatusCode());
			assertNotNull(mock.getStatusText());
			assertNotNull(mock.getHeaders());
			assertNotNull(mock.getBody());
			assertEquals(httpStatus, mock.getStatusCode());
			assertEquals(httpStatus.value(), mock.getRawStatusCode());
			assertEquals(httpStatus.getReasonPhrase(), mock.getStatusText());
			mock.close();

		} catch (final Exception e) {
			logger.error(ExceptionUtils.getStackTrace(e));
			fail("Excepcion inesperada");
		}
	}

	@Test
	void testMockClientResponse2() {
		try {
			final HttpStatus httpStatus = HttpStatus.OK;
			final MockHttpClientResponse mock = new MockHttpClientResponse();
			assertNotNull(mock.getStatusCode());
			assertNotNull(mock.getStatusText());
			assertNotNull(mock.getHeaders());
			assertNotNull(mock.getBody());
			assertEquals(httpStatus, mock.getStatusCode());
			assertEquals(httpStatus.value(), mock.getRawStatusCode());
			assertEquals(httpStatus.getReasonPhrase(), mock.getStatusText());
			mock.close();

		} catch (final Exception e) {
			logger.error(ExceptionUtils.getStackTrace(e));
			fail("Excepcion inesperada");
		}
	}

}
