const long long N = 1e5 + 5;
vector < long long > v1[N];
vector < bool > visited(N, false);
void DFS(long long src) {
  visited[src] = true;
  for (auto it: v1[src]) {
    if (!visited[it]) {
      DFS(it);
    }
  }
}
void solve() {
  long long n, e, u, v, source, i, component = 0;
  cin >> n >> e;
  while (e--) {
    cin >> u >> v;
    // undirected
    v1[u].push_back(v);
    v1[v].push_back(u);
    // directed
    // v1[u].push_back(v);
  }
  for (i = 0; i < n; i++) {
    if (!visited[i]) {
      DFS(i);
      component++;
    }
  }
  cout << component << endl;
}
