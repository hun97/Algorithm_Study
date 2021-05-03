#include <iostream>

using namespace std;

int N;
int S;
int input[20];
int res = 0;

void solve(int offset, int sum)
{
	int i;
	if (sum == S && offset != 0)
	{
		res++;
	}
	i = offset;
	while (i < N)
	{
		sum += input[i];
		solve(i + 1, sum);
		sum -= input[i];
		i++;
	}
}

int main(void)
{
	int i;

	i = 0;
	cin >> N >> S;
	while (i < N)
	{
		cin >> input[i];
		i++;
	}
	solve(0, 0);
	cout << res;
	return (0);
}
