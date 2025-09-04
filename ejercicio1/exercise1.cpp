/* Ejercicio 1: Inventario de Productos (Struct + Array + Funciones de
búsqueda) */

#include <iostream>
#include <limits>
using namespace std;

// Definición del struct Producto
struct Producto {
    int codigo;
    string nombre;
    float precio;
    int cantidad;
};

const int maxProductos = 100;
// Array para almacenar productos
Producto inventario[maxProductos];
// Variable para llevar el conteo de productos actuales
int totalProductos = 0;

int agregarProducto(Producto p[], int n){

    // Inicializa el nuevo producto
    Producto nuevoProducto;

    // Verifica si hay espacio en el inventario
    if (n < maxProductos) {
        cout << "Ingrese codigo: ";
        cin >> nuevoProducto.codigo;
        cout << "Ingrese nombre: ";
        // Limpia el búfer de entrada antes de usar getline
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
        getline(cin >> ws, nuevoProducto.nombre);
        cout << "Ingrese precio: ";
        cin >> nuevoProducto.precio;
        cout << "Ingrese cantidad: ";
        cin >> nuevoProducto.cantidad;

        p[n] = nuevoProducto;
        cout << "Producto agregado exitosamente!\n";

        // Retorna el nuevo conteo de productos
        return n + 1;

    } else {
        cout << "¡Inventario lleno!" << endl;
        return n;
    }
}

void buscarProductoPorCodigo(Producto p[], int n, int codigo) {
    for (int i = 0; i < n; i++) {
        if (p[i].codigo == codigo) {
            cout << "Producto encontrado:\n";
            cout << "Codigo: " << p[i].codigo << "\n";
            cout << "Nombre: " << p[i].nombre << "\n";
            cout << "Precio: " << p[i].precio << "\n";
            cout << "Cantidad: " << p[i].cantidad << "\n";
            // Si encuentra el producto, se sale de la función
            return;
        }
    }

    cout << "Producto con codigo " << codigo << " no encontrado.\n";
}

int totalValorInventario(Producto p[], int n) {
    float total = 0;
    // Calcula el valor total del inventario
    for (int i = 0; i < n; i++) {
        total += p[i].precio * p[i].cantidad;
    }
    //Retorna el valor total
    return total;

}

int main(){
    int opcion;

    cout << "=== Inventario de Productos ===\n";
    do {
        cout << "\nMenu:\n";
        cout << "1. Agregar producto\n";
        cout << "2. Buscar producto por codigo\n";
        cout << "3. Mostrar valor total del inventario\n";
        cout << "4. Salir\n\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        //Mientras la opcion no sea 4 el programa seguira corriendo
        switch (opcion) {
            case 1:
                totalProductos = agregarProducto(inventario, totalProductos);
                break;
            case 2: {
                int codigo;
                cout << "Ingrese el codigo del producto a buscar: ";
                cin >> codigo;
                cout << "\n-------------------------------\n";
                buscarProductoPorCodigo(inventario, totalProductos, codigo);
                break;
            }
            case 3:
                cout << "Valor total del inventario: $" << totalValorInventario(inventario, totalProductos) << "\n";
                break;
            case 4:
                cout << "Saliendo del programa.\n";
                break;
            default:
                cout << "Opcion no valida. Intente de nuevo.\n";
        }
    } while (opcion != 4);

    return 0;
}