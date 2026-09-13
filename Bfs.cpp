void bfs(int v)
{
    queue<int> q;

    vis[v] = true;
    q.push(v);

    while (!q.empty())
    {
        v = q.front();
        q.pop();

        for (int u : adj[v])
        {
            if (!vis[u])
            {
                vis[u] = true;
                q.push(u);
            }
        }
    }
}
