#include <iostream>
#include "ArregloDinamico.h"

using namespace std;

int main ()
{

    ArregloDinamico<string>arreglo;
    //quiere que decir que cualquier tipo de clase la tomara como la "T"

        arreglo.insertar_final("Fernanda");
        arreglo.insertar_final("no");
        arreglo.insertar_final("cree");
        arreglo.insertar_final("pasar");

        arreglo.insertar_inicio("semestre");
        arreglo.insertar_inicio("el");
        arreglo.insertar_inicio("cien");
        arreglo.insertar_inicio("con");


//        arreglo.insertar(":(",2); //Insertar el 100 en posicion 2
    
//        arreglo.eliminar_inicio();
//        arreglo.eliminar_final();
//        arreglo.eliminar(4); //eliminar el de la posicion 4

    for (size_t i = 0.0; i < arreglo.size(); i++)
    {
        cout << arreglo [i] << " ";
    }   
    cout << endl;

    return 0;
} 