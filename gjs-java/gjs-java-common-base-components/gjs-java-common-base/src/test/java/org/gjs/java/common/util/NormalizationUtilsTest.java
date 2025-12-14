package org.gjs.java.common.util;

import static org.junit.jupiter.api.Assertions.assertEquals;
import static org.junit.jupiter.api.Assertions.assertNotNull;
import static org.junit.jupiter.api.Assertions.assertNull;

import org.junit.jupiter.api.Test;
import org.gjs.java.common.util.NormalizationUtils;
import org.gjs.java.test.BaseClassTest;

class NormalizationUtilsTest extends BaseClassTest<NormalizationUtils> {

    @Test
    void testNormalizeAttributeName() {
        String field = NormalizationUtils.normalizeAttributeName(null);
        assertNull(field);
        field = NormalizationUtils.normalizeAttributeName("");
        assertNull(field);
        field = NormalizationUtils.normalizeAttributeName("_-.");
        assertNull(field);
        field = NormalizationUtils.normalizeAttributeName("ID");
        assertNotNull(field);
        assertEquals("id", field);
        field = NormalizationUtils.normalizeAttributeName("ID_ROL");
        assertNotNull(field);
        assertEquals("idRol", field);
        field = NormalizationUtils.normalizeAttributeName("id");
        assertNotNull(field);
        assertEquals("id", field);
        field = NormalizationUtils.normalizeAttributeName("idRol");
        assertNotNull(field);
        assertEquals("idRol", field);
        field = NormalizationUtils.normalizeAttributeName("ID__ROL_");
        assertNotNull(field);
        assertEquals("idRol", field);
        field = NormalizationUtils.normalizeAttributeName("7");
        assertNotNull(field);
        assertEquals("7", field);
        field = NormalizationUtils.normalizeAttributeName("Nombre_1");
        assertNotNull(field);
        assertEquals("nombre1", field);
        field = NormalizationUtils.normalizeAttributeName("NomBRE.7.");
        assertNotNull(field);
        assertEquals("nomBre7", field);
    }

}
