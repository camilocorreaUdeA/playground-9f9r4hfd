# Operador `static_cast<>()`

Este operador simplemente ejecuta una conversión explícita de un objeto desde una clase hacia otra. Solo es posible entre clases que estén relacionadas por herencia, es decir, se puede utilizar para hacer conversión de un objeto de clase base a una de sus clases derivadas ("downcasting") o bien para convertir un objeto de una clase derivada a su clase base ("upcasting"). En el caso de polimorfismo dinámico, cuando se usan métodos virtuales, es útil cuando se quiere hacer llamados a métodos a no-virtuales que fueron redefinidos en las clases derivadas. A esta operación en general se le conoce como "downcasting". Observe el siguiente ejemplo:

```C++ runnable
#include<iostream>
using namespace std;

class Base
{
    public:
    virtual void MetodoOne()
    {
        cout<<"Clase Base MetodoOne"<<endl;
    }
    void MetodoTwo()
    {
        cout<<"Clase Base MetodoTwo"<<endl;
    }
};

class Derivada:public Base
{
    public:
    void MetodoOne()
    {
        cout<<"Clase Derivada MetodoOne"<<endl;
    }
	
	void MetodoTwo()
    {
        cout<<"Clase Derivada MetodoTwo"<<endl;
    }
};

int main()
{
    Base *ptr = new Derivada; //Puntero de clase Base a un objeto de clase Derivada
    ptr->MetodoOne();
    static_cast<Derivada *>(ptr)->MetodoTwo();
    delete ptr;
    return 0;
}
```

El operador `static_cast` también se puede utilizar para realizar la operación conocida como "upcasting" en la que un objeto de la clase derivada se convierte de manera explícita en un objeto del tipo de su clase base para poder ejecutar llamados directos a los métodos de la clase base y no a la redefinición en la clase derivada. Observe y ejecute el siguiente ejemplo:

```C++ runnable
#include<iostream>
using namespace std;

class Base
{
    public:
    virtual void MetodoOne()
    {
        cout<<"Clase Base MetodoOne"<<endl;
    }
    void MetodoTwo()
    {
        cout<<"Clase Base MetodoTwo"<<endl;
    }
};

class Derivada:public Base
{
    public:
    void MetodoOne()
    {
        cout<<"Clase Derivada MetodoOne"<<endl;
    }
    void MetodoTwo()
    {
        cout<<"Clase Derivada MetodoTwo"<<endl;
    }
};

int main()
{
    Derivada *ptr = new Derivada; //Puntero de clase Base a un objeto de clase Derivada
    ptr->MetodoOne();
    static_cast<Base *>(ptr)->MetodoTwo(); //Operación de upcasting para llamar al método de la clase base
    delete ptr;
    return 0;
}
```
Desafortunadamente, cuando se usa `static_cast` el compilador no puede comprobar si la conversión que se está tratando de hacer es correcta, es decir si no se está haciendo entre clases incompatibles que tienen una clase base como ancestro en común. Para verificar y validar si se hace una conversión adecuada existe el operador `dynamic_cast<>()`

# Operador `dynamic_cast<>()`

Este operador sirve para identificar si un puntero involucrado en un polimorfismo puede ser convertido a cierto tipo de clase (clases derivadas). Se usa particularmente cuando en una función se pasa como parámetro un objeto polimorfico, es decir, un parámetro formal del tipo de la clase base que conlleva a un parámetro real del tipo de una clase derivada. Esto tiene como objetivo hacer que las funciones y métodos puedan ser más genéricos y se pueda definir un solo método que trabaje con objetos de distinto tipo al mismo tiempo. El operador `dynamic_cast<>()` retorna un puntero si se comprueba que la conversión es correcta, de otro modo retorna un puntero a `NULL`. Observe y ejecute el siguiente ejemplo en el que se implementa una función polimorfica (genérica):

```C++ runnable
#include<iostream>
using namespace std;

class Base
{
    public:
    virtual void printHola(){cout<<"Hola Base"<<endl;}
};

class Derivada:public Base
{
    public:
    virtual void printHola(){cout<<"Hola Derivada"<<endl;}
};

class Deriderivada:public Derivada
{
    public:
    virtual void printHola(){cout<<"Hola Deriderivada"<<endl;}
};

void printHola(Base* obj)
{
    /* Punteros para almacenar el retorno del operador dynamic_cast */
    Base *ptr1 = nullptr;
    Derivada *ptr2 = nullptr;
    Deriderivada *ptr3 = nullptr;
    
    if(ptr = dynamic_cast<Base *>(obj))
        ptr->printHola();
    if(ptr2 = dynamic_cast<Derivada *>(obj))
        ptr2->printHola();
    if(ptr3 = dynamic_cast<Deriderivada *>(obj))
        ptr3->printHola();
}

int main()
{
    Base *ptr = new Derivada;
    printHola(ptr);
    delete ptr;
    Base *ptr = new Deriderivada;
    printHola(ptr);
    delete ptr;
    
    return 0;
}
```
























