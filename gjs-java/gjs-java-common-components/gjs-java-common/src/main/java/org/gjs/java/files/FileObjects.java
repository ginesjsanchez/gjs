package org.gjs.java.files;

import java.io.File;
import java.nio.file.Path;
import java.util.ArrayList;
import java.util.List;

import org.apache.commons.lang3.StringUtils;
import org.springframework.util.CollectionUtils;

import org.gjs.java.common.ConditionUtils;
import org.gjs.java.common.NormalizationUtils;
import org.gjs.java.types.DataObject;

/**
 * The Class FileObjects.
 *
 * Clase de datos de la librería Semilla
 *
 * Facilita el manejo un fichero de texto plano visto como una secuencia de objetos con sus atributos.
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
public class FileObjects extends FileSheet {

    /** The objects. */
    private List<DataObject> objects;

    /**
     * Instantiates a new file objects.
     */
    public FileObjects() {
        // No hace nada
    }

    /**
     * Instantiates a new file objects.
     *
     * @param separator
     *            the separator
     */
    public FileObjects(char separator) {
        super(separator);
    }

    /**
     * Instantiates a new file objects.
     *
     * @param path
     *            the path
     */
    public FileObjects(String path) {
        super(path);
    }

    /**
     * Instantiates a new file objects.
     *
     * @param directory
     *            the directory
     * @param name
     *            the name
     */
    public FileObjects(String directory, String name) {
        super(directory, name);
    }

    /**
     * Instantiates a new file objects.
     *
     * @param separator
     *            the separator
     * @param path
     *            the path
     */
    public FileObjects(char separator, String path) {
        super(separator, path);
    }

    /**
     * Instantiates a new file objects.
     *
     * @param separator
     *            the separator
     * @param directory
     *            the directory
     * @param name
     *            the name
     */
    public FileObjects(char separator, String directory, String name) {
        super(separator, directory, name);
    }

    /**
     * Instantiates a new file objects.
     *
     * @param file
     *            the file
     */
    public FileObjects(File file) {
        super(file);
    }

    /**
     * Instantiates a new file objects.
     *
     * @param separator
     *            the separator
     * @param file
     *            the file
     */
    public FileObjects(char separator, File file) {
        super(separator, file);
    }

    /**
     * Instantiates a new file objects.
     *
     * @param path
     *            the path
     */
    public FileObjects(Path path) {
        super(path);
    }

    /**
     * Instantiates a new file objects.
     *
     * @param separator
     *            the separator
     * @param path
     *            the path
     */
    public FileObjects(char separator, Path path) {
        super(separator, path);
    }

    /* (non-Javadoc)
     *
     * @see org.gjs.java.files.FileSheet#init() */

    @Override
    public void init() {
        super.init();
        objects = new ArrayList<>();
    }

    /* (non-Javadoc)
     *
     * @see org.gjs.java.files.FileSheet#loadContent(java.lang.String) */

    @Override
    protected boolean loadContent(String path) {
        final boolean res = super.loadContent(path);
        if (ConditionUtils.allAreTrue(super.isValid(), columnsAreValid())) {
            for (int row = 0; row < super.rows(); row = row + 1) {
                final DataObject data = new DataObject();
                for (int col = 0; col < super.columns(); col = col + 1) {
                    final String attribute = NormalizationUtils.normalizeAttributeName(super.getColumnName(col));
                    data.setValue(attribute, super.getValue(row, col));
                }
                objects.add(data);
            }
        }
        return (res);
    }

    /* (non-Javadoc)
     *
     * @see org.gjs.java.files.FileSheet#isValid() */

    @Override
    public boolean isValid() {
        return ConditionUtils.allAreTrue(super.isValid(), columnsAreValid(), (objects.size() == super.rows()));
    }

    /**
     * Count.
     *
     * @return the int
     */
    public int count() {
        return objects.size();
    }

    /**
     * Attributes.
     *
     * @return the int
     */
    public int attributes() {
        return super.columns();
    }

    /**
     * Gets the attribute.
     *
     * @param column
     *            the column
     * @return the attribute
     */
    public String getAttribute(int column) {
        return NormalizationUtils.normalizeAttributeName(super.getColumnName(column));
    }

    /**
     * Gets the objects.
     *
     * @return the objects
     */
    public List<DataObject> getObjects() {
        return objects;
    }

    /**
     * Gets the object.
     *
     * @param row
     *            the row
     * @return the object
     */
    public DataObject getObject(int row) {
        DataObject data = null;
        if (validRow(row)) {
            data = objects.get(row);
        }
        return data;
    }

    /**
     * Adds the object.
     *
     * @return the data object
     */
    public DataObject addObject() {
        DataObject data = null;
        if (attributes() > 0) {
            data = new DataObject();
            for (int col = 0; col < super.columns(); col = col + 1) {
                final String attribute = NormalizationUtils.normalizeAttributeName(super.getColumnName(col));
                data.setValue(attribute, null);
            }
            addObject(data);
        }
        return data;
    }

    /**
     * Adds the object.
     *
     * @param value
     *            the value
     */
    public void addObject(DataObject value) {
        if (ConditionUtils.oneIsTrue(CollectionUtils.isEmpty(objects), (value.numFields() == columns()))) {
            objects.add(value);
            super.addRow(values(value));
        }
    }

    /**
     * Sets the object.
     *
     * @param row
     *            the row
     * @param value
     *            the value
     */
    public void setObject(int row, DataObject value) {
        if (ConditionUtils.allAreTrue(validRow(row), (value.numFields() == columns()))) {
            objects.set(row, value);
            super.setRow(row, values(value));
        }
    }

    /* (non-Javadoc)
     *
     * @see org.gjs.java.files.FileSheet#setColumnNames(java.util.ArrayList) */

    @Override
    public void setColumnNames(List<String> names) {
        if (objects.isEmpty()) {
            super.setColumnNames(names);
        }
    }

    /* (non-Javadoc)
     *
     * @see org.gjs.java.files.FileSheet#clearData() */

    @Override
    public void clearData() {
        super.clearData();
        objects.clear();
    }

    /* (non-Javadoc)
     *
     * @see org.gjs.java.files.FileSheet#setColumnNames(java.lang.String[]) */

    @Override
    public void setColumnNames(String... names) {
        if (objects.isEmpty()) {
            super.setColumnNames(names);
        }
    }

    /* (non-Javadoc)
     *
     * @see org.gjs.java.files.FileSheet#setColumnName(int, java.lang.String) */

    @Override
    public void setColumnName(int column, String name) {
        if (objects.isEmpty()) {
            super.setColumnName(column, name);
        }
    }

    /* (non-Javadoc)
     *
     * @see org.gjs.java.files.FileSheet#addRow(java.util.ArrayList) */

    @Override
    public void addRow(List<String> values) {
        // No hace nada
    }

    /* (non-Javadoc)
     *
     * @see org.gjs.java.files.FileSheet#addRow(java.lang.String[]) */

    @Override
    public void addRow(String... values) {
        // No hace nada
    }

    /* (non-Javadoc)
     *
     * @see org.gjs.java.files.FileSheet#setValue(int, int, java.lang.String) */

    @Override
    public void setValue(int row, int column, String value) {
        // No hace nada
    }

    /* (non-Javadoc)
     *
     * @see org.gjs.java.files.FileSheet#setRow(int, java.util.ArrayList) */

    @Override
    public void setRow(int row, List<String> values) {
        // No hace nada
    }

    /* (non-Javadoc)
     *
     * @see org.gjs.java.files.FileSheet#setRow(int, java.lang.String[]) */

    @Override
    public void setRow(int row, String... values) {
        // No hace nada
    }

    /**
     * Values.
     *
     * @param value
     *            the value
     * @return the array list
     */
    private ArrayList<String> values(DataObject value) {
        final ArrayList<String> values = new ArrayList<>();
        for (int col = 0; col < super.columns(); col = col + 1) {
            final String attribute = NormalizationUtils.normalizeAttributeName(super.getColumnName(col));
            values.add((String) value.getValue(attribute));
        }
        return values;
    }

    /**
     * Valid row.
     *
     * @param row
     *            the row
     * @return true, if successful
     */
    private boolean validRow(int row) {
        return ConditionUtils.allAreTrue((row >= 0), (row < objects.size()));
    }

    /**
     * Columns are valid.
     *
     * @return true, if successful
     */
    private boolean columnsAreValid() {
        boolean res = true;
        for (int col = 0; col < super.columns(); col = col + 1) {
            final String attribute = NormalizationUtils.normalizeAttributeName(super.getColumnName(col));
            if (StringUtils.isAllBlank(attribute)) {
                res = false;
                break;
            }
        }
        return res;
    }
}
