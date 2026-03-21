#set( $packagePath = ${package.replaceAll("\.","/")})
#set($parts = $package.split("\."))
#set($relativeDots = "")
#foreach($part in $parts)
  #set($relativeDots = "${relativeDots}../")
#end
import { add, subtract, multiply, divide } from '../../${relativeDots}main/typescript/${packagePath}/Index';

describe('Math Utils Tests', () => {
  test('Suma: 5 + 5 = 10', () => {
    expect(add(5, 5)).toBe(10);
  });

  test('Resta: 10 - 4 = 6', () => {
    expect(subtract(10, 4)).toBe(6);
  });

  test('Multiplicación: 3 * 3 = 9', () => {
    expect(multiply(3, 3)).toBe(9);
  });

  test('División: 10 / 2 = 5', () => {
    expect(divide(10, 2)).toBe(5);
  });

  test('Error al dividir por cero', () => {
    expect(() => divide(10, 0)).toThrow("No se puede dividir por cero");
  });
});