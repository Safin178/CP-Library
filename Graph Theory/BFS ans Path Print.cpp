vector<long long> v1[1009], parent(1009, -1); // 1009->question a maximum node joto thakte pare
vector<bool> visited(1009, false);

void BFS(long long src)
{
    queue<long long> q1;
    q1.push(src);
    visited[src] = true;
    while (!q1.empty())
    {
        for (auto it : v1[q1.front()])
        {
            if (!visited[it])
            {
                q1.push(it);
                visited[it] = true;
                parent[it] = q1.front();
            }
        }
        q1.pop();
    }
}

void Path_print(long long vertex)
{
    if (parent[vertex] == -1)
    {
        cout << vertex << ' ';
        return;
    }
    Path_print(parent[vertex]);
    cout << vertex << ' ';
}

void solve()
{
    long long n, e, u, v, source, destination;
    cin >> n >> e;
    while (e--)
    {
        cin >> u >> v;
        // undirected
        v1[u].push_back(v);
        v1[v].push_back(u);
    }
    cin >> source >> destination;
    BFS(source);
    Path_print(destination);
}
