/*
food ratink

rating L to R (incl)

X = average rating
k = min number of delivery

find k and the ratings.

*/

#include <bits/stdc++.h>

using namespace std;

int main() {
  string x;
  cin >> x;

  int dotidx = -1;
  dotidx = x.find('.');

  int xt;
  // 86
  int xdiv;
  // 10

  if (dotidx == string::npos) {
    xt = stoll(x);
    xdiv = 1;
  } else {
    string nodot = x.substr(0, dotidx) + x.substr(dotidx + 1);

    xt = stoll(nodot);
    xdiv = pow(10, x.length() - dotidx - 1);
  }

  int l, r;
  cin >> l >> r;

  int g = gcd(xt, xdiv);
  // 2
  // simplify frac
  // 43/5
  xt /= g;
  xdiv /= g;

  // 43/5
  // we need total 43 from 5 ppl

  if (xt < xdiv * l || xt > xdiv * r) {
    cout << "-1\n";
    return 0;
  }

  vector<int> res(xdiv, l);
  int rem = xt - xdiv * l;
  int maxadd = r - l;

  for (int i = 0; i < xdiv; i++) {
    if (rem == 0)
      break;
    int add = min(rem, maxadd);
    res[i] += add;
    rem -= add;
  }

  for (int i = 0; i < res.size(); i++) {
    if (i > 0)
      cout << ' ';
    cout << res[i];
  }
  cout << '\n';

  return 0;
}