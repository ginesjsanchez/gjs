package org.gjs.java.test.samples.supplier.manager;

import org.gjs.java.supplier.AbstractObjectSupplier;
import org.gjs.java.supplier.ObjectSupplierManager;
import org.gjs.java.test.samples.pojos.SampleMaterialized1;
import org.gjs.java.test.samples.pojos.SampleMaterialized2;
import org.gjs.java.test.samples.pojos.SampleMaterializedContainer;
import org.gjs.java.test.samples.pojos.SamplePojo;
import org.slf4j.Logger;

public class SampleGenericObjectSupplierManager extends ObjectSupplierManager {

	static class SamplePojoSupplier extends AbstractObjectSupplier<SamplePojo> {
		public SamplePojoSupplier(ObjectSupplierManager manager) {
			super(SamplePojo.class.getCanonicalName(), manager);
		}

		@Override
		protected SamplePojo[] createArray(int size) {
			return new SamplePojo[size];
		}
	}

	static class SampleMaterialized1Supplier extends AbstractObjectSupplier<SampleMaterialized1> {
		public SampleMaterialized1Supplier(ObjectSupplierManager manager) {
			super(SampleMaterialized1.class.getCanonicalName(), manager);
		}

		@Override
		protected SampleMaterialized1[] createArray(int size) {
			return new SampleMaterialized1[size];
		}
	}

	static class SampleMaterialized2Supplier extends AbstractObjectSupplier<SampleMaterialized2> {
		public SampleMaterialized2Supplier(ObjectSupplierManager manager) {
			super(SampleMaterialized2.class.getCanonicalName(), manager);
		}

		@Override
		protected SampleMaterialized2[] createArray(int size) {
			return new SampleMaterialized2[size];
		}
	}

	static class SampleMaterializedContainerSupplier extends AbstractObjectSupplier<SampleMaterializedContainer> {
		public SampleMaterializedContainerSupplier(ObjectSupplierManager manager) {
			super(SampleMaterializedContainer.class.getCanonicalName(), manager);
		}

		@Override
		protected SampleMaterializedContainer[] createArray(int size) {
			return new SampleMaterializedContainer[size];
		}
	}

	SamplePojoSupplier samplePojoSupplier = null;
	SampleMaterialized1Supplier sampleMaterialized1Supplier = null;
	SampleMaterialized2Supplier sampleMaterialized2Supplier = null;
	SampleMaterializedContainerSupplier sampleMaterializedContainerSupplier = null;

	public SampleGenericObjectSupplierManager(Logger logger) {
		super(logger);
		samplePojoSupplier = new SamplePojoSupplier(this);
		sampleMaterialized1Supplier = new SampleMaterialized1Supplier(this);
		sampleMaterialized2Supplier = new SampleMaterialized2Supplier(this);
		sampleMaterializedContainerSupplier = new SampleMaterializedContainerSupplier(this);
		samplePojoSupplier.setLogger(logger);
		sampleMaterialized1Supplier.setLogger(logger);
		sampleMaterialized2Supplier.setLogger(logger);
		sampleMaterializedContainerSupplier.setLogger(logger);
	}

	public SamplePojo getSamplePojo() {
		return samplePojoSupplier.get();
	}

	public SamplePojo getEmptySamplePojo() {
		return samplePojoSupplier.getEmpty();
	}

	public SampleMaterialized1 getSampleMaterialized1() {
		return sampleMaterialized1Supplier.get();
	}

	public SampleMaterialized1 getEmptySampleMaterialized1() {
		return sampleMaterialized1Supplier.getEmpty();
	}

	public SampleMaterialized2 getSampleMaterialized2() {
		return sampleMaterialized2Supplier.get();
	}

	public SampleMaterialized2 getEmptySampleMaterialized2() {
		return sampleMaterialized2Supplier.getEmpty();
	}

	public SampleMaterializedContainer getSampleMaterializedContainer() {
		return sampleMaterializedContainerSupplier.get();
	}

	public SampleMaterializedContainer getEmptySampleMaterializedContainer() {
		return sampleMaterializedContainerSupplier.getEmpty();
	}

}
