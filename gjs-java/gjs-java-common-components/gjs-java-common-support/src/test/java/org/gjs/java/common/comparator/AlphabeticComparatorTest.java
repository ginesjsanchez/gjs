package org.gjs.java.common.comparator;

import static org.junit.jupiter.api.Assertions.assertEquals;

import java.util.ArrayList;
import java.util.Comparator;
import java.util.List;

import org.gjs.java.common.comparator.AlphabeticComparator;
import org.gjs.java.common.comparator.DateComparator;
import org.gjs.java.test.BaseClassTest;
import org.junit.jupiter.api.Test;

public class AlphabeticComparatorTest extends BaseClassTest<DateComparator> {

	@Test
	void testAlphabeticComparator1() {
		final Comparator<String> comparator = new AlphabeticComparator();
		String s1 = null;
		String s2 = null;
		assertEquals(0, comparator.compare(s1, s2));
		s1 = "";
		assertEquals(1, comparator.compare(s1, s2));
		assertEquals(-1, comparator.compare(s2, s1));
		s1 = "abc";
		s2 = "ábç";
		assertEquals(0, comparator.compare(s1, s2));
		s2 = "abcd";
		assertEquals(-1, comparator.compare(s1, s2));
		assertEquals(1, comparator.compare(s2, s1));
	}

	@Test
	void testAlphabeticComparator2() {
		final String[] expected = { null, "", " ", "A" };
		final List<String> list = new ArrayList<>();
		list.add(expected[2]);
		list.add(expected[3]);
		list.add(expected[0]);
		list.add(expected[1]);
		list.sort(new AlphabeticComparator());
		logger.info("List after sort:");
		for (final String val : list) {
			logger.info(val);
		}
		for (int i = 0; i < expected.length; i = i + 1) {
			assertEquals(expected[i], list.get(i));
		}
	}

	@Test
	void testAlphabeticComparator3() {
		final String[] expected = { "alemania", "EspAña", "FRANcIA", "italia" };
		final List<String> list = new ArrayList<>();
		list.add(expected[2]);
		list.add(expected[3]);
		list.add(expected[0]);
		list.add(expected[1]);
		list.sort(new AlphabeticComparator());
		logger.info("List after sort:");
		for (final String val : list) {
			logger.info(val);
		}
		for (int i = 0; i < expected.length; i = i + 1) {
			assertEquals(expected[i], list.get(i));
		}
	}

	@Test
	void testAlphabeticComparator4() {
		final String[] expected = { " ", " EspAña", "ale mania", "F RANcIA", "italia " };
		final List<String> list = new ArrayList<>();
		list.add(expected[2]);
		list.add(expected[3]);
		list.add(expected[4]);
		list.add(expected[0]);
		list.add(expected[1]);
		list.sort(new AlphabeticComparator());
		logger.info("List after sort:");
		for (final String val : list) {
			logger.info(val);
		}
		for (int i = 0; i < expected.length; i = i + 1) {
			assertEquals(expected[i], list.get(i));
		}
	}

}
