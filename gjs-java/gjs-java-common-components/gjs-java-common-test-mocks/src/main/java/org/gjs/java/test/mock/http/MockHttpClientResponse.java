package org.gjs.java.test.mock.http;

import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;

import org.springframework.http.HttpHeaders;
import org.springframework.http.HttpStatus;
import org.springframework.http.client.ClientHttpResponse;

/**
 * The Class MockHttpClientResponse.
 *
 * Clase de datos de la librería Gjs
 *
 * Mock de un HttpClientResponse.
 *
 * --------------------------------------------------------------------------------------------------------------------
 *
 *
 * correspondiente licencia en los activos de la
 * SES. Los programas informáticos propiedad de la SES están protegidos por la propiedad intelectual, y por tanto está
 * estrictamente prohibida su reproducción, modificación, cesión o comunicación sin la debida autorización. Queda
 * estrictamente prohibido el uso, reproducción, cesión, transformación o comunicación pública de cualquier otro tipo de
 * obra o invención protegida por la propiedad intelectual sin la debida autorización.
 *
 *  Seguridad Ministerio del Interior
 * Gobierno de España
 * --------------------------------------------------------------------------------------------------------------------
 *
 * @author Gjs
 * @version 1.0.0
 * @since 1.0.0
 *
 */
public class MockHttpClientResponse implements ClientHttpResponse {

    /** The headers. */
    private final HttpHeaders headers;

    /** The status. */
    private final HttpStatus status;

    /** The body. */
    private final InputStream body;

    /**
     * Instantiates a new mock http client response.
     */
    public MockHttpClientResponse() {
        this(HttpStatus.OK);
    }

    /**
     * Instantiates a new mock http client response.
     *
     * @param httpStatus
     *            the http status
     */
    public MockHttpClientResponse(HttpStatus httpStatus) {
        this.status = httpStatus;
        headers = new HttpHeaders();
        headers.set("Content-type", "application/json");
        body = new ByteArrayInputStream("{}".getBytes());
    }

    /* (non-Javadoc)
     *
     * @see org.springframework.http.HttpInputMessage#getBody() */

    @Override
    public InputStream getBody() throws IOException {
        return body;
    }

    /* (non-Javadoc)
     *
     * @see org.springframework.http.HttpMessage#getHeaders() */

    @Override
    public HttpHeaders getHeaders() {
        return headers;
    }

    /* (non-Javadoc)
     *
     * @see org.springframework.http.client.ClientHttpResponse#getStatusCode() */

    @Override
    public HttpStatus getStatusCode() throws IOException {
        return status;
    }

    /* (non-Javadoc)
     *
     * @see org.springframework.http.client.ClientHttpResponse#getRawStatusCode() */

    @Override
    public int getRawStatusCode() throws IOException {
        return status.value();
    }

    /* (non-Javadoc)
     *
     * @see org.springframework.http.client.ClientHttpResponse#getStatusText() */

    @Override
    public String getStatusText() throws IOException {
        return status.getReasonPhrase();
    }

    /* (non-Javadoc)
     *
     * @see org.springframework.http.client.ClientHttpResponse#close() */

    @Override
    public void close() {
        // No hace nada
    }

}
