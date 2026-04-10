#set( $symbol_pound = '#' )
#set( $symbol_dollar = '$' )
#set( $symbol_escape = '\' )
#set( $capitalizedName = $shortName.substring(0,1).toUpperCase() + $shortName.substring(1))
import pytest
from pydantic import ValidationError
from ${package}.models.Models import ServerStatus

def test_server_status_valid_data():
    # Test con datos correctos: debe instanciar sin errores
    data = {
        "status": "Running",
        "date-time": "2026-03-27T19:00:00Z"
    }
    # Usar model_validate en lugar de **data para manejar claves con guión
    status_obj = ServerStatus.model_validate(data)

    assert status_obj.status == "Running"

    # Pydantic devuelve datetime, no str, así que comparamos correctamente
    from datetime import datetime, timezone
    expected = datetime(2026, 3, 27, 19, 0, 0, tzinfo=timezone.utc)
    assert status_obj.date_time == expected
    
def test_server_status_missing_required_fields():
    # Test de campo obligatorio faltante: debe lanzar ValidationError
    data = {"status": "OK"}  # Falta 'date-time'
    
    with pytest.raises(ValidationError):
        ServerStatus(**data)

def test_server_status_invalid_types():
    # Test de tipos incorrectos (ej: status como entero en lugar de string)
    # Pydantic intentará convertirlo, si no puede, lanzará ValidationError
    data = {
        "status": ["No soy un string"], 
        "date-time": "2026-03-27T19:00:00Z"
    }
    
    with pytest.raises(ValidationError):
        ServerStatus(**data)