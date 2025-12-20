package org.gjs.java.common.singleton;

import static org.junit.jupiter.api.Assertions.assertEquals;
import static org.junit.jupiter.api.Assertions.assertNotEquals;
import static org.junit.jupiter.api.Assertions.assertNotNull;
import static org.junit.jupiter.api.Assertions.assertNull;
import static org.junit.jupiter.api.Assertions.fail;

import java.util.List;

import org.apache.commons.lang3.exception.ExceptionUtils;
import org.gjs.java.test.BaseUnitTest;
import org.gjs.java.test.samples.dto.SampleEntityDto;
import org.gjs.java.test.samples.dto.SampleWithFKEntityDto;
import org.junit.jupiter.api.Test;

public class GlobalObjectsManagerTest extends BaseUnitTest<GlobalObjectsManager> {

	@Test
	public void testGlobalObjectsManager1() {
		try {
			GlobalObjectsManager.getInstance().clear();
			String key = null;
			Object obj = null;
			GlobalObjectsManager.getInstance().save(key, obj);
			key = "key1";
			GlobalObjectsManager.getInstance().save(key, obj);
			Object rec = GlobalObjectsManager.getInstance().load(key);
			assertNull(rec);
			obj = "Obj1";
			GlobalObjectsManager.getInstance().save(key, obj);
			rec = GlobalObjectsManager.getInstance().load(key);
			assertNotNull(rec);
			assertEquals(obj, rec);
			GlobalObjectsManager.getInstance().clear();
			rec = GlobalObjectsManager.getInstance().load(key);
			assertNull(rec);
			GlobalObjectsManager.getInstance().clear();

		} catch (final Exception e) {
			logger.error(ExceptionUtils.getStackTrace(e));
			fail("Excepcion recibida");
		}
	}

	@Test
	public void testGlobalObjectsManager2() {
		GlobalObjectsManager.getInstance().clear();
		final String key1 = "key1";
		final SampleEntityDto obj1 = new SampleEntityDto();
		obj1.setId(Long.valueOf(1));
		obj1.setNombre("test1");
		final String key2 = "key2";
		final SampleEntityDto obj2 = new SampleEntityDto();
		obj2.setId(Long.valueOf(2));
		obj2.setNombre("test2");
		final String key3 = "key3";

		SampleEntityDto rec = (SampleEntityDto) GlobalObjectsManager.getInstance().load(key1);
		assertNull(rec);
		GlobalObjectsManager.getInstance().save(key1, obj1);
		GlobalObjectsManager.getInstance().save(key2, obj2);
		rec = (SampleEntityDto) GlobalObjectsManager.getInstance().load(key1);
		assertNotNull(rec);
		assertEquals(obj1, rec);
		assertEquals(obj1.getId(), rec.getId());
		assertEquals(obj1.getNombre(), rec.getNombre());
		rec = (SampleEntityDto) GlobalObjectsManager.getInstance().load(key2);
		assertNotNull(rec);
		assertEquals(obj2, rec);
		assertEquals(obj2.getId(), rec.getId());
		assertEquals(obj2.getNombre(), rec.getNombre());
		rec = (SampleEntityDto) GlobalObjectsManager.getInstance().load(key3);
		assertNull(rec);

		obj1.setNombre("cambiado");
		rec = (SampleEntityDto) GlobalObjectsManager.getInstance().load(key1);
		assertNotNull(rec);
		assertEquals(obj1.getId(), rec.getId());
		assertEquals(obj1.getNombre(), rec.getNombre());
		GlobalObjectsManager.getInstance().clear();
	}

	@Test
	public void testGlobalObjectsManager3() {
		GlobalObjectsManager.getInstance().clear();
		final String key1 = "key1";
		String obj1 = "test1";
		final String key2 = "key2";
		Long obj2 = Long.valueOf(2);

		GlobalObjectsManager.getInstance().save(key1, obj1);
		GlobalObjectsManager.getInstance().save(key2, obj2);
		final String recString = (String) GlobalObjectsManager.getInstance().load(key1);
		assertNotNull(recString);
		logger.debug("obj={} res={}", obj1, recString);
		assertEquals(obj1, recString);
		obj1.concat("plus");
		logger.debug("obj={} res={}", obj1, recString);
		assertEquals(obj1, recString);
		obj1 = "cambiado";
		logger.debug("obj={} res={}", obj1, recString);
		assertNotEquals(obj1, recString);

		final Long recLong = (Long) GlobalObjectsManager.getInstance().load(key2);
		assertNotNull(recLong);
		logger.debug("res={}", recLong);
		assertEquals(obj2, recLong);
		obj2 = Long.valueOf(3);
		logger.debug("res={}", recLong);
		assertNotEquals(obj2, recLong);
		GlobalObjectsManager.getInstance().clear();
	}

	@Test
	public void testGlobalObjectsManager4() {
		GlobalObjectsManager.getInstance().clear();
		final String key1 = "key1";
		final SampleEntityDto obj1 = new SampleEntityDto();
		obj1.setId(Long.valueOf(1));
		obj1.setNombre("test1");
		final String key2 = "key2";
		final SampleEntityDto obj2 = new SampleEntityDto();
		obj2.setId(Long.valueOf(2));
		obj2.setNombre("test2");
		final String key3 = "key3";
		final SampleEntityDto obj3 = new SampleEntityDto();
		obj3.setId(Long.valueOf(3));
		obj3.setNombre("test3");
		final String key4 = "key4";
		final SampleEntityDto obj4 = new SampleEntityDto();
		obj4.setId(Long.valueOf(4));
		obj4.setNombre("test4");

		GlobalObjectsManager.getInstance().save(key1, obj1);
		GlobalObjectsManager.getInstance().save(key2, obj2);
		GlobalObjectsManager.getInstance().save(key3, obj3);
		GlobalObjectsManager.getInstance().save(key4, obj4);

		List<Object> list = GlobalObjectsManager.getInstance().loadAll(SampleEntityDto.class);
		assertNotNull(list);
		assertEquals(4, list.size());

		list = GlobalObjectsManager.getInstance().loadAll(SampleWithFKEntityDto.class);
		assertNotNull(list);
		assertEquals(0, list.size());
	}

	@Test
	public void testGlobalObjectsManager5() {
		GlobalObjectsManager.getInstance().clear();
		final String key1 = "key1";
		final SampleEntityDto obj1 = new SampleEntityDto();
		obj1.setId(Long.valueOf(1));
		obj1.setNombre("test1");
		final String key2 = "key2";
		final SampleEntityDto obj2 = new SampleEntityDto();
		obj2.setId(Long.valueOf(2));
		obj2.setNombre("test2");
		final String key3 = "key3";
		final SampleEntityDto obj3 = new SampleEntityDto();
		obj3.setId(Long.valueOf(3));
		obj3.setNombre("test3");
		final String key4 = "key4";
		final SampleEntityDto obj4 = new SampleEntityDto();
		obj4.setId(Long.valueOf(4));
		obj4.setNombre("test4");

		GlobalObjectsManager.getInstance().save(key1, obj1);
		GlobalObjectsManager.getInstance().save(key2, obj2);
		GlobalObjectsManager.getInstance().save(key3, obj3);
		GlobalObjectsManager.getInstance().save(key4, obj4);

		List<String> list = GlobalObjectsManager.getInstance().getKeys(SampleEntityDto.class);
		assertNotNull(list);
		assertEquals(4, list.size());

		list = GlobalObjectsManager.getInstance().getKeys(SampleWithFKEntityDto.class);
		assertNotNull(list);
		assertEquals(0, list.size());
	}

}
