package org.gjs.java.util;

import static org.junit.jupiter.api.Assertions.assertEquals;
import static org.junit.jupiter.api.Assertions.assertFalse;
import static org.junit.jupiter.api.Assertions.assertNotNull;
import static org.junit.jupiter.api.Assertions.assertNull;
import static org.junit.jupiter.api.Assertions.assertTrue;

import java.util.ArrayList;
import java.util.List;
import java.util.Locale;

import org.gjs.java.constant.CommonBaseConstants;
import org.gjs.java.test.BaseClassTest;
import org.junit.jupiter.api.Test;

class ValidationUtilsTest extends BaseClassTest<ValidationUtils> {

	@Test
	void testIsValidId1() {
		assertFalse(ValidationUtils.isValidId((Long) null));
		assertFalse(ValidationUtils.isValidId(Long.valueOf(0)));
		assertTrue(ValidationUtils.isValidId(Long.valueOf(1)));
	}

	@Test
	void testIsValidId2() {
		assertFalse(ValidationUtils.isValidId((String) null));
		assertFalse(ValidationUtils.isValidId(""));
		assertFalse(ValidationUtils.isValidId("    "));
		assertFalse(ValidationUtils.isValidId(" 12BS"));
		assertFalse(ValidationUtils.isValidId("&%$3·"));
		assertTrue(ValidationUtils.isValidId("COD1"));
	}

	@Test
	void testIsValidId3() {
		assertFalse(ValidationUtils.isValidId((String) null, 0));
		assertFalse(ValidationUtils.isValidId((String) null, 1));
		assertFalse(ValidationUtils.isValidId("", 0));
		assertFalse(ValidationUtils.isValidId("", 1));
		assertFalse(ValidationUtils.isValidId("A", 0));
		assertTrue(ValidationUtils.isValidId("A", 1));
		assertTrue(ValidationUtils.isValidId("A", 4));
		assertTrue(ValidationUtils.isValidId("ABC1", 4));
		assertFalse(ValidationUtils.isValidId("ABC1D", 4));
		assertTrue(ValidationUtils.isValidId("abc1", 4));
		assertFalse(ValidationUtils.isValidId("A%C1", 4));
		assertTrue(ValidationUtils.isValidId("EU-TS", 10));
		assertTrue(ValidationUtils.isValidId("R-UE/EU-R", 10));
		assertFalse(ValidationUtils.isValidId("ESA R", 10));
	}

	@Test
	void testAreValidId1() {
		List<Long> ids = null;
		assertFalse(ValidationUtils.areValidId(ids));
		ids = new ArrayList<>();
		assertFalse(ValidationUtils.areValidId(ids));
		ids.add(Long.valueOf(0));
		assertFalse(ValidationUtils.areValidId(ids));
		ids.add(Long.valueOf(1));
		assertFalse(ValidationUtils.areValidId(ids));
		ids.clear();
		ids.add(Long.valueOf(1));
		ids.add(Long.valueOf(2));
		assertTrue(ValidationUtils.areValidId(ids));
	}

	@Test
	void testAreValidId2() {
		List<String> ids = null;
		assertFalse(ValidationUtils.areValidStringId(ids));
		ids = new ArrayList<>();
		assertFalse(ValidationUtils.areValidStringId(ids));
		ids.add("");
		assertFalse(ValidationUtils.areValidStringId(ids));
		ids.add("COD1");
		assertFalse(ValidationUtils.areValidStringId(ids));
		ids.clear();
		ids.add("ABC");
		ids.add("COD2");
		assertTrue(ValidationUtils.areValidStringId(ids));
	}

	@Test
	void testAreValidId3() {
		List<String> ids = null;
		assertFalse(ValidationUtils.areValidStringId(ids, 4));
		ids = new ArrayList<>();
		assertFalse(ValidationUtils.areValidStringId(ids, 4));
		ids.add("");
		assertFalse(ValidationUtils.areValidStringId(ids, 4));
		ids.add("COD1");
		assertFalse(ValidationUtils.areValidStringId(ids, 4));
		ids.clear();
		ids.add("ABC");
		ids.add("COD2");
		assertTrue(ValidationUtils.areValidStringId(ids, 4));
	}

