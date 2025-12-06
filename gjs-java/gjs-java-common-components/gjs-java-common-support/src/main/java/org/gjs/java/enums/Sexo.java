package org.gjs.java.enums;

import java.util.Arrays;
import java.util.Set;
import java.util.TreeSet;

/**
 * The Enum Sexo.
 *
 * Enumerado de la librería Semilla
 *
 * Tipos de sexo.
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
public enum Sexo {

    /** The varon. */
    VARON("hombre", "V", "masculino", "macho", "caballero", "señor", "señorito", "chico", "muchacho", "esposo",
            "marido"),
    /** The hembra. */
    HEMBRA("mujer", "H", "femina", "hembra", "dama", "señora", "señorita", "chica", "muchacha", "esposa");

    /** The nombre. */
    private String nombre;

    /** The acronimo. */
    private String acronimo;

    /** The sinonimos. */
    private Set<String> sinonimos;

    /**
     * Instantiates a new sexo.
     *
     * @param nombre
     *            the nombre
     * @param acronimo
     *            the acronimo
     */
    Sexo(String nombre, String acronimo) {
        this.nombre = nombre;
        this.acronimo = acronimo;
        sinonimos = new TreeSet<>();
        sinonimos.add(acronimo);
        sinonimos.add(nombre);
    }

    /**
     * Instantiates a new sexo.
     *
     * @param nombre
     *            the nombre
     * @param acronimo
     *            the acronimo
     * @param sinonimos
     *            the sinonimos
     */
    Sexo(String nombre, String acronimo, String... sinonimos) {
        this(nombre, acronimo);
        this.sinonimos.addAll(Arrays.asList(sinonimos));
    }

    /**
     * Gets the nombre.
     *
     * @return the nombre
     */
    public String getNombre() {
        return nombre;
    }

    /**
     * Gets the acronimo.
     *
     * @return the acronimo
     */
    public String getAcronimo() {
        return acronimo;
    }

    /* (non-Javadoc)
     *
     * @see java.lang.Enum#toString() */

    @Override
    public String toString() {
        return acronimo;
    }

    /**
     * Gets the.
     *
     * @param texto
     *            the texto
     * @return the sexo
     */
    public static Sexo get(String texto) {
        Sexo res = null;
        for (final Sexo type : Sexo.values()) {
            if (type.sinonimos.stream().anyMatch(s -> s.equalsIgnoreCase(texto))) {
                res = type;
                break;
            }
        }
        return res;
    }

}
