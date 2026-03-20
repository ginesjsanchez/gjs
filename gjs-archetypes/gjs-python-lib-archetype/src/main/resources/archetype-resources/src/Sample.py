#set( $symbol_pound = '#' )
#set( $symbol_dollar = '$' )
#set( $symbol_escape = '\' )
${symbol_pound}
${symbol_pound} Library ${name} 
${symbol_pound}
${symbol_pound} Module Sample.py
${symbol_pound}


 
def sumar(a: float, b: float) -> float:
    """Devuelve la suma de dos números."""
    return a + b
 
 
def es_par(numero: int) -> bool:
    """Devuelve True si el número es par, False si es impar."""
    return numero % 2 == 0
 