	@Test
	void testIsValidIdSgu() {
		assertFalse(ValidationUtils.isValidIdSgu((String) null));
		assertFalse(ValidationUtils.isValidIdSgu(""));
		assertFalse(ValidationUtils.isValidIdSgu("12345678"));
		assertTrue(ValidationUtils.isValidIdSgu("dcmbDES33"));
		assertFalse(ValidationUtils.isValidIdSgu("d"));
		assertFalse(ValidationUtils.isValidIdSgu("1"));
		assertFalse(ValidationUtils.isValidIdSgu("dc"));
		assertTrue(ValidationUtils.isValidIdSgu("dcm"));
		assertFalse(ValidationUtils.isValidIdSgu("1cm"));
		assertTrue(ValidationUtils.isValidIdSgu("dcmD"));
		assertTrue(ValidationUtils.isValidIdSgu("dcmDE"));
		assertTrue(ValidationUtils.isValidIdSgu("dcmDES"));
		assertTrue(ValidationUtils.isValidIdSgu("dcmDES3"));
		assertTrue(ValidationUtils.isValidIdSgu("dcmbDES3"));
		assertTrue(ValidationUtils.isValidIdSgu("dcmbDES33"));
		assertTrue(ValidationUtils.isValidIdSgu("dcmbDES333"));
		assertTrue(ValidationUtils.isValidIdSgu("dcmbDES333X"));
		assertFalse(ValidationUtils.isValidIdSgu(" 2345678"));
		assertTrue(ValidationUtils.isValidIdSgu("A77"));
		assertFalse(ValidationUtils.isValidIdSgu("123 890"));
		assertFalse(ValidationUtils.isValidIdSgu("123-567"));
		assertFalse(ValidationUtils.isValidIdSgu("2000 "));
		assertTrue(ValidationUtils.isValidIdSgu("pionsAdmin"));
		assertTrue(ValidationUtils.isValidIdSgu("admin"));
		assertTrue(ValidationUtils.isValidIdSgu("consemilla2"));
		assertTrue(ValidationUtils.isValidIdSgu("consemilla"));
		assertTrue(ValidationUtils.isValidIdSgu("48915239N"));
		assertTrue(ValidationUtils.isValidIdSgu("X8274102J"));
		assertTrue(ValidationUtils.isValidIdSgu("B98498041"));
		assertTrue(ValidationUtils.isValidIdSgu("jose38"));
		assertTrue(ValidationUtils.isValidIdSgu("jose567890123456789012345"));
		assertFalse(ValidationUtils.isValidIdSgu("jose5678901234567890123456"));
	}

	@Test
	void testIsValidName() {
		assertFalse(ValidationUtils.isValidName((String) null));
		assertFalse(ValidationUtils.isValidName(""));
		assertFalse(ValidationUtils.isValidName("A"));
		assertTrue(ValidationUtils.isValidName("An"));
		assertFalse(ValidationUtils.isValidName("arrieta"));
		assertFalse(ValidationUtils.isValidName("ArrechavalEta"));
		assertTrue(ValidationUtils.isValidName("Arrechavaleta"));
		assertFalse(ValidationUtils.isValidName(" arrieta"));
		assertTrue(ValidationUtils.isValidName("Antón"));
		assertTrue(ValidationUtils.isValidName("Luis Carandel"));
		assertTrue(ValidationUtils.isValidName("Luis-Carandel"));
		assertTrue(ValidationUtils.isValidName("Alvar Nuño"));
		assertFalse(ValidationUtils.isValidName("towards-end"));
		assertFalse(ValidationUtils.isValidName("towards2000"));
		assertFalse(ValidationUtils.isValidName("José Andrés0"));
		assertTrue(ValidationUtils.isValidName("José Andrés"));
		assertTrue(ValidationUtils.isValidName("Tuco Benedito José María"));
		assertTrue(ValidationUtils.isValidName("Jean P."));
		assertFalse(ValidationUtils.isValidName("Jean P. Sartre"));
		assertFalse(ValidationUtils.isValidName("Jean-P."));
		assertFalse(ValidationUtils.isValidName("Jean P.S."));
		assertFalse(ValidationUtils.isValidName("J. Paul"));
	}

