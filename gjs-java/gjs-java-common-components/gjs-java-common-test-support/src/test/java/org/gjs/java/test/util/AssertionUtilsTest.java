package org.gjs.java.test.util;

import static org.junit.jupiter.api.Assertions.fail;

import java.math.BigInteger;
import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.util.ArrayList;
import java.util.Date;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.Set;
import java.util.TreeSet;

import org.apache.commons.lang3.exception.ExceptionUtils;
import org.gjs.java.test.BaseUnitTest;
import org.junit.jupiter.api.Test;
import org.opentest4j.AssertionFailedError;

class AssertionUtilsTest extends BaseUnitTest<AssertionUtils> {

	private static final SimpleDateFormat DAY_DATE_FORMAT = new SimpleDateFormat("dd/MM/yyyy hh:mm:ss");

	@Test
	void testAssertEqualsNumeric1() {
		try {
			org.gjs.java.test.util.AssertionUtils.assertEqualsNumeric((float) 1.0, (float) 1.000000009);
		} catch (final AssertionFailedError ex) {
			fail("Assert Exception inesperada");
		}
	}

	@Test
	void testAssertEqualsNumeric2() {
		try {
			org.gjs.java.test.util.AssertionUtils.assertEqualsNumeric((float) 1.0, (float) 0.999999999);
		} catch (final AssertionFailedError ex) {
			fail("Assert Exception inesperada");
		}
	}

	@Test
	void testAssertEqualsNumeric3() {
		try {
			org.gjs.java.test.util.AssertionUtils.assertEqualsNumeric((float) 1.0, (float) 1.0000001);
			fail("Assert Exception esperada");
		} catch (final AssertionFailedError ex) {
		}
	}

	@Test
	void testAssertEqualsNumeric4() {
		try {
			org.gjs.java.test.util.AssertionUtils.assertEqualsNumeric(1.0, 0.9999999999999999);
			fail("Assert Exception esperada");
		} catch (final AssertionFailedError ex) {
		}
	}

	@Test
	void testAssertEqualsNumeric5() {
		try {
			org.gjs.java.test.util.AssertionUtils.assertEqualsNumeric(1.0, 1.00000000000000009);
		} catch (final AssertionFailedError ex) {
			fail("Assert Exception inesperada");
		}
	}

	@Test
	void testAssertEqualsNumeric6() {
		try {
			org.gjs.java.test.util.AssertionUtils.assertEqualsNumeric(1.0, 0.999999999999999999);
		} catch (final AssertionFailedError ex) {
			fail("Assert Exception inesperada");
		}
	}

	@Test
	void testAssertEqualsNumeric7() {
		try {
			org.gjs.java.test.util.AssertionUtils.assertEqualsNumeric(1.0, 1.000000000000000001);
			fail("Assert Exception esperada");
		} catch (final AssertionFailedError ex) {
		}
	}

	@Test
	void testAssertEqualsNumeric8() {
		try {
			org.gjs.java.test.util.AssertionUtils.assertEqualsNumeric(1.0, 0.999999999);
			fail("Assert Exception esperada");
		} catch (final AssertionFailedError ex) {
		}
	}

	@Test
	void testAssertEqualsInt1() {
		final BigInteger value1 = null;
		final BigInteger value2 = null;
		try {
			org.gjs.java.test.util.AssertionUtils.assertEqualsInt(value1, value2);
			fail("Assert Exception esperada");
		} catch (final AssertionFailedError ex) {
		}
	}

	@Test
	void testAssertEqualsInt2() {
		final BigInteger value1 = new BigInteger("25");
		final BigInteger value2 = null;
		try {
			org.gjs.java.test.util.AssertionUtils.assertEqualsInt(value1, value2);
			fail("Assert Exception inesperada");
		} catch (final AssertionFailedError ex) {
		}
	}

	@Test
	void testAssertEqualsInt3() {
		final BigInteger value1 = new BigInteger("25");
		final BigInteger value2 = new BigInteger("-101");
		try {
			org.gjs.java.test.util.AssertionUtils.assertEqualsInt(value1, value2);
			fail("Assert Exception esperada");
		} catch (final AssertionFailedError ex) {
		}
	}

