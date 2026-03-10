/*
n = contestant count
Si = name
Ai = pts day 1
Bi = penalty day 1
Ci = points day 1
D1 = penalty day 2
*/

#include <algorithm>
#include <bits/stdc++.h>

using namespace std;

struct cont {
  string name;
  int pts;
  int pnlt;
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n;
  cin >> n;

  vector<cont> contestants(n);

  for (int i = 0; i < n; ++i) {
    string s;
    int a, b, c, d;
    cin >> s >> a >> b >> c >> d;
    contestants[i] = {s, a + c, b + d};
  }

  sort(contestants.begin(), contestants.end(),
       [](const cont &l, const cont &r) {
         if (l.pts != r.pts)
           return l.pts > r.pts;
         if (l.pnlt != r.pnlt)
           return l.pnlt < r.pnlt;
         return l.name < r.name;
       });

  for (auto c : contestants) {
    cout << c.name << '\n';
  }

  return 0;
}