	@Test
	void testIsValidSurname() {
		assertFalse(ValidationUtils.isValidSurname((String) null));
		assertFalse(ValidationUtils.isValidSurname(""));
		assertFalse(ValidationUtils.isValidSurname("A"));
		assertTrue(ValidationUtils.isValidSurname("An"));
		assertFalse(ValidationUtils.isValidSurname("arrieta"));
		assertFalse(ValidationUtils.isValidSurname("ArrechavalEta"));
		assertTrue(ValidationUtils.isValidSurname("Arrechavaleta"));
		assertFalse(ValidationUtils.isValidSurname(" arrieta"));
		assertTrue(ValidationUtils.isValidSurname("Antón"));
		assertTrue(ValidationUtils.isValidSurname("Luis Carandel"));
		assertTrue(ValidationUtils.isValidSurname("Luis-Carandel"));
		assertTrue(ValidationUtils.isValidSurname("Alvar Nuño"));
		assertFalse(ValidationUtils.isValidSurname("towards-end"));
		assertFalse(ValidationUtils.isValidSurname("towards2000"));
		assertFalse(ValidationUtils.isValidSurname("José Andrés0"));
		assertTrue(ValidationUtils.isValidSurname("José Andrés"));
		assertTrue(ValidationUtils.isValidSurname("Tuco Benedito José María"));
		assertFalse(ValidationUtils.isValidSurname("Jean P."));
		assertFalse(ValidationUtils.isValidSurname("Jean P. Sartre"));
		assertFalse(ValidationUtils.isValidSurname("Jean-P."));
		assertFalse(ValidationUtils.isValidSurname("Jean P.S."));
	}

	@Test
	void testIsValidPathPart() {
		assertFalse(ValidationUtils.isValidPathPart((String) null));
		assertFalse(ValidationUtils.isValidPathPart(""));
		assertTrue(ValidationUtils.isValidPathPart("A"));
		assertTrue(ValidationUtils.isValidPathPart("An"));
		assertTrue(ValidationUtils.isValidPathPart("arrieta"));
		assertTrue(ValidationUtils.isValidPathPart("ArrechavalEta"));
		assertTrue(ValidationUtils.isValidPathPart("Arrechavaleta"));
		assertFalse(ValidationUtils.isValidPathPart(" arrieta"));
		assertFalse(ValidationUtils.isValidPathPart("Antón"));
		assertFalse(ValidationUtils.isValidPathPart("Luis Carandel"));
		assertFalse(ValidationUtils.isValidPathPart("-safemail"));
		assertTrue(ValidationUtils.isValidPathPart("safe-mail"));
		assertTrue(ValidationUtils.isValidPathPart("towards2000"));
		assertFalse(ValidationUtils.isValidPathPart("2000towards"));
	}

	@Test
	void testIsValidCode() {
		assertFalse(ValidationUtils.isValidCode((String) null));
		assertFalse(ValidationUtils.isValidCode(""));
		assertTrue(ValidationUtils.isValidCode("arrieta"));
		assertTrue(ValidationUtils.isValidCode("a"));
		assertTrue(ValidationUtils.isValidCode("a1"));
		assertTrue(ValidationUtils.isValidCode("a2"));
		assertTrue(ValidationUtils.isValidCode("ArrechavalEta"));
		assertFalse(ValidationUtils.isValidCode(" arrieta"));
		assertFalse(ValidationUtils.isValidCode("Antón"));
		assertFalse(ValidationUtils.isValidCode("Luis Carandel"));
		assertFalse(ValidationUtils.isValidCode("towards-end"));
		assertTrue(ValidationUtils.isValidCode("towards2000"));
		assertTrue(ValidationUtils.isValidCode("towards_2000"));
		assertFalse(ValidationUtils.isValidCode("_towards2000"));
		assertTrue(ValidationUtils.isValidCode("arrieta8901234567890123456789012345678901234567890"));
		assertFalse(ValidationUtils.isValidCode("arrieta8901234567890123456789012345678901234567890X"));
		assertTrue(ValidationUtils.isValidCode("admin"));
		assertTrue(ValidationUtils.isValidCode("EstoEsUnaPrueba"));
		assertTrue(ValidationUtils.isValidCode("Anonimo"));
	}

