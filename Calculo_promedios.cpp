#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <cctype>
using namespace std;

// Códigos de color
#define Reset "\033[0m"
#define Bold "\033[1m"
#define Underline "\033[4m"
#define Red "\033[31m"
#define Green "\033[32m"
#define Yellow "\033[33m"
#define Blue "\033[34m"
#define Cyan "\033[36m"

// Función para mostrar título con marco
void Titulo_Marco(const string &titulo) {
    size_t longitud = titulo.length();
    string borde(longitud + 4, '*');
    
    cout << Green << borde << endl;
    cout << "* " << Blue << Bold << Underline << titulo << Reset << Green << " *" << endl;
    cout << borde << Reset << endl << endl;
}

// Función para mostrar contenido con marco
void Cuerpo_Marco(const vector<string>& lineas) {
    size_t maxLongitud = 0;
    for (const auto& linea : lineas) {
        maxLongitud = max(maxLongitud, linea.length());
    }
    
    string borde(maxLongitud + 4, '#');
    
    cout << Yellow << borde << endl;
    for (const auto& linea : lineas) {
        cout << "# " << Cyan << linea << string(maxLongitud - linea.length(), ' ') << Yellow << " #" << endl;
    }
    cout << borde << Reset << endl;
}

// Función para mostrar estado final del alumno
void MostrarEstadoFinal(double promedio) {
    if (promedio >= 70.0) {
        cout << Green << "Estado: Aprobado ✅" << Reset << endl;
    } else {
        cout << Red << "Estado: Reprobado ❌" << Reset << endl;
    }
}

// Función para validar notas
bool ValidarNota(double nota) {
    return nota >= 0.0 && nota <= 100.0;
}

int main() {
    string nombre, apellido1, apellido2, cedula;
    int edad;
    char genero;
    double notaTarea, notaExamen, notaProyecto, promedioFinal;
    
    Titulo_Marco("INICIO DEL SISTEMA DE INFORMACION");
    
    cout << Red << "Ingrese el Nombre: " << Reset;
    getline(cin, nombre);
    
    cout << Red << "Ingrese el Primer Apellido: " << Reset;
    getline(cin, apellido1);
    
    cout << Red << "Ingrese el Segundo Apellido: " << Reset;
    getline(cin, apellido2);
    
    cout << Red << "Ingrese el Número de Cédula: " << Reset;
    getline(cin, cedula);
    
    do {
        cout << Red << "Ingrese la Edad: " << Reset;
        cin >> edad;
        if (edad < 0 || edad > 120) {
            cout << Yellow << "Por favor ingrese una edad válida (0-120 años)." << Reset << endl;
        }
    } while (edad < 0 || edad > 120);
    cin.ignore();
    
    do {
        cout << Red << "Ingrese el Género (M/F): " << Reset;
        cin >> genero;
        genero = toupper(genero); // Convertir a mayúscula
        if (genero != 'M' && genero != 'F') {
            cout << Yellow << "Por favor ingrese M para Masculino o F para Femenino." << Reset << endl;
        }
    } while (genero != 'M' && genero != 'F');
    cin.ignore();
    
    // Ingreso de notas con validación básica
    do {
        cout << Red << "Ingrese la nota de Tarea (30%): " << Reset;
        cin >> notaTarea;
        if (!ValidarNota(notaTarea)) {
            cout << Yellow << "Por favor ingrese una nota entre 0 y 100." << Reset << endl;
        }
    } while (!ValidarNota(notaTarea));
    
    do {
        cout << Red << "Ingrese la nota de Examen (40%): " << Reset;
        cin >> notaExamen;
        if (!ValidarNota(notaExamen)) {
            cout << Yellow << "Por favor ingrese una nota entre 0 y 100." << Reset << endl;
        }
    } while (!ValidarNota(notaExamen));
    
    do {
        cout << Red << "Ingrese la nota de Proyecto (30%): " << Reset;
        cin >> notaProyecto;
        if (!ValidarNota(notaProyecto)) {
            cout << Yellow << "Por favor ingrese una nota entre 0 y 100." << Reset << endl;
        }
    } while (!ValidarNota(notaProyecto));
    
    // Cálculo del promedio final
    promedioFinal = (notaTarea * 0.3) + (notaExamen * 0.4) + (notaProyecto * 0.3);
    
    // Mostrar todos los datos con mejor formato
    string generoCompleto = (genero == 'M') ? "Masculino" : "Femenino";
    
    vector<string> datosAlumno = {
        "Nombre Completo: " + nombre + " " + apellido1 + " " + apellido2,
        "Número de Cédula: " + cedula,
        "Edad: " + to_string(edad) + " años",
        "Género: " + generoCompleto,
        "",
        "--- CALIFICACIONES ---",
        "Nota de Tarea (30%): " + to_string(static_cast<int>(notaTarea)) + " puntos",
        "Nota de Examen (40%): " + to_string(static_cast<int>(notaExamen)) + " puntos", 
        "Nota de Proyecto (30%): " + to_string(static_cast<int>(notaProyecto)) + " puntos",
        "",
        "Promedio Final: " + to_string(static_cast<int>(promedioFinal)) + " puntos"
    };
    
    cout << endl;
    Titulo_Marco("DATOS DEL ALUMNO Y NOTAS");
    Cuerpo_Marco(datosAlumno);
    
    cout << endl;
    Titulo_Marco("RESULTADO FINAL");
    
    cout << Green << "El promedio final es: " << setprecision(1) << fixed << promedioFinal << " puntos" << Reset << endl;
    MostrarEstadoFinal(promedioFinal);
    
    cout << endl << Green << "Gracias por usar el sistema." << Reset << endl;
    cout << Green << "Fin del programa." << Reset << endl << endl;
    
    return 0;
}
