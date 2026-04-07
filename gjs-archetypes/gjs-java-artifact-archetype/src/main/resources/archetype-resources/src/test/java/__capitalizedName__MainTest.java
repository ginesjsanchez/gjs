#set( $symbol_pound = '#' )
#set( $symbol_dollar = '$' )
#set( $symbol_escape = '\' )
#set( $capitalizedName = $shortName.substring(0,1).toUpperCase() + $shortName.substring(1))
package ${package};


import static org.junit.jupiter.api.Assertions.fail;

import org.junit.jupiter.api.Test;

import org.gjs.java.test.BaseClassTest;


class ${capitalizedName}MainTest extends BaseClassTest<${capitalizedName}Main> {

    @Override
    protected void prepareTest() throws Exception {
    }

    @Test
    void testMain_NullParams() {
		String[] args = null;
		try {
			${capitalizedName}Main.main(args);
			
		} catch(Exception ex) {
			logger.error(ex.getMessage(), ex);
			fail("Excepcion inesperada");
		}	
    }

    @Test
    void testMain_EmptyParams() {
		String[] args = new String[] {};
		try {
			${capitalizedName}Main.main(args);
			
		} catch(Exception ex) {
			logger.error(ex.getMessage(), ex);
			fail("Excepcion inesperada");
		}	
    }

    @Test
    void testMain_WithParams() {
		String[] args = new String[] { "param1", "param2" };
		try {
			${capitalizedName}Main.main(args);
			
		} catch(Exception ex) {
			logger.error(ex.getMessage(), ex);
			fail("Excepcion inesperada");
		}	
    }
}
