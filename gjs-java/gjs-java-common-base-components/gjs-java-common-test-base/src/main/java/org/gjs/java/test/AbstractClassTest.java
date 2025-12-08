package org.gjs.java.test;

import java.util.Objects;

import org.slf4j.LoggerFactory;

/**
 * The Class AbstractClassTest.
 *
 * Clase abstracta funcional de la librería Gjs
 *
 * Clase abstracta base para todos los test de clases de la librería Gjs
 *
 * --------------------------------------------------------------------------------------------------------------------
 *
 *
 * correspondiente licencia en los activos de la
 * SES. Los programas informáticos propiedad de la SES están protegidos por la propiedad intelectual, y por tanto está
 * estrictamente prohibida su reproducción, modificación, cesión o comunicación sin la debida autorización. Queda
 * estrictamente prohibido el uso, reproducción, cesión, transformación o comunicación pública de cualquier otro tipo de
 * obra o invención protegida por la propiedad intelectual sin la debida autorización.
 *
 *  Seguridad Ministerio del Interior
 * Gobierno de España
 * --------------------------------------------------------------------------------------------------------------------
 *
 * @author Gjs
 * @version 1.0.0
 * @since 1.0.0
 *
 */
public abstract class AbstractClassTest extends AbstractTest {

    /**
     * Gets the clazz.
     *
     * @return the clazz
     */
    protected abstract Class<?> getClazz();

    /* (non-Javadoc)
     *
     * @see org.gjs.java.test.AbstractTest#initializeLogger() */

    @Override
    protected void initializeLogger() {
        logger = LoggerFactory.getLogger(this.getClass());
        logger.info("INICIO Test de la clase {}", getClassName());
    }

    /* (non-Javadoc)
     *
     * @see org.gjs.java.test.AbstractTest#finalizeLogger() */

    @Override
    protected void finalizeLogger() {
        logger.info("FIN Test de la clase {}", getClassName());
    }

    private String getClassName() {
        String res = "<Ninguna>";
        if (Objects.nonNull(getClazz())) {
            res = getClazz().getName();
        }
        return res;
    }

    /* (non-Javadoc)
     *
     * @see org.gjs.java.test.AbstractTest#prepareTest() */

    @Override
    protected void prepareTest() {
        // Implementación por defecto: No hace falta hacer nada
    }

    /* (non-Javadoc)
     *
     * @see org.gjs.java.test.AbstractTest#finalizeTest() */

    @Override
    protected void finalizeTest() {
        // Implementación por defecto: No hace falta hacer nada
    }

}
