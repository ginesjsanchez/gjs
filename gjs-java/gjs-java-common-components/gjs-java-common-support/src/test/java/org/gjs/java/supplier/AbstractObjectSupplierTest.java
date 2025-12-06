package org.gjs.java.supplier;

import static org.junit.jupiter.api.Assertions.assertEquals;
import static org.junit.jupiter.api.Assertions.assertFalse;
import static org.junit.jupiter.api.Assertions.assertNotNull;
import static org.junit.jupiter.api.Assertions.assertNull;
import static org.junit.jupiter.api.Assertions.assertTrue;

import org.gjs.java.test.BaseClassTest;
import org.gjs.java.test.samples.supplier.manager.SampleArraysSupplierNotManaged;
import org.gjs.java.test.samples.supplier.manager.SampleCollectionsSupplierNotManaged;
import org.gjs.java.test.samples.supplier.manager.SampleMixedSupplierNotManaged;
import org.gjs.java.test.samples.supplier.manager.SampleNotJEESupplierNotManaged;
import org.gjs.java.test.samples.supplier.manager.SampleSupplierNotManaged;
import org.gjs.java.test.samples.type.AllArraysType;
import org.gjs.java.test.samples.type.AllPrimitivesType;
import org.gjs.java.test.samples.type.CollectionsType;
import org.gjs.java.test.samples.type.MixedType;
import org.gjs.java.test.samples.type.NotJEEType;
import org.junit.jupiter.api.Test;

@SuppressWarnings("rawtypes")
class AbstractObjectSupplierTest extends BaseClassTest<AbstractObjectSupplier> {

	private static SampleSupplierNotManaged sampleSupplier = null;
	private static SampleCollectionsSupplierNotManaged sampleCollectionsSupplier = null;
	private static SampleArraysSupplierNotManaged sampleArraysSupplier = null;
	private static SampleNotJEESupplierNotManaged sampleNotJEESupplier = null;
	private static SampleMixedSupplierNotManaged sampleMixedSupplier = null;

	@Override
	protected void prepareTest() {
		sampleSupplier = new SampleSupplierNotManaged();
		sampleSupplier.setLogger(logger);
		sampleCollectionsSupplier = new SampleCollectionsSupplierNotManaged();
		sampleCollectionsSupplier.setLogger(logger);
		sampleArraysSupplier = new SampleArraysSupplierNotManaged();
		sampleArraysSupplier.setLogger(logger);
		sampleNotJEESupplier = new SampleNotJEESupplierNotManaged();
		sampleNotJEESupplier.setLogger(logger);
		sampleMixedSupplier = new SampleMixedSupplierNotManaged();
		sampleMixedSupplier.setLogger(logger);
	}

	@Test
	void testAbstractObjectSupplier1() {
		assertTrue(sampleSupplier.isInformAllFields());
		assertTrue(sampleSupplier.isInformCollections());
		assertEquals(1, sampleSupplier.getMinSizeCollections());
		assertEquals(5, sampleSupplier.getMaxSizeCollections());
		final AllPrimitivesType sample = sampleSupplier.get();
		assertNotNull(sample);
		assertNotNull(sample.isBoolVal());
		assertNotNull(sample.getByVal());
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
		assertNotNull(sample.getStrVal());

		sampleSupplier.setInformAllFields(false);
		sampleSupplier.setInformCollections(false);
		sampleSupplier.setMinSizeCollections(0);
		sampleSupplier.setMaxSizeCollections(2);
		assertFalse(sampleSupplier.isInformAllFields());
		assertFalse(sampleSupplier.isInformCollections());
		assertEquals(0, sampleSupplier.getMinSizeCollections());
		assertEquals(2, sampleSupplier.getMaxSizeCollections());
	}

	@Test
	void testAbstractObjectSupplier2() {
		final AllPrimitivesType sample = sampleSupplier.getEmpty();
		assertNotNull(sample);
		assertNotNull(sample.isBoolVal());
		assertNotNull(sample.getByVal());
		assertNotNull(sample.getCarVal());
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
		assertFalse(sample.isBoolVal());
		assertEquals(0, sample.getByVal());
		assertEquals('\0', sample.getCarVal());
		assertEquals(0.0, sample.getDouVal());
		assertEquals(0.0, sample.getFloVal());
		assertEquals(0, sample.getIntVal());
		assertEquals(0, sample.getLonVal());
		assertFalse(sample.getObVal());
		assertEquals('\0', sample.getOcVal());
		assertEquals(0.0, sample.getOdVal());
		assertEquals((float) 0.0, sample.getOfVal());
		assertEquals(0, sample.getOiVal());
		assertEquals(0, sample.getOlVal());
		assertNull(sample.getDatVal());
		assertNull(sample.getDecVal());
		assertNotNull(sample.getStrVal());
		assertEquals("", sample.getStrVal());
	}

