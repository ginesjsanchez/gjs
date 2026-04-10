import unittest
from unittest.mock import patch, MagicMock
from ${package}.Main import main

class TestMain(unittest.TestCase):
    @patch('${package}.Main.${capitalizedName}Server')
    def test_main_instantiates_and_starts(self, MockServer):
        # Crear una instancia simulada
        mock_instance = MockServer.return_value
        
        # Ejecutar main
        main()
        
        # Verificar que se instanció y se llamó al método start
        MockServer.assert_called_once()
        mock_instance.start.assert_called_once()