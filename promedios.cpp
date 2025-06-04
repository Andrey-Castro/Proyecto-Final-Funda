#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Alumno {
    string nombre;
    float nota;
};

// Función para validar nombre
bool nombreValido(const string& nombre) {
    return !nombre.empty();
}

// Función para validar nota
bool notaValida(float nota) {
    return nota >= 0 && nota <= 100;
}

int main() {
    // Simulación de datos capturados
    vector<Alumno> alumnos = {
        {"Angelis", 85},
        {"Andrey", 65},
        {"Harold", 72},
        {"", 90},        // Nombre inválido
        {"Pedro", 105}   // Nota inválida
    };

    vector<Alumno> aprobados, reprobados;

    for (const auto& alumno : alumnos) {
        // Validaciones
        if (!nombreValido(alumno.nombre)) {
            cout << "\033[33m❌ Nombre inválido. Registro omitido.\033[0m\n";
            continue;
        }
        if (!notaValida(alumno.nota)) {
            cout << "\033[33m❌ Nota inválida para " << alumno.nombre << ". Registro omitido.\033[0m\n";
            continue;
        }

        // Clasificación
        if (alumno.nota >= 70) {
            aprobados.push_back(alumno);
        } else {
            reprobados.push_back(alumno);
        }
    }

    // Mostrar resultados
    cout << "\n\033[34m=============================\n";
    cout << "📘 LISTA DE APROBADOS\n";
    cout << "=============================\033[0m\n";
    for (const auto& a : aprobados) {
        cout << "\033[32m✅ " << a.nombre << " - Nota: " << a.nota << "\033[0m\n";
    }

    cout << "\n\033[34m=============================\n";
    cout << "📕 LISTA DE REPROBADOS\n";
    cout << "=============================\033[0m\n";
    for (const auto& r : reprobados) {
        cout << "\033[31m❌ " << r.nombre << " - Nota: " << r.nota << "\033[0m\n";
    }

    return 0;
}
