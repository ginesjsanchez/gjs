package org.gjs.java.test.mock;

import static org.junit.jupiter.api.Assertions.assertEquals;
import static org.junit.jupiter.api.Assertions.assertFalse;
import static org.junit.jupiter.api.Assertions.assertNotNull;
import static org.junit.jupiter.api.Assertions.assertNull;
import static org.junit.jupiter.api.Assertions.assertTrue;

import java.nio.file.Path;
import java.util.List;
import java.util.Set;

import org.gjs.java.data.DataKey;
import org.gjs.java.data.ForeignKey;
import org.gjs.java.test.AbstractUnitTest;
import org.gjs.java.test.samples.pojos.SampleContainerPojo;
import org.gjs.java.test.samples.pojos.SampleContainerWithRenamePojo;
import org.gjs.java.test.samples.pojos.SamplePojo;
import org.junit.jupiter.api.Test;

class MockEntityDataManagerTest extends AbstractUnitTest {

    static class MockSampleDataManager extends MockEntityDataManager<SamplePojo, Long> {

        @Override
        protected Class<?> getClazz() {
            return SamplePojo.class;
        }

        @Override
        protected Class<?> getPKClazz() {
            return Long.class;
        }
    }

    static class MockSampleEntityDataManager extends MockEntityDataManager<SampleContainerPojo, Long> {

        @Override
        protected Class<?> getClazz() {
            return SampleContainerPojo.class;
        }

        @Override
        protected Class<?> getPKClazz() {
            return Long.class;
        }

    }

    static class MockSampleEntityWithRenameDataManager
            extends MockEntityDataManager<SampleContainerWithRenamePojo, Long> {

        @Override
        protected Class<?> getClazz() {
            return SampleContainerWithRenamePojo.class;
        }

        @Override
        protected Class<?> getPKClazz() {
            return Long.class;
        }

    }

    private MockSampleEntityDataManager mockSampleEntityDataManager;

    private SamplePojo sample1;
    private SampleContainerPojo sampleContainer1;

    @Override
    protected Class<?> getClazz() {
        return MockEntityDataManager.class;
    }

    @Override
    protected void initialize() throws Exception {
        mockSampleEntityDataManager = new MockSampleEntityDataManager();

        sample1 = new SamplePojo(1, "Test 1");
        sampleContainer1 = new SampleContainerPojo(10, "Test 1", sample1);
        mockSampleEntityDataManager.put(sampleContainer1);
    }

    @Test
    void testMockEntityDataManager1() {
        assertEquals(SampleContainerPojo.class, mockSampleEntityDataManager.getClazz());
        assertEquals(Long.class, mockSampleEntityDataManager.getPKClazz());
        assertFalse(mockSampleEntityDataManager.exists(Long.valueOf(0)));
        assertTrue(mockSampleEntityDataManager.exists(sampleContainer1.getId()));
        SampleContainerPojo value = mockSampleEntityDataManager.get(Long.valueOf(0));
        assertNull(value);
        value = mockSampleEntityDataManager.get(sampleContainer1.getId());
        assertNotNull(value);
        assertEquals(sampleContainer1.getId(), value.getId());
        assertEquals(sampleContainer1.getNombre(), value.getNombre());
        final List<SampleContainerPojo> list = mockSampleEntityDataManager.getAll();
        assertNotNull(list);
        assertEquals(1, list.size());
        assertNotNull(list.get(0));
        assertEquals(sampleContainer1.getId(), list.get(0).getId());
        assertEquals(sampleContainer1.getNombre(), list.get(0).getNombre());
        assertEquals(1, mockSampleEntityDataManager.size());
        final Set<Long> setPK = mockSampleEntityDataManager.getAllPK();
        assertNotNull(setPK);
        assertEquals(1, setPK.size());
        assertTrue(setPK.contains(sampleContainer1.getId()));
    }

    @Test
    void testMockEntityDataManager2() {
        assertEquals(1, mockSampleEntityDataManager.size());
        final SamplePojo value1 = new SamplePojo(2, "Test 2");
        final SampleContainerPojo containerValue1 = new SampleContainerPojo(11, "Test2", value1);
        mockSampleEntityDataManager.put(containerValue1);
        assertEquals(2, mockSampleEntityDataManager.size());
        assertNull(mockSampleEntityDataManager.get(Long.valueOf(1)));
        assertNotNull(mockSampleEntityDataManager.get(sampleContainer1.getId()));
        assertNotNull(mockSampleEntityDataManager.get(containerValue1.getId()));

        final SampleContainerPojo containerValue2 = new SampleContainerPojo(10, "Test3", value1);
        mockSampleEntityDataManager.put(containerValue2);
        assertEquals(2, mockSampleEntityDataManager.size());
        SampleContainerPojo value = mockSampleEntityDataManager.get(containerValue2.getId());
        assertNotNull(value);
        assertEquals(sampleContainer1.getId(), value.getId());
        assertEquals(containerValue2.getNombre(), value.getNombre());

        mockSampleEntityDataManager.remove(sampleContainer1.getId());
        assertEquals(1, mockSampleEntityDataManager.size());
        assertNull(mockSampleEntityDataManager.get(sampleContainer1.getId()));
        assertNotNull(mockSampleEntityDataManager.get(containerValue1.getId()));
        mockSampleEntityDataManager.put(containerValue2);
        assertEquals(2, mockSampleEntityDataManager.size());
        value = mockSampleEntityDataManager.get(containerValue2.getId());
        assertNotNull(value);
        assertEquals(containerValue2.getId(), value.getId());
        assertEquals(containerValue2.getNombre(), value.getNombre());

        mockSampleEntityDataManager.removeAll();
        assertEquals(0, mockSampleEntityDataManager.size());
    }

