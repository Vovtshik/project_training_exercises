// Project exercises
#include <iostream>
#include <string>

int main()
{
using namespace std;

{
    int i = 5;
    do {
        cout << i;
    } while(i-- > 0);
    cout << --i;
    // result: 543210-2
}
}
