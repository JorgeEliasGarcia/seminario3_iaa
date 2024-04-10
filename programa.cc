#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <unordered_map>
#include <map>
#include <vector>

using namespace std;

int main() {
    // Definir un vector para almacenar las variables en orden
    vector<string> variables;

    // Abrir el archivo de entrada
    ifstream infile("entrada.txt");

    // Leer la primera línea para obtener las variables
    string first_line;
    getline(infile, first_line);
    stringstream first_ss(first_line);
    string variable;
    while (getline(first_ss, variable, ',')) {
        variables.push_back(variable);
    }

    // Definir un mapa para almacenar las frecuencias de cada variable en cada estado
    unordered_map<string, unordered_map<string, int>> variable_frequencies;
    
    int number_of_lines = 0; 
    // Leer el resto del archivo línea por línea
    string line;
    while (getline(infile, line)) {
        // Usar un stringstream para dividir la línea en tokens
        stringstream ss(line);
        string token;
        // Leer cada token de la línea
        int count = 0;
        while (getline(ss, token, ',')) {
            // Incrementar la frecuencia del valor de la variable en el estado actual
            variable_frequencies[variables[count ]][token]++;
            count++;
        }
        number_of_lines++;
    }

    // Mostrar los resultados
    for (const auto& variable : variable_frequencies) {
        cout << "Variable: " << variable.first << endl;
        for (const auto& valor : variable.second) {
            cout << "  Valor: " << valor.first << ", Probabilidad: " << double(valor.second) / double(number_of_lines) << endl;
        }
        cout << endl;
    }

    return 0;
}



