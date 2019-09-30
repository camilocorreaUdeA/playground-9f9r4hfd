# Punteros en C++

Los punteros (o apuntadores) son variables que se utilizan para almacenar direcciones de memoria, puntualmente las direcciones de memoria que fueron asignadas a variables convencionales en las que se almacenan datos de distinto tipo. Vale la pena entonces recordar que a todas las variables en C++ se les asigna un espacio de memoria en el cual se va almacenar el valor que se le asigne en algún punto de la aplicación a esa variable, el tamaño de dicho espacio va depender del tipo de dato que se pretende almacenar en la variable, del compilador y de la arquitectura del procesador. Cada uno de los espacios de memoria cuenta con una dirección para identificarlo, esta dirección es por lo general un número en representación hexadecimal. Es precisamente ese número correspondiente a la dirección lo que se almacena en un puntero. 

Observe la siguiente imagen de ejemplo, se declara una variable `var` y se inicializa directamente en la declaración, dicha variable recibe un espacio en memoria para almacenar el valor que se le asigna en la inicialización. Dicho espacio en memoria tiene su propia dirección para poder ser referenciado.

![Image of Yaktocat](var_memory.png)

Se puede declarar un puntero para almacenar la dirección de memoria correspondiente a la variable `var`, es decir, se puede "apuntar" un puntero a la variable `var`. Para declarar un puntero se utiliza la sintaxis para declaración de variables: calificadores opcionales, modificadores opcionales, tipo de dato obligatorio y un identifador para el puntero que también es obligatorio. El tipo de dato del puntero debe ser obligatoriamente el mismo tipo de dato de la variable a la que se pretende apuntar, es decir, si se requiere almacenar la dirección en memoria de una variable de tipo `int`, entonces el tipo de dato del puntero también debe ser `int`. Un puntero se distingue de otras variables porque en su declaración se utiliza el operador `*` luego del tipo de dato y antes del identificador del puntero. Observe a continuación la declaración de varios punteros:

```cpp
int *puntero_a_int;
float *puntero_a_float;
ClaseA *puntero_a_objeto_claseA;
```
Para apuntar un puntero a una variable se utilizan el operador de asignación `=`, el operador `&` y la variable a la que se quiere apuntar. Con el operador `&` se obtiene la dirección de la variable y se le asigna al puntero mediante el operador de asignación `=`. Observe, ejecute y analice el ejemplo a continuación:

```C++ runnable
#include<iostream>
using namespace std;

class MiClase
{
    int x;
    public:
    MiClase():x(0){}
};

int main()
{
    int var = 250;  //Una variable cualquiera
    int *ptr_var = &var;  //Apuntando un puntero a la variable
    
    MiClase obj;  //Un objeto cualquiera
    MiClase *ptr_obj = &obj;
    
    cout<<"Valor de la variable var: "<<var<<endl;
    cout<<"Direccion de la variable var: "<<&var<<endl;
    cout<<"Direccion almacenada en el puntero ptr_var: "<<ptr_var<<endl;
    cout<<"-------------------------------------------------------"<<endl;
    cout<<"Direccion del objeto obj: "<<&obj<<endl;
    cout<<"Direccion almacenada en el puntero ptr_obj: "<<ptr_obj<<endl;
    return 0;
}
```



















