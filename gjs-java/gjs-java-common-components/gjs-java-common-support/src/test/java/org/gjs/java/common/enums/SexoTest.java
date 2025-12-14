package org.gjs.java.common.enums;

import static org.junit.jupiter.api.Assertions.assertEquals;
import static org.junit.jupiter.api.Assertions.assertNotEquals;
import static org.junit.jupiter.api.Assertions.assertNotNull;

import org.gjs.java.common.enums.Sexo;
import org.gjs.java.test.BaseClassTest;
import org.junit.jupiter.api.Test;

public class SexoTest extends BaseClassTest<Sexo> {

	@Test
	void testSexo() {
		Sexo type = Sexo.VARON;
		assertNotNull(type.getNombre());
		assertNotNull(type.getAcronimo());
		assertNotNull(type.toString());
		assertEquals(type.getAcronimo(), type.toString());
		assertEquals(Sexo.VARON, type);
		assertNotEquals(Sexo.HEMBRA, type);

		type = Sexo.get("V");
		assertEquals(Sexo.VARON, type);
		type = Sexo.get("H");
		assertEquals(Sexo.HEMBRA, type);
		type = Sexo.get("SEÑOR");
		assertEquals(Sexo.VARON, type);
		type = Sexo.get("DAma");
		assertEquals(Sexo.HEMBRA, type);
		type = Sexo.get("hombre");
		assertEquals(Sexo.VARON, type);

	}

}
