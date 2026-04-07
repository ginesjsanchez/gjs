package org.gjs.java.test.mock;

import static org.junit.jupiter.api.Assertions.assertEquals;
import static org.junit.jupiter.api.Assertions.assertNotNull;

import java.util.List;

import org.gjs.java.test.AbstractUnitTest;
import org.gjs.java.test.samples.pojos.SampleContainerPojo;
import org.gjs.java.test.samples.pojos.SamplePojo;
import org.gjs.java.test.samples.pojos.SamplePojoFilter;
import org.junit.jupiter.api.Test;

class MockSimplePKEntityFromRepositoryServiceTest extends AbstractUnitTest {

	static class MockSampleRepository extends MockRepository<SamplePojo, Long> {
	}

	static class MockSampleService
			extends MockSimplePKEntityFromRepositoryService<SampleContainerPojo, SamplePojo, SamplePojoFilter> {

		public MockSampleService(MockSampleRepository mockRepository) {
			super(mockRepository);
		}

		@Override
		protected SampleContainerPojo entityToDto(SamplePojo entity) {
			return new SampleContainerPojo(entity.getId(), entity.getNombre(), null);
		}

	}

	private MockSampleRepository mockSampleRepository;
	private MockSampleService mockSampleService;

	private SamplePojo sample1;
	private SampleContainerPojo sampleContainer1;

	@Override
	protected Class<?> getClazz() {
		return MockEntityFromRepositoryService.class;
	}

	@Override
	protected void initialize() throws Exception {
		mockSampleRepository = new MockSampleRepository();

		sample1 = new SamplePojo(1, "Test B");
		sampleContainer1 = new SampleContainerPojo(1, "Test 1", sample1);
		sample1 = mockSampleRepository.save(sample1);

		mockSampleService = new MockSampleService(mockSampleRepository);

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
		filter.setNombre(value.getNombre());
		assertEquals(1, mockSampleService.count(filter));
		list = mockSampleService.filter(0, 10, "nombre", 1, filter);
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

}
