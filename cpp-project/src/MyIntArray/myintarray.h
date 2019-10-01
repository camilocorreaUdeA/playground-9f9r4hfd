/* MyIntArray.h */
#ifndef MYINTARRAY_H
#define MYINTARRAY_H

class MyIntArray
{
    int ocupado, tam_max;
    int *array = nullptr;
    void agregarMemoria(int e);
    public:
    MyIntArray();
    MyIntArray(int tam);
    MyIntArray(const MyIntArray &c);
    ~MyIntArray();
    int longitud();
    void agregarElemento(int elem);
    int& operator[](int pos);
};

#endif
