void dfs(int v)
{
    vis[v] = true;

    for (int u : adj[v])
    {
        if (!vis[u])
            dfs(u);
    }
}
