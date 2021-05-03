#include <iostream>

using namespace std;

int main(void)
{
   int max;
   int cnt;
   int i;
   int num;

   i = 0;
   max = 0;
   while (i < 9)
   {
      cin >> num;
      if (num > max)
      {
         max = num;
         cnt = i + 1;
      }
      i++;
   }
   cout << max << '\n' << cnt << endl;
   return (0);
}
