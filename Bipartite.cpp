#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
vector<int> color;

bool dfs(int v)
{
    for (int u : adj[v])
    {
        if (color[u] == 0)
        {
            color[u] = color[v] ^ 3;

            if (!dfs(u))
                return false;
        }
        else if (color[u] == color[v])
        {
            return false;
        }
    }

    return true;
}

int main()
{
    int n, m;
    cin >> n >> m;

    adj.resize(n + 1);
    color.assign(n + 1, 0);

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    bool bipartite = true;

    for (int v = 1; v <= n; v++)
    {
        if (color[v] == 0)
        {
            color[v] = 1;

            if (!dfs(v))
            {
                bipartite = false;
                break;
            }
        }
    }

    cout << (bipartite ? "Bipartite" : "Not Bipartite") << '\n';

    return 0;
}
