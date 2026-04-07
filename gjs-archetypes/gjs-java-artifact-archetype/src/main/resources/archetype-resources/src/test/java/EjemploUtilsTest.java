#set( $symbol_pound = '#' )
#set( $symbol_dollar = '$' )
#set( $symbol_escape = '\' )
#set( $capitalizedName = $shortName.substring(0,1).toUpperCase() + $shortName.substring(1))
package ${package};



import static org.junit.jupiter.api.Assertions.assertFalse;
import static org.junit.jupiter.api.Assertions.assertTrue;

import org.junit.jupiter.api.Test;

import org.gjs.java.test.BaseClassTest;


class EjemploUtilsTest extends BaseClassTest<EjemploUtils> {

    @Override
    protected void prepareTest() throws Exception {
    }

    @Test
    void testIsValidNombre() {
        assertFalse(EjemploUtils.isValidNombre((String) null));
        assertFalse(EjemploUtils.isValidNombre(""));
        assertTrue(EjemploUtils.isValidNombre("A"));
        assertTrue(EjemploUtils.isValidNombre("Abc"));
        assertTrue(EjemploUtils.isValidNombre("Abc1"));
        assertFalse(EjemploUtils.isValidNombre("Abc1%"));
        assertFalse(EjemploUtils.isValidNombre("Abc c1"));
		assertTrue(EjemploUtils.isValidNombre("AbcdèfghíjklmñòpqrstûvxyzAbcdefghijklmnopqrstuvxyzAbcd"));
        assertTrue(EjemploUtils.isValidNombre("AbcdefghijklmnopqrstuvxyzAbcdefghijklmnopqrstuvxyz"));
        assertFalse(EjemploUtils.isValidNombre("1Abc"));
        assertTrue(EjemploUtils.isValidNombre("Abc1"));
        assertTrue(EjemploUtils.isValidNombre("abc1"));
    }

}
