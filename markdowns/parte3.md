# Polimorfismo

Una clase puede exhibir comportamientos (métodos) que no tiene definidos en sí misma sino en otras clases que se derivan de ella. Es decir, una misma clase puede adoptar "muchas formas" diferentes dependiendo de las redefiniciones presentes en clases que se deriven de ella. Existen dos clases de polimorfismo que se verán a continuación:

<ul>
<li><b>Polimorfismo estático (en tiempo de compilación): </b></li>Este ocurre cuando se da un proceso conocido como "early binding" o "static binding" que no es otra cosa distinta a que la memoria que se reserva para un polimorfismo es reservada en tiempo de compilación. Este tipo de polimorfismo se ha aplicado en las prácticas anteriores a pesar de que no se menciono directamente. Se atribuye este polimorfismo particularmente a la sobrecarga de funciones (métodos), a la sobrecarga de operadores y a la programación genérica mediante el uso de "templates".

<li><b>Polimorfismo dinámico (en tiempo de ejecución): </b></li>Se le conoce como dinámico porque sucede en tiempo de ejecución de la aplicación, es decir la memoria que se reserva para este polimorfismo es reservada en el momento que la aplicación lo requiere (proceso conocido como "late binding" o "dynamic binding"). Esta situación se da mediante el uso de métodos virtuales de clases base que son redefinidos en clases derivadas. Es estrictamente necesario el uso de la palabra reservada `virtual` ya que este polimorfismo depende de un proceso en el cual un puntero a funciones consulta una tabla de funciones virtuales para resolver si un método que se invoca es el que está definido en la clase base o si por el contrario corresponde a una redefinición en una de las clases derivadas.
</ul>

# Polimorfismo dinámico

En pocas palabras el polimorfismo dinámico se refiere a que se puede apuntar un puntero del tipo de la clase base a objetos del tipo de la clase derivada, esto permite que una instancia del tipo de la clase base pueda invocar métodos del tipo de la clase derivada, siempre y cuando sean métodos redefinidos y que hayan sido declarados en la clase base con la palabra virtual. El siguiente ejemplo permite observar con mayor claridad la situación:

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
    ptr->MetodoTwo();
    delete ptr;
    return 0;
}
```
El resultado de la ejecución del código anterior se entiende así: en el caso del llamado a MetodoOne, al ser este una redefinición de un método virtual, entonces se busca en la tabla virtual y se ejecuta el que corresponde a la clase derivada. En el caso del llamado a MetodoTwo, por no ser una redefinición de un método virtual entonces C++ ejecuta el método que corresponde al tipo del puntero, en este caso la clase Base, ya que no está pendiente del tipo que se almacena en el puntero sino del tipo del puntero.

# Destructor virtual

Se mencionó que cuando se apunta un puntero de la clase base a un objeto de la clase derivada entonces C++ invoca los métodos no-virtuales de la clase base y busca en la tabla virtual las redefiniciones de los métodos virtuales. Lo mismo le sucede al destructor de la clase, si no se específica que el destructor sea virtual entonces C++ solo invoca el destructor de la clase base que es el tipo del puntero, esto configura una fuga de memoria "memory leak" ya que el operador `new` retorna un puntero a una reserva de memoria para un objeto del tipo de la clase derivada, dicha memoria no es liberada cuando se libera el puntero de la clase base. Por esto último es necesario que al implementar un polimorfismo dinámico el destructor de la clase base sea virtual. En el siguiente código de ejemplo ejecute usando la firma del destructor que no incluye la palabra `virtual` y la que si la incluye (comente y descomente las líneas) y observe la diferencia en el resultado de la ejecución:

```C++ runnable
#include<iostream>
using namespace std;

class Base
{
    public:
    Base(){cout<<"Constructor Base"<<endl;}
    ~Base(){cout<<"Destructor Base"<<endl;} //No virtual
    //virtual ~Base(){cout<<"Destructor Base"<<endl;} //Virtual
};

class Derivada:public Base
{
    public:
    Derivada(){cout<<"Constructor Derivada"<<endl;}
    ~Derivada(){cout<<"Destructor Derivada"<<endl;}
};

int main()
{
    Base *ptr = new Derivada; //Puntero de clase Base a un objeto de clase Derivada
    delete ptr;
    return 0;
}
```

# Polimorfismo dinámico y el constructor de copia

El polimorfismo tiene un problema con el constructor de copia.

```C++ runnable
#include<iostream>
using namespace std;

class Base
{
    public:
    Base(){cout<<"Constructor Base"<<endl;}
    Base(const Base &b){cout<<"Constructor Base"<<endl;}
    virtual ~Base(){cout<<"Destructor Base"<<endl;} //Virtual
};

class Derivada:public Base
{
    public:
    Derivada(){cout<<"Constructor Derivada"<<endl;}
    Derivada(const Derivada &d){cout<<"Constructor Derivada"<<endl;}
    ~Derivada(){cout<<"Destructor Derivada"<<endl;}
};

int main()
{
    Base *ptr = new Derivada; 
    Base *ptr2 = new Derivada(*ptr); //Intentando copia
    delete ptr;
    return 0;
}
```

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





























