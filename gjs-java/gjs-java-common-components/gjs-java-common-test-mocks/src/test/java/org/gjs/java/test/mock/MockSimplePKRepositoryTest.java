package org.gjs.java.test.mock;

import static org.junit.jupiter.api.Assertions.assertEquals;
import static org.junit.jupiter.api.Assertions.assertFalse;
import static org.junit.jupiter.api.Assertions.assertNotNull;
import static org.junit.jupiter.api.Assertions.assertNull;
import static org.junit.jupiter.api.Assertions.assertTrue;
import static org.junit.jupiter.api.Assertions.fail;

import java.nio.file.Path;
import java.util.ArrayList;
import java.util.List;
import java.util.Optional;

import org.gjs.java.idgenerator.IdGenerator;
import org.gjs.java.idgenerator.SequenceIdGenerator;
import org.gjs.java.test.AbstractUnitTest;
import org.gjs.java.test.samples.pojos.SampleContainerPojo;
import org.gjs.java.test.samples.pojos.SamplePojo;
import org.junit.jupiter.api.Test;
import org.springframework.data.domain.Example;
import org.springframework.data.domain.Page;
import org.springframework.data.domain.PageRequest;
import org.springframework.data.domain.Pageable;
import org.springframework.data.domain.Sort;
import org.springframework.data.jpa.domain.Specification;

import jakarta.persistence.EntityNotFoundException;

class MockSimplePKRepositoryTest extends AbstractUnitTest {

	class MockSampleRepository extends MockSimplePKRepository<SamplePojo> {

		@Override
		protected Class<?> getClazz() {
			return SamplePojo.class;
		}

		public Optional<SamplePojo> findByNombre(String nombre) {
			return findOneByField("nombre", nombre);
		}

	}

	class MockSampleContainerRepository extends MockRepository<SampleContainerPojo, Long> {

		IdGenerator<Long> idGenerator = new SequenceIdGenerator();

		@Override
		protected boolean autogenerateId() {
			return true;
		}

		@Override
		protected IdGenerator<Long> getGeneratorId() {
			return idGenerator;
		}

		@Override
		protected Class<?> getClazz() {
			return SampleContainerPojo.class;
		}

		@Override
		protected Class<?> getPKClazz() {
			return Long.class;
		}

		public Optional<SampleContainerPojo> findByNombre(String nombre) {
			return findOneByField("nombre", nombre);
		}

		public List<SampleContainerPojo> findBySampleId(Long id) {
			return findByField("samplePojo.id", id);
		}

	}

	static class MockSampleAutoIdDataManager extends MockSimplePKRepository<SamplePojo> {

		private final IdGenerator<Long> idGenerator = new SequenceIdGenerator();

		@Override
		protected Class<?> getClazz() {
			return SamplePojo.class;
		}

		@Override
		protected boolean autogenerateId() {
			return true;
		}

		@Override
		protected IdGenerator<Long> getGeneratorId() {
			return idGenerator;
		}

	}

	private MockSampleRepository mockSampleRepository;
	private MockSampleContainerRepository mockSampleContainerRepository;

	private SamplePojo sample1;
	private SampleContainerPojo sampleContainer1;
	private SamplePojo sample2;
	private SampleContainerPojo sampleContainer2;

	@Override
	protected Class<?> getClazz() {
		return MockRepository.class;
	}

	@Override
	protected void initialize() throws Exception {
		mockSampleRepository = new MockSampleRepository();
		mockSampleContainerRepository = new MockSampleContainerRepository();

		sample1 = new SamplePojo(1, "Test B");
		sampleContainer1 = new SampleContainerPojo(1, "Test 1", sample1);
		sample1 = mockSampleRepository.save(sample1);
		sampleContainer1 = mockSampleContainerRepository.save(sampleContainer1);
		sample2 = new SamplePojo(2, "Test A");
		sample2 = mockSampleRepository.save(sample2);
		sampleContainer2 = new SampleContainerPojo(2, "Test 2", sample2);
		sampleContainer2 = mockSampleContainerRepository.save(sampleContainer2);
	}

