package org.gjs.java.data;

/**
 * The Interface DataExtractor.
 *
 * Interfaz de la librería Semilla
 *
 * Interfaz que debe implementar los extractores de datos singulares de una clase de objetos concreta para integrarse en
 * el sistema automatizado de importación y exportación de datos de Semilla.
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
 *            la clase de datos del extractor
 *
 * @author Semilla
 * @version 4.0.0
 * @since 3.0.0
 *
 */
public interface DataExtractor<T> {

    /**
     * Columns.
     *
     * @return the int
     */
    int columns();

    /**
     * Gets the column name.
     *
     * @param column
     *            the column
     * @return the column name
     */
    String getColumnName(int column);

    /**
     * Gets the column value.
     *
     * @param obj
     *            the obj
     * @param column
     *            the column
     * @return the column value
     */
    String getColumnValue(T obj, int column);

    /**
     * Gets the column value.
     *
     * @param obj
     *            the obj
     * @param columnName
     *            the column name
     * @return the column value
     */
    String getColumnValue(T obj, String columnName);

}
