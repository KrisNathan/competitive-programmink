#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N, M;
    if (!(cin >> N >> M)) return 0;
    vector<pair<int,int>> edges(M);
    for (int i = 0; i < M; ++i) {
        int u, v;
        cin >> u >> v;
        --u; --v;
        edges[i] = {u, v};
    }
    vector<int> A(N);
    for (int i = 0; i < N; ++i) cin >> A[i];

    /* 1. sort vertices by decreasing A */
    vector<int> order(N);
    iota(order.begin(), order.end(), 0);
    sort(order.begin(), order.end(),
         [&](int x, int y) {
             if (A[x] != A[y]) return A[x] > A[y];
             return x < y;               // deterministic tie‑break
         });

    /* 2. position of each vertex (1‑based) */
    vector<int> pos(N);
    for (int i = 0; i < N; ++i) pos[order[i]] = i + 1;

    /* 3. check necessary condition pos[v] = N - A[v] + 1 */
    bool ok = true;
    for (int v = 0; v < N; ++v) {
        if (pos[v] != N - A[v] + 1) {
            ok = false;
            break;
        }
    }
    if (!ok) {
        cout << -1 << '\n';
        return 0;
    }

    /* 4. orient every edge from earlier to later */
    for (auto [u, v] : edges) {
        if (pos[u] < pos[v])
            cout << u + 1 << ' ' << v + 1 << '\n';
        else
            cout << v + 1 << ' ' << u + 1 << '\n';
    }
    return 0;
}