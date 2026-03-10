/*
n rows (1to n)
m columns (1 to m)
r = row
c = col
Arc = 1 has treasure
0 no
q = scenario count?
can move diagonal at same cost
*/

#include <bits/stdc++.h>

using namespace std;

typedef vector<vector<int>> vec2d;

int n, m;
vec2d cummMap;

int rectSum(int r1, int c1, int r2, int c2) {
  if (r1 > r2 || c1 > c2)
    return 0;
  r1 = max(r1, 1);
  c1 = max(c1, 1);
  r2 = min(r2, n);
  c2 = min(c2, m);
  if (r1 > r2 || c1 > c2)
    return 0;

  // br - t - l + tl
  return cummMap[r2][c2] - cummMap[r1 - 1][c2] - cummMap[r2][c1 - 1] +
         cummMap[r1 - 1][c1 - 1];
}

int countArea(int r, int c, int rad) {
  // tl, br
  return rectSum(r - rad, c - rad, r + rad, c + rad);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  cin >> n >> m;
  cummMap = vector<vector<int>>(n + 1, vector<int>(m + 1, 0));

  for (int i = 1; i <= n; i++) {
    string buf;
    cin >> buf;
    for (int j = 0; j < buf.length(); j++) {
      int t = buf[j] - '0';

      // t + l - tl
      cummMap[i][j + 1] =
          t + cummMap[i - 1][j + 1] + cummMap[i][j] - cummMap[i - 1][j];
    }
  }

  int q;
  cin >> q;

  for (int i = 0; i < q; i++) {
    int r, c, k;
    cin >> r >> c >> k;

    long long totalDist = 0;
    int tot = 0;
    int currDist = 0;
    int prevCount = 0;

    while (tot < k) {
      int currentCount = countArea(r, c, currDist);
      int currTot = currentCount - prevCount;

      int take = min(currTot, k - tot);
      totalDist += (long long)currDist * take * 2;
      tot += take;

      prevCount = currentCount;
      currDist++;
    }

    cout << totalDist << '\n';
  }
  return 0;
}