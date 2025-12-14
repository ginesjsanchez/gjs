package org.gjs.java.common.dto;

import static org.junit.jupiter.api.Assertions.assertEquals;
import static org.junit.jupiter.api.Assertions.assertNotNull;
import static org.junit.jupiter.api.Assertions.assertNull;
import static org.junit.jupiter.api.Assertions.assertTrue;

import org.gjs.java.common.dto.AuditDto;
import org.gjs.java.common.dto.StatisticsDto;
import org.gjs.java.common.supplier.random.RandomLongSupplier;
import org.gjs.java.test.BaseUnitTest;
import org.junit.jupiter.api.Test;

public class StatisticsDtoTest extends BaseUnitTest<StatisticsDto> {

	@Test
	void testStatisticsDto1() {
		final StatisticsDto statisticsDto = new StatisticsDto();
		assertNull(statisticsDto.getModule());
		assertNull(statisticsDto.getPrimitive());
		assertEquals(0, statisticsDto.getExecutions());
		assertEquals(Long.MAX_VALUE, statisticsDto.getMinTime());
		assertEquals(0, statisticsDto.getMaxTime());
		assertEquals(0, statisticsDto.getMediumTime());
		logger.info(statisticsDto.toString());

		statisticsDto.addMeassure(0);
		assertNull(statisticsDto.getModule());
		assertNull(statisticsDto.getPrimitive());
		assertEquals(1, statisticsDto.getExecutions());
		assertEquals(0, statisticsDto.getMinTime());
		assertEquals(0, statisticsDto.getMaxTime());
		assertEquals(0, statisticsDto.getMediumTime());
		logger.info(statisticsDto.toString());

		statisticsDto.addMeassure(-1);
		statisticsDto.addMeassure(0);
		assertNull(statisticsDto.getModule());
		assertNull(statisticsDto.getPrimitive());
		assertEquals(2, statisticsDto.getExecutions());
		assertEquals(0, statisticsDto.getMinTime());
		assertEquals(0, statisticsDto.getMaxTime());
		assertEquals(0, statisticsDto.getMediumTime());
		logger.info(statisticsDto.toString());
	}

	@Test
	void testStatisticsDto2() throws InterruptedException {
		final StatisticsDto statisticsDto = new StatisticsDto("modulo", "metodo");
		AuditDto auditDto = null;
		assertEquals(0, statisticsDto.getExecutions());
		assertEquals(Long.MAX_VALUE, statisticsDto.getMinTime());
		assertEquals(0, statisticsDto.getMaxTime());
		assertEquals(0, statisticsDto.getMediumTime());
		statisticsDto.addMeassure(auditDto);
		assertEquals(0, statisticsDto.getExecutions());
		assertEquals(Long.MAX_VALUE, statisticsDto.getMinTime());
		assertEquals(0, statisticsDto.getMaxTime());
		assertEquals(0, statisticsDto.getMediumTime());
		auditDto = new AuditDto();
		statisticsDto.addMeassure(auditDto);
		assertEquals(0, statisticsDto.getExecutions());
		assertEquals(Long.MAX_VALUE, statisticsDto.getMinTime());
		assertEquals(0, statisticsDto.getMaxTime());
		assertEquals(0, statisticsDto.getMediumTime());
		auditDto = new AuditDto("moduloX", "metodoX");
		statisticsDto.addMeassure(auditDto);
		assertEquals(0, statisticsDto.getExecutions());
		assertEquals(Long.MAX_VALUE, statisticsDto.getMinTime());
		assertEquals(0, statisticsDto.getMaxTime());
		assertEquals(0, statisticsDto.getMediumTime());
		auditDto = new AuditDto("modulo", "metodo");
		statisticsDto.addMeassure(auditDto);
		assertEquals(0, statisticsDto.getExecutions());
		assertEquals(Long.MAX_VALUE, statisticsDto.getMinTime());
		assertEquals(0, statisticsDto.getMaxTime());
		assertEquals(0, statisticsDto.getMediumTime());
		auditDto.begin();
		Thread.sleep(100);
		auditDto.end();
		statisticsDto.addMeassure(auditDto);
		assertEquals(1, statisticsDto.getExecutions());
		assertTrue(statisticsDto.getMinTime() >= 100);
		assertTrue(statisticsDto.getMinTime() >= 100);
		assertTrue(statisticsDto.getMinTime() >= 100);
		assertEquals(statisticsDto.getMinTime(), statisticsDto.getMaxTime());
		assertEquals(statisticsDto.getMinTime(), statisticsDto.getMediumTime());
	}

