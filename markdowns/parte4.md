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


