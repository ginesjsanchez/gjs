package org.gjs.java.test.mock;

import static org.junit.jupiter.api.Assertions.assertEquals;
import static org.junit.jupiter.api.Assertions.assertFalse;
import static org.junit.jupiter.api.Assertions.assertNotNull;
import static org.junit.jupiter.api.Assertions.assertTrue;

import java.nio.file.Path;
import java.util.Date;
import java.util.List;

import org.gjs.java.test.AbstractUnitTest;
import org.gjs.java.test.samples.pojos.SampleContainerPojo;
import org.gjs.java.test.samples.pojos.SamplePojo;
import org.gjs.java.test.samples.pojos.SamplePojoFilter;
import org.junit.jupiter.api.Test;

class MockEntityServiceTest extends AbstractUnitTest {

	static class MockSampleService extends MockEntityService<SampleContainerPojo, Long, SamplePojoFilter> {

		@Override
		protected Class<?> getClazz() {
			return SampleContainerPojo.class;
		}

		@Override
		protected Class<?> getPKClazz() {
			return Long.class;
		}

	}

	static class MockErrorService extends MockEntityService<SampleContainerPojo, Long, SamplePojoFilter> {

		@Override
		protected Class<?> getClazz() {
			return SampleContainerPojo.class;
		}

		@Override
		protected Class<?> getPKClazz() {
			return Date.class;
		}

	}

	private MockSampleService mockSampleService;
	private MockErrorService mockErrorService;

	private SamplePojo sample1;
	private SampleContainerPojo sampleContainer1;

	@Override
	protected Class<?> getClazz() {
		return MockEntityService.class;
	}

	@Override
	protected void initialize() throws Exception {
		mockSampleService = new MockSampleService();
		mockErrorService = new MockErrorService();

		sample1 = new SamplePojo(1, "Test 1");
		sampleContainer1 = new SampleContainerPojo(1, "Test 1", sample1);
		sampleContainer1 = mockSampleService.save(sampleContainer1);
	}

	@Test
	void testMockEntityService1() {
		SampleContainerPojo value = mockSampleService.find(sample1.getId());
		assertNotNull(value);
		assertEquals(sampleContainer1.getId(), value.getId());
		assertEquals(sampleContainer1.getNombre(), value.getNombre());
		List<SampleContainerPojo> list = mockSampleService.findAll();
		assertNotNull(list);
		assertEquals(1, list.size());
		assertNotNull(list.get(0));
		assertEquals(sampleContainer1.getId(), list.get(0).getId());
		assertEquals(sampleContainer1.getNombre(), list.get(0).getNombre());
		assertEquals(1, mockSampleService.count());
		final SamplePojoFilter filter = new SamplePojoFilter();
		filter.setNombre("NoData");
		assertEquals(0, mockSampleService.count(filter));
		list = mockSampleService.filter(0, 10, "nombre", 1, filter);
		assertNotNull(list);
		assertEquals(0, list.size());
		list = mockSampleService.filter("nombre", 1, filter);
		assertNotNull(list);
		assertEquals(0, list.size());
		filter.setNombre(value.getNombre());
		assertEquals(1, mockSampleService.count(filter));
		list = mockSampleService.filter(0, 10, "nombre", 1, filter);
		assertNotNull(list);
		assertEquals(1, list.size());
		assertNotNull(list.get(0));
		assertEquals(sampleContainer1.getId(), list.get(0).getId());
		assertEquals(sampleContainer1.getNombre(), list.get(0).getNombre());
		list = mockSampleService.filter("nombre", 1, filter);
		assertNotNull(list);
		assertEquals(1, list.size());
		assertNotNull(list.get(0));
		assertEquals(sampleContainer1.getId(), list.get(0).getId());
		assertEquals(sampleContainer1.getNombre(), list.get(0).getNombre());
		value = mockSampleService.update(value);
		assertNotNull(value);
		assertEquals(sampleContainer1.getId(), value.getId());
		assertEquals(sampleContainer1.getNombre(), value.getNombre());
	}

	@Test
	void testMockEntityService2() {
		SampleContainerPojo value1 = new SampleContainerPojo();

		value1 = mockErrorService.save(value1);
		assertNotNull(value1);
		assertTrue(value1.getId() > 0);

		SampleContainerPojo value2 = mockErrorService.find(value1.getId());
		assertNotNull(value2);
		assertEquals(value1.getId(), value2.getId());
		value2 = mockErrorService.update(value1);
		assertNotNull(value2);
		assertEquals(value1.getId(), value2.getId());

		SampleContainerPojo value3 = new SampleContainerPojo();
		value3.setId(99);

		value3 = mockErrorService.save(value3);
		assertNotNull(value1);
		assertEquals(99, value3.getId());
	}

	@Test
	void testMockEntityService3() {
		final MockSampleService service = new MockSampleService();
		final Path filePath = currentDir.resolve("data/sample1.csv");
		service.loadCsv(filePath.toAbsolutePath().toString());

		assertEquals(3, service.count());
		assertTrue(service.exists(Long.valueOf(1)));
		assertTrue(service.exists(Long.valueOf(2)));
		assertTrue(service.exists(Long.valueOf(3)));
		assertFalse(service.exists(Long.valueOf(0)));

	}

}
