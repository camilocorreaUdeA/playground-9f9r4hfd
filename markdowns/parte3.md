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

class Derivada
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
    return 0;
}
```






























