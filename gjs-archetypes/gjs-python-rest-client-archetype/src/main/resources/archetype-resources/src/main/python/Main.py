#set( $symbol_pound = '#' )
#set( $symbol_dollar = '$' )
#set( $symbol_escape = '\' )
#set( $capitalizedName = $shortName.substring(0,1).toUpperCase() + $shortName.substring(1))
${symbol_pound}
${symbol_pound} Program ${capitalizedName} Rest Client 
${symbol_pound}
${symbol_pound} Module Main.py
${symbol_pound}

import sys
import platform

from ${package}.client.${capitalizedName}Client import ${capitalizedName}Client


def main():
    client = ${capitalizedName}Client()
    try:
        resultado = client.get_server_status()
        print(f"Respuesta recibida: {resultado}")
    except Exception as e:
        print(f"Error en la llamada: {e}")
        
        
if __name__ == "__main__":
    main()