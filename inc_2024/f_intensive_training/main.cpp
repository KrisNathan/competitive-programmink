/*
n = day count
r = total rating
k = total train

last r = max r (1)
first k = max k (2)

for max ri * ki we actually want ri and ki to be same for all days
but obviously r/k or k/n will have remainders
those remainders are added to:
- last few r (1)
- first few k (2)

suppose:
n = 5
r = 12
k = 17

lets compute r first:
12 = 5p + a
p = floor(12/5) = 2
a = 12 % 5 = 2
r = np + a

lets take 5p to understand it
p p p p p
2 2 2 2 2 = 10

because last r = max r:
distribute a = 2 to the last a days
2 2 2 3 3 = 12

same thing applies to k but first b days
k = nq + b

3 3 3 3 3 = 15
4 4 3 3 3 = 17

4 4 3 3 3 = 17
2 2 2 3 3 = 12
---   ---
a       b

overlap handling:
if (a + b > N)
    t = a + b - N;

+= p * q * n (without remainders)
+= p * b (extra problem)
+= q * a (extra rating)
+= t (overlap, has both extra problem and rating)

overlap case:
44433
22333

*/

#include <bits/stdc++.h>
using namespace std;

using i128 = __int128_t;
using u64 = unsigned long long;

string to_string_i128(i128 x) {
  if (x == 0)
    return "0";
  bool neg = x < 0;
  if (neg)
    x = -x;
  string s;
  while (x > 0) {
    int digit = int(x % 10);
    s.push_back('0' + digit);
    x /= 10;
  }
  if (neg)
    s.push_back('-');
  reverse(s.begin(), s.end());
  return s;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int T;
  if (!(cin >> T))
    return 0;
  while (T--) {
    unsigned long long N, R, K;
    cin >> N >> R >> K;

    unsigned long long q = K / N;
    unsigned long long a = K % N;
    unsigned long long p = R / N;
    unsigned long long b = R % N;

    unsigned long long t = 0;
    if (a + b > N)
      t = a + b - N;

    i128 ans = 0;
    ans += (i128)q * (i128)p * (i128)N;
    ans += (i128)p * (i128)a;
    ans += (i128)q * (i128)b;
    ans += (i128)t;

    cout << to_string_i128(ans) << '\n';
  }
  return 0;
}