	@Test
	void testMockRepository1() {
		assertEquals(2, mockSampleRepository.count());
		assertTrue(mockSampleRepository.existsById(sample1.getId()));
		assertFalse(mockSampleRepository.existsById(Long.valueOf(0)));

		SamplePojo value = null;
		try {
			value = mockSampleRepository.getReferenceById(Long.valueOf(0));
			fail("No deberia pasar por aqui");
		} catch (final EntityNotFoundException e) {
			assertNotNull(e);
		}
		try {
			value = mockSampleRepository.getReferenceById(sample1.getId());
		} catch (final EntityNotFoundException e) {
			fail("No deberia recibir la excepcion");
		}
		assertNotNull(value);
		assertEquals(sample1.getId(), value.getId());
		assertEquals(sample1.getNombre(), value.getNombre());

		Optional<SamplePojo> optional = mockSampleRepository.findById(Long.valueOf(0));
		assertNotNull(optional);
		assertFalse(optional.isPresent());
		optional = mockSampleRepository.findById(sample1.getId());
		assertNotNull(optional);
		assertTrue(optional.isPresent());
		assertNotNull(optional.get());
		assertEquals(sample1.getId(), optional.get().getId());
		assertEquals(sample1.getNombre(), value.getNombre());

		optional = mockSampleRepository.findByNombre("Inexistente");
		assertNotNull(optional);
		assertFalse(optional.isPresent());
		optional = mockSampleRepository.findByNombre(sample2.getNombre());
		assertNotNull(optional);
		assertTrue(optional.isPresent());
		assertNotNull(optional.get());
		assertEquals(sample2.getId(), optional.get().getId());

		List<SamplePojo> list = mockSampleRepository.findAll();
		assertNotNull(list);
		assertEquals(2, list.size());
		assertNotNull(list.get(0));
		assertEquals(sample1.getId(), list.get(0).getId());
		assertEquals(sample1.getNombre(), list.get(0).getNombre());
		assertNotNull(list.get(1));
		assertEquals(sample2.getId(), list.get(1).getId());
		assertEquals(sample2.getNombre(), list.get(1).getNombre());

		final Sort sort = Sort.by("nombre").ascending();
		list = mockSampleRepository.findAll(sort);
		assertNotNull(list);
		assertEquals(2, list.size());
		assertNotNull(list.get(0));
		assertNotNull(list.get(1));
		assertEquals(sample2.getId(), list.get(0).getId());
		assertEquals(sample1.getId(), list.get(1).getId());

		final List<Long> ids = new ArrayList<>();
		ids.add(sample1.getId());
		ids.add(sample2.getId());
		ids.add(Long.valueOf(9));
		list = mockSampleRepository.findAllById(ids);
		assertNotNull(list);
		assertEquals(2, list.size());
		assertNotNull(list.get(0));
		assertEquals(sample1.getId(), list.get(0).getId());
		assertEquals(sample1.getNombre(), list.get(0).getNombre());
		assertNotNull(list.get(1));
		assertEquals(sample2.getId(), list.get(1).getId());
		assertEquals(sample2.getNombre(), list.get(1).getNombre());

		final Pageable pageable = PageRequest.of(0, 5, sort);
		Page<SamplePojo> page = mockSampleRepository.findAll(pageable);
		assertNotNull(page);
		assertEquals(2, page.getNumberOfElements());
		assertEquals(0, page.getNumber());
		assertEquals(1, page.getTotalPages());
		list = page.getContent();
		assertNotNull(list);
		assertNotNull(list.get(0));
		assertNotNull(list.get(1));
		assertEquals(sample2.getId(), list.get(0).getId());
		assertEquals(sample1.getId(), list.get(1).getId());

		final SamplePojo filter = new SamplePojo(0, "%B%");
		mockSampleRepository.setFilter(filter);
		final Specification<SamplePojo> spec = Specification.allOf();
		page = mockSampleRepository.findAll(spec, pageable);
		assertNotNull(page);
		assertEquals(1, page.getNumberOfElements());
		assertEquals(0, page.getNumber());
		assertEquals(1, page.getTotalPages());
		list = page.getContent();
		assertNotNull(list);
		assertNotNull(list.get(0));
		assertEquals(sample1.getId(), list.get(0).getId());

		final SamplePojo prueba = new SamplePojo();
		final Example<SamplePojo> example = Example.of(prueba);
		page = mockSampleRepository.findAll(example, pageable);
		assertNotNull(page);
		assertEquals(1, page.getNumberOfElements());
		assertEquals(0, page.getNumber());
		assertEquals(1, page.getTotalPages());
		list = page.getContent();
		assertNotNull(list);
		assertNotNull(list.get(0));
		assertEquals(sample1.getId(), list.get(0).getId());

		mockSampleRepository.deleteById(sample1.getId());
		assertEquals(1, mockSampleRepository.count());
		assertTrue(mockSampleRepository.existsById(sample2.getId()));
		assertFalse(mockSampleRepository.existsById(sample1.getId()));

		final List<SamplePojo> eliminar = new ArrayList<>();
		eliminar.add(sample1);
		eliminar.add(sample2);
		eliminar.add(new SamplePojo(0, ""));
		mockSampleRepository.deleteAll(eliminar);
		assertEquals(0, mockSampleRepository.count());
		assertFalse(mockSampleRepository.existsById(sample2.getId()));
		assertFalse(mockSampleRepository.existsById(sample1.getId()));
	}

