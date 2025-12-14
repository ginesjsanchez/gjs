package org.gjs.java.common.type;

import java.io.FileInputStream;
import java.io.IOException;
import java.nio.charset.StandardCharsets;

import org.apache.commons.io.IOUtils;
import org.springframework.core.io.ClassPathResource;

/**
 * The Class DocumentTemplate.
 *
 * Clase de datos de la librería Gjs
 *
 * Produce un texto de salida a partir de una plantilla por sustitución de parámetros. En la plantilla las variables
 * deben indicarse mediante el formato ${variable}.
 *
 * --------------------------------------------------------------------------------------------------------------------
 * Gj Software
 *
 * 2025 correspondiente licencia en los activos de la
 * SES. Los programas informáticos propiedad de la SES están protegidos por la propiedad intelectual, y por tanto está
 * estrictamente prohibida su reproducción, modificación, cesión o comunicación sin la debida autorización. Queda
 * estrictamente prohibido el uso, reproducción, cesión, transformación o comunicación pública de cualquier otro tipo de
 * obra o invención protegida por la propiedad intelectual sin la debida autorización.
 *
 * Seguridad Ministerio del Interior
 * Gobierno de España
 * --------------------------------------------------------------------------------------------------------------------
 *
 * @author Gjs
 * @version 4.0.0
 * @since 3.0.0
 *
 */
public class DocumentTemplate extends StringTemplate {

    /**
     * Instantiates a new document template.
     *
     * @param templatePath
     *            the template path
     * @throws IOException
     *             Signals that an I/O exception has occurred.
     */
    public DocumentTemplate(String templatePath) throws IOException {
        super(IOUtils.toString(new FileInputStream(new ClassPathResource(templatePath).getFile()),
                StandardCharsets.UTF_8.name()));
    }

    /**
     * Generate document.
     *
     * Por compatibilidad con la versión anterior.
     *
     * @return the string
     */
    public String generateDocument() {
        return generate();
    }
}
