# Asignación y liberación dinámica de memoria

Con ayuda de los punteros C++ permite reservar dinámicamente espacios de memoria ubicados en la zona que se conoce como `Heap` que comparte los recursos de memoria con el `Stack`. Para la reserva de memoria existen dos operadores, el primero es el operador `new` que se utiliza para reservar posiciones individuales de memoria del tamaño del tipo de dato que se va a alojar en esa posición. Mientras que el operador `new[]` permite reservar al tiempo varias posiciones consecutivas de memoria como en el caso de arreglos. El problema con la reserva dinámica de memoria es que debe ser liberada de nuevo de manera manual una vez no se necesita más, ya que en C++ a diferencia de otros lenguajes de programación no existe una entidad que se encargue de hacer esta liberación de memoria de manera automática (ejemplo: garbage collector), por tanto es necesario el uso de otros operadores o funciones que permitan realizar esa liberación de memoria, que en caso de no hacerse correctamente da lugar al problema de fuga de memoria o "memory leak". Entonces para liberar la memoria previamente reservada existen los operadores `delete` y `delete[]` que siven para liberar la memoria reservada con los operadores `new` y `new[]` respectivamente. <b>NOTA:</b> Para evitar el problema de fuga de memoria las nuevas versiones de C++ vienen con unas clases especiales llamadas `Smart Pointers` que automatizan el proceso de liberación de memoria y además brindan métodos para la reserva de memoria sin necesidad de utilizar directamente los operadores `new` y `new[]`.

El siguiente código de ejemplo ilustra el procedimiento de reserva y liberación de memoria dinámica con los operadores `new` y `delete`
```cpp

class MyClass
{
    // Miembros de la clase
};

int main()
{
    int *ptr = new int; // Reserva de memoria para un dato de tipo int (4 bytes en arquitecturas 32bits)
    *ptr = 150; // Guardando un dato en la memoria reservada
    
    MyClass *ptr2 = new MyClass[5]; // Arreglo dinamico de objetos del tipo MyClass
    for(int i=0; i<5; ++i)
    {
        MyClass obj;
        *(ptr2 + i) = obj; // Guardando los objetos en las posiciones de memoria reservadas
    }
    
    delete ptr; // Liberando de nuevo la memoria 
    delete[] ptr2;
    
    return 0;
}
```
# Reserva y liberación de memoria en Clases

Se puede realizar reserva dinámica de memoria para miembros de clase. En general, se declara un puntero del tipo de dato que se va a alojar en la memoria, en el constructor de la clase se realiza la reserva con los operadores `new` y `new[]` y finalmente se libera la memoria en el destructor de la clase con los operadores `delete` y `delete[]` por tanto la memoria reservada por el objeto se libera momentos antes de la destrucción del mismo. Observe el siguiente ejemplo:

```C++ runnable
#include<iostream>
using namespace std;

class MiClase
{
    int *ptr = nullptr;
    public: 
    MiClase():ptr(new int(0)){} // Constructor por defecto, la sintaxis equivale a *ptr = 0
    MiClase(int a):ptr(new int(a)){} // Constructor parametrizado, la sintaxis equivale a *ptr = a
    MiClase(const MiClase &c):ptr(new int(*(c.ptr))){} // Constructor de copia, la sintaxis equivale a *ptr = *(c.ptr)
    ~MiClase(){delete ptr;} // Liberando la memoria en el destructor
    void showMemory(){cout<<"*ptr = "<<*ptr<<endl;}

};

int main()
{
    MiClase o1;
    MiClase o2(10);
    MiClase o3(o2);
    o1.showMemory();
    o2.showMemory();
    o3.showMemory();

    return 0;
}
```



