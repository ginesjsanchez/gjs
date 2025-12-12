package org.gjs.java.types;

import static org.junit.jupiter.api.Assertions.assertEquals;
import static org.junit.jupiter.api.Assertions.assertNotNull;
import static org.junit.jupiter.api.Assertions.assertTrue;
import static org.junit.jupiter.api.Assertions.fail;

import java.io.IOException;

import org.gjs.java.test.BaseClassTest;
import org.junit.jupiter.api.Test;

class DocumentTemplateTest extends BaseClassTest<DocumentTemplate> {

	private static final String EXPECTED_TEXT = "Estimado/a usuario/a de la aplicación DRaVY:\r\n" + "\r\n"
			+ "Se le informa que se ha procedido a la apertura del PERIODO DE EVALUACIÓN. Este comienza el 11 de enero de 2023 y finaliza el 24 de enero de 2023.\r\n"
			+ "\r\n"
			+ "Asegúrese de finalizar y consolidar las evaluaciones de los internos/as PENADOS de su centro antes de que finalice dicho plazo.\r\n"
			+ "\r\n" + "Be water my Friend!\r\n" + "\r\n" + "Reciba un cordial saludo\r\n" + "\r\n"
			+ "Secretaría General de Instituciones Penitenciarias \r\n"
			+ "Dirección General de Ejecución Penal y Reinserción Social\r\n" + "\r\n"
			+ "Esta es una notificación automática de la aplicación DRaVY. No responda a este correo.\r\n" + "";

	@Test
	void testDocumentTemplate_Ok() {
		try {
			final DocumentTemplate documentTemplate = new DocumentTemplate("correos/avisoApertura.txt");

			assertEquals(3, documentTemplate.getFields().size());
			assertTrue(documentTemplate.getFields().contains("fechaInicio"));
			assertTrue(documentTemplate.getFields().contains("fechaFin"));
			assertTrue(documentTemplate.getFields().contains("mensajeAviso"));
			documentTemplate.setField("fechaInicio", "11 de enero de 2023");
			documentTemplate.setField("fechaFin", "24 de enero de 2023");
			documentTemplate.setField("mensajeAviso", "Be water my Friend!");
			final String document = documentTemplate.generateDocument();
			assertNotNull(document);
			assertEquals(EXPECTED_TEXT, document);

		} catch (final IOException e) {
			fail("Recibida excepcion", e);
		}
	}

	@Test
	void testDocumentTemplate_Ko() {
		try {
			@SuppressWarnings("unused")
			final DocumentTemplate documentTemplate = new DocumentTemplate("correos/inexistentetxt");
			fail("Se esperaba excepcion");

		} catch (final IOException e) {
			assertNotNull(e);
		}
	}

}