	@Test
	void testIsValidCode2() {
		assertFalse(ValidationUtils.isValidCode((String) null, 0));
		assertFalse(ValidationUtils.isValidCode((String) null, 1));
		assertFalse(ValidationUtils.isValidCode("", 0));
		assertFalse(ValidationUtils.isValidCode("", 1));
		assertFalse(ValidationUtils.isValidCode("A", 0));
		assertTrue(ValidationUtils.isValidCode("A", 1));
		assertTrue(ValidationUtils.isValidCode("A", 4));
		assertTrue(ValidationUtils.isValidCode("ABC1", 4));
		assertFalse(ValidationUtils.isValidCode("ABC1D", 4));
		assertTrue(ValidationUtils.isValidCode("abc1", 4));
		assertFalse(ValidationUtils.isValidCode("A%C1", 4));
	}

	@Test
	void testIsValidFileName() {
		assertFalse(ValidationUtils.isValidFileName((String) null));
		assertFalse(ValidationUtils.isValidFileName(""));
		assertTrue(ValidationUtils.isValidFileName("arrieta.csv"));
		assertTrue(ValidationUtils.isValidFileName("a"));
		assertTrue(ValidationUtils.isValidFileName("a1"));
		assertTrue(ValidationUtils.isValidFileName("a2.txt"));
		assertTrue(ValidationUtils.isValidFileName("ArrechavalEta"));
		assertFalse(ValidationUtils.isValidFileName(" arrieta"));
		assertFalse(ValidationUtils.isValidFileName("Antón"));
		assertFalse(ValidationUtils.isValidFileName("Luis Carandel"));
		assertTrue(ValidationUtils.isValidFileName("towards-end"));
		assertTrue(ValidationUtils.isValidFileName("towards2000"));
		assertTrue(ValidationUtils.isValidFileName("towards_2000-back.java"));
		assertFalse(ValidationUtils.isValidFileName("_towards2000"));
		String code = "arrieta890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890";
		assertTrue(ValidationUtils.isValidFileName(code));
		code = code + 'X';
		assertFalse(ValidationUtils.isValidFileName(code));
		assertTrue(ValidationUtils.isValidFileName("admin"));
		assertTrue(ValidationUtils.isValidFileName("EstoEsUnaPrueba"));
	}

	@Test
	void testIsValidPersonName() {
		assertFalse(ValidationUtils.isValidPersonName(null, null, null));
		assertFalse(ValidationUtils.isValidPersonName(null, null, "Ufarte"));
		assertFalse(ValidationUtils.isValidPersonName(null, "López", "Ufarte"));
		assertTrue(ValidationUtils.isValidPersonName("Roberto", "López", "Ufarte"));
		assertTrue(ValidationUtils.isValidPersonName("Roberto", "López", null));
		assertFalse(ValidationUtils.isValidPersonName("", "", null));
		assertFalse(ValidationUtils.isValidPersonName("A", "", null));
		assertTrue(ValidationUtils.isValidPersonName("Ana", "García", null));
		assertTrue(ValidationUtils.isValidPersonName("Ana", "García", "Ribera-De Santos"));
		assertFalse(ValidationUtils.isValidPersonName("Marta Lucía", "Emperador", "x"));
		assertTrue(ValidationUtils.isValidPersonName("Marta Lucía", "Emperador", "Burillo"));
		assertTrue(ValidationUtils.isValidPersonName("Tuco Benedito Pacífico José María", "Ramírez", null));
		assertTrue(ValidationUtils.isValidPersonName("Mariano José", "de Larra", "Sánchez de Castro"));
		assertTrue(ValidationUtils.isValidPersonName("Francisco", "De Goya", "Lucientes"));
		assertTrue(ValidationUtils.isValidPersonName("Ramón Pérez", "de Ayala", "Fernández del Portal"));
		assertTrue(ValidationUtils.isValidPersonName("Vicente", "Fuertes", "De la Huerta"));
		assertTrue(ValidationUtils.isValidPersonName("Vicente", "Fuertes", "Albricias de la Huerta"));
		assertTrue(ValidationUtils.isValidPersonName("Josep", "Puich", "Caldafach"));
	}