	@Test
	void testAssertEqualsInt4() {
		final BigInteger value1 = new BigInteger("25");
		final BigInteger value2 = new BigInteger("25");
		try {
			org.gjs.java.test.util.AssertionUtils.assertEqualsInt(value1, value2);
		} catch (final AssertionFailedError ex) {
			fail("Assert Exception esperada");
		}
	}

	@Test
	void testAssertEqualsAsWarning1() {
		try {
			final String obj1 = "1";
			final String obj2 = "1";
			org.gjs.java.test.util.AssertionUtils.assertEqualsAsWarning(obj1, obj2, "La copia no es identica", logger);
			org.gjs.java.test.util.AssertionUtils.assertEqualsAsWarning("1", obj1, "La copia no es identica", null);
		} catch (final AssertionFailedError ex) {
			fail("Assert Exception inesperada");
		}
	}

	@Test
	void testAssertEqualsAsWarning2() {
		try {
			final String obj1 = "1";
			final String obj2 = "2";
			org.gjs.java.test.util.AssertionUtils.assertEqualsAsWarning(obj1, obj2, "La copia no es identica", logger);
		} catch (final AssertionFailedError ex) {
			fail("Assert Exception inesperada");
		}
	}

	@Test
	void testAssertCollectionEquals1() {
		try {
			final List<String> list1 = new ArrayList<>();
			final List<String> list2 = new ArrayList<>();
			org.gjs.java.test.util.AssertionUtils.assertCollectionEquals(list1, list2,
					"La coleccion vacia no es identica");
		} catch (final AssertionFailedError ex) {
			fail("Assert Exception inesperada");
		}
	}

	@Test
	void testAssertCollectionEquals2() {
		try {
			final List<String> list1 = new ArrayList<>();
			final List<String> list2 = new ArrayList<>();
			list1.add("valor1");
			list1.add("valor2");
			list2.add("valor2");
			org.gjs.java.test.util.AssertionUtils.assertCollectionEquals(list1, list2, "La coleccion no es identica");
			fail("Assert Exception esperada");
		} catch (final AssertionFailedError ex) {
		}
	}

	@Test
	void testAssertCollectionEquals3() {
		try {
			final List<String> list1 = new ArrayList<>();
			final List<String> list2 = new ArrayList<>();
			list1.add("valor1");
			list1.add("valor2");
			list2.add("valor2");
			list2.add("valor1");
			org.gjs.java.test.util.AssertionUtils.assertCollectionEquals(list1, list2, "La coleccion no es identica");
			fail("Assert Exception esperada");
		} catch (final AssertionFailedError ex) {
		}
	}

	@Test
	void testAssertCollectionEquals4() {
		try {
			final List<String> list1 = new ArrayList<>();
			final List<String> list2 = new ArrayList<>();
			list1.add("valor1");
			list1.add("valor2");
			list2.add("valor1");
			list2.add("valor2");
			org.gjs.java.test.util.AssertionUtils.assertCollectionEquals(list1, list2,
					"La coleccion vacia no es identica");
		} catch (final AssertionFailedError ex) {
			fail("Assert Exception inesperada");
		}
	}

	@Test
	void testAssertCollectionEquals5() {
		try {
			final Set<String> set1 = new TreeSet<>();
			final Set<String> set2 = new TreeSet<>();
			set1.add("valor1");
			set1.add("valor2");
			set2.add("valor2");
			set2.add("valor1");
			org.gjs.java.test.util.AssertionUtils.assertCollectionEquals(set1, set2,
					"La coleccion vacia no es identica");
		} catch (final AssertionFailedError ex) {
			fail("Assert Exception inesperada");
		}
	}

