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
    // result: ошибка компиляции
} 
*/


// exercice 3
 void F(int& x, int& y)
{
    cout << x++ << --y;
}
 void main()
{
    int a = 5;
    F(a, 6);
    cout << a;
}