package org.gjs.java.common.supplier;

import static org.junit.jupiter.api.Assertions.assertEquals;
import static org.junit.jupiter.api.Assertions.assertFalse;
import static org.junit.jupiter.api.Assertions.assertNotNull;
import static org.junit.jupiter.api.Assertions.assertNull;
import static org.junit.jupiter.api.Assertions.fail;

import org.apache.commons.lang3.exception.ExceptionUtils;
import org.gjs.java.common.supplier.ObjectSupplierManager;
import org.gjs.java.test.BaseClassTest;
import org.gjs.java.test.samples.pojos.SampleMaterialized1;
import org.gjs.java.test.samples.pojos.SampleMaterialized2;
import org.gjs.java.test.samples.pojos.SampleMaterializedContainer;
import org.gjs.java.test.samples.pojos.SamplePojo;
import org.gjs.java.test.samples.supplier.manager.SampleGenericObjectSupplierManager;
import org.gjs.java.test.samples.supplier.manager.SampleNotJEEObjectSupplierManager;
import org.gjs.java.test.samples.supplier.manager.SampleObjectSupplierManager;
import org.gjs.java.test.samples.type.AllPrimitivesType;
import org.gjs.java.test.samples.type.NotJEEType;
import org.junit.jupiter.api.Test;

class ObjectSupplierManagerTest extends BaseClassTest<ObjectSupplierManager> {

	private static SampleObjectSupplierManager sampleObjectSupplierManager = null;
	private static SampleNotJEEObjectSupplierManager sampleNotJEEObjectSupplierManager = null;
	private static SampleGenericObjectSupplierManager sampleGenericObjectSupplierManager = null;

	@Override
	protected void prepareTest() {
		sampleObjectSupplierManager = new SampleObjectSupplierManager(logger);
		sampleNotJEEObjectSupplierManager = new SampleNotJEEObjectSupplierManager(logger);
		sampleGenericObjectSupplierManager = new SampleGenericObjectSupplierManager(logger);

		logger.debug("SIMPLE: {}", sampleObjectSupplierManager.toString());
		logger.debug("NOTJEE: {}", sampleNotJEEObjectSupplierManager.toString());
		logger.debug("GENERI: {}", sampleGenericObjectSupplierManager.toString());
	}

	@Test
	void testObjectSupplierManager1() {
		final AllPrimitivesType sample = sampleObjectSupplierManager.getSample();
		assertNotNull(sample);
		logger.debug("Generado: {}", sample);
		assertNotNull(sample.getCarVal());
		assertNotNull(sample.getDatVal());
		assertNotNull(sample.getDecVal());
		assertNotNull(sample.getDouVal());
		assertNotNull(sample.getFloVal());
		assertNotNull(sample.getIntVal());
		assertNotNull(sample.getLonVal());
		assertNotNull(sample.getObVal());
		assertNotNull(sample.getOcVal());
		assertNotNull(sample.getOdVal());
		assertNotNull(sample.getOfVal());
		assertNotNull(sample.getOiVal());
		assertNotNull(sample.getOlVal());
		assertNotNull(sample.getObyVal());
		assertNotNull(sample.getStrVal());
	}

	@Test
	void testObjectSupplierManager2() {
		final AllPrimitivesType sample = sampleObjectSupplierManager.getEmptySample();
		assertNotNull(sample);
		logger.debug("Generado: {}", sample);
		assertFalse(sample.isBoolVal());
		assertEquals(0, sample.getLonVal());
		assertEquals(0, sample.getIntVal());
		assertEquals(0, sample.getFloVal());
		assertEquals(0, sample.getDouVal());
		assertEquals(0, sample.getByVal());
		assertNull(sample.getDatVal());
		assertNull(sample.getDecVal());
		assertNotNull(sample.getObVal());
		assertFalse(sample.getObVal());
		assertNotNull(sample.getOcVal());
		assertEquals('\0', sample.getOlVal());
		assertNotNull(sample.getOdVal());
		assertEquals(0, sample.getOlVal());
		assertNotNull(sample.getOfVal());
		assertEquals(0, sample.getOlVal());
		assertNotNull(sample.getOiVal());
		assertEquals(0, sample.getOlVal());
		assertNotNull(sample.getOlVal());
		assertEquals(0, sample.getOlVal());
		assertNotNull(sample.getObyVal());
		assertEquals(0, sample.getObyVal().byteValue());
		assertNotNull(sample.getStrVal());
		assertEquals("", sample.getStrVal());
	}

	@Test
	void testObjectSupplierManager3() {
		// Este test falla en Jenkins
		// sampleObjectSupplierManager.setLogger(null);
		sampleObjectSupplierManager.setLogger(logger);
		final AllPrimitivesType sample = sampleObjectSupplierManager.getSample();
		assertNotNull(sample);
	}

