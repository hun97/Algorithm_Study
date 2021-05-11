#include <iostream>

using namespace std;

int main(void)
{
    int N[8];
    int i;

    i = 0;
    while (i < 8)
    {
        cin >> N[i];
        i++;
    }
    if (N[0] == 1)
    {
        i = 0;
        while (i < 8)
        {
            if (N[i] == (i + 1))
                i++;
            else
            {
                cout << "mixed" << endl;
                return (0);
            }
        }
        cout << "ascending" << endl;
    }
    else if (N[0] == 8)
    {
        i = 0;
        while (i < 8)
        {
            if (N[i] == (8 - i))
                i++;
            else
            {
                cout << "mixed" << endl;
                return (0);
            }
        }
        cout << "descending" << endl;
    }
    else
        cout << "mixed" << endl;
    return (0);
}
