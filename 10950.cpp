#include <iostream>

using namespace std;

int main(void)
{
    int T;
    int i;
    int A;
    int B;
   
    i = 0;
    cin >> T;
    int* res = new int[T];
    while (i < T)
    {
        cin >> A >> B;
        res[i] = (A + B);
        i++;
    }
    i = 0;
    while (i < T)
    {
        cout << res[i] << endl;
        i++;
    }
    delete res;
    return (0);
}
