#include <bits/stdc++.h>
using namespace std;

int N, M;
vector<vector<int>> pref;

inline long long rectSum(int r1, int c1, int r2, int c2) {
  if (r1 > r2 || c1 > c2)
    return 0;
  r1 = max(r1, 1);
  c1 = max(c1, 1);
  r2 = min(r2, N);
  c2 = min(c2, M);
  if (r1 > r2 || c1 > c2)
    return 0;
  return pref[r2][c2] - pref[r1 - 1][c2] - pref[r2][c1 - 1] +
         pref[r1 - 1][c1 - 1];
}

inline long long countWithin(int R, int C, int r) {
  return rectSum(R - r, C - r, R + r, C + r);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> N >> M;
  pref.assign(N + 1, vector<int>(M + 1, 0));
  for (int i = 1; i <= N; ++i) {
    string s;
    cin >> s;
    for (int j = 1; j <= M; ++j) {
      int v = s[j - 1] - '0';
      pref[i][j] = v + pref[i - 1][j] + pref[i][j - 1] - pref[i - 1][j - 1];
    }
  }

  int Q;
  cin >> Q;
  int D = max(N, M);

  while (Q--) {
    int R, C, K;
    cin >> R >> C >> K;

    // Binary search minimal radius containing at least K treasures
    int lo = 0, hi = D, rStar = D;
    while (lo <= hi) {
      int mid = (lo + hi) / 2;
      cout << mid << '\n';
      if (countWithin(R, C, mid) >= K) {
        rStar = mid;
        hi = mid - 1;
      } else {
        lo = mid + 1;
      }
    }

    long long totalDist = 0;
    long long remaining = K;
    long long prevCnt = 0;

    // Accumulate shells from 0 up to rStar
    for (int r = 0; r <= rStar && remaining > 0; ++r) {
      long long curCnt = countWithin(R, C, r);
      long long onShell = curCnt - prevCnt;
      long long take = min(onShell, remaining);
      totalDist += 1LL * r * take;
      remaining -= take;
      prevCnt = curCnt;
    }

    // Round trip time
    cout << (totalDist << 1) << '\n';
  }
  return 0;
}