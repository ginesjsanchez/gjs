package org.gjs.java.test.samples.supplier.manager;

import org.gjs.java.supplier.AbstractObjectSupplier;
import org.gjs.java.test.samples.type.NotJEEType;

public class SampleNotJEESupplierNotManaged extends AbstractObjectSupplier<NotJEEType> {
	public SampleNotJEESupplierNotManaged() {
		super(NotJEEType.class.getCanonicalName());
	}

	@Override
	protected NotJEEType[] createArray(int size) {
		return new NotJEEType[size];
	}
}
