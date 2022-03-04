#include <iostream>

using namespace std;

int N;
int S[20];
int arr[20 * 100000 + 1];

void solve(int offset, int sum)
{
	if (offset == N)
	{
		arr[sum] = 1;
		return ;
	}
	solve(offset + 1, sum);
	solve(offset + 1, sum + S[offset]);
}

int main(void)
{
	int i;

	i = 0;
	cin >> N;
	while (i < N)
	{
		cin >> S[i];
		i++;
	}
	solve(0, 0);
	i = 1;
	while (1)
	{
		if (!arr[i])
		{
			cout << i;
			break;
		}
		i++;
	}
	return (0);
}
