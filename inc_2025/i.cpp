/*
n = row (1 to n)
m = col (1 to m)

puddle .
dirt #

pool = puddles

rect puddle:
total puddle = (rmax - rmin + 1) * (cmax - cmin + 1)

non-rect exist -> print NO
else -> print RECTANGLES

non rect always has L
.
..

*/

#include <bits/stdc++.h>

using namespace std;

typedef vector<vector<bool>> vvb;
typedef vector<vector<int>> vvi;

int n, m;
vvb grid;
vvi psquares;
int cbad = 0;

bool inbounds(int r, int c) { return r >= 1 && r <= n && c >= 1 && c <= m; }

// r,c is bot right
int countpsquare(int r, int c) {
  int cnt = 0;
  if (inbounds(r, c))
    cnt += grid[r][c];
  if (inbounds(r - 1, c))
    cnt += grid[r - 1][c];
  if (inbounds(r, c - 1))
    cnt += grid[r][c - 1];
  if (inbounds(r - 1, c - 1))
    cnt += grid[r - 1][c - 1];
  return cnt;
}

void updsquare(int r, int c) {
  if (r < 1 || r > n || c < 1 || c > m)
    return;

  int oldCount = psquares[r][c];
  int newCount = countpsquare(r, c);

  if (oldCount == 3)
    cbad--;
  if (newCount == 3)
    cbad++;

  psquares[r][c] = newCount;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  cin >> n >> m;

  grid = vvb(n + 1, vector<bool>(m + 1));
  // true = puddle
  psquares = vvi(n + 1, vector<int>(m + 1));

  string buf;
  for (int r = 1; r <= n; r++) {
    cin >> buf;
    for (int c = 1; c <= m; c++) {
      grid[r][c] = (buf[c - 1] == '.');

      psquares[r][c] = countpsquare(r, c);
      if (psquares[r][c] == 3)
        cbad++;
    }
  }

  int q;
  cin >> q;

  while (q--) {
    int r, c;
    cin >> r >> c;

    grid[r][c] = !grid[r][c];

    // chang 4 squares: (r,c), (r+1,c), (r,c+1), (r+1,c+1)
    updsquare(r, c);
    updsquare(r + 1, c);
    updsquare(r, c + 1);
    updsquare(r + 1, c + 1);

    if (cbad > 0) {
      cout << "NO\n";
    } else {
      cout << "RECTANGLES\n";
    }
  }

  return 0;
}