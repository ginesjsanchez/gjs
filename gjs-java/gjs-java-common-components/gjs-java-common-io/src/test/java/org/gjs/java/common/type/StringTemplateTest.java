package org.gjs.java.common.type;

import static org.junit.jupiter.api.Assertions.assertEquals;
import static org.junit.jupiter.api.Assertions.assertFalse;
import static org.junit.jupiter.api.Assertions.assertNotNull;
import static org.junit.jupiter.api.Assertions.assertNull;
import static org.junit.jupiter.api.Assertions.assertTrue;

import org.gjs.java.test.BaseClassTest;
import org.junit.jupiter.api.Test;

class StringTemplateTest extends BaseClassTest<StringTemplate> {

	private static final String EXPECTED_TEXT = "### 11/01/2023 : Se realizó la acción de borrado";

	@Test
	void testStringTemplate1() {
		final StringTemplate template = new StringTemplate("### ${fecha} : Se realizó la acción de ${nombre}");
		assertTrue(template.isOk());
		assertEquals(2, template.getFields().size());
		assertTrue(template.getFields().contains("fecha"));
		assertTrue(template.getFields().contains("nombre"));
		template.setField("fecha", "11/01/2023");
		template.setField("nombre", "borrado");
		final String text = template.generate();
		assertNotNull(text);
		assertEquals(EXPECTED_TEXT, text);
	}

	@Test
	void testStringTemplate_Ko() {
		final StringTemplate template = new StringTemplate(null);
		assertFalse(template.isOk());
		assertNull(template.generate());
		assertEquals(0, template.getFields().size());
	}

}
