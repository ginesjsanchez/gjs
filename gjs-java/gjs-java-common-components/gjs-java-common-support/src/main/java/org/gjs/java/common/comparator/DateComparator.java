package org.gjs.java.common.comparator;

import java.util.Comparator;
import java.util.Date;
import java.util.Objects;

import org.gjs.java.common.util.ConditionUtils;

/**
 * The Class DateComparator.
 *
 * Clase de datos de la librería Gjs
 *
 * Comparador para ordenar fechas de forma ascendente.
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
public class DateComparator implements Comparator<Date> {

    /* (non-Javadoc)
     *
     * @see java.util.Comparator#compare(java.lang.Object, java.lang.Object) */

    @Override
    public int compare(Date o1, Date o2) {
        int res = 1;
        if (ConditionUtils.allAreTrue(Objects.isNull(o1), Objects.isNull(o2))) {
            res = 0;
        } else if (Objects.isNull(o2)) {
            res = -1;
        } else if (Objects.isNull(o1)) {
            res = 1;
        } else {
            res = o1.compareTo(o2);
        }
        return res;
    }

}
