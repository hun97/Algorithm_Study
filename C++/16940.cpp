#include <iostream>
#include <queue>
#include <vector>
#include <set>

using namespace std;

int N, cur;
vector<int> edge[100001];
bool check[100001] = {false};
int order[100001];
queue<int> q;
set<int> s;

int main()
{
    cin >> N;
    for (int i = 1; i < N; i++)
    {
        int a, b;
        cin >> a >> b;
        edge[a].push_back(b);
        edge[b].push_back(a);
    }
    for (int i = 0; i < N; i++)
    {
        cin >> order[i];
    }
    if (order[0] != 1)
    {
        cout << 0 << endl;
        return 0;
    }

    q.push(1);
    check[1] = true;
    cur = 1;

    while (!q.empty())
    {
        int node;

        node = q.front();
        q.pop();
        for (vector<int>::iterator itr = edge[node].begin(); itr != edge[node].end(); itr++)
        {
            if (!check[*itr])
            {
                check[*itr] = true;
                q.push(*itr);
                s.insert(*itr);
            }
        }
        int size = s.size();
        for (int i = 0; i < size; i++)
        {
            if (s.count(order[cur]) == 0)
            {
                cout << 0 << endl;
                return 0;
            }
            else
            {
                s.erase(order[cur]);
                cur++;
            }
        }
    }

    cout << 1 << endl;

    return 0;
}