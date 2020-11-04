// Clase - arreglo dinamico para enteros
#ifndef ARREGLODINAMICO_H
#define ARREGLODINAMICO_H

#include <iostream>
using namespace std;

// modificaremos la clase arreglo para que sea un template
// estamos creando la clase "T" representando el dato generico.
template <class T>
class ArregloDinamico
{
    T *arreglo;
    size_t tam; //elementos para  almacenar
    size_t cont;
    // MAX sera el tamaño de el arreglo dinamico
    const static size_t MAX = 100;
    public:
        ArregloDinamico ();
        ~ArregloDinamico();

        void insertar_final (const T& v);
        void insertar_inicio (const T& v);
        void insertar (const T& v, size_t p);

        void eliminar_final(); 
        void eliminar_inicio();
        void eliminar(size_t p); 

        size_t size();
        string operator[](size_t p) //
        {
            return arreglo[p];
        }
    private:
        void expandir();
};

    //constructor
    template <class T>
    ArregloDinamico<T>::ArregloDinamico()
    {
        arreglo = new T[MAX];
        cont = 0;
        tam = MAX;
    }

    //destructor
    template <class T>
    ArregloDinamico<T>::~ArregloDinamico()
    {
        delete[]arreglo;
    }

    template <class T>
    void ArregloDinamico<T>::insertar_final(const T& v)
    {
        if (cont == tam)
        {   
            expandir (); 
        }
        arreglo[cont] = v;
        cont++;
    }

    template <class T>
    void ArregloDinamico<T>::insertar_inicio(const T& v)
    {
        if (cont == tam)
        {   
            expandir ();
        }
        for (size_t i = cont; i > 0; i--)
            {   
                arreglo[i] = arreglo [i-1];
            }
        arreglo[0] = v;
        cont++;
    }

    template <class T>
    void ArregloDinamico<T>::insertar(const T& v, size_t p)
    {
        if (p >= cont)
        {
            cout << "Es una posicion no valida" << endl;
            return;
        }

        if (cont ==tam) 
        {
            expandir();
        }
        for (size_t i = cont; i> p; i--)
        {
            arreglo[i] = arreglo[i-1];
        } 
        arreglo [p]= v;
        cont++;
    }

// si contador es = 0, no puedo eliminar 0 elementos 
    template <class T>
    void ArregloDinamico<T>::eliminar_final()
    {
        if (cont == 0)
        {
            cout<< "Arreglo vacio"<< endl;
            return;
        }
        cont--;
    }

    template <class T>
    void ArregloDinamico<T>::eliminar_inicio()
    {
        if (cont == 0)
        {
            cout<< "Arreglo vacio"<< endl;
            return;
        }
        for (size_t i = 0; i < cont -1; i++)
        {
            arreglo[i] = arreglo [i+1];
        }
        cont--;
    }

    template <class T>
    void ArregloDinamico<T>::eliminar(size_t p)
    {
        if (cont == 0)
        {
            cout<< "Arreglo vacio"<< endl;
            return;
        }
        for (size_t i = p; i < cont - 1; i++)
        {
            arreglo[i] = arreglo [i+1];
        } 
        cont--;
    }


    template <class T>
    size_t ArregloDinamico<T>::size()
    {
        return cont;
    }

    template <class T>
    void ArregloDinamico<T>::expandir()
    {
        T *nuevo = new T[tam+MAX];
        for (size_t i = 0; i< cont; i++)
            {   
                nuevo [i] = arreglo [i];
            }  
                delete[] arreglo;
                arreglo = nuevo;
                tam = tam + MAX;
    }

#endif