#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
vector<int> indegree;

int main()
{
    int n, m;
    cin >> n >> m;

    adj.resize(n + 1);
    indegree.assign(n + 1, 0);

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        indegree[v]++;
    }

    queue<int> q;

    for (int v = 1; v <= n; v++)
    {
        if (indegree[v] == 0)
            q.push(v);
    }

    vector<int> topo;

    while (!q.empty())
    {
        int v = q.front();
        q.pop();

        topo.push_back(v);

        for (int u : adj[v])
        {
            indegree[u]--;

            if (indegree[u] == 0)
                q.push(u);
        }
    }

    if (topo.size() != n)
    {
        cout << "Cycle exists\n";
    }
    else
    {
        for (int v : topo)
            cout << v << " ";

        cout << '\n';
    }

    return 0;
}