	@Test
	void testAssertCollectionEquals6() {
		try {
			final Map<String, String> map1 = new HashMap<>();
			final Map<String, String> map2 = new HashMap<>();
			org.gjs.java.test.util.AssertionUtils.assertCollectionEquals(map1, map2,
					"La coleccion vacia no es identica");
		} catch (final AssertionFailedError ex) {
			fail("Assert Exception inesperada");
		}
	}

	@Test
	void testAssertCollectionEquals7() {
		try {
			final Map<String, String> map1 = new HashMap<>();
			final Map<String, String> map2 = new HashMap<>();
			map1.put("key1", "valor1");
			map1.put("key2", "valor2");
			map2.put("key2", "valor2");
			org.gjs.java.test.util.AssertionUtils.assertCollectionEquals(map1, map2, "La coleccion no es identica");
			fail("Assert Exception esperada");
		} catch (final AssertionFailedError ex) {
		}
	}

	@Test
	void testAssertCollectionEquals8() {
		try {
			final Map<String, String> map1 = new HashMap<>();
			final Map<String, String> map2 = new HashMap<>();
			map1.put("key1", "valor1");
			map1.put("key2", "valor2");
			map2.put("key1", "valor2");
			map2.put("key2", "valor1");
			org.gjs.java.test.util.AssertionUtils.assertCollectionEquals(map1, map2, "La coleccion no es identica");
			fail("Assert Exception esperada");
		} catch (final AssertionFailedError ex) {
		}
	}

	@Test
	void testAssertCollectionEquals9() {
		try {
			final Map<String, String> map1 = new HashMap<>();
			final Map<String, String> map2 = new HashMap<>();
			map1.put("key1", "valor1");
			map1.put("key2", "valor2");
			map2.put("key1", "valor1");
			map2.put("key2", "valor2");
			org.gjs.java.test.util.AssertionUtils.assertCollectionEquals(map1, map2, "La coleccion no es identica");
		} catch (final AssertionFailedError ex) {
			fail("Assert Exception inesperada");
		}
	}

	@Test
	void testAssertCollectionEquals10() {
		try {
			final Map<String, String> map1 = new HashMap<>();
			final Map<String, String> map2 = new HashMap<>();
			map1.put("key1", "valor1");
			map1.put("key2", "valor2");
			map2.put("key1", "valor1");
			map2.put("key2", "valor2");
			org.gjs.java.test.util.AssertionUtils.assertCollectionEquals(map1, map2,
					"La coleccion vacia no es identica");
		} catch (final AssertionFailedError ex) {
			fail("Assert Exception inesperada");
		}
	}

	@Test
	void testAssertCollectionEquals11() {
		try {
			final Map<String, String> map1 = new HashMap<>();
			final Map<String, String> map2 = new HashMap<>();
			map1.put("key1", "valor1");
			map1.put("key2", "valor2");
			map2.put("key2", "valor2");
			map2.put("key1", "valor1");
			org.gjs.java.test.util.AssertionUtils.assertCollectionEquals(map1, map2,
					"La coleccion vacia no es identica");
		} catch (final AssertionFailedError ex) {
			fail("Assert Exception inesperada");
		}
	}

	@Test
	void testAssertSameDay1() {
		try {
			final Date date1 = null;
			final Date date2 = null;
			org.gjs.java.test.util.AssertionUtils.assertSameDay(date1, date2);
		} catch (final AssertionFailedError ex) {
			fail("Assert Exception inesperada");
		}
	}

	@Test
	void testAssertSameDay2() {
		try {
			final Date date1 = DAY_DATE_FORMAT.parse("01/01/2024 12:00:00");
			final Date date2 = null;
			org.gjs.java.test.util.AssertionUtils.assertSameDay(date1, date2);
			fail("Assert Exception esperada");
		} catch (final AssertionFailedError ex) {
		} catch (final ParseException e) {
			fail("Assert Exception esperada");
		}
	}

	@Test
	void testAssertSameDay3() {
		try {
			final Date date1 = null;
			final Date date2 = DAY_DATE_FORMAT.parse("01/01/2024 12:00:00");
			org.gjs.java.test.util.AssertionUtils.assertSameDay(date1, date2);
			fail("Assert Exception esperada");
		} catch (final AssertionFailedError ex) {
		} catch (final ParseException e) {
			fail("ParseException inesperada");
		}
	}

