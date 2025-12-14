package org.gjs.java.test.supplier.testinggame;

import static org.junit.jupiter.api.Assertions.assertEquals;
import static org.junit.jupiter.api.Assertions.assertNotNull;
import static org.junit.jupiter.api.Assertions.assertNull;

import org.gjs.java.common.supplier.AbstractObjectSupplier;
import org.gjs.java.common.supplier.ObjectSupplierManager;
import org.gjs.java.test.BaseUnitTest;
import org.gjs.java.test.samples.dto.SampleEntityDto;
import org.gjs.java.test.supplier.testinggame.TestingGamesSingleton;
import org.junit.jupiter.api.Test;
import org.slf4j.Logger;

class TestingGamesSingletonTest extends BaseUnitTest<TestingGamesSingleton> {

	private final class DtoTestingGame extends ObjectSupplierManager {

		class SampleEntityDtoSupplier extends AbstractObjectSupplier<SampleEntityDto> {
			public SampleEntityDtoSupplier(ObjectSupplierManager manager) {
				super(SampleEntityDto.class.getCanonicalName(), manager);
			}

			@Override
			protected SampleEntityDto[] createArray(int size) {
				return new SampleEntityDto[size];
			}

		}

		SampleEntityDtoSupplier sampleEntityDtoSupplier = null;

		public DtoTestingGame(Logger logger) {
			super(logger);
			sampleEntityDtoSupplier = new SampleEntityDtoSupplier(this);

			sampleEntityDtoSupplier.setLogger(logger);
		}

		public SampleEntityDto getSampleEntityDto() {
			return sampleEntityDtoSupplier.get();
		}

	}

	@Test
	void testTestingGamesSingleton() {
		final TestingGamesSingleton testing = TestingGamesSingleton.getInstance();
		assertNotNull(testing);
		assertEquals(testing, TestingGamesSingleton.getInstance());
	}

	@Test
	void testObjectSupplierManager1() {
		assertNotNull(TestingGamesSingleton.getInstance());
		TestingGamesSingleton.getInstance().setLogger(logger);
		assertNull(TestingGamesSingleton.getInstance().getTestingGame("Dtos"));
		TestingGamesSingleton.getInstance().addTestingGamne(null, new DtoTestingGame(logger));
		TestingGamesSingleton.getInstance().addTestingGamne("X", null);
		TestingGamesSingleton.getInstance().addTestingGamne("Dtos", new DtoTestingGame(logger));
		assertNull(TestingGamesSingleton.getInstance().getTestingGame(null));
		assertNull(TestingGamesSingleton.getInstance().getTestingGame("X"));
		assertNotNull(TestingGamesSingleton.getInstance().getTestingGame("Dtos"));
		TestingGamesSingleton.getInstance().setLogger(logger);
		assertNotNull(
				((DtoTestingGame) TestingGamesSingleton.getInstance().getTestingGame("Dtos")).getSampleEntityDto());
		TestingGamesSingleton.getInstance().clear();
		assertNull(TestingGamesSingleton.getInstance().getTestingGame("Dtos"));
	}

}
