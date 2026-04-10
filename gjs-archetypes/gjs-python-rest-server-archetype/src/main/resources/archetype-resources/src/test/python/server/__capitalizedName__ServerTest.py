from fastapi.testclient import TestClient
from ${package}.server.${capitalizedName}Server import ${capitalizedName}Server

def test_status_endpoint():
    # Instanciamos la clase del servidor
    server_instance = ${capitalizedName}Server()
    # Usamos el TestClient sobre la propiedad .app de la clase
    client = TestClient(server_instance.app)
    
    response = client.get("/status")
    
    assert response.status_code == 200
    data = response.json()
    assert "status" in data
    assert "date-time" in data
    assert data["status"] == "OK"