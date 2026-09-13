#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
vector<bool> vis;

bool dfs(int v, int parent)
{
    vis[v] = true;

    for (int u : adj[v])
    {
        if (!vis[u])
        {
            if (dfs(u, v))
                return true;
        }
        else if (u != parent)
        {
            return true;
        }
    }

    return false;
}

int main()
{
    int n, m;
    cin >> n >> m;

    adj.resize(n + 1);
    vis.assign(n + 1, false);

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    bool cycle = false;

    for (int v = 1; v <= n; v++)
    {
        if (!vis[v])
        {
            if (dfs(v, -1))
            {
                cycle = true;
                break;
            }
        }
    }

    cout << (cycle ? "Cycle Found" : "No Cycle") << '\n';

    return 0;
}
