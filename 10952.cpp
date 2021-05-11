#include <iostream>

using namespace std;

int main(void)
{
    int A;
    int B;
    
    while (1)
    {
        cin >> A >> B;
        if (A == 0 && B == 0)
            break;
        cout << A + B << endl;
    }
    return (0);
}
