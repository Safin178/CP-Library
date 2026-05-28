const long long N = 1e5 + 5;
vector<long long> v1[N];
vector<bool> visited(N, false), path(N, 0);
bool cycle = false;
void DFS(long long src)
{
    visited[src] = true;
    path[src] = true;
    for (auto it : v1[src])
    {
        if (!visited[it])
        {
            DFS(it);
        }
        else if (path[it])
            cycle = true;
    }
    path[src] = false;
}
void solve()
{
    long long n, e, u, v, i;
    cin >> n >> e;
    while (e--)
    {
        cin >> u >> v;
        //  undirected
        v1[u].push_back(v);
        v1[v].push_back(u);
    }
    for (i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            DFS(i);
        }
    }
    if (cycle) cout << "YES";
    else cout << "NO";
}
