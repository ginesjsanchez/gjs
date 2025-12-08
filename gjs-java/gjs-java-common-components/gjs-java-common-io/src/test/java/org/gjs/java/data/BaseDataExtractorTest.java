package org.gjs.java.data;

import static org.junit.jupiter.api.Assertions.assertEquals;
import static org.junit.jupiter.api.Assertions.assertNotNull;
import static org.junit.jupiter.api.Assertions.assertNull;
import static org.junit.jupiter.api.Assertions.fail;

import org.apache.commons.lang3.exception.ExceptionUtils;
import org.gjs.java.supplier.testinggame.TestingGamesSingleton;
import org.gjs.java.test.BaseUnitTest;
import org.gjs.java.test.samples.dto.SampleEntityDto;
import org.gjs.java.test.testinggame.DtoTestingGame;
import org.gjs.java.util.ConversionUtils;
import org.junit.jupiter.api.Test;

@SuppressWarnings("rawtypes")
public class BaseDataExtractorTest extends BaseUnitTest<BaseDataExtractor> {

	static class DataExtractor1 extends BaseDataExtractor<SampleEntityDto> {

		public DataExtractor1() {
			super("Id", "Nombre", "Descripcion");
		}

		@Override
		public String getColumnValue(SampleEntityDto obj, int column) {
			String value = null;
			switch (column) {
			case 0:
				value = ConversionUtils.toString(obj.getId());
				break;
			case 1:
				value = ConversionUtils.toString(obj.getNombre());
				break;
			case 2:
				value = ConversionUtils.toString(obj.getDescripcion());
				break;
			default:
				break;
			}
			return value;
		}
	}

	static class DataExtractor2 extends BaseDataExtractor<SampleEntityDto> {

		public DataExtractor2() {
			super.addColumnName("Nombre");
			super.addColumnName("Descripcion");
		}

		@Override
		public String getColumnValue(SampleEntityDto obj, int column) {
			String value = null;
			switch (column) {
			case 0:
				value = ConversionUtils.toString(obj.getNombre());
				break;
			case 1:
				value = ConversionUtils.toString(obj.getDescripcion());
				break;
			default:
				break;
			}
			return value;
		}
	}

	@Override
	protected void initialize() throws Exception {
	}

	@Test
	void testDataStreamer1() {
		try {
			final DataExtractor1 extractor = new DataExtractor1();
			final SampleEntityDto nullDto = new SampleEntityDto();
			logger.info("DTO {}", nullDto);
			for (int i = 0; i < extractor.columns(); i = i + 1) {
				final String value = extractor.getColumnValue(nullDto, i);
				logger.info("Column {} = {}", extractor.getColumnName(i), value);
				assertNotNull(value);
				assertEquals("null", value);
			}
			final SampleEntityDto emptyDto = ((DtoTestingGame) TestingGamesSingleton.getInstance()
					.getTestingGame("dtos")).getEmptySampleEntityDto();
			logger.info("DTO {}", emptyDto);
			String value1 = extractor.getColumnValue(emptyDto, 0);
			String value2 = extractor.getColumnValue(emptyDto, 1);
			String value3 = extractor.getColumnValue(emptyDto, 2);
			logger.info("Column {} = {}", extractor.getColumnName(0), value1);
			logger.info("Column {} = {}", extractor.getColumnName(1), value2);
			logger.info("Column {} = {}", extractor.getColumnName(2), value3);
			assertEquals(ConversionUtils.toString(emptyDto.getId()), value1);
			assertEquals(emptyDto.getNombre(), value2);
			assertEquals(emptyDto.getDescripcion(), value3);
			assertNull(extractor.getColumnValue(emptyDto, null));
			assertNull(extractor.getColumnValue(emptyDto, ""));
			assertNull(extractor.getColumnValue(emptyDto, null));
			assertNotNull(extractor.getColumnValue(emptyDto, "Id"));

			for (int i = 0; i < 10; i = i + 1) {
				final SampleEntityDto dto = ((DtoTestingGame) TestingGamesSingleton.getInstance()
						.getTestingGame("dtos")).getSampleEntityDto();
				logger.info("DTO {}", dto);
				value1 = extractor.getColumnValue(dto, 0);
				value2 = extractor.getColumnValue(dto, 1);
				value3 = extractor.getColumnValue(dto, 2);
				logger.info("Column {} = {}", extractor.getColumnName(0), value1);
				logger.info("Column {} = {}", extractor.getColumnName(1), value2);
				logger.info("Column {} = {}", extractor.getColumnName(2), value3);
				assertEquals(ConversionUtils.toString(dto.getId()), value1);
				assertEquals(dto.getNombre(), value2);
				assertEquals(dto.getDescripcion(), value3);
				final String value1b = extractor.getColumnValue(dto, extractor.getColumnName(0));
				final String value2b = extractor.getColumnValue(dto, extractor.getColumnName(1));
				final String value3b = extractor.getColumnValue(dto, extractor.getColumnName(2));
				assertEquals(value1, value1b);
				assertEquals(value2, value2b);
				assertEquals(value3, value3b);
			}

		} catch (final Exception e) {
			logger.error(ExceptionUtils.getStackTrace(e));
			fail("Se ha producido un error");
		}
	}

	@Test
	void testDataStreamer2() {
		try {
			final DataExtractor2 extractor = new DataExtractor2();
			final SampleEntityDto dto = ((DtoTestingGame) TestingGamesSingleton.getInstance().getTestingGame("dtos"))
					.getSampleEntityDto();
			logger.info("DTO {}", dto);
			assertEquals(2, extractor.getColumnNames().size());
			assertEquals(2, extractor.columns());
			extractor.setColumnName(0, "Name");
			extractor.setColumnName(1, "Description");
			assertEquals("Name", extractor.getColumnName(0));
			assertEquals("Description", extractor.getColumnName(1));
			final String value1 = extractor.getColumnValue(dto, 0);
			final String value2 = extractor.getColumnValue(dto, 1);
			logger.info("Column {} = {}", extractor.getColumnName(0), value1);
			logger.info("Column {} = {}", extractor.getColumnName(1), value2);

		} catch (final Exception e) {
			logger.error(ExceptionUtils.getStackTrace(e));
			fail("Se ha producido un error");
		}
	}

}