	@Test
	void testIsValidCid() {
		assertFalse(ValidationUtils.isValidCid((String) null));
		assertFalse(ValidationUtils.isValidCid(""));
		assertTrue(ValidationUtils.isValidCid("BG+s8q3uzVe3CndviSZO4g=="));
		assertTrue(ValidationUtils.isValidCid("y5Cb_G4R8wUQwtgq+hFu5A=="));
		assertTrue(ValidationUtils.isValidCid("y5Cb_=R8wUQwtgq+hFu5A=="));
		assertTrue(ValidationUtils.isValidCid(
				"Ijt4EsnLXoi+tF8p8CcUfjtytxhv_YWfkzrfplrgaGrzuklDOhP9P_JdEUwR95Mqwx18OAcNXOU1Iy_q6tnvnqPKOwzUAM3EVs8qyZ5MUTC8Rco="));
		assertTrue(ValidationUtils.isValidCid("yCb_G4R8wUQwtgq+hFu5A=="));
		assertTrue(ValidationUtils.isValidCid("5saY3tWmCh5XjRYQR3Dg3CeQw7bjULCuml5x0zu_QRjt0Yn0cjFhRQ=="));
		assertFalse(ValidationUtils.isValidCid(
				"Ijt4EsnLXoi+tF8p8CcUfjtytxhv_YWfkzrfplrgaGrzuklDOhP9P_JdEUwR95Mqw/18OAcNXOU1Iy_q6tnvnqPKOwzUAM3EVs8qyZ5MUTC8Rco="));
	}

	@Test
	void testIsValidPath() {
		assertFalse(ValidationUtils.isValidPath((String) null));
		assertFalse(ValidationUtils.isValidPath(""));
		assertTrue(ValidationUtils.isValidPath("/semilla"));
		assertTrue(ValidationUtils.isValidPath("/semilla/home/"));
		assertTrue(ValidationUtils.isValidPath("/semilla/home"));
		assertFalse(ValidationUtils.isValidPath("semilla"));
		assertFalse(ValidationUtils.isValidPath("semilla-home"));
		assertTrue(ValidationUtils.isValidPath("/Semilla1/hoMe2"));
		assertFalse(ValidationUtils.isValidPath("\\semilla"));
		assertFalse(ValidationUtils.isValidPath("/sem illa/home"));
		assertFalse(ValidationUtils.isValidPath("/2000/"));
		assertTrue(ValidationUtils.isValidPath("/semilla2000/"));
		assertTrue(ValidationUtils.isValidPath("/"));
	}

	@Test
	void testIsValidEmail() {
		assertFalse(ValidationUtils.isValidEmail((String) null));
		assertFalse(ValidationUtils.isValidEmail(""));
		assertTrue(ValidationUtils.isValidEmail("username@domain.com"));
		assertTrue(ValidationUtils.isValidEmail("jose.wairbut@externos.interior.es"));
		assertFalse(ValidationUtils.isValidEmail("user name@domain.com"));
		assertFalse(ValidationUtils.isValidEmail("username#domain.com"));
		assertFalse(ValidationUtils.isValidEmail("usérname@domain.com"));
		assertFalse(ValidationUtils.isValidEmail("username@domain.com."));
		assertTrue(ValidationUtils.isValidEmail("desarrollo@dgims.info.sis"));
		assertTrue(ValidationUtils.isValidEmail("semilla@dgims.info.sis"));
		assertTrue(ValidationUtils.isValidEmail("EstoEsUnTEST2@correo.es"));
	}

