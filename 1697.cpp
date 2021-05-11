#include <iostream>
#include <queue>

using namespace std;

int N;
int K;
bool check[1000001] = {false};

void bfs(int N)
{
	queue<pair<int, int> > q;
	check[N] = true;
	q.push(make_pair(N, 0));
	while (!q.empty())
	{
		pair <int, int> n = q.front();
		if (n.first == K)
		{
			cout << n.second;
			return ;
		}
		q.pop();
		if (n.first - 1 >= 0 && check[n.first - 1] == false)
		{
			q.push(make_pair(n.first - 1, n.second + 1));
			check[n.first - 1] = true;
		}
		if (n.first + 1 <= 100001 && check[n.first + 1] == false)
		{
			q.push(make_pair(n.first + 1, n.second + 1));
			check[n.first + 1] = true;
		}
		if (n.first * 2 <= 100001 && check[n.first * 2] == false)
		{
			q.push(make_pair(n.first * 2, n.second + 1));
			check[n.first * 2] = true;
		}
	}
}

int main(void)
{
	cin >> N >> K;

	bfs(N);
	return 0;
}
