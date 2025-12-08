package org.gjs.java.test;

import org.gjs.java.test.tester.ExceptionTester;

/**
 * The Class AbstractExceptionTest.
 *
 * Clase abstracta funcional de la librería Gjs
 *
 * Clase abstracta base para todos los test unitarios Pojos de paquetes de excepciones de la librería Gjs
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
public abstract class AbstractExceptionTest extends AbstractPackageTest {

    /**
     * Instantiates a new abstract exception test.
     */
    public AbstractExceptionTest() {
        super(new ExceptionTester());
    }

    /**
     * Gets the tester.
     *
     * @return the tester
     */
    public ExceptionTester getTester() {
        return ((ExceptionTester) testers.get(0));
    }

    /**
     * Adds the special parameter.
     *
     * @param className
     *            the class name
     * @param defaultObj
     *            the default obj
     */
    public void addSpecialParameter(String className, Object defaultObj) {
        getTester().addSpecialParameter(className, defaultObj);
    }

}
