#include <bits/stdc++.h>
using namespace std;

struct DSU {
  vector<int> parent, siz;
  DSU(int n = 0) { init(n); }
  void init(int n) {
    parent.resize(n + 1);
    siz.assign(n + 1, 1);
    iota(parent.begin(), parent.end(), 0);
  }
  int find(int x) {
    if (parent[x] == x)
      return x;
    parent[x] = find(parent[x]);
    return parent[x];
  }
  void unite(int a, int b) {
    a = find(a);
    b = find(b);
    if (a == b)
      return;
    if (siz[a] < siz[b])
      swap(a, b);
    parent[b] = a;
    siz[a] += siz[b];
  }
  int size(int x) { return siz[find(x)]; }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int N, M;
  if (!(cin >> N >> M))
    return 0;

  vector<int> U(M), V(M);
  for (int i = 0; i < M; ++i) {
    cin >> U[i] >> V[i];
  }

  vector<int> A(N + 1);
  for (int i = 1; i <= N; ++i)
    cin >> A[i];

  DSU dsu(N);
  vector<int> edge_idx(M);
  iota(edge_idx.begin(), edge_idx.end(), 0);
  vector<int> weight(M);
  for (int i = 0; i < M; ++i)
    weight[i] = max(A[U[i]], A[V[i]]);
  sort(edge_idx.begin(), edge_idx.end(), [&](int lhs, int rhs) {
    if (weight[lhs] != weight[rhs])
      return weight[lhs] < weight[rhs];
    return lhs < rhs;
  });

  vector<int> order(N);
  iota(order.begin(), order.end(), 1);
  sort(order.begin(), order.end(), [&](int x, int y) {
    if (A[x] != A[y])
      return A[x] < A[y];
    return x < y;
  });

  int ptr = 0;
  for (int v : order) {
    while (ptr < M && weight[edge_idx[ptr]] <= A[v]) {
      int idx = edge_idx[ptr++];
      dsu.unite(U[idx], V[idx]);
    }
    if (dsu.size(v) != A[v]) {
      cout << -1 << '\n';
      return 0;
    }
  }

  vector<vector<int>> adj(N + 1);
  for (int i = 0; i < M; ++i) {
    adj[U[i]].push_back(V[i]);
    adj[V[i]].push_back(U[i]);
  }

  vector<int> seen(N + 1, 0);
  int token = 1;
  for (int s = 1; s <= N; ++s, ++token) {
    queue<int> q;
    q.push(s);
    seen[s] = token;
    int cnt = 0;
    while (!q.empty()) {
      int u = q.front();
      q.pop();
      ++cnt;
      for (int v : adj[u]) {
        if (seen[v] == token)
          continue;
        if (A[v] <= A[u]) {
          seen[v] = token;
          q.push(v);
        }
      }
    }
    if (cnt != A[s]) {
      cout << -1 << '\n';
      return 0;
    }
  }

  vector<int> dir(M, -1);
  vector<int> forced_order;
  forced_order.reserve(M);
  vector<vector<pair<int, int>>> same_adj(N + 1);
  for (int i = 0; i < M; ++i) {
    if (A[U[i]] == A[V[i]]) {
      same_adj[U[i]].push_back({V[i], i});
      same_adj[V[i]].push_back({U[i], i});
    } else if (A[U[i]] > A[V[i]]) {
      dir[i] = 0;
      forced_order.push_back(i);
    } else {
      dir[i] = 1;
      forced_order.push_back(i);
    }
  }

  vector<int> disc(N + 1, 0), low(N + 1, 0), parent(N + 1, 0);
  vector<char> vis(N + 1, 0);
  int timer = 0;
  bool bad = false;
  vector<int> orient_order;
  orient_order.reserve(M);
  auto orient = [&](int idx, int from, int to) {
    if (dir[idx] != -1)
      return;
    if (U[idx] == from && V[idx] == to)
      dir[idx] = 0;
    else
      dir[idx] = 1;
    orient_order.push_back(idx);
  };

  function<void(int, int)> dfs = [&](int u, int group) {
    vis[u] = 1;
    disc[u] = low[u] = ++timer;
    for (auto [v, idx] : same_adj[u]) {
      if (A[v] != group)
        continue;
      if (!vis[v]) {
        parent[v] = u;
        orient(idx, u, v);
        dfs(v, group);
        low[u] = min(low[u], low[v]);
        if (low[v] > disc[u]) {
          bad = true;
          return;
        }
      } else if (v != parent[u]) {
        low[u] = min(low[u], disc[v]);
        orient(idx, u, v);
      }
      if (bad)
        return;
    }
  };

  for (int u = 1; u <= N; ++u) {
    if (!vis[u]) {
      parent[u] = 0;
      dfs(u, A[u]);
      if (bad)
        break;
    }
  }

  if (bad) {
    cout << -1 << '\n';
    return 0;
  }

  vector<vector<int>> directed_adj(N + 1);
  for (int i = 0; i < M; ++i) {
    if (dir[i] == 0)
      directed_adj[U[i]].push_back(V[i]);
    else
      directed_adj[V[i]].push_back(U[i]);
  }

  fill(seen.begin(), seen.end(), 0);
  token = 1;
  for (int s = 1; s <= N; ++s, ++token) {
    queue<int> q;
    q.push(s);
    seen[s] = token;
    int cnt = 0;
    while (!q.empty()) {
      int u = q.front();
      q.pop();
      ++cnt;
      for (int v : directed_adj[u]) {
        if (seen[v] == token)
          continue;
        seen[v] = token;
        q.push(v);
      }
    }
    if (cnt != A[s]) {
      cout << -1 << '\n';
      return 0;
    }
  }

  // Remaining same-level edges must be oriented by DFS; guard in debug mode.
  for (int i = 0; i < M; ++i) {
    if (dir[i] == -1) {
      dir[i] = 0;
      orient_order.push_back(i);
    }
  }

  for (int idx : forced_order) {
    if (dir[idx] == 0)
      cout << U[idx] << ' ' << V[idx] << '\n';
    else
      cout << V[idx] << ' ' << U[idx] << '\n';
  }
  for (int idx : orient_order) {
    if (dir[idx] == 0)
      cout << U[idx] << ' ' << V[idx] << '\n';
    else
      cout << V[idx] << ' ' << U[idx] << '\n';
  }

  return 0;
}