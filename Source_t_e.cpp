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
    for(int i = 5; i > 0; i--)
        cout << i;
    cout << i;
    // result: compilation error
} 
*/

/* 
// exercise 3
 void F(int& x, int& y)
{
    cout << x++ << --y;
}
 void main()
{
    int a = 5;
    F(a, 6);
    cout << a;
    // result: compilation error (void F(int& x, int& y) - return value cannot be void)
} */

/* 
//exercise 4
void F(const int* x)
{
    for(int i = 0; i < 3; i++)
        x[i] += 2;
}
void main()
{
    int mas[] = {1, 2, 3};
    f(mas);
    for(int i = 0; i < 3; i++)
        cout << mas[i];
}

// result compilation error (void F(const int* x) - return value cannot be void)
 */

/* 
//exercise 5
void main()
{
    char* ptr = new char('a');
    char* ptr2 = ptr;
    ptr = new char('b');
    cout << *ptr << *ptr2;
}
// result compilation error (void main() - return value cannot be void) 
*/

/* 
//exercise 6
void main()
{
    int mas[5] = {0,1,2,3,4};
    int* ad = mas + 2;
    cout << *(mas + 2) + *(ad + 2);
}
// result compilation error (void main() - main' must return 'int') 
*/

/* 
//exercise 7
void F(int* x)
{
    for(int i = 0; i < 3; i++)
        x[i] += 2;
}
void main()
{
    int mas[] = {1,2,3};
    F(mas);
    for(int i = 0; i < 3; i++)
        cout << mas[i];
}
// result compilation error (void main() - main' must return 'int')  
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
void Test()
{
    A a(1);
    A *arr = &a;
    arr = new A(a);

}
// result compilation error (undefined reference to `WinMain')
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
void Test()
{
    A a(5);
    A b(3.2);
}
// result compilation error (undefined reference to `WinMain')
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