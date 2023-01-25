#include <iostream>

using namespace std;

int main()
{
    int arr[3];
    int sol[3];
    int n, min;

    cin >> n;

    for (int i = 0; i < 3; i++)
    {
        cin >> arr[i];
    }

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cin >> sol[j];
            min = -1;
            for (int k = 0; k < 3; k++)
            {
                if (j != k)
                {
                    if (min == -1)
                    {
                        min = arr[k];
                    }
                    else if (min > arr[k])
                    {
                        min = arr[k];
                    }
                }
            }
            sol[j] += min;
        }
        for (int j = 0; j < 3; j++)
        {
            arr[j] = sol[j];
        }
    }
    min = arr[0];
    for (int i = 1; i < 3; i++)
    {
        if (min > arr[i])
            min = arr[i];
    }
    cout << min << endl;

    return 0;
}