	@Test
	void testAssertSameDay4() {
		try {
			final Date date1 = DAY_DATE_FORMAT.parse("01/01/2024 12:00:00");
			final Date date2 = DAY_DATE_FORMAT.parse("02/01/2024 12:00:00");
			org.gjs.java.test.util.AssertionUtils.assertSameDay(date1, date2);
			fail("Assert Exception esperada");
		} catch (final AssertionFailedError ex) {
		} catch (final ParseException e) {
			fail("ParseException inesperada");
		}
	}

	@Test
	void testAssertSameDay5() {
		try {
			final Date date1 = DAY_DATE_FORMAT.parse("01/01/2024 12:00:00");
			final Date date2 = DAY_DATE_FORMAT.parse("01/01/2024 13:00:00");
			org.gjs.java.test.util.AssertionUtils.assertSameDay(date1, date2);
		} catch (final AssertionFailedError ex) {
			fail("Assert Exception inesperada");
		} catch (final ParseException e) {
			fail("ParseException inesperada");
		}
	}

	@Test
	void testAssertSameHour1() {
		try {
			final Date date1 = DAY_DATE_FORMAT.parse("01/01/2024 12:00:00");
			final Date date2 = DAY_DATE_FORMAT.parse("01/01/2024 13:01:54");
			org.gjs.java.test.util.AssertionUtils.assertSameDay(date1, date2);
			fail("Assert Exception esperada");
		} catch (final AssertionFailedError ex) {
		} catch (final ParseException e) {
			fail("ParseException inesperada");
		}
	}

	@Test
	void testAssertSameHour2() {
		try {
			final Date date1 = DAY_DATE_FORMAT.parse("01/01/2024 12:00:00");
			final Date date2 = DAY_DATE_FORMAT.parse("01/01/2024 12:01:54");
			org.gjs.java.test.util.AssertionUtils.assertSameDay(date1, date2);
		} catch (final AssertionFailedError ex) {
			fail("Assert Exception inesperada");
		} catch (final ParseException e) {
			fail("ParseException inesperada");
		}
	}

	@Test
	void testAssertSameSecond1() {
		try {
			final Date date1 = DAY_DATE_FORMAT.parse("01/01/2024 12:01:32");
			final Date date2 = DAY_DATE_FORMAT.parse("01/01/2024 12:01:33");
			org.gjs.java.test.util.AssertionUtils.assertSameDay(date1, date2);
			fail("Assert Exception esperada");
		} catch (final AssertionFailedError ex) {
		} catch (final ParseException e) {
			fail("ParseException inesperada");
		}
	}

	@Test
	void testAssertSameSecond2() {
		try {
			final Date date1 = DAY_DATE_FORMAT.parse("01/01/2024 12:01:45");
			final Date date2 = DAY_DATE_FORMAT.parse("01/01/2024 12:01:45");
			org.gjs.java.test.util.AssertionUtils.assertSameDay(date1, date2);
		} catch (final AssertionFailedError ex) {
			fail("Assert Exception inesperada");
		} catch (final ParseException e) {
			fail("ParseException inesperada");
		}
	}

	@Test
	void testAssertMatches1() {
		try {
			final String pattern = null;
			final String value = null;
			org.gjs.java.test.util.AssertionUtils.assertMatches(pattern, value);
			fail("Se esperaba excepcion");
		} catch (final AssertionFailedError ex) {
		} catch (final Exception e) {
			logger.error(ExceptionUtils.getStackTrace(e));
			fail("Excepcion inesperada");
		}
	}

