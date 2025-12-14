package org.gjs.java.common.util;

import static org.junit.jupiter.api.Assertions.assertEquals;
import static org.junit.jupiter.api.Assertions.assertFalse;
import static org.junit.jupiter.api.Assertions.assertNotNull;
import static org.junit.jupiter.api.Assertions.assertNull;
import static org.junit.jupiter.api.Assertions.assertTrue;

import java.util.Collection;
import java.util.Set;
import java.util.TreeSet;

import org.gjs.java.common.dto.CodedEntityDto;
import org.gjs.java.common.util.ConversionUtils;
import org.gjs.java.common.util.LocaleUtils;
import org.gjs.java.test.BaseUnitTest;
import org.junit.jupiter.api.Test;

class LocaleUtilsTest extends BaseUnitTest<LocaleUtils> {

	@Override
	protected void initialize() throws Exception {
	}

	@Test
	void testGetCountryName1() {
		assertNull(LocaleUtils.getCountryName(null));
		assertNull(LocaleUtils.getCountryName(""));
		assertNull(LocaleUtils.getCountryName("XX"));
		assertNotNull(LocaleUtils.getCountryName("AU"));
	}

	@Test
	void testGetCountryName2() {
		final String[] countries = { "ES", "AU", "BE", "BH", "BR", "BL", "CY", "CO", "CR", "EA", "US", "FI", "FR" };

		for (final String country : countries) {
			final String code = LocaleUtils.getCountryName(country);
			assertNotNull(code, String.format("Locale system not supporting %s", country));
		}
	}

	@Test
	void testGetCountries1() {
		logger.info("Countries:");
		for (final CodedEntityDto country : LocaleUtils.getCountries()) {
			logger.info(ConversionUtils.toString(country));
		}
	}

	@Test
	void testGetCountries2() {
		final Set<String> set = null;
		final Collection<CodedEntityDto> list = LocaleUtils.getCountries(set);
		assertNotNull(list);
		assertEquals(LocaleUtils.getCountries().size(), list.size());
	}

	@Test
	void testGetCountries3() {
		final Set<String> set = new TreeSet<>();
		final Collection<CodedEntityDto> list = LocaleUtils.getCountries(set);
		assertNotNull(list);
		assertEquals(LocaleUtils.getCountries().size(), list.size());
	}

	@Test
	void testGetCountries4() {
		final Set<String> set = new TreeSet<>();
		set.add("ES");
		final Collection<CodedEntityDto> list = LocaleUtils.getCountries(set);
		assertNotNull(list);
		assertEquals(set.size(), list.size());
	}

	@Test
	void testGetCountries5() {
		final Set<String> set = new TreeSet<>();
		set.add("ES");
		set.add("GB");
		set.add("US");
		set.add("XX");
		final Collection<CodedEntityDto> list = LocaleUtils.getCountries(set);
		assertNotNull(list);
		assertEquals(set.size() - 1, list.size());
	}

	@Test
	void testGetLanguages1() {
		logger.info("Languages:");
		for (final CodedEntityDto lan : LocaleUtils.getLanguages()) {
			logger.info(ConversionUtils.toString(lan));
		}
	}

	@Test
	void testGetLanguages2() {
		final Set<String> set = null;
		final Collection<CodedEntityDto> list = LocaleUtils.getLanguages(set);
		assertNotNull(list);
		assertEquals(LocaleUtils.getLanguages().size(), list.size());
	}

	@Test
	void testGetLanguages3() {
		final Set<String> set = new TreeSet<>();
		final Collection<CodedEntityDto> list = LocaleUtils.getLanguages(set);
		assertNotNull(list);
		assertEquals(LocaleUtils.getLanguages().size(), list.size());
	}

	@Test
	void testGetLanguages4() {
		final Set<String> set = new TreeSet<>();
		set.add("es-ES");
		final Collection<CodedEntityDto> list = LocaleUtils.getLanguages(set);
		assertNotNull(list);
		assertEquals(set.size(), list.size());
	}

	@Test
	void testGetLanguages5() {
		final Set<String> set = new TreeSet<>();
		set.add("es-ES");
		set.add("en");
		set.add("en-US");
		set.add("ix-XX");
		final Collection<CodedEntityDto> list = LocaleUtils.getLanguages(set);
		assertNotNull(list);
		assertEquals(set.size() - 1, list.size());
	}

	@Test
	void testIsValidCountry() {
		assertFalse(LocaleUtils.isValidCountry(null));
		assertFalse(LocaleUtils.isValidCountry(""));
		assertFalse(LocaleUtils.isValidCountry(" "));
		assertFalse(LocaleUtils.isValidCountry("ZZ"));
		assertTrue(LocaleUtils.isValidCountry("ES"));
		assertTrue(LocaleUtils.isValidCountry("GB"));
		assertTrue(LocaleUtils.isValidCountry("US"));
	}

	@Test
	void testIsValidLanguage() {
		assertFalse(LocaleUtils.isValidLanguage(null));
		assertFalse(LocaleUtils.isValidLanguage(""));
		assertFalse(LocaleUtils.isValidLanguage(" "));
		assertFalse(LocaleUtils.isValidLanguage("zz"));
		assertTrue(LocaleUtils.isValidLanguage("es"));
		assertTrue(LocaleUtils.isValidLanguage("en"));
		assertTrue(LocaleUtils.isValidLanguage("es-ES"));
	}

}
