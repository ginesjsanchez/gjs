package org.gjs.java.util;

import static org.junit.jupiter.api.Assertions.assertFalse;
import static org.junit.jupiter.api.Assertions.assertTrue;

import org.gjs.java.test.BaseClassTest;
import org.junit.jupiter.api.Test;

class AdministrativeUtilsTest extends BaseClassTest<AdministrativeUtils> {

	@Test
	void testValidateNif() {
		assertFalse(AdministrativeUtils.validateNif("99100510E"));
		assertTrue(AdministrativeUtils.validateNif("99100510L"));
		assertTrue(AdministrativeUtils.validateNif("89859502C"));
		assertTrue(AdministrativeUtils.validateNif("00000000T"));
		assertFalse(AdministrativeUtils.validateNif("X6290423S"));
	}

	@Test
	void testValidateNie() {
		assertFalse(AdministrativeUtils.validateNie("99100510E"));
		assertFalse(AdministrativeUtils.validateNie("V9100510L"));
		assertTrue(AdministrativeUtils.validateNie("X6290423S"));
		assertTrue(AdministrativeUtils.validateNie("X0000000T"));
		assertFalse(AdministrativeUtils.validateNie("X6290423Z"));
	}

	@Test
	void testValidateNifNie() {
		assertFalse(AdministrativeUtils.validateNifNie("99100510E"));
		assertTrue(AdministrativeUtils.validateNifNie("99100510L"));
		assertTrue(AdministrativeUtils.validateNifNie("89859502C"));
		assertTrue(AdministrativeUtils.validateNifNie("00000000T"));
		assertFalse(AdministrativeUtils.validateNifNie("V9100510L"));
		assertTrue(AdministrativeUtils.validateNifNie("X6290423S"));
	}

}
