// Project exercises
#include <iostream>
#include <string>
using namespace std;

/*
// exercise 1
int main()
{
int i = 5;
    do {
        cout << i;
    } while(i-- > 0);
    cout << --i;
    // result: 543210-2
}
 */

/*
// exercise 2
int main()
{
    for(int i = 5; i > 0; i--)    // область видимости переменной i - только этот цикл, за пределами его переменная i - скрыта
        cout << i;
    cout << i;                    // идентификатор "i" не определен
    // result: compilation error
}
 */

/*
// exercise 3
 void F(int& x, int& y)
{
    cout << x++ << --y;
}
 void main()                      // ошибка: главная функция main должна возвращать int
{
    int a = 5;
    F(a, 6);                      //начальное значение ссылки на неконстантный параметр должно быть левосторонним значением (6 - не lvalue)
    cout << a;
    // result: compilation error
}
 */

/*
//exercise 4
void F(const int* x)              // неправильная передача массива, нужно кроме указателя на первый элемент передать и колличество елементов
{
    for(int i = 0; i < 3; i++)
        x[i] += 2;                // ошибка: 1) обращение по индексу к переменной типа int; 2) x объявлен как const и не может быть левосторонним значением для присваивания
}
void main()                       // ошибка: главная функция main должна возвращать int
{
    int mas[] = {1, 2, 3};
    F(mas);
    for(int i = 0; i < 3; i++)
        cout << mas[i];
}

// result compilation error
 */

/*
//exercise 5
void main()                         //int main()
{
    char* ptr = new char('a');
    char* ptr2 = ptr;
    ptr = new char('b');
    cout << *ptr << *ptr2;
}
// result compilation error (void main() - главная функция main должна возвращать int)

 */

/*
//exercise 6
void main()                         //int main()
{
    int mas[5] = {0,1,2,3,4};
    int* ad = mas + 2;
    cout << *(mas + 2) + *(ad + 2);
}
// result compilation error (void main() - главная функция main должна возвращать int)
 */

/*
//exercise 7
void F(int* x)
{
    for(int i = 0; i < 3; i++)
        x[i] += 2;
}
 void main()                         //int main()
{
    int mas[] = {1,2,3};
    F(mas);
    for(int i = 0; i < 3; i++)
        cout << mas[i];
}
// result compilation error (void main() - главная функция main должна возвращать int)
 */


/*
//exercise 8
class A{
    private:
        char l;
    public:
        A() {};
        int print() {cout << l; return 1;}
};
int main()
{
    A a1;
    int rez = a1.print();
}
 */

/*
//exercise 9
class A{
    private:
        char l;
    public:
        A() : l('L') {};
        void print() { cout << l;}
};
int main()
{
    A a1;
    a1.print();
}
 */

/*
//exercise 10
class A{
    private:
        int a;
    public:
        A() :a(0) {cout << '1' << a;}
        A(int y) :a(y) {cout << '2' << a;}
        A(const A& x) :a(x.a) {cout << '3' << a;}
};
void Test()                              //int main()
{
    A a(1);
    A *arr = &a;
    arr = new A(a);

}
// result compilation error (отсутствие главной функции main)
 */

/*
//exercise 11
class A{
    private:
        int a;
    public:
        A() :a(0) {cout << '1' << a;}
        A(int y) :a(y) {cout << '2' << a;}
        A(const A& x) :a(x.a) {cout << '3' << a;}
};
void Test()                               //int main()
{
    A a(5);
    A b(3.2);
}
// result compilation error (отсутствие главной функции main)
 */

/*
//exercise 12
class Exc : exception                      //class Exc :public exception
{
    public:
    Exc() :exception() {}
};
class A{
    int x;
public:
    A(int i) :x(i) {}

    const string g(int i) {
        if(i>x) throw Exc();
        return "Ok";
    }
};
void f()                                  //int main()
{
    try {cout << (A(10)).g(19);}
    catch (Exc e) {cout << e.what(); }
}
//  result compilation error (перед указанием базового класса exception для класса Exc
// ожидается квалификатор public; отсутствие главной функции main)
 */

