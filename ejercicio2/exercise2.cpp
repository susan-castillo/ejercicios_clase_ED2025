#include <iostream>
// Libreria complementaria para manejar el buffer de entrada
#include <limits>

using namespace std;

// Tamaño máximo de estudiantes y materias
const int MAX_ESTUDIANTES = 100;
const int MAX_MATERIAS = 100;

// Declaración de la matriz de notas y los arrays para nombres
float notas[MAX_ESTUDIANTES][MAX_MATERIAS];
string nombresEstudiantes[MAX_ESTUDIANTES];
string nombresMaterias[MAX_MATERIAS];
int numEstudiantes = 0;
int numMaterias = 0;

// Función para solicitar todos los datos
void solicitarDatos() {
    cout << "Ingrese el total de estudiantes (max " << MAX_ESTUDIANTES << "): ";
    cin >> numEstudiantes;
    cout << "Ingrese el total de materias (max " << MAX_MATERIAS << "): ";
    cin >> numMaterias;

    cout << "\n<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<\n";

    // Se limpia el buffer de entrada
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    // Se ingresan los nombres de los estudiantes
    for (int i = 0; i < numEstudiantes; i++) {
        cout << "Ingrese el nombre del estudiante " << i + 1 << ": ";
        getline(cin, nombresEstudiantes[i]);
    }

    cout << "\n<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<\n";

    // Se ingresan los nombres de las materias
    for (int j = 0; j < numMaterias; j++) {
        cout << "Ingrese el nombre de la materia " << j + 1 << ": ";
        getline(cin, nombresMaterias[j]);
    }

    cout << "\n<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<\n";

    // Se solicita el ingreso de notas
    for (int i = 0; i < numEstudiantes; i++) {
        cout << "\n--- Notas de " << nombresEstudiantes[i] << " ---" << endl;
        for (int j = 0; j < numMaterias; j++) {
            cout << "Ingrese la nota para " << nombresMaterias[j] << ": ";
            cin >> notas[i][j];
        }
    }

    cout << "\n<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<\n";
}


// Funciones para calcular promedios
void calcularPromedioEstudiantes() {
    cout << "\n--- Promedios por estudiante ---" << endl;
    for (int i = 0; i < numEstudiantes; i++) {
        float suma = 0;
        for (int j = 0; j < numMaterias; j++) {
            suma += notas[i][j];
        }
        cout << "El promedio de " << nombresEstudiantes[i] << " es: " << suma / numMaterias << endl;
    }
}

void calcularPromedioMaterias() {
    cout << "\n--- Promedios por materia ---" << endl;
    for (int j = 0; j < numMaterias; j++) {
        float suma = 0;
        for (int i = 0; i < numEstudiantes; i++) {
            suma += notas[i][j];
        }
        cout << "El promedio de " << nombresMaterias[j] << " es: " << suma / numEstudiantes << endl;
    }
}

int main() {
    cout << "Sistema de gestion de notas" << endl;

    solicitarDatos();
    calcularPromedioEstudiantes();
    calcularPromedioMaterias();

    return 0;
}