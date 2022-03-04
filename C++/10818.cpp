#include <iostream>

using namespace std;

int main(void)
{
    int N;
    int i;
    int max;
    int min;
    int num;

    i = 0;
    cin >> N;
    cin >> num;
    max = num;
    min = num;
    i++;
    while (i < N)
    {
        cin >> num;
        if (num > max)
            max = num;
        if (num < min)
            min = num;
        i++;
    }
    cout << min << " " << max << endl;
    return (0);
}
