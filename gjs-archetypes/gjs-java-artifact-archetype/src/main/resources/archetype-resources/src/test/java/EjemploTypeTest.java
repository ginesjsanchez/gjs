#set( $symbol_pound = '#' )
#set( $symbol_dollar = '$' )
#set( $symbol_escape = '\' )
#set( $capitalizedNombre = $shortNombre.substring(0,1).toUpperCase() + $shortNombre.substring(1))
package ${package};



import static org.junit.jupiter.api.Assertions.assertEquals;
import static org.junit.jupiter.api.Assertions.assertFalse;
import static org.junit.jupiter.api.Assertions.assertNotNull;
import static org.junit.jupiter.api.Assertions.assertNull;
import static org.junit.jupiter.api.Assertions.assertTrue;


import org.junit.jupiter.api.Test;

import org.gjs.java.test.BaseClassTest;


class EjemploTypeTest extends BaseClassTest<EjemploType> {

    @Override
    protected void prepareTest() throws Exception {
    }

    @Test
    void testEjemploType() {
        final EjemploType value1 = new EjemploType();
        logger.info("Object={}", value1.toString());
        assertNull(value1.getNombre());
        assertNull(value1.getDescripcion());
        assertFalse(value1.isValid());
        assertEquals(31, value1.hashCode());
        assertNotNull(value1.toString());

        final EjemploType value2 = new EjemploType();
		value2.setNombre("obj2");
		value2.setDescripcion("Este es el objeto obj2");
        logger.info("Object={}", value2.toString());
        assertNotNull(value2.getNombre());
        assertNotNull(value2.getDescripcion());
        assertTrue(value2.isValid());
        assertTrue(value2.hashCode() > 0);
        assertNotNull(value1.toString());

        final EjemploType value3 = new EjemploType();
		value3.setNombre("obj3");
		value3.setDescripcion("Este es el objeto obj3");
        final EjemploType value4 = new EjemploType();
		value4.setNombre("obj2");
		value4.setDescripcion("Este es el objeto obj4");

        assertFalse(value1.equals(value2));
        assertFalse(value2.equals(value1));
        assertFalse(value1.equals(null));
        assertFalse(value2.equals(null));

        assertFalse(value1.equals(value3));
        assertFalse(value2.equals(value3));
        assertFalse(value1.equals(value4));
		assertTrue(value2.equals(value4));
        assertFalse(value3.equals(value1));
        assertFalse(value3.equals(value2));
		assertFalse(value4.equals(value1));
		assertTrue(value4.equals(value2));
    }

}