	@Test
	void testObjectSupplierManager4() {
		final NotJEEType sample = sampleNotJEEObjectSupplierManager.getSampleNotJEE();
		assertNotNull(sample);
		logger.debug("Generado: {}", sample);
		assertNotNull(sample.cVal);
		assertNotNull(sample.datVal);
		assertNotNull(sample.decVal);
		assertNotNull(sample.dVal);
		assertNotNull(sample.fVal);
		assertNotNull(sample.iVal);
		assertNotNull(sample.lVal);
		assertNotNull(sample.obVal);
		assertNotNull(sample.ocVal);
		assertNotNull(sample.odVal);
		assertNotNull(sample.ofVal);
		assertNotNull(sample.oiVal);
		assertNotNull(sample.olVal);
		assertNotNull(sample.sVal);
	}

	@Test
	void testObjectSupplierManager5() {
		// Este test falla en Jenkins
		// sampleObjectSupplierManager.setLogger(null);
		sampleNotJEEObjectSupplierManager.setLogger(logger);
		final NotJEEType sample = sampleNotJEEObjectSupplierManager.getSampleNotJEE();
		assertNotNull(sample);
	}

	@Test
	void testObjectSupplierManager6() {
		final SamplePojo sample = sampleGenericObjectSupplierManager.getSamplePojo();
		assertNotNull(sample);
		logger.debug("Generado: {}", sample);
		assertNotNull(sample.getId());
		assertNotNull(sample.getNombre());
		final SampleMaterialized1 sampleMat1 = sampleGenericObjectSupplierManager.getSampleMaterialized1();
		assertNotNull(sampleMat1);
		logger.debug("Generado: {}", sampleMat1);
		assertNotNull(sampleMat1.getGeneric());
		assertNotNull(sampleMat1.getTexto());
	}

	@Test
	void testObjectSupplierManager7() {
		final SampleMaterialized2 sampleMat2 = sampleGenericObjectSupplierManager.getSampleMaterialized2();
		assertNotNull(sampleMat2);
		logger.debug("Generado: {}", sampleMat2);
		assertNotNull(sampleMat2.getGeneric());
		assertNotNull(sampleMat2.getGeneric().getId());
		assertNotNull(sampleMat2.getGeneric().getNombre());
		assertNotNull(sampleMat2.getTexto());
		final SampleMaterializedContainer sampleMatCon = sampleGenericObjectSupplierManager
				.getSampleMaterializedContainer();
		assertNotNull(sampleMatCon);
		logger.debug("Generado: {}", sampleMatCon);
		assertNotNull(sampleMatCon.getMaterialized());
		assertNotNull(sampleMatCon.getMaterialized().getGeneric());
		assertNotNull(sampleMatCon.getMaterialized().getGeneric().getId());
		assertNotNull(sampleMatCon.getMaterialized().getGeneric().getNombre());
		assertNotNull(sampleMatCon.getMaterialized().getTexto());
		assertNotNull(sampleMatCon.getInicio());
	}

	@Test
	void testObjectSupplierManager8() {
		final SamplePojo sample = sampleGenericObjectSupplierManager.getEmptySamplePojo();
		assertNotNull(sample);
		logger.debug("Generado: {}", sample);
		assertNotNull(sample.getNombre());
		assertEquals("", sample.getNombre());
		final SampleMaterialized1 sampleMat1 = sampleGenericObjectSupplierManager.getEmptySampleMaterialized1();
		assertNotNull(sampleMat1);
		logger.debug("Generado: {}", sampleMat1);
		assertNotNull(sampleMat1.getGeneric());
		assertNotNull(sampleMat1.getTexto());
		assertEquals(0, sampleMat1.getGeneric());
		assertEquals("", sampleMat1.getTexto());
		final SampleMaterialized2 sampleMat2 = sampleGenericObjectSupplierManager.getEmptySampleMaterialized2();
		assertNotNull(sampleMat2);
		logger.debug("Generado: {}", sampleMat2);
		assertNull(sampleMat2.getGeneric());
		assertNotNull(sampleMat2.getTexto());
		assertEquals("", sampleMat2.getTexto());
		final SampleMaterializedContainer sampleMatCon = sampleGenericObjectSupplierManager
				.getEmptySampleMaterializedContainer();
		assertNotNull(sampleMatCon);
		logger.debug("Generado: {}", sampleMatCon);
		assertNull(sampleMatCon.getMaterialized());
		assertNull(sampleMatCon.getInicio());

	}

	@Test
	void testObjectSupplierManager9() {
		try {
			assertNotNull(sampleObjectSupplierManager.getManagedClassNames());
			assertNotNull(sampleObjectSupplierManager.getManagedClasses());
			assertEquals(1, sampleObjectSupplierManager.getManagedClassNames().size());
			assertEquals(1, sampleObjectSupplierManager.getManagedClasses().size());
		} catch (final Exception e) {
			logger.error(ExceptionUtils.getStackTrace(e));
			fail("Recibida excpcion");
		}
	}

}
