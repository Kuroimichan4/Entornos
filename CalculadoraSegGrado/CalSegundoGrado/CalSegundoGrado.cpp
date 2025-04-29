// CalSegundoGrado.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <cmath>
using namespace std;

double a;
double b;
double c;
double raiz;
double x1;
double x2;
double resul1;

void PedirDatos() {

    do {
        cout << "Introduce el valor de a (no puede ser 0)\n";
        cin >> a;
    } while (a == 0);

    cout << "Introduce el valor de b\n";
    cin >> b;
    cout << "Introduce el valor de c\n";
    cin >> c;
}

void CalcularDatos() {
    //discriminante
    raiz = sqrt((b * b) - 4 * a * c);//sqrt es para hacer operaciones matemáticas

    if (raiz < 0) {
        
        raiz = NAN;  // Usamos NAN para indicar que no hay soluciones reales 
    }
    else {

        if (raiz == 0) {
            resul1 = (-b + raiz) / (2 * a);
        }
        else if (raiz > 0) {
            x1 = (-b + raiz) / (2 * a);
            x2 = (-b - raiz) / (2 * a);
        }
    }
}


void mostrarResultado() {

    if (raiz == 0) {
        cout << "Solo tiene un resultado que es: \n" << resul1;
    }

    else if (raiz > 0) {
        cout << "la solucion para x1 es: " << x1;
        cout << "\nla solucion para x2 es: " << x2;
    }
    else if (raiz = NAN ) {
        cout << "No tiene resultado real";
    }
}
double ObtenerRaiz() {
    return raiz;
}

double ObtenerX1() {
    return x1;
}

double ObtenerX2() {
    return x2;
}

double ObtenerResultadoUnico() {
    return resul1;
}

int main() {

    PedirDatos();
    CalcularDatos();
    mostrarResultado();

    
}