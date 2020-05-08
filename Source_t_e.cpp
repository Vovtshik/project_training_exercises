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
    // result: compilation error
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

// result:
 */
