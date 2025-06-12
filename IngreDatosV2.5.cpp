#include <iostream>  
#include <string>    
#include <vector>    
#include <algorithm> 

using namespace std;

#define Reset     "\033[0m"     
#define Bold      "\033[1m"     
#define Underline "\033[4m"    
#define Red       "\033[31m"    
#define Green     "\033[32m"    
#define Yellow    "\033[33m"    
#define Blue      "\033[34m"   
#define Cyan      "\033[36m"  

void Titulo_Marco(const string & titulo){           
    size_t longitud = titulo.length();
    string borde(longitud + 4, '*');

    cout << Green << borde << endl;         
    cout << "* " << Blue << Bold << Underline << titulo << Reset << Green << " *" << endl;
    cout << borde << Reset << endl << endl;
}

void Cuerpo_Marco(const vector<string>& lineas) {  
    size_t maxLongitud = 0;
    for (const auto & linea : lineas) {
        maxLongitud = max(maxLongitud, linea.length());
    }

    string borde(maxLongitud + 4, '#');

    cout << Yellow << borde << endl;
    for (const auto & linea : lineas) {
        cout << "# " << Cyan << linea
             << string(maxLongitud - linea.length(), ' ')
             << Yellow << " #" << endl;
    }
    cout << borde << Reset << endl;
}

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