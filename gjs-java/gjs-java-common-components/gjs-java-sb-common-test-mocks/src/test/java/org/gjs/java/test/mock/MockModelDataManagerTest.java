package org.gjs.java.test.mock;

import static org.junit.jupiter.api.Assertions.assertFalse;
import static org.junit.jupiter.api.Assertions.assertNotNull;
import static org.junit.jupiter.api.Assertions.assertNull;
import static org.junit.jupiter.api.Assertions.assertTrue;
import static org.junit.jupiter.api.Assertions.fail;

import org.gjs.java.test.AbstractUnitTest;
import org.gjs.java.test.samples.pojos.SampleBoolean;
import org.gjs.java.test.samples.pojos.SampleContainerPojo;
import org.gjs.java.test.samples.pojos.SamplePojo;
import org.junit.jupiter.api.Test;

class MockModelDataManagerTest extends AbstractUnitTest {

    static class MockSampleEntityDataManager extends MockEntityDataManager<SamplePojo, Long> {

        @Override
        protected Class<?> getClazz() {
            return SamplePojo.class;
        }

        @Override
        protected Class<?> getPKClazz() {
            return Long.class;
        }

    }

    static class MockSampleContainerEntityDataManager extends MockEntityDataManager<SampleContainerPojo, Long> {

        @Override
        protected Class<?> getClazz() {
            return SampleContainerPojo.class;
        }

        @Override
        protected Class<?> getPKClazz() {
            return Long.class;
        }

    }

    MockModelDataManager mockModelDataManager;

    @Override
    protected Class<?> getClazz() {
        return MockModelDataManager.class;
    }

    @Override
    protected void initialize() throws Exception {
        final MockSampleEntityDataManager mockSampleEntityDataManager = new MockSampleEntityDataManager();
        final MockSampleContainerEntityDataManager mockSampleContainerEntityDataManager = new MockSampleContainerEntityDataManager();

        mockModelDataManager = new MockModelDataManager();
        mockModelDataManager.addEntityDataManager(mockSampleEntityDataManager);
        mockModelDataManager.addEntityDataManager(mockSampleContainerEntityDataManager);
    }

    @Test
    void testMockModelDataManager1() {
        try {
            assertNotNull(mockModelDataManager.getEntityDataManager(SamplePojo.class));
            assertNotNull(mockModelDataManager.getEntityDataManager(SampleContainerPojo.class));
            assertTrue(mockModelDataManager.manage(SamplePojo.class));
            assertTrue(mockModelDataManager.manage(SampleContainerPojo.class));
            assertFalse(mockModelDataManager.manage(Long.class));
            mockModelDataManager.addEntityDataManager(null);
            mockModelDataManager.refreshForeignCollections();
            final SamplePojo sample1 = new SamplePojo(1, "Test 1");
            ((MockSampleEntityDataManager) mockModelDataManager.getEntityDataManager(SamplePojo.class)).put(sample1);
            final SampleContainerPojo sampleContainer1 = new SampleContainerPojo(10, "Test 1",
                    ((MockSampleEntityDataManager) mockModelDataManager.getEntityDataManager(SamplePojo.class))
                            .get(sample1.getId()));
            ((MockSampleContainerEntityDataManager) mockModelDataManager
                    .getEntityDataManager(SampleContainerPojo.class)).put(sampleContainer1);

        } catch (final Exception e) {
            logger.error(e.getMessage());
            fail("No se esperaba excepcion");
        }
    }

    @Test
    void testMockModelDataManager2() {
        try {
            final SamplePojo sample1 = new SamplePojo(2, "Test 2");
            final SampleContainerPojo sampleContainer1 = new SampleContainerPojo(2, "Test 2", sample1);

            SamplePojo sample2 = (SamplePojo) mockModelDataManager.get(sample1.getId(), SamplePojo.class);
            SampleContainerPojo sampleContainer2 = (SampleContainerPojo) mockModelDataManager
                    .get(sampleContainer1.getId(), SampleContainerPojo.class);
            assertNull(sample2);
            assertNull(sampleContainer2);

            mockModelDataManager.put(sample1);
            mockModelDataManager.put(sampleContainer1);
            sample2 = (SamplePojo) mockModelDataManager.get(sample1.getId(), SamplePojo.class);
            sampleContainer2 = (SampleContainerPojo) mockModelDataManager.get(sampleContainer1.getId(),
                    SampleContainerPojo.class);
            assertNotNull(sample2);
            assertNotNull(sampleContainer2);

            sample2 = (SamplePojo) mockModelDataManager.get(sample1.getId(), SamplePojo.class.getCanonicalName());
            sampleContainer2 = (SampleContainerPojo) mockModelDataManager.get(sampleContainer1.getId(),
                    SampleContainerPojo.class.getCanonicalName());
            assertNotNull(sample2);
            assertNotNull(sampleContainer2);

            sample2 = (SamplePojo) mockModelDataManager.get(sample1.getId(), SampleBoolean.class);
            assertNull(sample2);

        } catch (final Exception e) {
            logger.error(e.getMessage());
            fail("No se esperaba excepcion");
        }
    }

}
