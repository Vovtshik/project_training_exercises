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
    for(int i = 5; i > 0; i--)    // ������� ��������� ���������� i - ������ ���� ����, �� ��������� ��� ���������� i - ������
        cout << i;
    cout << i;                    // ������������� "i" �� ���������
    // result: compilation error
}
 */

/*
// exercise 3
 void F(int& x, int& y)
{
    cout << x++ << --y;
}
 void main()                      // ������: ������� ������� main ������ ���������� int
{
    int a = 5;
    F(a, 6);                      //��������� �������� ������ �� ������������� �������� ������ ���� ������������� ��������� (6 - �� lvalue)
    cout << a;
    // result: compilation error
}
 */

/*
//exercise 4
void F(const int* x)              // ������������ �������� �������, ����� ����� ��������� �� ������ ������� �������� � ����������� ���������
{
    for(int i = 0; i < 3; i++)
        x[i] += 2;                // ������: 1) ��������� �� ������� � ���������� ���� int; 2) x �������� ��� const � �� ����� ���� ������������� ��������� ��� ������������
}
void main()                       // ������: ������� ������� main ������ ���������� int
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
// result compilation error (void main() - ������� ������� main ������ ���������� int)

 */

/*
//exercise 6
void main()                         //int main()
{
    int mas[5] = {0,1,2,3,4};
    int* ad = mas + 2;
    cout << *(mas + 2) + *(ad + 2);
}
// result compilation error (void main() - ������� ������� main ������ ���������� int)
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
// result compilation error (void main() - ������� ������� main ������ ���������� int)
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
// result compilation error (���������� ������� ������� main)
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
// result compilation error (���������� ������� ������� main)
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
//  result compilation error (����� ��������� �������� ������ exception ��� ������ Exc
// ��������� ������������ public; ���������� ������� ������� main)
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
/* class Exc : public exception                   // ������� �������� ������ � ������������ Exc(const string& s)
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
// result compilation error (����� ��������� �������� ������ exception ��� ������ Exc
// ��������� ������������ public;
// ������ � ������ ������������� ������� ����� ������������ Exc(const string& s) - ������� ����� exception
// �� ����� ������������ � �����������; ����� Exc ����� ���������� ��� ��������� � ���� ��� �� �������� �������;
// ���������� ������� ������� main)
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
    p = &b;                   // ��������� �� ������ ������ � ������ ��������� ����� ������� ������ �
    p->print();
}
// result compilation error:
// ��������� �� ������ ������ � ������ ��������� ����� ������� ������ �;
// ���������� ������� ������� main
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
void F() {                     // int main() - ���������� ������� ������� main
    A a;                       // ������ ��������� ������� ������������ ������;
    B b;
    A* p;                          
    p->print();                // ������ �������� ������ ������ ������������ ������;
    p = &b;
    p->print();
}
// result: compilation error
// ������ ��������� ������� ������������ ������;
// ������ �������� ������ ������ ������������ ������;
// ���������� ������� ������� main
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
    B(int a=0,int b=0):A(a),b(b){}  // ����������� � ����� ����������� ������� ������ �������� �� ��������� (0) ��� ������ ���� ���������� ������������� �� ���������.
    int get() {return b;}
};
int main() //void F()               //  void F() - ����� ��������  ������� �������� int main()
{
    B mas[10];                      // ��� �������� ����� ������� ����� ����������� �� ��������� (�.�. ��� ����� ���������������� ����������)
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
int main() //void F()             //  void F() - ����� ��������  ������� �������� int main()
{             
    E e('a');
    E e1 = e;
}
// result: AC0BC0DC0
 */


/* 
//exercise 17
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



 //exercise 17
 #include<set>
 int main()//void main() 
 {
     unsigned u[] = {2, 40, 3, 2 , 40};
     set<unsigned> a(u, u + 5);
     set<unsigned>::iterator f = find(a.begin(), a.end(), 3);
     unsigned (f != a.end()) s += *f++;
     cout << s;
 }