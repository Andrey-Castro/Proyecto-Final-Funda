#include <iostream>
#include <string>   // Importante cuando se quiere trabajar con strings o caracteres tipo cadena.

using namespace std;
// A) Encabezado con seccion y estilos de colores.
// B) Datos personales.

#define Reset     "\033[0m"
#define Red       "\033[31m"
#define Green     "\033[32m"
#define Yellow    "\033[33m"
#define Blue      "\033[34m"
#define Magenta   "\033[35m"
#define Cyan      "\033[36m"
#define Bold      "\033[1m"
#define Underline "\033[4m"

void encabezado() {
    cout << Blue << "============\n";
    cout << "mi programa c++\n";
    cout << "================" << Reset << endl;
}

void seccion(string titulo, const char* color){
cout << Yellow << color << "\n -------" << "---\n" << Reset;
}

//Esta parte del programa busca cumplir con el ingreso de los datos personales de estudiantes de forma exitosa.

string nombre;    //Nombre del estudiante
string apellido1; // Primer apellido del estudiante.
string apellido2; // Segundo apellido del estudiante.

int edad;     // Edad del estudiante.
char genero;  // Genero del estudiante; Masculino o fememino.

int main (){

    encabezado();
    seccion("Seccion 1: Datos de usuario", Green);
    cout << "Nombre: juan\nEdad: 25\n";
    seccion("Seccion 2: Resultados", Yellow);
    cout << "puntaje: 89\nEstado: Aprobado\n";
    seccion("Fin del programa", Blue);
    
    cout << "Ingresar informacion personal del estudiante: Nombre, Apellidos, Edad y Genero:" << endl;

    cin >> nombre;        // Ingresar nombre y sugundo nombre.
    cin >> apellido1;     // Ingresar primer apellido.
    cin >> apellido2;     // Ingresar segundo apellido.
    cin >> edad;          // ingresar edad.
    cin >> genero;        // Ingresar edad Masculino o Femenino, la consola mostrara M o F.
    cout << "\n";     //  \n; es como dejar un espacio en un reglon. por ejemplo las lineas 26, 27 y 28.
    
    cout << "Nombre y Apellidos del estudiante:" << endl;
    cout << "\n";
    cout << "Nombre del estudiante: " << nombre << endl;
    cout << "Primer apellido: " << apellido1 << endl;
    cout << "Segundo apellido: " << apellido2 << endl;
    cout << "\n";

    cout << "Edad y Genero del estudiante:" << endl;
    cout << "\n";
    cout << "Edad: " << edad << endl;
    cout << "Genero: " << genero << endl;
}    