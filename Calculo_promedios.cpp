#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iomanip> // Para setprecision

using namespace std;

// Códigos de color
#define Reset     "\033[0m"
#define Bold      "\033[1m"
#define Underline "\033[4m"
#define Red       "\033[31m"
#define Green     "\033[32m"
#define Yellow    "\033[33m"
#define Blue      "\033[34m"
#define Cyan      "\033[36m"

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
        cout << "# " << Cyan << linea
             << string(maxLongitud - linea.length(), ' ')
             << Yellow << " #" << endl;
    }
    cout << borde << Reset << endl;
}

int main() {
    string nombre, apellido1, apellido2;
    int edad;
    char genero;

    float notaTarea, notaExamen, notaProyecto, promedioFinal;

    Titulo_Marco("INICIO DEL SISTEMA DE INFORMACION");

    cout << Red << "Ingrese el Nombre: " << Reset;
    getline(cin, nombre);

    cout << Red << "Ingrese el Primer Apellido: " << Reset;
    getline(cin, apellido1);

    cout << Red << "Ingrese el Segundo Apellido: " << Reset;
    getline(cin, apellido2);

    cout << Red << "Ingrese la Edad: " << Reset;
    cin >> edad;
    cin.ignore();

    cout << Red << "Ingrese el Género (M/F): " << Reset;
    cin >> genero;
    cin.ignore();

    // Ingreso de notas
    cout << Red << "Ingrese la nota de Tarea (30%): " << Reset;
    cin >> notaTarea;

    cout << Red << "Ingrese la nota de Examen (40%): " << Reset;
    cin >> notaExamen;

    cout << Red << "Ingrese la nota de Proyecto (30%): " << Reset;
    cin >> notaProyecto;

    // Cálculo del promedio final
    promedioFinal = (notaTarea * 0.3f) + (notaExamen * 0.4f) + (notaProyecto * 0.3f);

    // Mostrar todos los datos
    vector<string> datosAlumno = {
        "Nombre: " + nombre,
        "Primer Apellido: " + apellido1,
        "Segundo Apellido: " + apellido2,
        "Edad: " + to_string(edad),
        "Género: " + string(1, genero),
        "Nota de Tarea: " + to_string(notaTarea),
        "Nota de Examen: " + to_string(notaExamen),
        "Nota de Proyecto: " + to_string(notaProyecto),
        "Promedio Final: " + to_string(promedioFinal)
    };

    cout << endl;
    Titulo_Marco("DATOS DEL ALUMNO Y NOTAS");
    Cuerpo_Marco(datosAlumno);

    cout << endl;
    Titulo_Marco("DATOS PROCESADOS CON EXITO");

    cout << Green << "El promedio final del alumno es: "
         << setprecision(2) << fixed << promedioFinal << Reset << endl;

    cout << Green << "Gracias por usar el sistema." << Reset << endl;
    cout << Green << "Fin del programa." << Reset << endl;
    cout << endl;
    

    return 0;
}
