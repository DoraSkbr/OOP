#include <iostream>
using namespace std;
#pragma pack(1) // Задает выравнивание упаковки для членов структуры, объединения и класса
void ff()
{
    cout << "Global:" << endl;
}
// 1) Создание базового класса Base
class Base
{
    double d;

protected:
    long l;

public:
    int i;
    // Конструктор без параметров
    Base() {}
    // Конструктор с параметрами
    Base(int it, long lo, double db) : i(it), l(lo), d(db)
    {
    }
    void ff()
    {
        cout << "Base:" << endl;
    }
};

// 2) Создание дочернего класса Derived от Base
class Derived : public Base
{
    float f;

public:
    // Конструктор без параметров
    Derived() {}
    // Конструктор с параметрами
    Derived(int it, long lo, double db, float fl) : Base(it, lo, db), f(fl)
    {
    }
    // Перегрузка операции вставки в поток
    friend ostream &operator<<(ostream &os, const Derived &tip);
    void ff()
    {
        cout << "Derived:" << endl;
    }
};

// Создание дочернего класса Derived_1 от Derived
class Derived_1 : public Derived
{
public:
    // Конструктор без параметров
    Derived_1() {}
    // Конструктор с параметрами(их надо 4)
    Derived_1(int it, long lo, double db, float fl) : Derived(it, lo, db, fl)
    {
    }
    void foo()
    {
        i++;
        l += 1;
        ff();

    }
};

ostream &operator<<(ostream &os, const Derived &tip)
{
    // Поскольку operator << является другом класса Derived, то мы имеем прямой доступ к членам Derived
    os << "i = " << tip.i << ", адрес i = " << &(tip.i) << endl
       << "l = " << tip.l << ", адрес l = " << &(tip.l) << endl
       /*
       Нет доступа, так как переменная d находится в спецификаторе доступа private
       << "d = " << tip.d << ", адрес d = " << &(tip.d) << endl
       */
       << "f = " << tip.f << ", адрес f = " << &(tip.f) << endl;
    return os;
}

int main()
{
    Derived der;
    // sizeof - размер типов данных
    cout << "Derived: " << sizeof(Derived) << endl;
    cout << "Base: " << sizeof(Base) << endl;
    Derived der1(1, 2, 3, 4);
    cout << "Derived:" << endl;
    cout << der1 << endl;
    Derived_1 der_1(1, 2, 3, 4);
    cout << "Derived_1:" << endl;
    cout << der_1 << endl;
    der_1.foo();
    cout << "Derived_1 с foo():" << endl;
    cout << der_1 << endl;
}
