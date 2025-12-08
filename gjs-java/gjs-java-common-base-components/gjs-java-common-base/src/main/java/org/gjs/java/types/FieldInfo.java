package org.gjs.java.types;

import java.lang.reflect.Field;
import java.lang.reflect.Type;
import java.util.Objects;

import lombok.Getter;
import lombok.Setter;

/**
 * The Class FiledInfo.
 *
 * Clase de datos de la librería Gjs
 *
 * Clase utilizada en nuestras utilidades de Reflection y que nos sirve para manejar los atributos de forma general,
 * tratando por igual los normales y los que son de una clase parametrizada.
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
@Getter
@Setter
public class FieldInfo {

    /** The field. */
    private Field field;

    /** The clazz. */
    private Class<?> clazz;

    /** The generic class. */
    private Type genericClass;

    /**
     * Instantiates a new field info.
     */
    public FieldInfo() {
    }

    /**
     * Instantiates a new field info.
     *
     * @param field
     *            the field
     * @param clazz
     *            the clazz
     */
    public FieldInfo(Field field, Class<?> clazz) {
        this.field = field;
        this.clazz = clazz;
    }

    /**
     * Instantiates a new field info.
     *
     * @param field
     *            the field
     * @param clazz
     *            the clazz
     * @param genericClass
     *            the generic class
     */
    public FieldInfo(Field field, Class<?> clazz, Type genericClass) {
        this.field = field;
        this.clazz = clazz;
        this.genericClass = genericClass;
    }

    /**
     * Checks if is from generic class.
     *
     * @return true, if is from generic class
     */
    public boolean isFromGenericClass() {
        return Objects.nonNull(genericClass);
    }
}
