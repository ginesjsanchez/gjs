package org.gjs.java.test.mock;

import static org.junit.jupiter.api.Assertions.assertEquals;
import static org.junit.jupiter.api.Assertions.assertFalse;
import static org.junit.jupiter.api.Assertions.assertNotNull;
import static org.junit.jupiter.api.Assertions.assertTrue;
import static org.junit.jupiter.api.Assertions.fail;

import java.nio.file.Path;
import java.util.ArrayList;
import java.util.List;
import java.util.Optional;

import org.gjs.java.test.AbstractUnitTest;
import org.gjs.java.test.samples.pojos.SampleStringIdPojo;
import org.junit.jupiter.api.Test;
import org.springframework.data.domain.Example;
import org.springframework.data.domain.Page;
import org.springframework.data.domain.PageRequest;
import org.springframework.data.domain.Pageable;
import org.springframework.data.domain.Sort;
import org.springframework.data.jpa.domain.Specification;

import jakarta.persistence.EntityNotFoundException;

class MockStringPKRepositoryTest extends AbstractUnitTest {

    class MockSampleRepository extends MockStringPKRepository<SampleStringIdPojo> {

        @Override
        protected Class<?> getClazz() {
            return SampleStringIdPojo.class;
        }

        public Optional<SampleStringIdPojo> findByNombre(String nombre) {
            return findOneByField("nombre", nombre);
        }

    }

    private MockSampleRepository mockSampleRepository;

    private SampleStringIdPojo sample1;
    private SampleStringIdPojo sample2;

    @Override
    protected Class<?> getClazz() {
        return MockRepository.class;
    }

    @Override
    protected void initialize() throws Exception {
        mockSampleRepository = new MockSampleRepository();

        sample1 = new SampleStringIdPojo("1", "Test B");
        sample1 = mockSampleRepository.save(sample1);
        sample2 = new SampleStringIdPojo("2", "Test A");
        sample2 = mockSampleRepository.save(sample2);
    }

    @Test
    void testMockRepository1() {
        assertEquals(2, mockSampleRepository.count());
        assertTrue(mockSampleRepository.existsById(sample1.getId()));
        assertFalse(mockSampleRepository.existsById("0"));

        SampleStringIdPojo value = null;
        try {
            value = mockSampleRepository.getReferenceById("0");
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

        Optional<SampleStringIdPojo> optional = mockSampleRepository.findById("0");
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

        List<SampleStringIdPojo> list = mockSampleRepository.findAll();
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

        final List<String> ids = new ArrayList<>();
        ids.add(sample1.getId());
        ids.add(sample2.getId());
        ids.add("9");
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
        Page<SampleStringIdPojo> page = mockSampleRepository.findAll(pageable);
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

        final SampleStringIdPojo filter = new SampleStringIdPojo("%", "%B%");
        mockSampleRepository.setFilter(filter);
        final Specification<SampleStringIdPojo> spec = Specification.where(null);
        page = mockSampleRepository.findAll(spec, pageable);
        assertNotNull(page);
        assertEquals(1, page.getNumberOfElements());
        assertEquals(0, page.getNumber());
        assertEquals(1, page.getTotalPages());
        list = page.getContent();
        assertNotNull(list);
        assertNotNull(list.get(0));
        assertEquals(sample1.getId(), list.get(0).getId());

        final SampleStringIdPojo prueba = new SampleStringIdPojo();
        final Example<SampleStringIdPojo> example = Example.of(prueba);
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

        final List<SampleStringIdPojo> eliminar = new ArrayList<>();
        eliminar.add(sample1);
        eliminar.add(sample2);
        eliminar.add(new SampleStringIdPojo("0", ""));
        mockSampleRepository.deleteAll(eliminar);
        assertEquals(0, mockSampleRepository.count());
        assertFalse(mockSampleRepository.existsById(sample2.getId()));
        assertFalse(mockSampleRepository.existsById(sample1.getId()));
    }

    @Test
    void testMockRepository2() {
        final MockSampleRepository repository = new MockSampleRepository();
        final Path filePath = currentDir.resolve("data/sample1.csv");
        repository.loadCsv(filePath.toAbsolutePath().toString());

        assertEquals(3, repository.count());
        assertTrue(repository.existsById("1"));
        assertTrue(repository.existsById("2"));
        assertTrue(repository.existsById("3"));
        assertFalse(repository.existsById("9"));

    }
}