	@Test
	void testAbstractObjectSupplier3() {
		assertTrue(sampleNotJEESupplier.isInformAllFields());
		assertTrue(sampleNotJEESupplier.isInformCollections());
		assertEquals(1, sampleNotJEESupplier.getMinSizeCollections());
		assertEquals(5, sampleNotJEESupplier.getMaxSizeCollections());
		final NotJEEType sample = sampleNotJEESupplier.get();
		assertNotNull(sample);
		assertNotNull(sample.bVal);
		assertNotNull(sample.byVal);
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

		sampleNotJEESupplier.setInformAllFields(false);
		sampleNotJEESupplier.setInformCollections(false);
		sampleNotJEESupplier.setMinSizeCollections(0);
		sampleNotJEESupplier.setMaxSizeCollections(2);
		assertFalse(sampleNotJEESupplier.isInformAllFields());
		assertFalse(sampleNotJEESupplier.isInformCollections());
		assertEquals(0, sampleNotJEESupplier.getMinSizeCollections());
		assertEquals(2, sampleNotJEESupplier.getMaxSizeCollections());
	}

	@Test
	void testAbstractObjectSupplier4() {
		assertTrue(sampleArraysSupplier.isInformAllFields());
		assertTrue(sampleArraysSupplier.isInformCollections());
		assertEquals(1, sampleArraysSupplier.getMinSizeCollections());
		assertEquals(5, sampleArraysSupplier.getMaxSizeCollections());
		final AllArraysType sample = sampleArraysSupplier.get();
		assertNotNull(sample);
		assertNotNull(sample.getIntVal());
		assertNotNull(sample.getLonVal());
		assertNotNull(sample.getObVal());
		assertNotNull(sample.getStrVal());
		assertTrue(sample.getIntVal().length >= sampleCollectionsSupplier.getMinSizeCollections());
		assertTrue(sample.getLonVal().length >= sampleCollectionsSupplier.getMinSizeCollections());
		assertTrue(sample.getObVal().length >= sampleCollectionsSupplier.getMinSizeCollections());
		assertTrue(sample.getStrVal().length >= sampleCollectionsSupplier.getMinSizeCollections());
		assertTrue(sample.getIntVal().length <= sampleCollectionsSupplier.getMaxSizeCollections());
		assertTrue(sample.getLonVal().length <= sampleCollectionsSupplier.getMaxSizeCollections());
		assertTrue(sample.getObVal().length <= sampleCollectionsSupplier.getMaxSizeCollections());
		assertTrue(sample.getStrVal().length <= sampleCollectionsSupplier.getMaxSizeCollections());
	}

	@Test
	void testAbstractObjectSupplier5() {
		assertTrue(sampleMixedSupplier.isInformAllFields());
		assertTrue(sampleMixedSupplier.isInformCollections());
		assertEquals(1, sampleMixedSupplier.getMinSizeCollections());
		assertEquals(5, sampleMixedSupplier.getMaxSizeCollections());
		final MixedType sample = sampleMixedSupplier.get();
		assertNotNull(sample);
		assertNotNull(sample.boolVal);
		assertNotNull(sample.getIntVal());
		assertNotNull(sample.getCarVal());
	}

	@Test
	void testAbstractObjectSupplier6() {
		assertTrue(sampleCollectionsSupplier.isInformAllFields());
		assertTrue(sampleCollectionsSupplier.isInformCollections());
		assertEquals(1, sampleCollectionsSupplier.getMinSizeCollections());
		assertEquals(5, sampleCollectionsSupplier.getMaxSizeCollections());
		final CollectionsType sample = sampleCollectionsSupplier.get();
		assertNotNull(sample);
		assertNotNull(sample.getCoiVal());
		assertNotNull(sample.getColVal());
		assertNull(sample.getMocdVal());
		assertNotNull(sample.getCdecVal());
		assertTrue(sample.getCoiVal().size() >= sampleCollectionsSupplier.getMinSizeCollections());
		assertTrue(sample.getColVal().size() >= sampleCollectionsSupplier.getMinSizeCollections());
		// assertTrue(sample.getMocdVal().size() >=
		// sampleCollectionsSupplier.getMinSizeCollections());
		assertTrue(sample.getCdecVal().size() >= sampleCollectionsSupplier.getMinSizeCollections());
		assertTrue(sample.getCoiVal().size() <= sampleCollectionsSupplier.getMaxSizeCollections());
		assertTrue(sample.getColVal().size() <= sampleCollectionsSupplier.getMaxSizeCollections());
		// assertTrue(sample.getMocdVal().size() <=
		// sampleCollectionsSupplier.getMaxSizeCollections());
		assertTrue(sample.getCdecVal().size() <= sampleCollectionsSupplier.getMaxSizeCollections());
	}

}
