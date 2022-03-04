#include <iostream>

using namespace std;

int N;
int A[100];
int cnt_plus;
int cnt_minus;
int cnt_mul;
int cnt_div;
int max_num; 
int min_num;
int flag = 1;

void solve(int idx, int res, int cur_plus, int cur_minus, int cur_mul, int cur_div)
{
	if (idx == N)
	{
		if (flag)
		{
			max_num = res;
			min_num = res;
			flag = 0;
		}
		if (res > max_num)
			max_num = res;
		if (res < min_num)
			min_num = res;
		return;
	}
	if (cur_plus < cnt_plus)
		solve(idx + 1, res + A[idx], cur_plus + 1, cur_minus, cur_mul, cur_div);
	if (cur_minus < cnt_minus)
		solve(idx + 1, res - A[idx], cur_plus, cur_minus + 1, cur_mul, cur_div);
	if (cur_mul < cnt_mul)
		solve(idx + 1, res * A[idx], cur_plus, cur_minus, cur_mul + 1, cur_div);
	if (cur_div < cnt_div)
		solve(idx + 1, res / A[idx], cur_plus, cur_minus, cur_mul, cur_div + 1);
}

int main(void)
{
	int i;

	i = 0;
	cin >> N;
	while (i < N)
	{
		cin >> A[i];
		i++;
	}
	cin >> cnt_plus >> cnt_minus >> cnt_mul >> cnt_div;
	solve(1, A[0], 0, 0, 0, 0);
	cout << max_num << '\n' << min_num << endl;
	return (0);
}