	@Test
	void testStatisticsDto3() {
		final StatisticsDto statisticsDto = new StatisticsDto("modulo", "metodo");
		assertNotNull(statisticsDto.getModule());
		assertNotNull(statisticsDto.getPrimitive());
		assertEquals("modulo", statisticsDto.getModule());
		assertEquals("metodo", statisticsDto.getPrimitive());
		assertEquals(0, statisticsDto.getExecutions());
		assertEquals(Long.MAX_VALUE, statisticsDto.getMinTime());
		assertEquals(0, statisticsDto.getMaxTime());
		assertEquals(0, statisticsDto.getMediumTime());

		final RandomLongSupplier supplier = new RandomLongSupplier(0L, 10000L);
		final int numValues = 100;
		final long[] values = new long[numValues];
		for (int i = 0; i < numValues; i = i + 1) {
			values[i] = supplier.get();
			statisticsDto.addMeassure(values[i]);
			logger.info(statisticsDto.toString());
		}
		long medium;
		long min = Long.MAX_VALUE;
		long max = 0;
		long sum = 0;
		for (int i = 0; i < numValues; i = i + 1) {
			if (values[i] < min) {
				min = values[i];
			}
			if (values[i] > max) {
				max = values[i];
			}
			sum = sum + values[i];
			// logger.info("sum={} medium={}", sum, sum / (i + 1));
		}
		medium = sum / numValues;
		final long error = 1; // 2 + numValues / 4;
		logger.info("medium={}", medium);
		assertNotNull(statisticsDto.getModule());
		assertNotNull(statisticsDto.getPrimitive());
		assertEquals("modulo", statisticsDto.getModule());
		assertEquals("metodo", statisticsDto.getPrimitive());
		assertEquals(numValues, statisticsDto.getExecutions());
		assertEquals(min, statisticsDto.getMinTime());
		assertEquals(max, statisticsDto.getMaxTime());
		// assertEquals(medium, statisticsDto.getMediumTime());
		// logger.info("Range medium time: {}-{}", statisticsDto.getMediumTime() -
		// error,
		// statisticsDto.getMediumTime() + error);
		assertTrue(medium <= statisticsDto.getMediumTime() + error,
				String.format("%s > %s", medium, statisticsDto.getMediumTime() + error));
		assertTrue(medium >= statisticsDto.getMediumTime() - error,
				String.format("%s < %s", medium, statisticsDto.getMediumTime() - error));
	}

	// @Test
	// void testStatisticsDto3() {
	// for (int j = 0; j < 200; j = j + 1) {
	// final StatisticsDto statisticsDto = new StatisticsDto("modulo", "metodo");
	//
	// final RandomLongSupplier supplier = new RandomLongSupplier(0L, 10000L);
	// final int numValues = 100;
	// final long[] values = new long[numValues];
	// long sum = 0;
	// for (int i = 0; i < numValues; i = i + 1) {
	// values[i] = supplier.get();
	// statisticsDto.addMeassure(values[i]);
	// sum = sum + values[i];
	// }
	// final long medium = sum / numValues;
	// logger.info("medium expected={} / calculated={} => diff={}", medium,
	// statisticsDto.getMediumTime(),
	// medium - statisticsDto.getMediumTime());
	// }
	// }

}
