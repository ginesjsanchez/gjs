package org.gjs.java.comparator;

import static org.junit.jupiter.api.Assertions.assertEquals;
import static org.junit.jupiter.api.Assertions.assertTrue;

import java.util.ArrayList;
import java.util.Date;
import java.util.List;

import org.gjs.java.common.ConversionUtils;
import org.gjs.java.common.DateUtils;
import org.gjs.java.supplier.random.RandomDateSupplier;
import org.gjs.java.test.BaseClassTest;
import org.junit.jupiter.api.Test;

public class DateComparatorTest extends BaseClassTest<DateComparator> {

	private RandomDateSupplier supplier;

	@Override
	protected void prepareTest() {
		supplier = new RandomDateSupplier(1000, false);
	}

	@Test
	void testDateComparator1() {
		final List<Date> list = new ArrayList<>();
		final Date date1 = DateUtils.tomorrow();
		final Date date2 = DateUtils.yesterday();
		final Date date3 = null;
		final Date date4 = DateUtils.today();
		list.add(date1);
		list.add(date2);
		list.add(date3);
		list.add(date4);
		list.sort(new DateComparator());
		logger.info("List after sort:");
		for (final Date date : list) {
			logger.info(ConversionUtils.toString(date));
		}
		assertEquals(date2, list.get(0));
		assertEquals(date4, list.get(1));
		assertEquals(date1, list.get(2));
		assertEquals(date3, list.get(3));

	}

	@Test
	void testDateComparator2() {
		final List<Date> list = new ArrayList<>();
		for (int i = 0; i < 20; i = i + 1) {
			list.add(supplier.get());
		}
		logger.info("1) List before sort:");
		for (final Date date : list) {
			logger.info(ConversionUtils.toString(date));
		}
		list.sort(new DateComparator());
		logger.info("2) List after sort:");
		for (final Date date : list) {
			logger.info(ConversionUtils.toString(date));
		}
		Date date1 = list.get(0);
		for (int i = 1; i < 20; i = i + 1) {
			final Date date2 = list.get(i);
			assertTrue(beforeOrEqual(date1, date2),
					String.format("Date %s not before or equals than date %s", date1, date2));
			date1 = date2;
		}
	}

	private boolean beforeOrEqual(Date date1, Date date2) {
		boolean res = false;
		if (date1 == null) {
			res = (date2 == null);
		} else if (date2 == null) {
			res = true;
		} else {
			res = date1.before(date2) || date1.equals(date2);
		}
		return res;
	}

}
