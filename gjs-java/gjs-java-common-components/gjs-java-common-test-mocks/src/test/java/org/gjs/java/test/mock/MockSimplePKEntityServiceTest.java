package org.gjs.java.test.mock;

import static org.junit.jupiter.api.Assertions.assertEquals;
import static org.junit.jupiter.api.Assertions.assertFalse;
import static org.junit.jupiter.api.Assertions.assertNotNull;
import static org.junit.jupiter.api.Assertions.assertTrue;

import java.io.IOException;
import java.nio.file.Path;
import java.util.List;

import org.gjs.java.test.AbstractUnitTest;
import org.gjs.java.test.samples.pojos.SampleContainerPojo;
import org.gjs.java.test.samples.pojos.SamplePojo;
import org.gjs.java.test.samples.pojos.SamplePojoFilter;
import org.junit.jupiter.api.Test;
import org.springframework.core.io.ClassPathResource;

class MockSimplePKEntityServiceTest extends AbstractUnitTest {

	static class MockSampleService1 extends MockSimplePKEntityService<SampleContainerPojo, SamplePojoFilter> {

	}

	static class MockSampleService2 extends MockSimplePKEntityService<SampleContainerPojo, SamplePojoFilter> {
		public MockSampleService2() throws IOException {
			super(new ClassPathResource("data/sample1.csv"));
		}
	}

	static class MockSampleService3 extends MockSimplePKEntityService<SampleContainerPojo, SamplePojoFilter> {
		public MockSampleService3(String path) throws IOException {
			super(path);
		}
	}

	private MockSampleService1 mockSampleService1;

	private SamplePojo sample1;
	private SampleContainerPojo sampleContainer1;

	@Override
	protected Class<?> getClazz() {
		return MockSimplePKEntityService.class;
	}

	@Override
	protected void initialize() throws Exception {
		mockSampleService1 = new MockSampleService1();

		sample1 = new SamplePojo(1, "Test 1");
		sampleContainer1 = new SampleContainerPojo(1, "Test 1", sample1);
		sampleContainer1 = mockSampleService1.save(sampleContainer1);
	}

	@Test
	void testMockEntityService1() {
		SampleContainerPojo value = mockSampleService1.find(sample1.getId());
		assertNotNull(value);
		assertEquals(sampleContainer1.getId(), value.getId());
		assertEquals(sampleContainer1.getNombre(), value.getNombre());
		List<SampleContainerPojo> list = mockSampleService1.findAll();
		assertNotNull(list);
		assertEquals(1, list.size());
		assertNotNull(list.get(0));
		assertEquals(sampleContainer1.getId(), list.get(0).getId());
		assertEquals(sampleContainer1.getNombre(), list.get(0).getNombre());
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
		assertEquals(sampleContainer1.getId(), list.get(0).getId());
		assertEquals(sampleContainer1.getNombre(), list.get(0).getNombre());
		value = mockSampleService1.update(value);
		assertNotNull(value);
		assertEquals(sampleContainer1.getId(), value.getId());
		assertEquals(sampleContainer1.getNombre(), value.getNombre());
	}

	@Test
	void testMockEntityService2() {
		final MockSampleService1 service = new MockSampleService1();
		final Path filePath = currentDir.resolve("data/sample1.csv");
		service.loadCsv(filePath.toAbsolutePath().toString());

		assertEquals(3, service.count());
		assertTrue(service.exists(Long.valueOf(1)));
		assertTrue(service.exists(Long.valueOf(2)));
		assertTrue(service.exists(Long.valueOf(3)));
		assertFalse(service.exists(Long.valueOf(0)));

	}

}
