#include <iostream>

using namespace std;

int N;

int main(void)
{
   int i;
   int j;

   cin >> N;
   i = 0;
   while (i < N)
   {
      j = 0;
      while (j <= i)
      {
         cout << '*';
         j++;
      }
      cout << endl;
      i++;
   }
   return (0);
}

