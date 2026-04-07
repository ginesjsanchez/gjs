#set( $symbol_pound = '#' )
#set( $symbol_dollar = '$' )
#set( $symbol_escape = '\' )
#set( $capitalizedName = $shortName.substring(0,1).toUpperCase() + $shortName.substring(1))
package ${package}.utils;

import org.apache.commons.lang3.StringUtils;

import org.gjs.java.common.util.ConditionUtils;
import org.gjs.java.common.util.ValidationUtils;

/**
 * The Class EjemploUtils.
 *
 * Clase de utilidades generales de la aplicación ${capitalizedName}
 *
 * TODO.
 *
 * --------------------------------------------------------------------------------------------------------------------
 * @author GJ Software
 * @version 1.0.0
 * @since 1.0.0
 *
 */
public class EjemploUtils {

    /** The Constant TIPO_CLASIFICACION_EXT_CODE_PATTERN. */
    private static final String NOMBRE_EJEMPLO_CODE_PATTERN = "^[a-zA-Z][a-zA-Z0-9]*";

    public static boolean isValidNombre(String name) {
        final int length = StringUtils.length(name);
        return ConditionUtils.allAreTrue((length > 0),
                ValidationUtils.meetsPattern(StringUtils.stripAccents(name), NOMBRE_EJEMPLO_CODE_PATTERN));
    }

}