	@Test
	void testIsValidDniNie() {
		assertFalse(ValidationUtils.isValidNifNie((String) null));
		assertFalse(ValidationUtils.isValidNifNie(""));
		assertFalse(ValidationUtils.isValidNifNie("1234567890"));
		assertFalse(ValidationUtils.isValidNifNie("         "));
		assertFalse(ValidationUtils.isValidNifNie("arrieta"));
		assertTrue(ValidationUtils.isValidNifNie("48915239N"));
		assertTrue(ValidationUtils.isValidNifNie("X8274102J"));
		assertFalse(ValidationUtils.isValidNifNie("48915239X"));
		assertFalse(ValidationUtils.isValidNifNie("X8275102J"));
		assertFalse(ValidationUtils.isValidNifNie("X827X102J"));
		assertFalse(ValidationUtils.isValidNifNie("489v5239N"));
	}

	@Test
	void testIsValidString() {
		assertFalse(ValidationUtils.isValidString((String) null));
		assertFalse(ValidationUtils.isValidString(""));
		assertFalse(ValidationUtils.isValidString("  "));
		assertTrue(ValidationUtils.isValidString("value"));
		assertTrue(ValidationUtils.isValidString(" value "));
	}

	@Test
	void testIsValidPassword() {
		assertFalse(ValidationUtils.isValidPassword((String) null));
		assertFalse(ValidationUtils.isValidPassword(""));
		assertFalse(ValidationUtils.isValidPassword("t3mp0r4"));
		assertFalse(ValidationUtils.isValidPassword("t3mp0r4l"));
		assertTrue(ValidationUtils.isValidPassword("T3mp0r4l"));
		assertFalse(ValidationUtils.isValidPassword("T3mp0r4"));
		assertTrue(ValidationUtils.isValidPassword("Semilla1"));
		assertFalse(ValidationUtils.isValidPassword("semilla1"));
		assertFalse(ValidationUtils.isValidPassword("SEMILLA1"));
	}

	@Test
	void testValidateLocale() {
		Locale locale = Locale.ENGLISH;
		logger.info("Locale={}", locale);
		locale = Locale.US;
		logger.info("Locale={}", locale);
		locale = Locale.forLanguageTag("en_US");
		logger.info("Locale={}", locale);

		locale = ValidationUtils.validateLocale(null);
		assertNull(locale);
		locale = ValidationUtils.validateLocale("");
		assertNull(locale);
		locale = ValidationUtils.validateLocale("es_ES");
		assertNotNull(locale);
		logger.info("Locale={}", locale);
		assertEquals(CommonBaseConstants.DEFAULT_LOCALE, locale);
		locale = ValidationUtils.validateLocale("en_US");
		assertNotNull(locale);
		logger.info("Locale={}", locale);
		assertEquals(Locale.US, locale);
		locale = ValidationUtils.validateLocale("es");
		assertNotNull(locale);
		locale = ValidationUtils.validateLocale("XX");
		assertNull(locale);
		locale = ValidationUtils.validateLocale("EN");
		assertNull(locale);
		locale = ValidationUtils.validateLocale("en");
		assertNotNull(locale);
		logger.info("Locale={}", locale);
		assertEquals(Locale.ENGLISH, locale);
		locale = ValidationUtils.validateLocale("en_US");
		assertNotNull(locale);
		logger.info("Locale={}", locale);
		assertEquals(Locale.US, locale);

	}

