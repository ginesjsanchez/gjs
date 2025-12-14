package org.gjs.java.test.samples.supplier.manager;

import org.gjs.java.common.supplier.AbstractObjectSupplier;
import org.gjs.java.test.samples.type.CollectionsType;

public class SampleCollectionsSupplierNotManaged extends AbstractObjectSupplier<CollectionsType> {
	public SampleCollectionsSupplierNotManaged() {
		super(CollectionsType.class.getCanonicalName());
	}

	public static void main(String[] args) {
	}

	@Override
	protected CollectionsType[] createArray(int size) {
		return new CollectionsType[size];
	}
}
