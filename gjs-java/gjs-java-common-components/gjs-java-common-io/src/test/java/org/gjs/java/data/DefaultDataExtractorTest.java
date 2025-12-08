package org.gjs.java.data;

import static org.junit.jupiter.api.Assertions.assertEquals;
import static org.junit.jupiter.api.Assertions.assertNotNull;
import static org.junit.jupiter.api.Assertions.fail;

import org.apache.commons.lang3.exception.ExceptionUtils;
import org.gjs.java.supplier.testinggame.TestingGamesSingleton;
import org.gjs.java.test.BaseUnitTest;
import org.gjs.java.test.samples.dto.SampleEntityDto;
import org.gjs.java.test.testinggame.DtoTestingGame;
import org.gjs.java.util.ConversionUtils;
import org.junit.jupiter.api.Test;

public class DefaultDataExtractorTest extends BaseUnitTest<DefaultDataExtractor> {

	@Override
	protected void initialize() throws Exception {
	}

	@Test
	void testDefaultDataExtractor() {
		try {
			final SampleEntityDto nullDto = new SampleEntityDto();
			final DefaultDataExtractor extractor = new DefaultDataExtractor(nullDto);
			assertEquals(6, extractor.columns());
			final String[] EXPECTED_COLUMNS = { "id", "nombre", "descripcion", "fechaAlta", "fechaBaja", "activo" };
			for (int i = 0; i < extractor.columns(); i = i + 1) {
				final String column = extractor.getColumnName(i);
				assertNotNull(column);
				assertEquals(EXPECTED_COLUMNS[i], column);
			}

			final SampleEntityDto dto = ((DtoTestingGame) TestingGamesSingleton.getInstance().getTestingGame("dtos"))
					.getSampleEntityDto();
			logger.info("DTO {}", dto);
			final String value1 = extractor.getColumnValue(dto, 0);
			final String value2 = extractor.getColumnValue(dto, 1);
			final String value3 = extractor.getColumnValue(dto, 2);
			final String value4 = extractor.getColumnValue(dto, 3);
			final String value5 = extractor.getColumnValue(dto, 4);
			final String value6 = extractor.getColumnValue(dto, 5);
			logger.info("Column {} = {}", extractor.getColumnName(0), value1);
			logger.info("Column {} = {}", extractor.getColumnName(1), value2);
			logger.info("Column {} = {}", extractor.getColumnName(2), value3);
			logger.info("Column {} = {}", extractor.getColumnName(3), value4);
			logger.info("Column {} = {}", extractor.getColumnName(4), value5);
			logger.info("Column {} = {}", extractor.getColumnName(5), value6);
			assertEquals(ConversionUtils.toString(dto.getId()), value1);
			assertEquals(String.format("\"%s\"", dto.getNombre()), value2);
			assertEquals(String.format("\"%s\"", dto.getDescripcion()), value3);
			assertEquals(ConversionUtils.toString(dto.getFechaAlta()), value4);
			assertEquals(ConversionUtils.toString(dto.getFechaBaja()), value5);
			assertEquals(ConversionUtils.toString(dto.getActivo()), value6);

			final String value1b = extractor.getColumnValue(dto, "id");
			final String value2b = extractor.getColumnValue(dto, "nombre");
			final String value3b = extractor.getColumnValue(dto, "descripcion");
			final String value4b = extractor.getColumnValue(dto, "fechaAlta");
			final String value5b = extractor.getColumnValue(dto, "fechaBaja");
			final String value6b = extractor.getColumnValue(dto, "activo");
			assertEquals(ConversionUtils.toString(dto.getId()), value1b);
			assertEquals(String.format("\"%s\"", dto.getNombre()), value2b);
			assertEquals(String.format("\"%s\"", dto.getDescripcion()), value3b);
			assertEquals(ConversionUtils.toString(dto.getFechaAlta()), value4b);
			assertEquals(ConversionUtils.toString(dto.getFechaBaja()), value5b);
			assertEquals(ConversionUtils.toString(dto.getActivo()), value6b);

		} catch (final Exception e) {
			logger.error(ExceptionUtils.getStackTrace(e));
			fail("Se ha producido un error");
		}
	}

}
