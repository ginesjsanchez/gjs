package org.gjs.java.types;

import java.util.Map;
import java.util.concurrent.ConcurrentHashMap;

import org.apache.commons.lang3.StringUtils;

import org.gjs.java.common.ConditionUtils;

/**
 * The Class Translator.
 *
 * Clase de datos de la librería Semilla
 *
 * Clase que mantiene una asociación de parejas de cadenas.Está pensada para se utilizada como ayuda en el tratamiento
 * multi-idioma de literales de uso dinámico que sean utilizados como parámetros en la construcción de cadenas o
 * mensajes: nombres de atributo, por ejemplo.
 *
 * PENDIENTE: Constructor qe cargue un fichero
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
public class Translator {

    /** The map translations. */
    private final Map<String, String> mapTranslations = new ConcurrentHashMap<>();

    /**
     * Instantiates a new translator.
     */
    public Translator() {
        // No hace nada
    }

    /**
     * Adds the.
     *
     * @param original
     *            the original
     * @param translation
     *            the translation
     */
    public void add(String original, String translation) {
        if (!ConditionUtils.oneIsTrue(StringUtils.isAllBlank(original), StringUtils.isAllBlank(translation))) {
            mapTranslations.put(original, translation);
        }
    }

    /**
     * Translate.
     *
     * @param original
     *            the original
     * @return the string
     */
    public String translate(String original) {
        String res = null;
        if (!StringUtils.isAllBlank(original)) {
            res = mapTranslations.get(original);
        }
        return res;
    }

    /**
     * Clear.
     */
    public void clear() {
        mapTranslations.clear();
    }
}
