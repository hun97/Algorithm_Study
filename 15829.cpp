#include <iostream>

using namespace std;

int main(void)
{
    int N;
    int i;
    long long r;
    long long res;

    i = 0;
    res = 0;
    r = 1;
    cin >> N;
    char* arr = new char[N];
    cin >> arr;
    while (i < N)
    {
        res += (((arr[i] - 'a' + 1) * r) % 1234567891);
        r = (r * 31) % 1234567891;
        i++;
    }
    res %= 1234567891;
    cout << res << endl;
    delete arr;
    return (0);
}
