#include <iostream>

using namespace std;

int main(void)
{
    int N;
    int i;

    i = 0;
    cin >> N;
    while (i < 9)
    {
        cout << N << " * " << i + 1 << " = " << N * (i + 1) << endl;
        i++;
    }
    return (0);
}
