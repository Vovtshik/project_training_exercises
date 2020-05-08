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
void main()
{
    int mas[5] = {0,1,2,3,4};
    int* ad = mas + 2;
    cout << *(mas + 2) + *(ad + 2);
}
// result compilation error (void main() - main' must return 'int') 
*/