	@Test
	void testIsValidCommaSeparatedValues() {
		assertFalse(ValidationUtils.isValidCommaSeparatedValues((String) null));
		assertFalse(ValidationUtils.isValidCommaSeparatedValues(""));
		assertTrue(ValidationUtils.isValidCommaSeparatedValues("abc"));
		assertTrue(ValidationUtils.isValidCommaSeparatedValues("abc,cdf,xyz,a@s.com"));
		assertTrue(ValidationUtils.isValidCommaSeparatedValues("abc1"));
		assertTrue(ValidationUtils.isValidCommaSeparatedValues("cd-f"));
		assertTrue(ValidationUtils.isValidCommaSeparatedValues(" x_yz "));
		assertTrue(ValidationUtils.isValidCommaSeparatedValues("a@s.com"));
		assertFalse(ValidationUtils.isValidCommaSeparatedValues("ab cd"));
		assertTrue(ValidationUtils.isValidCommaSeparatedValues("abc1,cd-f, x_yz,a@s.com"));
		assertFalse(ValidationUtils.isValidCommaSeparatedValues("abc;cdf; xyz"));
	}

	@Test
	void testIsValidHttpUrl() {
		assertFalse(ValidationUtils.isValidHttpUrl(null));
		assertFalse(ValidationUtils.isValidHttpUrl(""));
		assertTrue(ValidationUtils.isValidHttpUrl("http://localhost:8080/semilla-sb-back/con/restablecer"));
		assertTrue(ValidationUtils.isValidHttpUrl("http://127.0.0.1:4200/semilla-angular/#/con/restablecer"));
		assertFalse(ValidationUtils.isValidHttpUrl("localhost:8080/semilla-sb-back/con/restablecer"));
		assertFalse(ValidationUtils.isValidHttpUrl("localhost:8080\\semilla-sb-back\\con\\restablecer"));
		assertFalse(ValidationUtils.isValidHttpUrl("semilla-sb-back/con/restablecer"));
		assertTrue(ValidationUtils.isValidHttpUrl("http://localhost:8080"));
		assertTrue(ValidationUtils.isValidHttpUrl("http://localhost/"));
		assertFalse(ValidationUtils.isValidHttpUrl("semilla-sb-back"));
	}

	@Test
	void testIsValidThingName() {
		assertFalse(ValidationUtils.isValidThingName((String) null, 0));
		assertFalse(ValidationUtils.isValidThingName((String) null, 1));
		assertFalse(ValidationUtils.isValidThingName("", 1));
		assertFalse(ValidationUtils.isValidThingName("A", 0));
		assertTrue(ValidationUtils.isValidThingName("A", 1));
		assertTrue(ValidationUtils.isValidThingName("A", 2));
		assertTrue(ValidationUtils.isValidThingName("a", 2));
		assertTrue(ValidationUtils.isValidThingName("Á", 2));
		assertFalse(ValidationUtils.isValidThingName("Organización", 2));
		assertTrue(ValidationUtils.isValidThingName("Organización", 50));
		assertTrue(ValidationUtils.isValidThingName("Organización para la Cooperación Conjunta en Materia de Armamento",
				100));
		assertTrue(ValidationUtils.isValidThingName("organización", 50));
		assertTrue(ValidationUtils.isValidThingName("Organización 1", 50));
		assertFalse(ValidationUtils.isValidThingName("Organización %", 50));
		assertTrue(ValidationUtils.isValidThingName("ALTA/CLASIFICACIÓN", 50));
		assertTrue(ValidationUtils.isValidThingName("ALTA_CLASIFICACIÓN", 50));
		assertTrue(ValidationUtils.isValidThingName("ALTA-CLASIFICACIÓN", 50));
	}

	@Test
	void testIsValidText() {
		assertFalse(ValidationUtils.isValidText((String) null, 0));
		assertFalse(ValidationUtils.isValidText((String) null, 1));
		assertFalse(ValidationUtils.isValidText("", 1));
		assertFalse(ValidationUtils.isValidText(" ", 1));
		assertTrue(ValidationUtils.isValidText("A", 1));
		assertTrue(ValidationUtils.isValidText("a", 1));
		assertFalse(ValidationUtils.isValidText("An", 1));
		assertTrue(ValidationUtils.isValidText(
				"Desclasificación: necesita firma de la Autoridad o Responsable de la desclasificación final; inmunidad ilimitada, y brezas del bosque.",
				300));
	}

