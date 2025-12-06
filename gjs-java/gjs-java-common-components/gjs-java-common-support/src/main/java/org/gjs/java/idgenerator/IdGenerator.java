package org.gjs.java.idgenerator;

/**
 * The Interface IdGenerator.
 *
 * Interfaz de la librería Semilla
 *
 * Interfaz que debe implementar un generador de identificadores para las clases mock de gestión de datos.
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
 * @param <T>
 *            la clase del identificador a generar
 *
 * @author Semilla
 * @version 4.0.0
 * @since 3.0.0
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
