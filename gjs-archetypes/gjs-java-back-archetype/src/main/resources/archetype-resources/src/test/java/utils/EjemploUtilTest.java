package ${package}.util;

import static org.junit.jupiter.api.Assertions.assertFalse;
import static org.junit.jupiter.api.Assertions.assertTrue;

import org.junit.jupiter.api.Test;

import es.mir.semilla.util.test.BaseUnitTest;

class ${nombreCapitalizado}ValidationUtilTest extends BaseUnitTest<${nombreCapitalizado}ValidationUtil> {

    @Override
    protected void initialize() throws Exception {
    }

    @Test
    void testIsValidNombreEjemplo3() {
        assertFalse(${nombreCapitalizado}ValidationUtil.isValidNombreEjemplo((String) null));
        assertFalse(${nombreCapitalizado}ValidationUtil.isValidNombreEjemplo(""));
        assertTrue(${nombreCapitalizado}ValidationUtil.isValidNombreEjemplo("A"));
        assertTrue(${nombreCapitalizado}ValidationUtil.isValidNombreEjemplo("Abc"));
        assertTrue(${nombreCapitalizado}ValidationUtil.isValidNombreEjemplo("Abc1"));
        assertFalse(${nombreCapitalizado}ValidationUtil.isValidNombreEjemplo("Abc1%"));
        assertFalse(${nombreCapitalizado}ValidationUtil.isValidNombreEjemplo("Abc c1"));
        assertFalse(${nombreCapitalizado}ValidationUtil.isValidNombreEjemplo("AbcdefghijklmnopqrstuvxyzAbcdefghijklmnopqrstuvxyzAbcd"));
        assertTrue(${nombreCapitalizado}ValidationUtil.isValidNombreEjemplo("AbcdefghijklmnopqrstuvxyzAbcdefghijklmnopqrstuvxyz"));
    }

}
