# Nota: 6.5  

# Instrucciones para ejecutar los códigos:

# Problema 1: Carpeta Subiendo la Escalera.

i) Compilación: Para compilar el archivo "subiendoEscalera.cpp", abra la consola en el directorio correspondiente y ejecute el comando "make".  

ii) Antes de ejecutar el programa, considere los siguientes valores: 
   - n: número de escalones.
   - p: base de la potencia de los saltos permitidos.
   - r: número de escalones rotos.

iii) Ejecución: En la consola, escriba: ./prog1 n p r 
   Asegúrate de ingresar valores válidos para n, p y r. Solo verificamos r < n, según el enunciado.

iv) Programa en funcionamiento: El programa se iniciará y validará la entrada.

# Comentario   
   - graficos.ipynb → Archivo hecho en Jupyter Notebook para la creación de los gráficos que se ven en el informe.  

Por defecto, el programa "subiendoEscalera.cpp" mostrará la solución para el algoritmo PD, si desea ver también la solución para FB, debe cambiar el '0' por un '1', en la línea 7. 

# Problema 2: Carpeta Ruta en Grafos.  

i) Compilación: Para compilar el archivo "solucionGrafos.cpp", abra la consola en el directorio correspondiente y ejecute el comando "make".  

ii) Antes de ejecutar el programa, considere los siguientes valores:  
   - n: nodos del continente.
   - k: puertos del continente.
   - m: nodos del archipiélago.

iii) Ejecución: En la consola, escriba: ./prog2 n k m
   Asegúrate de ingresar valores válidos para n, k y m. Solo verificamos k < n, según el enunciado.

iv) Programa en funcionamiento: El programa se iniciará y validará la entrada.

# Comentario
Entregamos 3 códigos en C++ y 1 extra:
   - Dijkstra.cpp → Algoritmo visto en clases de manera teórica, lo implementamos para que sirva como referencia a los demas archivos.
   
   - variante.cpp → Nuestra primera versión a la solución del problema, el cual creemos que la lógica esta bien, pero nos daba un error que a simple vista intuimos que es Overflow, el cual se encuentra comentado en el código. Creemos que es importante enviar este código a pesar del error. Si desea ejecutar este código, deberá hacerlo manual, es decir, escribir en consola: g++ -o solucion variante.cpp y luego ./solucion

   - solucionGrafos.cpp → Luego del problema mencionado, decidimos crear otra solución basada en la anterior, la cual creemos que es la más cercana o posiblemente correcta. El Makefile proporcionado es para ejecutar este archivo.  

   - graficos.ipynb → Archivo hecho en Jupyter Notebook para la creación de los gráficos que se ven en el informe.  
