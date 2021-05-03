#include <iostream>

using namespace std;

int k;
int input[13];
int res[6];

void solve(int offset, int depth)
{
	int i;

	if (depth == 6)
	{
		i = 0;
		while (i < 5)
		{
			cout << res[i] << " ";
			i++;
		}
		cout << res[5] << endl;
		return ;
	}
	i = offset;
	while (i < k)
	{
		res[depth] = input[i];
		print_sol(i + 1, depth + 1);
		i++;
	}
}

int main(void)
{
	int i;

	while (1)
	{
		i = 0;
		cin >> k;
		if (k == 0)
			break;
		while (i < k)
		{
			cin >> input[i];
			i++;
		}
		solve(0, 0);
		cout << endl;
	}

	return (0);
}
