package org.gjs.java.test.samples.supplier.manager;

import org.gjs.java.supplier.AbstractObjectSupplier;
import org.gjs.java.test.samples.type.MixedType;

public class SampleMixedSupplierNotManaged extends AbstractObjectSupplier<MixedType> {
	public SampleMixedSupplierNotManaged() {
		super(MixedType.class.getCanonicalName());
	}

	@Override
	protected MixedType[] createArray(int size) {
		return new MixedType[size];
	}
}
