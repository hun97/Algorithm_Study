#include <iostream>
#include <queue>

using namespace std;

int arr[1001][1001];
bool check[1001] = {false};
int N;
int M;
int V;

void dfs(int V)
{
	cout << V << ' ';
	check[V] = true;
	for (int i = 1; i <= N; i++)
	{
		if (arr[V][i] == 1 && check[i] == false)
			dfs(i);
	}
}

void bfs(int V)
{
	queue<int> q;

	q.push(V);
	check[V] = true;
	while(!q.empty())
	{
		int n = q.front();
		cout << n << ' ';
		q.pop();
		for (int i = 1; i <= 1001; i++)
		{
			if (arr[n][i] == 1 && check[i] == false)
			{
				q.push(i);
				check[i] = true;
			}
		}
	}
}

int main(void)
{
	int x;
	int y;

	cin >> N >> M >> V;
	for (int i = 0; i < M; i++)
	{
		cin >> x >> y;
		arr[x][y] = 1;
		arr[y][x] = 1;
	}
	dfs(V);
	cout << '\n';
	for (int i = 0; i <= 1001; i++)
		check[i] = false;
	bfs(V);

	return 0;
}
