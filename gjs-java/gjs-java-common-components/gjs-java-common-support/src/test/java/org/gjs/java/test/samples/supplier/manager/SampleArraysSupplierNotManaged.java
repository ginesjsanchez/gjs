package org.gjs.java.test.samples.supplier.manager;

import org.gjs.java.common.supplier.AbstractObjectSupplier;
import org.gjs.java.test.samples.type.AllArraysType;

public class SampleArraysSupplierNotManaged extends AbstractObjectSupplier<AllArraysType> {
	public SampleArraysSupplierNotManaged() {
		super(AllArraysType.class.getCanonicalName());
	}

	public static void main(String[] args) {
	}

	@Override
	protected AllArraysType[] createArray(int size) {
		return new AllArraysType[size];
	}
}
