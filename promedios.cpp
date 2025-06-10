#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Estructura de datos para almacenar la información de cada estudiante
struct Alumno {
    string nombre;
    string apellido1;
    string apellido2;
    int edad;
    char genero; // M o F
    float nota;
    string nombreCompleto() const {
        return nombre + " " + apellido1 + " " + apellido2;
    }
};

// Constante para definir la nota mínima aprobatoria
const float NOTA_MINIMA = 70.0;

// Validaciones
bool nombreValido(const string& nombre) {
    return !nombre.empty();
}

bool notaValida(float nota) {
    return nota >= 0 && nota <= 100;
}

bool generoValido(char g) {
    return g == 'M' || g == 'F';
}

int main() {
    int cantidad;
    vector<Alumno> aprobados, reprobados;

    cout << "¿Cuántos estudiantes desea ingresar?: ";
    cin >> cantidad;
    cin.ignore(); // Limpiar el salto de línea pendiente

    for (int i = 0; i < cantidad; ++i) {
        Alumno alumno;
        cout << "\n--- Ingreso de datos del estudiante #" << i + 1 << " ---\n";

        cout << "Nombre: ";
        cin >> alumno.nombre;

        cout << "Primer apellido: ";
        cin >> alumno.apellido1;

        cout << "Segundo apellido: ";
        cin >> alumno.apellido2;

        cout << "Edad: ";
        cin >> alumno.edad;

        cout << "Género (M/F): ";
        cin >> alumno.genero;

        cout << "Nota: ";
        cin >> alumno.nota;
        cin.ignore(); // Limpiar salto de línea pendiente

        // Validaciones
        if (!nombreValido(alumno.nombre) || !nombreValido(alumno.apellido1) || !nombreValido(alumno.apellido2)) {
            cout << "\033[33m❌ Nombre o apellidos inválidos. Registro omitido.\033[0m\n";
            continue;
        }
        if (!generoValido(alumno.genero)) {
            cout << "\033[33m❌ Género inválido. Registro omitido.\033[0m\n";
            continue;
        }
        if (!notaValida(alumno.nota)) {
            cout << "\033[33m❌ Nota inválida. Registro omitido.\033[0m\n";
            continue;
        }

        // Clasificación
        if (alumno.nota >= NOTA_MINIMA) {
            aprobados.push_back(alumno);
        } else {
            reprobados.push_back(alumno);
        }
    }

    // Mostrar resultados
    cout << "\n\033[34m=============================\n";
    cout << "📘 ESTUDIANTES APROBADOS (" << aprobados.size() << ")\n";
    cout << "=============================\033[0m\n";
    for (const auto& a : aprobados) {
        cout << "\033[32m✅ " << a.nombreCompleto() << " - Nota: " << a.nota << "\033[0m\n";
    }

    cout << "\n\033[34m=============================\n";
    cout << "📕 ESTUDIANTES REPROBADOS (" << reprobados.size() << ")\n";
    cout << "=============================\033[0m\n";
    for (const auto& r : reprobados) {
        cout << "\033[31m❌ " << r.nombreCompleto() << " - Nota: " << r.nota << "\033[0m\n";
    }

    return 0;
}

  



