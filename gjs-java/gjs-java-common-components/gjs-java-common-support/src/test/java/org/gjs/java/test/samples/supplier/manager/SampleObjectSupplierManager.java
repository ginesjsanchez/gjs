package org.gjs.java.test.samples.supplier.manager;

import org.gjs.java.common.supplier.AbstractObjectSupplier;
import org.gjs.java.common.supplier.ObjectSupplierManager;
import org.gjs.java.test.samples.type.AllPrimitivesType;
import org.slf4j.Logger;

public class SampleObjectSupplierManager extends ObjectSupplierManager {

	static class SampleSupplier extends AbstractObjectSupplier<AllPrimitivesType> {
		public SampleSupplier(ObjectSupplierManager manager) {
			super(AllPrimitivesType.class.getCanonicalName(), manager);
		}

		@Override
		protected AllPrimitivesType[] createArray(int size) {
			return new AllPrimitivesType[size];
		}
	}

	SampleSupplier sampleSupplier = null;

	public SampleObjectSupplierManager(Logger logger) {
		super(logger);
		sampleSupplier = new SampleSupplier(this);
		sampleSupplier.setLogger(logger);
	}

	public AllPrimitivesType getSample() {
		return sampleSupplier.get();
	}

	public AllPrimitivesType getEmptySample() {
		return sampleSupplier.getEmpty();
	}

}
