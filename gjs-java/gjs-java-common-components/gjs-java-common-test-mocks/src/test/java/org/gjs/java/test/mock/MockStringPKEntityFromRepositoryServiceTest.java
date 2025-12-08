package org.gjs.java.test.mock;

import static org.junit.jupiter.api.Assertions.assertEquals;
import static org.junit.jupiter.api.Assertions.assertNotNull;

import java.util.List;

import org.gjs.java.test.AbstractUnitTest;
import org.gjs.java.test.samples.pojos.SamplePojoFilter;
import org.gjs.java.test.samples.pojos.SampleStringIdPojo;
import org.junit.jupiter.api.Test;

class MockStringPKEntityFromRepositoryServiceTest extends AbstractUnitTest {

	static class MockSampleRepository extends MockRepository<SampleStringIdPojo, String> {
	}

	static class MockSampleService
			extends MockStringPKEntityFromRepositoryService<SampleStringIdPojo, SampleStringIdPojo, SamplePojoFilter> {

		public MockSampleService(MockSampleRepository mockRepository) {
			super(mockRepository);
		}

		@Override
		protected SampleStringIdPojo entityToDto(SampleStringIdPojo entity) {
			return new SampleStringIdPojo(entity.getId(), entity.getNombre());
		}

	}

	private MockSampleRepository mockSampleRepository;
	private MockSampleService mockSampleService;

	private SampleStringIdPojo sample1;
	private SampleStringIdPojo sample2;

	@Override
	protected Class<?> getClazz() {
		return MockEntityFromRepositoryService.class;
	}

	@Override
	protected void initialize() throws Exception {
		mockSampleRepository = new MockSampleRepository();

		sample1 = new SampleStringIdPojo("1", "Test B");
		sample1 = mockSampleRepository.save(sample1);

		mockSampleService = new MockSampleService(mockSampleRepository);

		sample2 = new SampleStringIdPojo("2", "Test 1");
		sample2 = mockSampleService.save(sample2);
	}

	@Test
	void testMockEntityService1() {
		SampleStringIdPojo value = mockSampleService.find(sample1.getId());
		assertNotNull(value);
		assertEquals(sample1.getId(), value.getId());
		assertEquals(sample1.getNombre(), value.getNombre());
		value = mockSampleService.find(sample2.getId());
		assertNotNull(value);
		assertEquals(sample2.getId(), value.getId());
		assertEquals(sample2.getNombre(), value.getNombre());
		List<SampleStringIdPojo> list = mockSampleService.findAll();
		assertNotNull(list);
		assertEquals(2, list.size());
		assertNotNull(list.get(0));
		assertEquals(sample1.getId(), list.get(0).getId());
		assertEquals(sample1.getNombre(), list.get(0).getNombre());
		assertNotNull(list.get(1));
		assertEquals(sample2.getId(), list.get(1).getId());
		assertEquals(sample2.getNombre(), list.get(1).getNombre());
		assertEquals(2, mockSampleService.count());
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
		assertEquals(sample2.getId(), list.get(0).getId());
		assertEquals(sample2.getNombre(), list.get(0).getNombre());
		value = mockSampleService.update(value);
		assertNotNull(value);
		assertEquals(sample2.getId(), value.getId());
		assertEquals(sample2.getNombre(), value.getNombre());
	}

}