/*
//exercise 13
#include <cstring>
class Exc : exception
{
    public:
        Exc() :exception() {}
        Exc(const string& s) : exception(s.c_str()) {}
        virtual const char* what() const throw() {return exception::what();}
};*/
/* class Exc : public exception                   // Вариант рабочего класса с конструтором Exc(const string& s)
{
    string str;
    public:
        Exc() :exception() {}
        Exc(const string& s) : exception() {
            str = s;
        }
        virtual const char* what() const throw() {return str.c_str();}
}; */
/*class A
{
    string x;
    public:
    A(string i) :x(i) {}
    const string& g(const string& i) {
        if(i>x) throw Exc("Over");
        return x;
    }
};
void F() {                                        //int main()
    try{
        A a("10");
        cout << a.g("20");
    }
    catch(const Exc & e) { cout << e.what(); }
    cout << ":)";
}
// result compilation error (перед указанием базового класса exception для класса Exc
// ожидается квалификатор public;
// ошибка в строке инициализации базовой части конструктора Exc(const string& s) - базовый класс exception
// не имеет конструктора с аргументами; класс Exc можно переделать как показанно в коде что бы принимал аргумет;
// отсутствие главной функции main)
*/

/*
//exercise 14
class A {
public:
    void print() {cout << "A";}
};
class B {
public:
    void print() {cout << "B";}
};
void F() {
    A a;
    a.print();
    B b;
    b.print();
    A* p = &a;
    p->print();
    p = &b;                   // указателю на объект класса А нельзя присвоить адрес объекта класса В
    p->print();
}
// result compilation error:
// указателю на объект класса А нельзя присвоить адрес объекта класса В;
// отсутствие главной функции main
 */

/*
//exercise 15
class A {
public:
    virtual void print() = 0;
};
class B : public A {
public:
    void print() {cout << "B";}
};
void F() {                     // int main() - отсутствие главной функции main
    A a;                       // нельзя создавать объекты абстрактного класса;
    B b;
    A* p;
    p->print();                // нельзя вызывать чистые методы абстрактного класса;
    p = &b;
    p->print();
}
// result: compilation error
// нельзя создавать объекты абстрактного класса;
// нельзя вызывать чистые методы абстрактного класса;
// отсутствие главной функции main
 */


/*
//exercise 16
class A {
    int a;
public:
    A(int a) :a(a) {}
    int get() {return a;}
};
class B : public A {
    int b;
public:
    B(int a=0,int b=0):A(a),b(b){}  // конструктор с двумя аргументами которые имеють значение по умолчанию (0) что делает этот коструктор конструктором по умолчанию.
    int get() {return b;}
};
int main() //void F()               //  void F() - нужно заменить  главной функцией int main()
{
    B mas[10];                      // для создания этого массива нужен конструктор по умолчанию (т.е. без явных инициализирующих аргументов)
}
 */


/*
//exercise 17
struct A {
    char i;
    A() : i('0') {}
    A(const A& a) : i(a.i) {cout << "AC" << i;}
    A(char ii) : i(ii) {cout << "A" << i;}
};
struct B : virtual A {
    B() {}
    B(const B& b) {cout << "BC" << i;}
    B(char ii) : A(ii) {cout << "B" << i;}
};
struct D : virtual A {
    D() {}
    D(const D& d) {cout << "DC" << i;}
    D(char ii) : A(ii) {cout << "D" << i;}
};
struct E : B, D {
    E(char ii) : A(), B(), D() {}
};
int main() //void F()             //  void F() - нужно заменить  главной функцией int main()
{
    E e('a');
    E e1 = e;
}
// result: AC0BC0DC0
 */


/*
//exercise 18
#include<vector>
int main() {
    vector<int> v1;
    v1.insert(v1.begin(), 3);
    v1.push_back(7);
    v1.push_back(4);
    v1[2] = 9;
    v1.front() = 6;
    for(int i = 0; i < v1.size(); i++)
        cout << v1[i];
}
// result: 679
 */


/* 
 //exercise 19
 #include<set>
 int main()//void main()
 {
     unsigned u[] = {2, 40, 3, 2 , 40};
     set<unsigned> a(u, u + 5);
     set<unsigned>::iterator f = a.find(3);            //find(a.begin(), a.end(), 3)
     unsigned s = 0;
     while (f != a.end()) s += *f++;
     cout << s;
 }
// result: 43 (если возвращаемое значение в функции main поменять на int; a.find(a.begin(), a.end(), 3) 
// не работает в Visual Studio Code a в Viseal Studio 2017 работает)
 */


