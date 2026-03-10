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

#include <algorithm>
#include <bits/stdc++.h>
#include <climits>

using namespace std;

typedef vector<vector<int>> vec2d;

bool boundChk(int r, int c, int n, int m) {
  return r >= 1 && r <= n && c >= 1 && c <= m;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n, m;
  cin >> n >> m;

  vec2d map(n + 1, vector<int>(m + 1, 0));
  for (int i = 1; i <= n; i++) {
    string buf;
    cin >> buf;
    for (int j = 0; j < buf.length(); j++) {
      map[i][j + 1] = buf[j] - '0';
    }
  }

  int q;
  cin >> q;

  for (int i = 0; i < q; i++) {
    int r, c, k;
    cin >> r >> c >> k;

    int totalDist = 0;
    int visited = 0;

    if (map[r][c] == 1) {
      visited++;
    }

    int dist = 1;
    while (visited < k) {
      // t
      for (int col = c - dist + 1; col <= c + dist - 1; col++) {
        if (visited == k)
          break;
        if (boundChk(r - dist, col, n, m) && map[r - dist][col] == 1) {
          totalDist += dist * 2;
          visited++;
        }
      }

      // b
      for (int col = c - dist + 1; col <= c + dist - 1; col++) {
        if (visited == k)
          break;
        if (boundChk(r + dist, col, n, m) && map[r + dist][col] == 1) {
          totalDist += dist * 2;
          visited++;
        }
      }

      // l
      for (int row = r - dist; row <= r + dist; row++) {
        if (visited == k)
          break;
        if (boundChk(row, c - dist, n, m) && map[row][c - dist] == 1) {
          totalDist += dist * 2;
          visited++;
        }
      }

      // r
      for (int row = r - dist; row <= r + dist; row++) {
        if (visited == k)
          break;
        if (boundChk(row, c + dist, n, m) && map[row][c + dist] == 1) {
          totalDist += dist * 2;
          visited++;
        }
      }

      dist++;
    }

    cout << totalDist << '\n';
  }

  return 0;
}