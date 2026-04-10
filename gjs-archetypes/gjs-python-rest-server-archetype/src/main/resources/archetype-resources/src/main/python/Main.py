#
# Program ${capitalizedName} Rest Server 
#
# Module Main.py
#

import sys
import platform
import site


# Forzar la inclusión de la ruta de usuario donde se instalan los paquetes
site.ENABLE_USER_SITE = True
user_site = site.getusersitepackages()
if user_site not in sys.path:
    sys.path.append(user_site)


from ${package}.server.${capitalizedName}Server import ${capitalizedName}Server
    
def main():
    try:
        server = ${capitalizedName}Server()
        server.start()
    except KeyboardInterrupt:
        print("\nPrograma finalizado por el usuario.")
        sys.exit(0)

if __name__ == "__main__":
    main()