#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
vector<bool> vis;

void dfs(int v)
{
    vis[v] = true;

    for (int u : adj[v])
    {
        if (!vis[u])
            dfs(u);
    }
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

    int components = 0;

    for (int v = 1; v <= n; v++)
    {
        if (!vis[v])
        {
            components++;
            dfs(v);
        }
    }

    cout << components << '\n';

    return 0;
}
