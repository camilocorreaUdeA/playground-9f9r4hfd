/* main.cpp */
#include<iostream>
#include "myintarray.h"

using namespace std;

int main()
{
    MyIntArray arreglo(10);
    for(int i=1; i<11; ++i)
        arreglo.agregarElemento(i);
    cout<<arreglo.longitud()<<endl;
    cout<<arreglo[5]<<endl;
    arreglo.agregarElemento(12);
    cout<<arreglo.longitud()<<endl;
    cout<<arreglo[11]<<endl;
    return 0;
}