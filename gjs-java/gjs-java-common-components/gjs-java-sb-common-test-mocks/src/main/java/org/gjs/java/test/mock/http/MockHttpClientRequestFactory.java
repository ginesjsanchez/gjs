package org.gjs.java.test.mock.http;

import java.io.IOException;
import java.net.URI;

import org.springframework.http.HttpMethod;
import org.springframework.http.client.ClientHttpRequest;
import org.springframework.http.client.ClientHttpRequestFactory;

/**
 * The Class MockHttpClientRequest.
 *
 * Clase de datos de la librería Gjs
 *
 * Mock de un HttpClientRequestFactory.
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
public class MockHttpClientRequestFactory implements ClientHttpRequestFactory {

    /* (non-Javadoc)
     *
     * @see org.springframework.http.client.ClientHttpRequestFactory#createRequest(java.net.URI,
     * org.springframework.http.HttpMethod) */

    @Override
    public ClientHttpRequest createRequest(URI uri, HttpMethod httpMethod) throws IOException {
        return new MockHttpClientRequest(uri, httpMethod);
    }

}
