#include <iostream>  // No hace falta explicar...
#include <string>    // Importante cuando se quiere trabajar con strings o caracteres tipo cadena.
#include <vector>    // Le dice al programa que va a utilizar vectores.
#include <algorithm> // Usa funciones estandar, ordena,buscar,manipular datos.

using namespace std;

//Codigos de escape ANSI o lista de colores.
#define Reset     "\033[0m"  // Vuelve al color por defecto.
#define Bold      "\033[1m"  // Negrita.
#define Underline "\033[4m"  // Subrayado.
#define Red       "\033[31m" // Rojo, este es el color de las lineas que piden la informacion del alumno.
#define Green     "\033[32m" // Verde, Color del marco del titulo (color de los * que rodean el titulo).
#define Yellow    "\033[33m" // Amarillo, color del cuerpo del marco (color de los # del marco).
#define Blue      "\033[34m" // Azul, color del texto del titulo. 
#define Cyan      "\033[36m" // Cyan, color de la informacion mostrada del alumno.

// Esta parte del programa busca cumplir con el diseño del encabezado y seccion con estilos y colores.
void Titulo_Marco(const string & titulo){           //El marco del titulo.
    size_t longitud = titulo.length();
    string borde(longitud + 4, '*');

    cout << Green << borde << endl;                 //Caracteristicas, color, negrita, etc.
    cout << "* " << Blue << Bold << Underline << titulo << Reset << Green << " *" << endl;
    cout << borde << Reset << endl << endl;
}

void Cuerpo_Marco(const vector<string>& lineas) {   // Cuerpo del encabezado
    size_t maxLongitud = 0;
    for (const auto & linea : lineas) {
        maxLongitud = max(maxLongitud, linea.length());
    }

    string borde(maxLongitud + 4, '#');             // caracteristicas, color, etc.

    cout << Yellow << borde << endl;
    for (const auto & linea : lineas) {
        cout << "# " << Cyan << linea
             << string(maxLongitud - linea.length(), ' ')
             << Yellow << " #" << endl;
    }
    cout << borde << Reset << endl;
}

//Esta parte del programa busca cumplir con el ingreso de los datos personales de estudiantes de forma exitosa.
int main(){

    string nombre, apellido1, apellido2;
    int edad;
    char genero;

    Titulo_Marco("INICIO DEL SISTEMA DE INFORMACION");

    cout << Red << "Ingrese el Nombre: " << Reset;
    getline(cin,nombre);

    cout << Red <<  "Ingrese el Primer Apellido: : " << Reset;
    getline(cin, apellido1);

    cout << Red << "Ingrese el Segundo Apellido: " << Reset;
    getline(cin, apellido2);

    cout << Red "Ingrese la Edad: " << Reset;
    cin >> edad;
    cin.ignore();

    cout << Red << "Ingrese el Genero: " << Reset;
    cin >> genero;

    vector<string> datosAlumno = {
        "Nombre: " + nombre,
        "Primer Apellido: " + apellido1,
        "Segundo Apellido: " + apellido2,
        "Edad: " + to_string(edad),
        "Género: " + genero
    };

    Titulo_Marco("DATOS DEL ALUMNO");
    Cuerpo_Marco(datosAlumno);

    cout << endl;
    Titulo_Marco("DATOS PROCESADOS CON EXITO!");

    return 0;
}