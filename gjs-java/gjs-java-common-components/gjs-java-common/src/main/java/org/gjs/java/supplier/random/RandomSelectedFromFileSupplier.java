package org.gjs.java.supplier.random;

import java.io.IOException;
import java.util.List;

import org.springframework.core.io.ClassPathResource;
import org.springframework.core.io.Resource;

import org.gjs.java.files.FileLines;

/**
 * The Class RandomSelectedFromFileSupplier.
 *
 * Clase de datos de la librería Semilla
 *
 * Selector aleatorio de valores importados de un fichero.
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
public class RandomSelectedFromFileSupplier extends RandomSelectedStringSupplier {

    /**
     * Instantiates a new random selected from file supplier.
     *
     * @param txtFile
     *            the txt file
     * @throws IOException
     *             Signals that an I/O exception has occurred.
     */
    public RandomSelectedFromFileSupplier(String txtFile) throws IOException {
        final Resource resource = new ClassPathResource(txtFile);
        final FileLines file = new FileLines(resource.getFile());
        final List<String> options = file.getLines();
        setOptions(options);
        setNullable(false);
    }

}
