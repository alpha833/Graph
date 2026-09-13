#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
vector<bool> vis;

void dfs(int v, vector<int>& comp)
{
    vis[v] = true;
    comp.push_back(v);

    for (int u : adj[v])
    {
        if (!vis[u])
            dfs(u, comp);
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

    for (int v = 1; v <= n; v++)
    {
        if (!vis[v])
        {
            vector<int> comp;

            dfs(v, comp);

            cout << "Size: " << comp.size() << '\n';

            cout << "Nodes: ";
            for (int u : comp)
                cout << u << " ";

            cout << '\n';
        }
    }

    return 0;
}
