package org.gjs.java.common;

import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.time.LocalDate;
import java.time.LocalDateTime;
import java.time.ZoneId;
import java.util.Calendar;
import java.util.Date;
import java.util.GregorianCalendar;
import java.util.Locale;
import java.util.Objects;
import java.util.concurrent.TimeUnit;

/**
 * The Class DateUtils.
 *
 * Clase de utilidades generales de la librería Semilla
 *
 * Incluye algunas funciones sobre fechas que se utilizan en las rutinas de test automatizados de Semilla.
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
public final class DateUtils {

    /**
     * Clase no instanciable.
     */
    private DateUtils() {
        throw new IllegalStateException("Utility class");
    }

    /**
     * Start of day.
     *
     * @param date
     *            the date
     * @return the date
     */
    public static Date startOfDay(Date date) {
        Date res = null;
        if (Objects.nonNull(date)) {
            final SimpleDateFormat simpleDateFormatBegin = new SimpleDateFormat("yyyy-MM-dd 00:00:00",
                    Locale.getDefault());
            final SimpleDateFormat simpleDateFormatNormal = new SimpleDateFormat("yyyy-MM-dd HH:mm:ss",
                    Locale.getDefault());
            try {
                res = simpleDateFormatNormal.parse(simpleDateFormatBegin.format(date));
            } catch (final ParseException e) {
                // Es imposible que se produzca un Parse exception puesto que el parametro es una fecha válida
            }
        }
        return res;
    }

    /**
     * End of day.
     *
     * @param date
     *            the date
     * @return the date
     */
    public static Date endOfDay(Date date) {
        Date res = null;
        if (Objects.nonNull(date)) {
            final SimpleDateFormat simpleDateFormatEnd = new SimpleDateFormat("yyyy-MM-dd 23:59:59",
                    Locale.getDefault());
            final SimpleDateFormat simpleDateFormatNormal = new SimpleDateFormat("yyyy-MM-dd HH:mm:ss",
                    Locale.getDefault());
            try {
                res = simpleDateFormatNormal.parse(simpleDateFormatEnd.format(date));
            } catch (final ParseException e) {
                // Es imposible que se produzca un Parse exception puesto que el parametro es una fecha válida
            }
        }
        return res;
    }

    /**
     * Today.
     *
     * @return the date
     */
    public static Date today() {
        final Date in = new Date();
        final LocalDateTime ldt = LocalDateTime.ofInstant(in.toInstant(), ZoneId.systemDefault());
        return Date.from(ldt.atZone(ZoneId.systemDefault()).toInstant());
    }

    /**
     * Yesterday.
     *
     * @return the date
     */
    public static Date yesterday() {
        return relativeToToday(-1);
    }

    /**
     * Tomorrow.
     *
     * @return the date
     */
    public static Date tomorrow() {
        return relativeToToday(1);
    }

    /**
     * Relative to today.
     *
     * @param days
     *            the days
     * @return the date
     */
    public static Date relativeToToday(int days) {
        final Calendar cal = Calendar.getInstance();
        cal.add(Calendar.DATE, days);
        return cal.getTime();
    }

    /**
     * After.
     *
     * @param date1
     *            the date 1
     * @param date2
     *            the date 2
     * @return true, if successful
     */
    public static boolean after(Date date1, Date date2) {
        boolean res = false;
        if (Objects.isNull(date2)) {
            res = false;
        } else if (Objects.isNull(date1)) {
            res = true;
        } else {
            res = ConditionUtils.allAreTrue(date1.after(date2),
                    !org.apache.commons.lang3.time.DateUtils.isSameDay(date1, date2));
        }
        return res;
    }

    /**
     * Before.
     *
     * @param date1
     *            the date 1
     * @param date2
     *            the date 2
     * @return true, if successful
     */
    public static boolean before(Date date1, Date date2) {
        boolean res = false;
        if (Objects.isNull(date2)) {
            res = Objects.nonNull(date1);
        } else if (Objects.isNull(date1)) {
            res = false;
        } else {
            res = ConditionUtils.allAreTrue(date1.before(date2),
                    !org.apache.commons.lang3.time.DateUtils.isSameDay(date1, date2));
        }
        return res;
    }

    /**
     * Before or equal.
     *
     * @param date1
     *            the date 1
     * @param date2
     *            the date 2
     * @return true, if successful
     */
    public static boolean beforeOrEqual(Date date1, Date date2) {
        boolean res = false;
        if (Objects.isNull(date1)) {
            res = (Objects.isNull(date2));
        } else if (Objects.isNull(date2)) {
            res = true;
        } else {
            res = ConditionUtils.oneIsTrue(date1.before(date2),
                    org.apache.commons.lang3.time.DateUtils.isSameDay(date1, date2));
        }
        return res;
    }

    /**
     * Before or equal.
     *
     * @param date1
     *            the date 1
     * @param date2
     *            the date 2
     * @return true, if successful
     */
    public static boolean beforeOrEqual(LocalDate date1, LocalDate date2) {
        boolean res = false;
        if (Objects.isNull(date1)) {
            res = (Objects.isNull(date2));
        } else if (Objects.isNull(date2)) {
            res = true;
        } else {
            res = ConditionUtils.oneIsTrue(date1.isBefore(date2), date1.isEqual(date2));
        }
        return res;
    }

    /**
     * After or equal.
     *
     * @param date1
     *            the date 1
     * @param date2
     *            the date 2
     * @return true, if successful
     */
    public static boolean afterOrEqual(Date date1, Date date2) {
        boolean res = false;
        if (Objects.isNull(date1)) {
            res = true;
        } else if (Objects.isNull(date2)) {
            res = (Objects.isNull(date1));
        } else {
            res = ConditionUtils.oneIsTrue(date1.after(date2),
                    org.apache.commons.lang3.time.DateUtils.isSameDay(date1, date2));
        }
        return res;
    }

    /**
     * After or equal.
     *
     * @param date1
     *            the date 1
     * @param date2
     *            the date 2
     * @return true, if successful
     */
    public static boolean afterOrEqual(LocalDate date1, LocalDate date2) {
        boolean res = false;
        if (Objects.isNull(date1)) {
            res = true;
        } else if (Objects.isNull(date2)) {
            res = (Objects.isNull(date1));
        } else {
            res = ConditionUtils.oneIsTrue(date1.isAfter(date2), date1.isEqual(date2));
        }
        return res;
    }

    /**
     * Days between.
     *
     * Hay que tener el cuenta el offset por cambio de hora verano/invierno
     *
     * @param date1
     *            the date 1
     * @param date2
     *            the date 2
     * @return the long
     */
    public static long daysBetween(Date date1, Date date2) {
        long days = 0;
        if (ConditionUtils.allAreTrue(Objects.nonNull(date1), Objects.nonNull(date2))) {
            final GregorianCalendar cal1 = new GregorianCalendar();
            cal1.setTime(date1);
            final GregorianCalendar cal2 = new GregorianCalendar();
            cal2.setTime(date2);
            final long diffInMillis = (cal2.getTimeInMillis() + cal2.get(Calendar.DST_OFFSET))
                    - (cal1.getTimeInMillis() + cal1.get(Calendar.DST_OFFSET));
            days = TimeUnit.DAYS.convert(diffInMillis, TimeUnit.MILLISECONDS);
        } else if (!ConditionUtils.allAreTrue(Objects.isNull(date1), Objects.isNull(date2))) {
            if (Objects.isNull(date1)) {
                days = Long.MAX_VALUE;
            } else {
                days = Long.MIN_VALUE;
            }
        }
        return days;
    }

    /**
     * Checks if is valid date range.
     *
     * @param startDate
     *            the start date
     * @param endDate
     *            the end date
     * @return true, if is valid date range
     */
    public static boolean isValidDateRange(Date startDate, Date endDate) {
        final Date today = DateUtils.startOfDay(DateUtils.today());
        if (Objects.isNull(startDate)) {
            return Objects.isNull(endDate) || today.before(endDate);
        }
        return DateUtils.afterOrEqual(today, DateUtils.startOfDay(startDate))
                && (Objects.isNull(endDate) || beforeOrEqual(today, endDate));

    }

    /**
     * Checks if is valid date range.
     *
     * @param startDate
     *            the start date
     * @param endDate
     *            the end date
     * @return true, if is valid date range
     */
    public static boolean isValidDateRange(LocalDate startDate, LocalDate endDate) {
        final LocalDate today = LocalDate.now();
        if (Objects.isNull(startDate)) {
            return Objects.isNull(endDate) || beforeOrEqual(today, endDate);
        }
        return DateUtils.afterOrEqual(today, startDate) && (Objects.isNull(endDate) || beforeOrEqual(today, endDate));

    }

    /**
     * Checks if is valid end date.
     *
     * @param endDate
     *            the end date
     * @return true, if is valid end date
     */
    public static boolean isValidEndDate(Date endDate) {
        final Date today = DateUtils.startOfDay(DateUtils.today());
        return Objects.isNull(endDate) || beforeOrEqual(today, endDate);
    }

    /**
     * Checks if is valid end date.
     *
     * @param endDate
     *            the end date
     * @return true, if is valid end date
     */
    public static boolean isValidEndDate(LocalDate endDate) {
        final LocalDate today = LocalDate.now();
        return Objects.isNull(endDate) || today.isBefore(endDate) || today.isEqual(endDate);
    }

}
