package org.gjs.java.dto;

import static org.junit.jupiter.api.Assertions.assertEquals;

import java.util.ArrayList;
import java.util.List;

import org.gjs.java.test.BaseUnitTest;
import org.junit.jupiter.api.Test;

@SuppressWarnings("rawtypes")
public class CollectionDtoTest extends BaseUnitTest<CollectionDto> {

	@Test
	void testCollectionDto1() {
		final List<String> data = new ArrayList<>();
		data.add("dato1");
		data.add("dato2");
		final CollectionDto<String> dto = new CollectionDto<>(data);
		assertEquals(data.size(), dto.getContenido().size());
		logger.info(dto.toString());
	}

}
