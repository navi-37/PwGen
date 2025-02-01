# PwGen
Generador de contraseñas
Programita que hice un día que estaba al pedo luego de cursar PP, crea una contraseña aleatoria del largo seleccionado y la copia al portapapeles. 
Antes de subirla pa acá le pegué una reestructuración bastante grande porque me puse a leer el código que hice en su momento y era un desastre. 
Comentando y descomentando algunas cosillas se puede hacer compatible con linux o windows.
Pa compilar:
gcc -o pwgen main.c func.c
o 
clang -o -Wall -Werror pwgen main.c func.c
