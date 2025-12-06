package org.gjs.java.test;

import static org.junit.jupiter.api.Assertions.fail;

import java.nio.file.FileSystems;
import java.nio.file.Path;
import java.nio.file.Paths;

import org.gjs.java.supplier.testinggame.TestingGamesSingleton;
import org.gjs.java.test.junit.GjsJUnitExtension;
import org.junit.jupiter.api.extension.ExtendWith;

/**
 * The Class AbstractUnitTest.
 *
 * Clase abstracta funcional de la librería Semilla
 *
 * Clase abstracta base para todos los test unitarios de la librería Semilla
 *
 * --------------------------------------------------------------------------------------------------------------------
 * Este software es propiedad del Ministerio del Interior CETSE - 2025
 *
 * Queda estrictamente prohibido el uso de programas informáticos sin la correspondiente licencia en los activos de la
 * SES. Los programas informáticos propiedad de la SES están protegidos por la propiedad intelectual, y por tanto está
 * estrictamente prohibida su reproducción, modificación, cesión o comunicación sin la debida autorización. Queda
 * estrictamente prohibido el uso, reproducción, cesión, transformación o comunicación pública de cualquier otro tipo de
 * obra o invención protegida por la propiedad intelectual sin la debida autorización.
 *
 * Subdirección General de Sistemas de la Información y Comunicaciones para la Seguridad Ministerio del Interior
 * Gobierno de España
 * --------------------------------------------------------------------------------------------------------------------
 *
 * @author Semilla
 * @version 4.0.0
 * @since 3.0.0
 *
 */
@ExtendWith(GjsJUnitExtension.class)
public abstract class AbstractUnitTest extends AbstractClassTest {

    /** The line sep. */
    protected static String lineSep = System.lineSeparator();

    /** The file sep. */
    protected static String fileSep = FileSystems.getDefault().getSeparator();

    /** The current dir. */
    protected Path currentDir;

    /** The results dir. */
    protected Path resultsDir;

    /**
     * Initialize.
     *
     * @throws Exception
     *             the exception
     */
    protected void initialize() throws Exception {
        logger.debug("Empty initialize: maybe you should overwrite it?");
        TestingGamesSingleton.getInstance().setLogger(logger);
    }

    /**
     * Prepare Test.
     */
    @Override
    protected void prepareTest() {
        try {
            currentDir = Paths.get("").resolve("target/test-classes");
            resultsDir = currentDir.resolve("results");
            logger.debug("Directorio de ejecucion : {}", currentDir.toFile().getAbsolutePath());
            logger.debug("Directorio de resultados: {}", resultsDir.toFile().getAbsolutePath());
            if (!resultsDir.toFile().exists()) {
                resultsDir.toFile().mkdirs();
            }
            initialize();
        } catch (final Exception e) {
            logger.error("Error inicializando los datos para el test", e);
            fail("Error inicializando los datos para el test");
        }
    }

}
