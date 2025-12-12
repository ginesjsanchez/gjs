package org.gjs.java.types;

import org.springframework.lang.Nullable;
import org.springframework.util.ObjectUtils;

/**
 * The Class Pair.
 *
 * Clase de datos de la librería Semilla
 *
 * Clase útil para contener luna pareja de dos datos de cualquier clase.
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
 * @param <S>
 *            la clase primera
 * @param <T>
 *            la clase segunda
 *
 * @author Semilla
 * @version 4.0.0
 * @since 3.0.0
 *
 */
public class Pair<S, T> {

    /** The first. */
    private S first;

    /** The second. */
    private T second;

    /**
     * Instantiates a new pair.
     *
     * @param first
     *            the first
     * @param second
     *            the second
     */
    public Pair(S first, T second) {
        this.first = first;
        this.second = second;
    }

    /**
     * Creates a new {@link Pair} for the given elements.
     *
     * @param <S>
     *            the generic type
     * @param <T>
     *            the generic type
     * @param first
     *            must not be {@literal null}.
     * @param second
     *            must not be {@literal null}.
     * @return the pair
     */
    public static <S, T> Pair<S, T> of(S first, T second) {
        return new Pair<>(first, second);
    }

    /**
     * Returns the first element of the {@link Pair}.
     *
     * @return the first
     */
    public S getFirst() {
        return first;
    }

    /**
     * Returns the second element of the {@link Pair}.
     *
     * @return the second
     */
    public T getSecond() {
        return second;
    }

    /**
     * Sets the first.
     *
     * @param value
     *            the new first
     */
    public void setFirst(S value) {
        first = value;
    }

    /**
     * Sets the second.
     *
     * @param value
     *            the new second
     */
    public void setSecond(T value) {
        second = value;
    }

    /* (non-Javadoc)
     *
     * @see java.lang.Object#equals(java.lang.Object) */
    @Override
    public boolean equals(@Nullable Object o) {
        boolean res = false;
        if (this == o) {
            res = true;
        } else if (o instanceof Pair) {
            final Pair<?, ?> pair = (Pair<?, ?>) o;
            if (ObjectUtils.nullSafeEquals(first, pair.first)) {

                res = ObjectUtils.nullSafeEquals(second, pair.second);
            }
        }
        return res;
    }

    /* (non-Javadoc)
     *
     * @see java.lang.Object#hashCode() */
    @Override
    public int hashCode() {
        int result = ObjectUtils.nullSafeHashCode(first);
        result = 31 * result + ObjectUtils.nullSafeHashCode(second);
        return result;
    }

    /* (non-Javadoc)
     *
     * @see java.lang.Object#toString() */
    @Override
    public String toString() {
        return String.format("%s->%s", this.first, this.second);
    }

}
