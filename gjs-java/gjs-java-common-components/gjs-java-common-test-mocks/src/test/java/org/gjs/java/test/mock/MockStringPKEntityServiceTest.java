package org.gjs.java.test.mock;

import static org.junit.jupiter.api.Assertions.assertEquals;
import static org.junit.jupiter.api.Assertions.assertFalse;
import static org.junit.jupiter.api.Assertions.assertNotNull;
import static org.junit.jupiter.api.Assertions.assertTrue;

import java.io.IOException;
import java.nio.file.Path;
import java.util.List;

import org.gjs.java.test.AbstractUnitTest;
import org.gjs.java.test.samples.pojos.SamplePojoFilter;
import org.gjs.java.test.samples.pojos.SampleStringIdPojo;
import org.junit.jupiter.api.Test;
import org.springframework.core.io.ClassPathResource;

class MockStringPKEntityServiceTest extends AbstractUnitTest {

	static class MockSampleService1 extends MockStringPKEntityService<SampleStringIdPojo, SamplePojoFilter> {

	}

	static class MockSampleService2 extends MockStringPKEntityService<SampleStringIdPojo, SamplePojoFilter> {
		public MockSampleService2() throws IOException {
			super(new ClassPathResource("data/sample3.csv"));
		}
	}

	static class MockSampleService3 extends MockStringPKEntityService<SampleStringIdPojo, SamplePojoFilter> {
		public MockSampleService3(String path) throws IOException {
			super(path);
		}
	}

	private MockSampleService1 mockSampleService1;

	private SampleStringIdPojo sample1;

	@Override
	protected Class<?> getClazz() {
		return MockStringPKEntityService.class;
	}

	@Override
	protected void initialize() throws Exception {
		mockSampleService1 = new MockSampleService1();

		sample1 = new SampleStringIdPojo("1", "Test 1");
		sample1 = mockSampleService1.save(sample1);
	}

	@Test
	void testMockEntityService1() {
		SampleStringIdPojo value = mockSampleService1.find(sample1.getId());
		assertNotNull(value);
		assertEquals(sample1.getId(), value.getId());
		assertEquals(sample1.getNombre(), value.getNombre());
		List<SampleStringIdPojo> list = mockSampleService1.findAll();
		assertNotNull(list);
		assertEquals(1, list.size());
		assertNotNull(list.get(0));
		assertEquals(sample1.getId(), list.get(0).getId());
		assertEquals(sample1.getNombre(), list.get(0).getNombre());
		assertEquals(1, mockSampleService1.count());
		final SamplePojoFilter filter = new SamplePojoFilter();
		filter.setNombre("NoData");
		assertEquals(0, mockSampleService1.count(filter));
		list = mockSampleService1.filter(0, 10, "nombre", 1, filter);
		assertNotNull(list);
		assertEquals(0, list.size());
		filter.setNombre(value.getNombre());
		assertEquals(1, mockSampleService1.count(filter));
		list = mockSampleService1.filter(0, 10, "nombre", 1, filter);
		assertNotNull(list);
		assertEquals(1, list.size());
		assertNotNull(list.get(0));
		assertEquals(sample1.getId(), list.get(0).getId());
		assertEquals(sample1.getNombre(), list.get(0).getNombre());
		value = mockSampleService1.update(value);
		assertNotNull(value);
		assertEquals(sample1.getId(), value.getId());
		assertEquals(sample1.getNombre(), value.getNombre());
	}

	@Test
	void testMockEntityService2() {
		final MockSampleService1 service = new MockSampleService1();
		final Path filePath = currentDir.resolve("data/sample1.csv");
		service.loadCsv(filePath.toAbsolutePath().toString());

		assertEquals(3, service.count());
		assertTrue(service.exists("1"));
		assertTrue(service.exists("2"));
		assertTrue(service.exists("3"));
		assertFalse(service.exists("9"));

	}

}
