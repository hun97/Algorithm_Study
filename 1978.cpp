#include <iostream>

using namespace std;

bool is_prime(int num)
{
    int i;
    
    i = 2;
    if (num == 1)
        return false;
    if (num == 2 || num == 3)
        return true;
    while (i * i <= num)
    {
        if (num % i == 0)
            return false;
        i++;
    }
    return true;
}

int main(void)
{
    int N;
    int i;
    int cnt;
    int num;

    i = 0;
    cnt = 0;
    cin >> N;
    while (i < N)
    {
        cin >> num;
        if (is_prime(num))
            cnt++;
        i++;
    }
    cout << cnt << endl;
    return (0);
}