	@Test
	void testAssertMatches2() {
		final String pattern = "foo";
		String value = "";
		try {
			org.gjs.java.test.util.AssertionUtils.assertMatches(pattern, value);
			fail("Se esperaba excepcion");
		} catch (final AssertionFailedError ex) {
		} catch (final Exception e) {
			logger.error(ExceptionUtils.getStackTrace(e));
			fail("Excepcion inesperada");
		}
		value = "foo";
		try {
			org.gjs.java.test.util.AssertionUtils.assertMatches(pattern, value);
		} catch (final Exception e) {
			logger.error(ExceptionUtils.getStackTrace(e));
			fail("Excepcion inesperada");
		}
		value = "afoo";
		try {
			org.gjs.java.test.util.AssertionUtils.assertMatches(pattern, value);
			fail("Se esperaba excepcion");
		} catch (final AssertionFailedError ex) {
		} catch (final Exception e) {
			logger.error(ExceptionUtils.getStackTrace(e));
			fail("Excepcion inesperada");
		}
	}

	@Test
	void testAssertMatches3() {
		final String pattern = "^[A-Z]([a-z])+";
		String value = "";
		try {
			org.gjs.java.test.util.AssertionUtils.assertMatches(pattern, value);
			fail("Se esperaba excepcion");
		} catch (final AssertionFailedError ex) {
		} catch (final Exception e) {
			logger.error(ExceptionUtils.getStackTrace(e));
			fail("Excepcion inesperada");
		}
		value = "foo";
		try {
			org.gjs.java.test.util.AssertionUtils.assertMatches(pattern, value);
			fail("Se esperaba excepcion");
		} catch (final AssertionFailedError ex) {
		} catch (final Exception e) {
			logger.error(ExceptionUtils.getStackTrace(e));
			fail("Excepcion inesperada");
		}
		value = "Foo";
		try {
			org.gjs.java.test.util.AssertionUtils.assertMatches(pattern, value);
		} catch (final Exception e) {
			logger.error(ExceptionUtils.getStackTrace(e));
			fail("Excepcion inesperada");
		}
		value = "F";
		try {
			org.gjs.java.test.util.AssertionUtils.assertMatches(pattern, value);
			fail("Se esperaba excepcion");
		} catch (final AssertionFailedError ex) {
		} catch (final Exception e) {
			logger.error(ExceptionUtils.getStackTrace(e));
			fail("Excepcion inesperada");
		}
		value = "FOO";
		try {
			org.gjs.java.test.util.AssertionUtils.assertMatches(pattern, value);
			fail("Se esperaba excepcion");
		} catch (final AssertionFailedError ex) {
		} catch (final Exception e) {
			logger.error(ExceptionUtils.getStackTrace(e));
			fail("Excepcion inesperada");
		}
	}

	@Test
	void testAssertMatches4() {
		final String pattern = "\\d+{2}-\\d+{2}-\\d+{4}T\\d+{2}:\\d+{2}:\\d+{2}";
		String value = "";
		try {
			org.gjs.java.test.util.AssertionUtils.assertMatches(pattern, value);
			fail("Se esperaba excepcion");
		} catch (final AssertionFailedError ex) {
		} catch (final Exception e) {
			logger.error(ExceptionUtils.getStackTrace(e));
			fail("Excepcion inesperada");
		}
		value = "14-02-2024T11:59:07";
		try {
			org.gjs.java.test.util.AssertionUtils.assertMatches(pattern, value);
		} catch (final Exception e) {
			logger.error(ExceptionUtils.getStackTrace(e));
			fail("Excepcion inesperada");
		}
		value = "1-02-2024T11:59:07";
		try {
			org.gjs.java.test.util.AssertionUtils.assertMatches(pattern, value);
			fail("Se esperaba excepcion");
		} catch (final AssertionFailedError ex) {
		} catch (final Exception e) {
			logger.error(ExceptionUtils.getStackTrace(e));
			fail("Excepcion inesperada");
		}
		value = "14-02-2024 11:59:07";
		try {
			org.gjs.java.test.util.AssertionUtils.assertMatches(pattern, value);
			fail("Se esperaba excepcion");
		} catch (final AssertionFailedError ex) {
		} catch (final Exception e) {
			logger.error(ExceptionUtils.getStackTrace(e));
			fail("Excepcion inesperada");
		}
	}

}
