/* MyIntArray.cpp */
#include "myintarray.h"

MyIntArray::MyIntArray()
{
    tam_max = 20; // Longitud por defecto del arreglo
    array = new int[tam_max];
    ocupado = 0;
}

MyIntArray::MyIntArray(int tam)
{
    tam_max = tam; // Longitud del arreglo
    array = new int[tam_max];
    ocupado = 0;
}

MyIntArray::MyIntArray(const MyIntArray &c)
{
    tam_max = c.tam_max; // Longitud del otro arreglo
    array = new int[tam_max];
    ocupado = c.ocupado; //Cuanto se ha utilizado en el otro arreglo
    for(int i=0; i<ocupado; ++i) //Copiando los elementos del otro arreglo
        *(array + i) = *(c.array + i);
}

MyIntArray::~MyIntArray() 
{
    delete[] array; //Liberando la memoria reservada
}

int MyIntArray::longitud()
{
    return ocupado;
}

int& MyIntArray::operator[](int pos) //Sobrecarga del operador [] para leer o modificar elementos del arreglo
{
    if(pos>=ocupado) //Error, posicion por fuera de la longitud del arreglo
        throw("Error");
    
    return array[pos];
}

void MyIntArray::agregarMemoria(int e)
{
    tam_max += 5; // Agregando capacidad extra al vector
    int *temporal = new int[tam_max]; // Arreglo temporal
    for(int i=0; i<ocupado; ++i) //Copiando los elementos en el arreglo temporal
        *(temporal + i) = *(array + i);
    *(temporal + ocupado) = e;
    delete[] array; //Liberando la memoria
    array = temporal; //Apuntando array a la direccion de memoria de temporal
    ocupado++;
}

void MyIntArray::agregarElemento(int elem) //Agrega un nuevo elemento al final del arreglo
{
    if((ocupado + 1) >= tam_max)
        agregarMemoria(elem);
    else
    {
        *(array + ocupado) = elem;
        ocupado++;
    }
}
