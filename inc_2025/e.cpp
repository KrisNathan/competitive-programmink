#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<char> vc;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n, q;
  cin >> n >> q;

  vc type(n);
  vi k(n);

  vector<vector<int>> mem();

  for (int i = 0; i < n; i++) {
    cin >> type[i];
    cin >> k[i];
  }

  vi queryindex(q);
  vc querytype(q);
  vi queryvalue(q);

  for (int i = 0; i < q; i++) {
    cin >> queryindex[i];
    queryindex[i]--;
    cin >> querytype[i];
    cin >> queryvalue[i];
  }

  for (int i = 0; i < q; i++) {
    int index = queryindex[i];
    type[index] = querytype[i];
    if (querytype[i] == '+')
      queryvalue[i] %= 16;
    k[index] = queryvalue[i];

    int res = 0;
    for (int a = 0; a < n; a++) {
      if (type[a] == '+') {
        res = (res + k[a]) % 16;
      } else {
        res = res ^ k[a];
      }
    }
    cout << res << '\n';
  }

  return 0;
}