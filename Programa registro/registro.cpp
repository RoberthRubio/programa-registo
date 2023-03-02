#include <iostream>
#include <string>

using namespace std;

struct Paciente {
    string nombre;
    int documento;
    Paciente *siguiente;
};

void registrar(Paciente *&inicio, Paciente *&fin) {
    Paciente *nuevo = new Paciente();
    cout << "Ingrese el nombre del paciente: ";
    getline(cin, nuevo->nombre);
    cout << "Ingrese el numero de documento: ";
    cin >> nuevo->documento;
    cin.ignore();
    nuevo->siguiente = NULL;
    if (inicio == NULL) {
        inicio = nuevo;
    } else {
        fin->siguiente = nuevo;
    }
    fin = nuevo;
    cout << "Paciente registrado correctamente." << endl;
}

void mostrar(Paciente *inicio) {
    if (inicio == NULL) {
        cout << "No hay pacientes registrados." << endl;
        return;
    }
    int contador = 1;
    Paciente *actual = inicio;
    while (actual != NULL) {
        cout << contador << ". " << actual->nombre << " - " << actual->documento << endl;
        actual = actual->siguiente;
        contador++;
    }
}

int contar(Paciente *inicio) {
    int contador = 0;
    Paciente *actual = inicio;
    while (actual != NULL) {
        contador++;
        actual = actual->siguiente;
    }
    return contador;
}

int main() {
    Paciente *inicio = NULL;
    Paciente *fin = NULL;
    int opcion;
    do {
        cout << "MENU" << endl;
        cout << "1. Registrar paciente" << endl;
        cout << "2. Mostrar pacientes" << endl;
        cout << "3. Mostrar cantidad de pacientes" << endl;
        cout << "4. Salir" << endl;
        cout << "Ingrese una opcion: ";
        cin >> opcion;
        cin.ignore();
        switch (opcion) {
            case 1:
                registrar(inicio, fin);
                break;
            case 2:
                mostrar(inicio);
                break;
            case 3:
                cout << "Cantidad de pacientes registrados: " << contar(inicio) << endl;
                break;
            case 4:
                cout << "Hasta luego." << endl;
                break;
            default:
                cout << "Opcion invalida." << endl;
                break;
        }
    } while (opcion != 4);
    return 0;
}
//Roberth Rubio, Jhonier Cortes.