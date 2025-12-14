package org.gjs.java.test.samples.supplier.manager;

import org.gjs.java.common.supplier.AbstractObjectSupplier;
import org.gjs.java.test.samples.type.AllPrimitivesType;

public class SampleSupplierNotManaged extends AbstractObjectSupplier<AllPrimitivesType> {
	public SampleSupplierNotManaged() {
		super(AllPrimitivesType.class.getCanonicalName());
	}

	@Override
	protected AllPrimitivesType[] createArray(int size) {
		return new AllPrimitivesType[size];
	}
}
