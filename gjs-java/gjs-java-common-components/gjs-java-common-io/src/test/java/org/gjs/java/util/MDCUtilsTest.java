package org.gjs.java.util;

import static org.junit.jupiter.api.Assertions.assertEquals;
import static org.junit.jupiter.api.Assertions.assertNotEquals;
import static org.junit.jupiter.api.Assertions.assertNotNull;
import static org.junit.jupiter.api.Assertions.assertNull;
import static org.junit.jupiter.api.Assertions.fail;

import org.apache.commons.lang3.exception.ExceptionUtils;
import org.gjs.java.test.BaseClassTest;
import org.gjs.java.test.samples.dto.SampleEntityDto;
import org.junit.jupiter.api.Test;

public class MDCUtilsTest extends BaseClassTest<MDCUtils> {

	@Test
	public void testMDC1() {
		try {
			MDCUtils.clear();
			String key = null;
			String obj = null;
			MDCUtils.save(key, obj);
			key = "key1";
			MDCUtils.save(key, obj);
			Object rec = MDCUtils.load(key);
			assertNull(rec);
			obj = "Obj1";
			MDCUtils.save(key, obj);
			rec = MDCUtils.load(key);
			assertNotNull(rec);
			assertEquals(obj, rec);
			MDCUtils.clear();
			rec = MDCUtils.load(key);
			assertNull(rec);
			MDCUtils.clear();

		} catch (final Exception e) {
			logger.error(ExceptionUtils.getStackTrace(e));
			fail("Excepcion recibida");
		}
	}

	@Test
	public void testMDC2() {
		MDCUtils.clear();
		final String key1 = "key1";
		final SampleEntityDto obj1 = new SampleEntityDto();
		obj1.setId(Long.valueOf(1));
		obj1.setNombre("test1");
		final String key2 = "key2";
		final SampleEntityDto obj2 = new SampleEntityDto();
		obj2.setId(Long.valueOf(2));
		obj2.setNombre("test2");
		final String key3 = "key3";

		SampleEntityDto rec = (SampleEntityDto) MDCUtils.load(key1, SampleEntityDto.class);
		assertNull(rec);
		MDCUtils.save(key1, obj1);
		MDCUtils.save(key2, obj2);
		rec = (SampleEntityDto) MDCUtils.load(key1, SampleEntityDto.class);
		assertNotNull(rec);
		assertEquals(obj1.toString(), rec.toString());
		assertEquals(obj1.getId(), rec.getId());
		assertEquals(obj1.getNombre(), rec.getNombre());
		rec = (SampleEntityDto) MDCUtils.load(key2, SampleEntityDto.class);
		assertNotNull(rec);
		assertEquals(obj2.toString(), rec.toString());
		assertEquals(obj2.getId(), rec.getId());
		assertEquals(obj2.getNombre(), rec.getNombre());
		rec = (SampleEntityDto) MDCUtils.load(key3, SampleEntityDto.class);
		assertNull(rec);

		final String expected = obj1.getNombre();
		obj1.setNombre("cambiado");
		rec = (SampleEntityDto) MDCUtils.load(key1, SampleEntityDto.class);
		assertNotNull(rec);
		assertEquals(obj1.getId(), rec.getId());
		assertEquals(expected, rec.getNombre());
		MDCUtils.clear();
	}

	@Test
	public void testMDC3() {
		MDCUtils.clear();
		final String key1 = "key1";
		String obj1 = "test1";
		final String key2 = "key2";
		Long obj2 = Long.valueOf(2);

		MDCUtils.save(key1, obj1);
		MDCUtils.save(key2, obj2);
		final String recString = MDCUtils.load(key1);
		assertNotNull(recString);
		logger.debug("obj={} res={}", obj1, recString);
		assertEquals(obj1, recString);
		obj1.concat("plus");
		logger.debug("obj={} res={}", obj1, recString);
		assertEquals(obj1, recString);
		obj1 = "cambiado";
		logger.debug("obj={} res={}", obj1, recString);
		assertNotEquals(obj1, recString);

		final Long recLong = (Long) MDCUtils.load(key2, Long.class);
		assertNotNull(recLong);
		logger.debug("res={}", recLong);
		assertEquals(obj2, recLong);
		obj2 = Long.valueOf(3);
		logger.debug("res={}", recLong);
		assertNotEquals(obj2, recLong);
		MDCUtils.clear();
	}

}