	@Test
	void testMockRepository2() {
		assertEquals(2, mockSampleContainerRepository.count());
		assertTrue(mockSampleContainerRepository.existsById(sample1.getId()));
		assertFalse(mockSampleContainerRepository.existsById(Long.valueOf(0)));

		SampleContainerPojo value = null;
		try {
			value = mockSampleContainerRepository.getReferenceById(Long.valueOf(0));
			fail("No deberia pasar por aqui");
		} catch (final EntityNotFoundException e) {
			assertNotNull(e);
		}
		try {
			value = mockSampleContainerRepository.getReferenceById(sampleContainer1.getId());
		} catch (final EntityNotFoundException e) {
			fail("No deberia recibir la excepcion");
		}
		assertNotNull(value);
		assertEquals(sampleContainer1.getId(), value.getId());
		assertEquals(sampleContainer1.getNombre(), value.getNombre());

		Optional<SampleContainerPojo> optional = mockSampleContainerRepository.findById(Long.valueOf(0));
		assertNotNull(optional);
		assertFalse(optional.isPresent());

		optional = mockSampleContainerRepository.findById(sample1.getId());
		assertNotNull(optional);
		assertTrue(optional.isPresent());
		assertNotNull(optional.get());
		assertEquals(sampleContainer1.getId(), optional.get().getId());
		assertEquals(sampleContainer1.getNombre(), value.getNombre());

		optional = mockSampleContainerRepository.findByNombre("Inexistente");
		assertNotNull(optional);
		assertFalse(optional.isPresent());
		optional = mockSampleContainerRepository.findByNombre(sampleContainer2.getNombre());
		assertNotNull(optional);
		assertTrue(optional.isPresent());
		assertNotNull(optional.get());
		assertEquals(sampleContainer2.getId(), optional.get().getId());

		List<SampleContainerPojo> list = mockSampleContainerRepository.findAll();
		assertNotNull(list);
		assertEquals(2, list.size());
		assertNotNull(list.get(0));
		assertEquals(sampleContainer1.getId(), list.get(0).getId());
		assertEquals(sampleContainer1.getNombre(), list.get(0).getNombre());
		assertNotNull(list.get(1));
		assertEquals(sampleContainer2.getId(), list.get(1).getId());
		assertEquals(sampleContainer2.getNombre(), list.get(1).getNombre());

		list = mockSampleContainerRepository.findBySampleId(Long.valueOf(0));
		assertNotNull(list);
		assertEquals(0, list.size());
		list = mockSampleContainerRepository.findBySampleId(sample1.getId());
		assertNotNull(list);
		assertEquals(1, list.size());
		assertNotNull(list.get(0));
		assertEquals(sampleContainer1.getId(), list.get(0).getId());
		assertEquals(sampleContainer1.getNombre(), list.get(0).getNombre());

		final Sort sort = Sort.by("nombre").descending();
		list = mockSampleContainerRepository.findAll(sort);
		assertNotNull(list);
		assertEquals(2, list.size());
		assertNotNull(list.get(0));
		assertNotNull(list.get(1));
		assertEquals(sample2.getId(), list.get(0).getId());
		assertEquals(sample1.getId(), list.get(1).getId());

		list = mockSampleContainerRepository.findBySampleId(sample1.getId());
		assertNotNull(list);
		assertEquals(1, list.size());
		assertNotNull(list.get(0));
		assertEquals(sampleContainer1.getId(), list.get(0).getId());
		assertEquals(sampleContainer1.getNombre(), list.get(0).getNombre());
		assertEquals(sample1.getId(), list.get(0).getSamplePojo().getId());

		final List<Long> ids = new ArrayList<>();
		ids.add(sampleContainer1.getId());
		ids.add(sampleContainer2.getId());
		ids.add(Long.valueOf(9));
		list = mockSampleContainerRepository.findAllById(ids);
		assertNotNull(list);
		assertEquals(2, list.size());
		assertNotNull(list.get(0));
		assertEquals(sampleContainer1.getId(), list.get(0).getId());
		assertEquals(sampleContainer1.getNombre(), list.get(0).getNombre());
		assertNotNull(list.get(1));
		assertEquals(sampleContainer2.getId(), list.get(1).getId());
		assertEquals(sampleContainer2.getNombre(), list.get(1).getNombre());

		mockSampleContainerRepository.delete(sampleContainer1);
		assertEquals(1, mockSampleContainerRepository.count());
		assertTrue(mockSampleContainerRepository.existsById(sample2.getId()));
		assertFalse(mockSampleContainerRepository.existsById(sample1.getId()));

		mockSampleContainerRepository.deleteAll();
		assertEquals(0, mockSampleContainerRepository.count());
		assertFalse(mockSampleContainerRepository.existsById(sample2.getId()));

		final List<SampleContainerPojo> nuevos = new ArrayList<>();
		nuevos.add(sampleContainer1);
		nuevos.add(sampleContainer2);
		list = mockSampleContainerRepository.saveAll(nuevos);
		assertNotNull(list);
		assertEquals(2, list.size());
		assertNotNull(list.get(0));
		assertEquals(sampleContainer1.getId(), list.get(0).getId());
		assertEquals(sampleContainer1.getNombre(), list.get(0).getNombre());
		assertNotNull(list.get(1));
		assertEquals(sampleContainer2.getId(), list.get(1).getId());
		assertEquals(sampleContainer2.getNombre(), list.get(1).getNombre());

		SampleContainerPojo filter = new SampleContainerPojo(0, "%2%", null);
		mockSampleContainerRepository.setFilter(filter);
		final Specification<SampleContainerPojo> spec = Specification.allOf();
		assertEquals(1, mockSampleContainerRepository.count(spec));
		optional = mockSampleContainerRepository.findOne(spec);
		assertNotNull(optional);
		assertTrue(optional.isPresent());
		assertNotNull(optional.get());
		assertEquals(sampleContainer2.getId(), optional.get().getId());

		list = mockSampleContainerRepository.findAll(spec);
		assertNotNull(list);
		assertEquals(1, list.size());
		assertNotNull(list.get(0));
		assertEquals(sampleContainer2.getId(), list.get(0).getId());

		list = mockSampleContainerRepository.findAll(spec, sort);
		assertNotNull(list);
		assertEquals(1, list.size());
		assertNotNull(list.get(0));
		assertEquals(sampleContainer2.getId(), list.get(0).getId());

		final SampleContainerPojo prueba = new SampleContainerPojo();
		final Example<SampleContainerPojo> example = Example.of(prueba);
		assertEquals(1, mockSampleContainerRepository.count(example));
		optional = mockSampleContainerRepository.findOne(example);
		assertNotNull(optional);
		assertTrue(optional.isPresent());
		assertNotNull(optional.get());
		assertEquals(sampleContainer2.getId(), optional.get().getId());

		list = mockSampleContainerRepository.findAll(example);
		assertNotNull(list);
		assertEquals(1, list.size());
		assertNotNull(list.get(0));
		assertEquals(sampleContainer2.getId(), list.get(0).getId());

		list = mockSampleContainerRepository.findAll(example, sort);
		assertNotNull(list);
		assertEquals(1, list.size());
		assertNotNull(list.get(0));
		assertEquals(sampleContainer2.getId(), list.get(0).getId());

		filter = new SampleContainerPojo(0, "%X%", null);
		mockSampleContainerRepository.setFilter(filter);
		assertEquals(0, mockSampleContainerRepository.count(spec));
		optional = mockSampleContainerRepository.findOne(spec);
		assertNotNull(optional);
		assertFalse(optional.isPresent());

		list = mockSampleContainerRepository.findAll(spec);
		assertNotNull(list);
		assertEquals(0, list.size());

		assertEquals(0, mockSampleContainerRepository.count(example));
		assertNotNull(optional);
		assertFalse(optional.isPresent());

		list = mockSampleContainerRepository.findAll(example);
		assertNotNull(list);
		assertEquals(0, list.size());

	}

	@Test
	void testMockRepository3() {
		final MockSampleRepository repository = new MockSampleRepository();
		final Path filePath = currentDir.resolve("data/sample1.csv");
		repository.loadCsv(filePath.toAbsolutePath().toString());

		assertEquals(3, repository.count());
		assertTrue(repository.existsById(Long.valueOf(1)));
		assertTrue(repository.existsById(Long.valueOf(2)));
		assertTrue(repository.existsById(Long.valueOf(3)));
		assertFalse(repository.existsById(Long.valueOf(0)));

	}

	@Test
	void testMockRepository4() {
		final MockSampleAutoIdDataManager repository = new MockSampleAutoIdDataManager();
		final Path filePath1 = currentDir.resolve("data/sample1NoId.csv");
		repository.loadCsv(filePath1.toAbsolutePath().toString());

		assertEquals(3, repository.size());
		assertNotNull(repository.get(Long.valueOf(1)));
		assertNotNull(repository.get(Long.valueOf(2)));
		assertNotNull(repository.get(Long.valueOf(3)));
		assertNull(repository.get(Long.valueOf(0)));

	}

}
