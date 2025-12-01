package org.gjs.java.common;

import java.util.Arrays;
import java.util.Set;
import java.util.TreeSet;

/**
 * The Class ReflectionUtils.
 *
 * Clase de utilidades generales de la librería Semilla
 *
 * Rutinas de ayuda para manejarse con clases que tengan atributos que sean colecciones de objetos en las rutinas de
 * automatización de test de Semilla.
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
public final class CollectionUtils {

    /** The Constant COLLECTIONS. */
    private static final String[] COLLECTIONS =
            { "java.util.Collection", "java.util.List", "java.util.Set", "java.util.Map" };

    /** The Constant COLLECTIONS_LIST. */
    private static final String[] COLLECTIONS_LIST =
            { "java.util.List", "java.util.ArrayList", "java.util.LinkedList", "java.util.Vector", "java.util.Stack" };

    /** The Constant COLLECTIONS_SET. */
    private static final String[] COLLECTIONS_SET = { "java.util.Set", "java.util.TreeSet", "java.util.HashSet",
            "java.util.EnumSet", "java.util.LinkedHashSet" };

    /** The Constant COLLECTIONS_MAP. */
    private static final String[] COLLECTIONS_MAP = { "java.util.Map", "java.util.TreeMap", "java.util.HashMap",
            "java.util.EnumMap", "java.util.LinkedHashMap" };

    /** The collections. */
    private static Set<String> collectionsAll;

    /** The collections set. */
    private static Set<String> collectionsSet;

    /** The collections list. */
    private static Set<String> collectionsList;

    /** The collections map. */
    private static Set<String> collectionsMap;

    static {
        collectionsAll = new TreeSet<>();
        collectionsSet = new TreeSet<>();
        collectionsList = new TreeSet<>();
        collectionsMap = new TreeSet<>();
        collectionsAll.addAll(Arrays.asList(COLLECTIONS));
        collectionsSet.addAll(Arrays.asList(COLLECTIONS_SET));
        collectionsList.addAll(Arrays.asList(COLLECTIONS_LIST));
        collectionsMap.addAll(Arrays.asList(COLLECTIONS_MAP));
        collectionsAll.addAll(collectionsSet);
        collectionsAll.addAll(collectionsList);
        collectionsAll.addAll(collectionsMap);
    }

    /**
     * Clase no instanciable.
     */
    private CollectionUtils() {
        throw new IllegalStateException("Utility class");
    }

    /**
     * Checks if is collection.
     *
     * @param clazz
     *            the clazz
     * @return true, if is collection
     */
    public static boolean isCollection(Class<?> clazz) {
        return isCollection(clazz.getCanonicalName());
    }

    /**
     * Checks if is collection.
     *
     * @param className
     *            the class name
     * @return true, if is collection
     */
    public static boolean isCollection(String className) {
        return collectionsAll.contains(className);
    }

    /**
     * Checks if is list.
     *
     * @param clazz
     *            the clazz
     * @return true, if is list
     */
    public static boolean isList(Class<?> clazz) {
        return isList(clazz.getCanonicalName());
    }

    /**
     * Checks if is list.
     *
     * @param className
     *            the class name
     * @return true, if is list
     */
    public static boolean isList(String className) {
        return collectionsList.contains(className);
    }

    /**
     * Checks if is sets the.
     *
     * @param clazz
     *            the clazz
     * @return true, if is sets the
     */
    public static boolean isSet(Class<?> clazz) {
        return isSet(clazz.getCanonicalName());
    }

    /**
     * Checks if is sets the.
     *
     * @param className
     *            the class name
     * @return true, if is sets the
     */
    public static boolean isSet(String className) {
        return collectionsSet.contains(className);
    }

    /**
     * Checks if is map.
     *
     * @param clazz
     *            the clazz
     * @return true, if is map
     */
    public static boolean isMap(Class<?> clazz) {
        return isMap(clazz.getCanonicalName());
    }

    /**
     * Checks if is map.
     *
     * @param className
     *            the class name
     * @return true, if is map
     */
    public static boolean isMap(String className) {
        return collectionsMap.contains(className);
    }

}
