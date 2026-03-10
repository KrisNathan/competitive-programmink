#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  string s;
  cin >> s;

  vi cfreqs(26, 0);
  for (auto c : s) {
    cfreqs[c - 'a']++;
  }

  int oddcount = 0;
  string mir;
  string mids;

  for (int i = 0; i < 26; i++) {
    int freq = cfreqs[i];

    int cpair = freq / 2; // floored
    if (freq % 2 == 1) {
      oddcount++;
      mids += char('a' + i);
    }

    for (int j = 0; j < cpair; j++) {
      mir += char('a' + i);
    }
  }

  int comb = max(1, oddcount);
  cout << comb << '\n';

  string right = mir;
  reverse(right.begin(), right.end());

  cout << mir << mids[0] << right << '\n';

  for (int i = 1; i < comb; i++) {
    cout << mids[i] << '\n';
  }

  return 0;
}