/* Integrantes:
	- Felipe Cordova
	- Sebastian Montecinos
*/
#include <iostream> 
#include <vector> // Trabajamos con vectores
#include <cmath> // Para usar la funcion pow y log
#include <stdlib.h> // Para los numeros randoms
#include <algorithm> // Para utilizar el metodo find
using namespace std;

// Declarando la funciones utilizadas
vector<vector<int>> encontrarFormasPosibles(int n, int p, vector<int>& escalones_rotos);
vector<int> generarIndicesAleatorios(int n, int r);
void imprimirFormasPosibles(const vector<vector<int>>& formas);
void imprimirEscalonesRotos(const vector<int>& escalonesRotos);

/* Programa principal. Se extrae n,p,r desde los argumentos realizando las verificaciones 
correspondientes. Luego se crea un vector el cual sera el retorno de la funcion que genera 
los indices con r escalones rotos. Finalmente se crea una matriz de vectores para almacenar los
posibles caminos que tiene nuestro heroe Super Mario para llegar al final de la escalera sin pisar 
los escalones rotos. Como se menciona en el README, recomendamos comentar las funciones para imprimir 
si va a ejecutar con entradas muy grandes. */
int main(int argc, char* argv[]){
    if(argc != 4 || atoi(argv[3]) >= atoi(argv[1])){
        if(argc != 4){
            cout << "¡¡ERROR!! Tiene que compilar ./prog1 n p r" << endl;
        }else{// Obligamos que r < n --> Esto dice el enunciado. Se pueden pedir mas condiciones... 
            cout << "¡¡Debe cumplirse que r < n!!" << endl;
        }
        return EXIT_FAILURE; // --> Se termina el programa de manera inesperada.
    }
    cout << "¡¡Bienvenido Al Problema Subiendo La Escalera Hecho Por Fuerza Bruta!!" << endl;
    int n = atoi(argv[1]); // Numero de escalones
    int p = atoi(argv[2]); // Base de la otencia de salto
    int r = atoi(argv[3]); // Numero de escalones rotos
    vector<int> escalones_rotos = generarIndicesAleatorios(n, r);
    imprimirEscalonesRotos(escalones_rotos); 
    vector<vector<int>> formas = encontrarFormasPosibles(n, p, escalones_rotos);
    imprimirFormasPosibles(formas);
    cout << "¡¡Fin Fuerza Bruta!!" << endl;
    return EXIT_SUCCESS;
}

/* Funcion que genera los indices aleatorios para los escalones rotos. Se crea un vector de largo r
y se genera una semilla con el tiempo actual, asi tenemos randoms distintos en cada ejecucion.
Luego simplemente se generan los r numeros aleatorios en el rango 1..n-1, validando que no se repitan. 
Finalmente se agregan al vector en su posicion i respectiva. */
vector<int> generarIndicesAleatorios(int n, int r) {
    vector<int> escalones_rotos(r);
    srand(time(0));
    int k_aleatorio;
    for(int i = 0; i < r; i++){ // O(r)
        k_aleatorio = 1 + rand() % (n - 1);
        // El costo de este while en el peor caso es O(r-1)
        while(find(escalones_rotos.begin(), escalones_rotos.begin() + i, k_aleatorio) != escalones_rotos.begin() + i){
            k_aleatorio = 1 + rand() % (n - 1);
        }
        escalones_rotos[i] = k_aleatorio;
    } // --> Costo total de este ciclo anidado es O(r(r-1)) <--> O(r²)
    return escalones_rotos;
}

/* En esta funcion se usan varios metodos de vectores. Consideremos que v es un vector entonces...
    v.push_back(...) --> Agregamos un nuevo elemento al final de v
    v.empty() --> Para verificar si v esta sin elementos o no.
    v.pop_back() --> Para eliminar el ultimo elemento de v
    v.back() --> Para acceder al ultimo elemento de v
    v.erase(...) --> para eliminar uno o varios elementos de v
    v.begin() --> Iterador que apunta a la primera posicion de v
*/
vector<vector<int>> encontrarFormasPosibles(int n, int p, vector<int>& escalones_rotos) {
    vector<vector<int>> formas; // Esta matriz retornara todos los posibles caminos 
    
    vector<int> forma_inicial;
    
    vector<vector<int>> formas_actuales;
    formas_actuales.push_back(forma_inicial);
    
    while(!formas_actuales.empty()){
        vector<int> forma_actual = formas_actuales.back();
        formas_actuales.pop_back();
        
        int pos_actual;
        if(forma_actual.empty()){
            pos_actual = 0;
        }else{
            pos_actual = forma_actual.back();
        }
        
        if(pos_actual == n){
            if(!forma_actual.empty() && forma_actual[0] == 0){
                forma_actual.erase(forma_actual.begin()); // Eliminar el 0 al comienzo
            }
            formas.push_back(forma_actual);
            continue; /* Si estas condiciones se cumplen se pasa a la sgte iteracion. Se salta el
            codigo faltante */
        }
        // La condición i <= log(n) / log(p) garantiza que p^k <= n --> Esto dice el enunciado
        for(int i = 0; i <= int(log(n) / log(p)); i++){
            int siguiente_escalon = pos_actual + pow(p, i);
            
            bool escalon_roto = false;
            for(int escalon : escalones_rotos){
                if(siguiente_escalon == escalon){
                    escalon_roto = true;
                    break;
                }
            }
            if(escalon_roto == true || siguiente_escalon > n){
                continue; /* Si estas condiciones se cumplen se pasa a la sgte iteracion. Se salta el
            codigo faltante */
            }
            vector<int> nueva_forma = forma_actual;
            nueva_forma.push_back(siguiente_escalon);
            formas_actuales.push_back(nueva_forma);
        }
    }
    
    return formas;
}

/* En las siguientes funciones de imprimir, no consideraremos el costo asintotico, ya que para 
entradas grandes el costo asintotico se inflaria de manera innecesaria. */

void imprimirEscalonesRotos(const vector<int>& escalonesRotos) {
    cout << "Los escalones rotos son: ";
    for(int indice : escalonesRotos) {
        cout << indice << " ";
    }
    cout << "\n¡¡Tenga cuidado de pisarlos!!" << endl;
    return;
}

void imprimirFormasPosibles(const vector<vector<int>>& formas) {
    cout << "Numero total de formas posibles: " << formas.size() << endl;
    if(formas.size() == 0){
        cout << "No puede subir :c" << endl;
    }else{
        for(unsigned int i = 0; i < formas.size(); i++){
            cout << "Forma " << i + 1 << ": ";
            for(unsigned int j = 0; j < formas[i].size(); j++){
                cout << formas[i][j] << " ";
            }
            cout << endl;
        }
    }
    return;
}
