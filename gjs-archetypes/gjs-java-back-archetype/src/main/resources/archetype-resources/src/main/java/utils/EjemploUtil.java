#set( $symbol_pound = '#' )
#set( $symbol_dollar = '$' )
#set( $symbol_escape = '\' )
package ${package}.util;

import org.apache.commons.lang3.StringUtils;

import es.mir.semilla.util.ValidationUtil;
import es.mir.semilla.util.common.ConditionUtils;
import ${package}.util.Constantes${nombreCapitalizado}.${nombreCapitalizado}EntityFieldSizes;

/**
 * The Class ${nombreCapitalizado}ValidationUtil.
 *
 * Clase de utilidades generales de la aplicación ${nombreCapitalizado}
 *
 * Funciones de validación particulares.
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
 * @version 1.0.0
 * @since 1.0.0
 *
 */
public class ${nombreCapitalizado}ValidationUtil {

	// TODO: Incluir validaciones específicas de la aplicacion
    /** The Constant TIPO_CLASIFICACION_EXT_CODE_PATTERN. */
    private static final String NOMBRE_EJEMPLO_CODE_PATTERN = "^[a-zA-Z][a-zA-Z0-9]*";

    public static boolean isValidNombreEjemplo(String name) {
        final int length = StringUtils.length(name);
        return ConditionUtils.allAreTrue((length > 0), (length <= ${nombreCapitalizado}EntityFieldSizes.EJEMPLO_NOMBRE),
                ValidationUtil.meetsPattern(StringUtils.stripAccents(name), NOMBRE_EJEMPLO_CODE_PATTERN));
    }

}