	@Test
	void testIsNullOrValidText() {
		assertTrue(ValidationUtils.isNullOrValidText((String) null, 0));
		assertTrue(ValidationUtils.isNullOrValidText((String) null, 1));
		assertFalse(ValidationUtils.isNullOrValidText("", 1));
		assertFalse(ValidationUtils.isNullOrValidText(" ", 1));
		assertTrue(ValidationUtils.isNullOrValidText("A", 1));
		assertTrue(ValidationUtils.isNullOrValidText("a", 1));
		assertFalse(ValidationUtils.isNullOrValidText("An", 1));
		assertTrue(ValidationUtils.isNullOrValidText(
				"Desclasificación: necesita firma de la Autoridad o Responsable de la desclasificación final; inmunidad ilimitada, y brezas del bosque.",
				300));
	}

	@Test
	void testIsNullOrValidThingName() {
		assertTrue(ValidationUtils.isNullOrValidThingName((String) null, 0));
		assertTrue(ValidationUtils.isNullOrValidThingName((String) null, 1));
		assertFalse(ValidationUtils.isNullOrValidThingName("", 1));
		assertFalse(ValidationUtils.isNullOrValidThingName("A", 0));
		assertTrue(ValidationUtils.isNullOrValidThingName("A", 1));
		assertTrue(ValidationUtils.isNullOrValidThingName("A", 2));
		assertTrue(ValidationUtils.isNullOrValidThingName("a", 2));
		assertTrue(ValidationUtils.isNullOrValidThingName("Á", 2));
		assertFalse(ValidationUtils.isNullOrValidThingName("Organización", 2));
		assertTrue(ValidationUtils.isNullOrValidThingName("Organización", 50));
		assertTrue(ValidationUtils
				.isNullOrValidThingName("Organización para la Cooperación Conjunta en Materia de Armamento", 100));
	}

	@Test
	void testIsValidCif() {
		assertFalse(ValidationUtils.isValidCif((String) null));
		assertFalse(ValidationUtils.isValidCif(""));
		assertFalse(ValidationUtils.isValidCif("1234567890"));
		assertFalse(ValidationUtils.isValidCif("         "));
		assertFalse(ValidationUtils.isValidCif("arrieta"));
		assertFalse(ValidationUtils.isValidCif("48915239N"));
		assertFalse(ValidationUtils.isValidCif("X8274102J"));
		assertTrue(ValidationUtils.isValidCif("S8155931B"));
		assertTrue(ValidationUtils.isValidCif("A15830516"));
		assertTrue(ValidationUtils.isValidCif("U62974357"));
		assertTrue(ValidationUtils.isValidCif("A03642980"));
		assertFalse(ValidationUtils.isValidCif("G02A22944"));
		assertFalse(ValidationUtils.isValidCif("G02532944"));
		assertTrue(ValidationUtils.isValidCif("G02522944"));
		assertTrue(ValidationUtils.isValidCif("S5732597I"));
		assertTrue(ValidationUtils.isValidCif("W4665249A"));
		assertTrue(ValidationUtils.isValidCif("V42340687"));
	}

	@Test
	void testIsValidNifNieCif() {
		assertFalse(ValidationUtils.isValidNifNieCif((String) null));
		assertFalse(ValidationUtils.isValidNifNieCif(""));
		assertFalse(ValidationUtils.isValidNifNieCif("1234567890"));
		assertFalse(ValidationUtils.isValidNifNieCif("         "));
		assertFalse(ValidationUtils.isValidNifNieCif("arrieta"));
		assertTrue(ValidationUtils.isValidNifNieCif("48915239N"));
		assertTrue(ValidationUtils.isValidNifNieCif("X8274102J"));
		assertTrue(ValidationUtils.isValidNifNieCif("S8155931B"));
		assertTrue(ValidationUtils.isValidNifNieCif("A15830516"));
		assertFalse(ValidationUtils.isValidNifNieCif("48915239X"));
		assertFalse(ValidationUtils.isValidNifNieCif("G02532944"));
	}

}
