#set( $symbol_pound = '#' )
#set( $symbol_dollar = '$' )
#set( $symbol_escape = '\' )
package ${package}.util.dto;

import org.apache.logging.log4j.LogManager;
import org.apache.logging.log4j.Logger;
import org.junit.jupiter.api.Test;

import es.mir.semilla.util.test.AbstractPojosTest;

/**
 *
 */
class PojosTest extends AbstractPojosTest {

    private static final Logger logger = LogManager.getLogger(PojosTest.class);

    /**
     * @return logger
     */
    @Override
    protected Logger getLogger() {
        return logger;
    }

    /**
     * @return package to test
     */
    @Override
    protected String getPojoPackage() {
        return getClass().getPackage().getName();
    }

    /**
     *
     */
    @Test
    void testPojos() {
        testPojoClasses("GenericDto");
    }

}
