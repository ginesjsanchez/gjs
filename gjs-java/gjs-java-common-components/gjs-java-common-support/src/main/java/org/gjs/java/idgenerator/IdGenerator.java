package org.gjs.java.idgenerator;

/**
 * The Interface IdGenerator.
 *
 * Interfaz de la librería Gjs
 *
 * Interfaz que debe implementar un generador de identificadores para las clases mock de gestión de datos.
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
 * @param <T>
 *            la clase del identificador a generar
 *
 * @author Gjs
 * @version 1.0.0
 * @since 1.0.0
 *
 */
public interface IdGenerator<T> {

    /**
     * Generate.
     *
     * @return the t
     */
    T generate();
}
