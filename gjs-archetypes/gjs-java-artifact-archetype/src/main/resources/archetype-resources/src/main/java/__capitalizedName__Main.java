#set( $symbol_pound = '#' )
#set( $symbol_dollar = '$' )
#set( $symbol_escape = '\' )
#set( $capitalizedName = $shortName.substring(0,1).toUpperCase() + $shortName.substring(1))
package ${package};


/**
 * The Class ${capitalizedName}Main.
 *
 * Clase principal del artefacto ${capitalizedName}Main
 *
 * TODO
 *
 * --------------------------------------------------------------------------------------------------------------------
 * @author GJ Software
 * @version 1.0.0
 * @since 1.0.0
 *
 **/
 public class ${capitalizedName}Main {

	/**
	 * Text blocks sample.
	 */
	private static void textBlocksSample() {
		int año = 2024;
		String nombre = "Mundo";
		// Text blocks (Java 15+)
		String mensaje = """
				¡Hola, %s!
				Año: %d
				""".formatted(nombre, año);

		System.out.println(mensaje);
	}

	/**
	 * Pattern matching sample.
	 */
	private static void patternMatchingSample() {
		// Pattern matching con instanceof (Java 16+)
		Object obj = "Java 21 es genial";
		if (obj instanceof String s && s.length() > 5) {
			System.out.println("Texto: " + s.toUpperCase());
		}
	}

	/**
	 * Switch expression sample.
	 */
	private static void switchExpressionSample() {
		// Switch expression con pattern matching (Java 21)
		Object valor = 42;
		String resultado = switch (valor) {
		case Integer i when i > 0 -> "Entero positivo: " + i;
		case Integer i -> "Entero no positivo: " + i;
		case String s -> "Cadena: " + s;
		default -> "Otro tipo";
		};
		System.out.println(resultado);
	}

	/**
	 * Record sample.
	 */
	private static void recordSample() {
		// Records (Java 16+)
		record Punto(int x, int y) {
			double distancia() {
				return Math.sqrt(x * x + y * y);
			}
		}
		var punto = new Punto(3, 4);
		System.out.printf("Punto %s → distancia: %.1f%n", punto, punto.distancia());
	}

	/**
	 * The main method.
	 *
	 * @param args the arguments
	 */
	public static void main(String[] args) {
		int año = 2024;

		textBlocksSample();
		patternMatchingSample();
		switchExpressionSample();
		recordSample();
	}
}