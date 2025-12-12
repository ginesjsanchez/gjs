package org.gjs.java.types;

import java.util.Map;
import java.util.Map.Entry;
import java.util.Set;
import java.util.concurrent.ConcurrentHashMap;

import org.apache.commons.lang3.StringUtils;

/**
 * The Class StringTemplate.
 *
 * Clase de datos de la librería Semilla
 *
 * Produce un texto de salida a partir de una plantilla por sustitución de parámetros. En la plantilla las variables
 * deben indicarse mediante el formato ${variable}.
 *
 * --------------------------------------------------------------------------------------------------------------------
 * Este software es propiedad del Ministerio del Interior CETSE - 2025
 *
 * Queda estrictamente prohibido el uso de programas informáticos sin la correspondiente licencia en los activos de la
 * SES. Los programas informáticos propiedad de la SES están protegidos por la propiedad intelectual, y por tanto está
 * estrictamente prohibida su reproducción, modificación, cesión o comunicación sin la debida autorización. Queda
 * estrictamente prohibido el uso, reproducción, cesión, transformación o comunicación pública de cualquier otro tipo de
 * obra o invención protegida por la propiedad intelectual sin la debida autorización.
 *
 * Subdirección General de Sistemas de la Información y Comunicaciones para la Seguridad Ministerio del Interior
 * Gobierno de España
 * --------------------------------------------------------------------------------------------------------------------
 *
 * @author Semilla
 * @version 4.0.0
 * @since 3.0.0
 *
 */
public class StringTemplate {

    /** The template. */
    private final String template;

    /** The fields. */
    private final Map<String, String> fields = new ConcurrentHashMap<>();

    /**
     * Instantiates a new string template.
     *
     * @param templateString
     *            the template string
     */
    public StringTemplate(String templateString) {
        template = templateString;
        if (!StringUtils.isAllBlank(template)) {
            boolean end = false;
            int pos = 0;
            while (!end) {

                final int iniPos = template.indexOf("${", pos);
                if (iniPos >= 0) {
                    final int endPos = template.indexOf('}', iniPos);
                    if (endPos > iniPos) {
                        final String field = template.substring(iniPos + 2, endPos).trim();
                        fields.put(field, "");
                        pos = endPos + 1;
                    } else {
                        end = true;
                    }
                } else {
                    end = true;
                }
            }
        }
    }

    /**
     * Gets the fields.
     *
     * @return the fields
     */
    public Set<String> getFields() {
        return fields.keySet();
    }

    /**
     * Sets the field.
     *
     * @param field
     *            the field
     * @param value
     *            the value
     */
    public void setField(String field, String value) {
        if (fields.containsKey(field)) {
            fields.put(field, value);
        }
    }

    /**
     * Generate.
     *
     * @return the string
     */
    public String generate() {
        String document = template;
        for (final Entry<String, String> entry : fields.entrySet()) {
            final String field = entry.getKey();
            document = document.replace(String.format("${%s}", field), entry.getValue());
            document = document.replace(String.format("&{%s}", field), entry.getValue());
        }
        return document;
    }

    /**
     * Checks if is ok.
     *
     * @return true, if is ok
     */
    public boolean isOk() {
        return (!StringUtils.isAllBlank(template));
    }
}