    @Test
    void testMockEntityDataManager3() {
        final MockSampleDataManager sampleEntityDataManager = new MockSampleDataManager();
        final Path filePath1 = currentDir.resolve("data/sample1.csv");
        final Path filePath2 = currentDir.resolve("data/containerSample1.csv");
        sampleEntityDataManager.loadCsv(filePath1.toAbsolutePath().toString());

        assertEquals(3, sampleEntityDataManager.size());
        assertNotNull(sampleEntityDataManager.get(Long.valueOf(1)));
        assertNotNull(sampleEntityDataManager.get(Long.valueOf(2)));
        assertNotNull(sampleEntityDataManager.get(Long.valueOf(3)));
        assertNull(sampleEntityDataManager.get(Long.valueOf(0)));

        final MockSampleEntityDataManager complexEntityDataManager = new MockSampleEntityDataManager();
        complexEntityDataManager.addRelation(new ForeignKey(new DataKey("sampleId"), new DataKey("id")),
                sampleEntityDataManager);
        complexEntityDataManager.loadCsv(filePath2.toAbsolutePath().toString());
        assertEquals(3, complexEntityDataManager.size());
        assertNotNull(complexEntityDataManager.get(Long.valueOf(1)));
        assertNotNull(complexEntityDataManager.get(Long.valueOf(2)));
        assertNotNull(complexEntityDataManager.get(Long.valueOf(3)));
        assertNull(complexEntityDataManager.get(Long.valueOf(0)));
        final SampleContainerPojo obj1 = complexEntityDataManager.get(Long.valueOf(1));
        final SampleContainerPojo obj2 = complexEntityDataManager.get(Long.valueOf(2));
        final SampleContainerPojo obj3 = complexEntityDataManager.get(Long.valueOf(3));
        assertNotNull(obj1.getSamplePojo());
        assertNull(obj2.getSamplePojo());
        assertNotNull(obj3.getSamplePojo());
        assertNotNull(obj1.getSamplePojo().getId());
        assertEquals(Long.valueOf(1), obj1.getSamplePojo().getId());
        assertNotNull(obj1.getSamplePojo().getNombre());
        assertNotNull(obj3.getSamplePojo().getId());
        assertEquals(Long.valueOf(1), obj3.getSamplePojo().getId());
        assertNotNull(obj3.getSamplePojo().getNombre());
    }

    @Test
    void testMockEntityDataManager4() {
        final MockSampleDataManager sampleEntityDataManager = new MockSampleDataManager();
        final Path filePath1 = currentDir.resolve("data/sample1.csv");
        final Path filePath2 = currentDir.resolve("data/containerSample1.csv");
        sampleEntityDataManager.loadCsv(filePath1.toAbsolutePath().toString());

        assertEquals(3, sampleEntityDataManager.size());
        assertNotNull(sampleEntityDataManager.get(Long.valueOf(1)));
        assertNotNull(sampleEntityDataManager.get(Long.valueOf(2)));
        assertNotNull(sampleEntityDataManager.get(Long.valueOf(3)));
        assertNull(sampleEntityDataManager.get(Long.valueOf(0)));

        final MockSampleEntityWithRenameDataManager complexEntityDataManager = new MockSampleEntityWithRenameDataManager();
        complexEntityDataManager.addRelation(new ForeignKey("data", new DataKey("sampleId"), new DataKey("id")),
                sampleEntityDataManager);
        complexEntityDataManager.loadCsv(filePath2.toAbsolutePath().toString());
        assertEquals(3, complexEntityDataManager.size());
        assertNotNull(complexEntityDataManager.get(Long.valueOf(1)));
        assertNotNull(complexEntityDataManager.get(Long.valueOf(2)));
        assertNotNull(complexEntityDataManager.get(Long.valueOf(3)));
        assertNull(complexEntityDataManager.get(Long.valueOf(0)));
        final SampleContainerWithRenamePojo obj1 = complexEntityDataManager.get(Long.valueOf(1));
        final SampleContainerWithRenamePojo obj2 = complexEntityDataManager.get(Long.valueOf(2));
        final SampleContainerWithRenamePojo obj3 = complexEntityDataManager.get(Long.valueOf(3));
        assertNotNull(obj1.getData());
        assertNull(obj2.getData());
        assertNotNull(obj3.getData());
        assertNotNull(obj1.getData().getId());
        assertEquals(Long.valueOf(1), obj1.getData().getId());
        assertNotNull(obj1.getData().getNombre());
        assertNotNull(obj3.getData().getId());
        assertEquals(Long.valueOf(1), obj3.getData().getId());
        assertNotNull(obj3.getData().getNombre());
    }

}
