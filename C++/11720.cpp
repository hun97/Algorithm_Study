#include <iostream>

using namespace std;

int main(void)
{
    int N;
    int i;
    int res;

    i = 0;
    res = 0;
    cin >> N;
    char* arr = new char[N];
    cin >> arr;
    while (i < N)
    {
        res += arr[i] - '0';
        i++;
    }
    cout << res << endl;
    return (0);
}
