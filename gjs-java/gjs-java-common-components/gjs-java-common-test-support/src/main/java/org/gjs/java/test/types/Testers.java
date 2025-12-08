package org.gjs.java.test.types;

import com.openpojo.validation.test.Tester;
import com.openpojo.validation.test.impl.SetterTester;

/**
 * The Class Testers.
 *
 * Clase de datos de la librería Gjs
 *
 * Clase pensada para incluir testers especiales que puedan definirse en las aplicaciones para test Pojos automatizados
 * de clases especiales.
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
public class Testers {

    /** The setter tester. */
    // Todo: ampliar a la customizacion de todos los tipos de testers
    private final Tester setterTester;

    /**
     * Instantiates a new testers.
     */
    public Testers() {
        this(new SetterTester());
    }

    /**
     * Instantiates a new testers.
     *
     * @param setterTester
     *            the setter tester
     */
    public Testers(Tester setterTester) {
        this.setterTester = setterTester;
    }

    /**
     * Gets the setter tester.
     *
     * @return the setter tester
     */
    public Tester getSetterTester() {
        return setterTester;
    }

}
