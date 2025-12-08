package org.gjs.java.test.samples.supplier.manager;

import org.gjs.java.supplier.AbstractObjectSupplier;
import org.gjs.java.supplier.ObjectSupplierManager;
import org.gjs.java.test.samples.type.NotJEEType;
import org.slf4j.Logger;

public class SampleNotJEEObjectSupplierManager extends ObjectSupplierManager {

	static class SampleNotJEESupplier extends AbstractObjectSupplier<NotJEEType> {
		public SampleNotJEESupplier(ObjectSupplierManager manager) {
			super(NotJEEType.class.getCanonicalName(), manager);
		}

		@Override
		protected NotJEEType[] createArray(int size) {
			return new NotJEEType[size];
		}

	}

	SampleNotJEESupplier sampleNotJEESupplier = null;

	public SampleNotJEEObjectSupplierManager(Logger logger) {
		super(logger);
		sampleNotJEESupplier = new SampleNotJEESupplier(this);
		sampleNotJEESupplier.setLogger(logger);
	}

	public NotJEEType getSampleNotJEE() {
		return sampleNotJEESupplier.get();
	}

	public NotJEEType getEmptySampleNotJEE() {
		return sampleNotJEESupplier.getEmpty();
	}

}
