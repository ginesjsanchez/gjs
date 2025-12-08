package org.gjs.java.test.mock;

import static org.junit.jupiter.api.Assertions.assertEquals;
import static org.junit.jupiter.api.Assertions.assertNotNull;

import java.util.List;

import org.gjs.java.test.AbstractUnitTest;
import org.gjs.java.test.samples.pojos.SampleContainerPojo;
import org.gjs.java.test.samples.pojos.SamplePojo;
import org.gjs.java.test.samples.pojos.SamplePojoFilter;
import org.junit.jupiter.api.Test;

class MockEntityFromRepositoryServiceTest extends AbstractUnitTest {

	static class MockSampleRepository extends MockRepository<SamplePojo, Long> {

		@Override
		protected Class<?> getClazz() {
			return SamplePojo.class;
		}

		@Override
		protected Class<?> getPKClazz() {
			return Long.class;
		}
	}

	static class MockSampleService
			extends MockEntityFromRepositoryService<SampleContainerPojo, Long, SamplePojo, Long, SamplePojoFilter> {

		public MockSampleService(MockSampleRepository mockRepository) {
			super(mockRepository);
		}

		@Override
		protected Class<?> getClazz() {
			return SampleContainerPojo.class;
		}

		@Override
		protected Class<?> getPKClazz() {
			return Long.class;
		}

		@Override
		protected SampleContainerPojo entityToDto(SamplePojo entity) {
			return new SampleContainerPojo(entity.getId(), entity.getNombre(), entity);
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
		SamplePojoFilter filter = new SamplePojoFilter();
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
		filter = new SamplePojoFilter();
		final byte[] data = mockSampleService.export("id,nombre", "nombre", 1, filter);
		assertNotNull(data);
		logger.info("Data={}", data);
		final String text1 = new String(data);
		logger.info("Text 1={}", text1);
		final String text2 = (String) mockSampleService.customExport("id,nombre", "nombre", 1, filter);
		assertNotNull(text2);
		logger.info("Data={}", data);
		assertEquals(text1, text2);
	}

}
