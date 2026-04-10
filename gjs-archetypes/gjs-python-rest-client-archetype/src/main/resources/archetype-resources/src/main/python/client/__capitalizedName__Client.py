#set( $symbol_pound = '#' )
#set( $symbol_dollar = '$' )
#set( $symbol_escape = '\' )
#set( $capitalizedName = $shortName.substring(0,1).toUpperCase() + $shortName.substring(1))
${symbol_pound}
${symbol_pound} Program ${capitalizedName} Rest Client 
${symbol_pound}
${symbol_pound} Module ${capitalizedName}Client.py
${symbol_pound}

import sys
import os
import httpx

# Inyectar ruta de modelos generados
from ${package}.models.Models import ServerStatus

class ${capitalizedName}Client:
    def __init__(self, base_url="http://${host}:${port}"):
        self.base_url = base_url

    def get_server_status(self) -> ServerStatus:
        with httpx.Client() as client:
            response = client.get(f"{self.base_url}/status")
            response.raise_for_status()
            return ServerStatus(**response.json())
            
            