/*
 //exercise 20
 #include<vector>
 int main() {                             //void main()
     vector<int> q(5);                    //vector<int> q;
     for(int i = 0; i < 5; i++) q[i] = i;
     cout << q.size() << q.back();
 }
 // result: ошибка компиляции (попытка присвоить значения елементам пустого массива; 
 // главная функция не может возвращать void); eсли поменять void main() на int main()
 // и при создании вектора указать колличество елементов (5) - то результат 54)
 */


/* 
//exercise 21
#include<cstring>
template <class T> void swapn(T& x, T& y) {
    T temp = x; x = y; y = temp;
}
void swapn(char* s1, char* s2) {
    unsigned size = (strlen(s1) >= strlen(s2)) ? strlen(s1) : strlen(s2);
    char* temp = new char[size + 1];
    strcpy(temp, s1); strcpy(s1, s2); strcpy(s2, temp);
}
template <class T1, class T2> ostream& show(T1& ar1, T2& ar2) {         //дописанно для илюстрации результата
    cout << ar1 << " - " << ar2 << "\n";
}
struct A {
    char* m;
    A(const char* x) :m(new char[strlen(x) + 1]) {strcpy(m, x); }
    A(const A& a) :m(new char[strlen(a.m) + 1]) { strcpy(m, a.m); }
    A& operator=(const A& a) { delete[] m; m = new char[strlen(a.m) + 1]; strcpy(m, a.m); return *this; }
    friend ostream& operator<<(ostream& os, A& obj) { cout << obj.m; }  //дописанно для илюстрации результата 
};

int main() {                                                          // void F() 
    A a("abc"), b("10");
    char d[] = {'1', '2', '\0'}, c[] = {'A', 'B', 'C', '\0'};
    
    //1
    cout << "before: ";                                               //дописанно для илюстрации результата
    show(a, b);                                                       //дописанно для илюстрации результата
    swapn(a, b);
    cout << "after: ";                                                //дописанно для илюстрации результата
    show(a, b);                                                       //дописанно для илюстрации результата
    //2
    cout << "\nbefore: ";                                             //дописанно для илюстрации результата
    show(a.m, b.m);                                                   //дописанно для илюстрации результата
    swapn<char*>(a.m, b.m);
    cout << "after: ";                                                //дописанно для илюстрации результата
    show(a.m, b.m);                                                   //дописанно для илюстрации результата
    //3
    cout << "\nbefore: ";                                             //дописанно для илюстрации результата
    show(c, d);                                                       //дописанно для илюстрации результата
    swapn(c, d);
    cout << "after: ";                                                //дописанно для илюстрации результата
    show(c, d);                                                       //дописанно для илюстрации результата
    //4
    //swapn<int*>(c, d);                                              //ошибка: не соотвецтвие аргументов типу экземпляра шаблона
    //5
    cout << "\nbefore: ";                                             //дописанно для илюстрации результата
    show(a.m, d);                                                     //дописанно для илюстрации результата
    swapn(a.m, d);
    cout << "after: ";                                                //дописанно для илюстрации результата
    show(a.m, d);                                                     //дописанно для илюстрации результата
} */
//result: 1 2 3 5 (при условии eсли поменять void F() на int main() и 
// закоментировать пятый вызов функции swapn (swapn<int*>(c, d)))

/* для илюстрации работы функции swapn дописанно функцию вывода на экран show и дружественную функцию 
operator<< для класса А
В результате следующий вывод на экран:
 before: abc - 10
after: 10 - abc

before: 10 - abc
after: abc - 10

before: ABC - 12
after: 12 - ABC

before: abc - ABC
after: ABC - abc
 */


/* 
//exercise 22
int main()                                           // исправленно: вместо void main() вставленно int main()
{
    const char* text = "abcdef";                     // исправленно: добавлен квалификатор const (const char* text )
    int i = 0;
    do
    {
        cout << text[++i];
    } while (i != 4);
    
}
 */
//result: ошибка компиляции (указателю на чар присвоен константная строка и 
// функция main должна возвращать int a не void)

// Если исправить эти ошибки получим результат: bcde




//exercise 22
