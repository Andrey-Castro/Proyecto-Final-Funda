#include <iostream>
#include <string>   // Importante cuando se quiere trabajar con strings o caracteres tipo cadena.

using namespace std;
// A) Encabezado con seccion y estilos de colores.
// B) Datos personales.

//Esta parte del programa busca cumplir con el ingreso de los datos personales de estudiantes de forma exitosa.

string nombre;    //Nombre del estudiante
string apellido1; // Primer apellido del estudiante.
string apellido2; // Segundo apellido del estudiante.

int edad;     // Edad del estudiante.
char genero;  // Genero del estudiante; Masculino o fememino.

int main (){
    
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