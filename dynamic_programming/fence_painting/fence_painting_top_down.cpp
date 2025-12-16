#include <iostream>
#include <vector>

using namespace std;

int dp(int n, int k, vector<int> &mem) {
  if (n == 1)
    return k;
  if (n == 2)
    return k * k;

  if (mem[n] != -1)
    return mem[n];

  return mem[n] = (k - 1) * (dp(n - 1, k, mem) + dp(n - 2, k, mem));
}

int solve(int n, int k) {
  vector<int> mem(n + 1, -1);
  return dp(n, k, mem);
}

void test(int n, int k, int expected_result) {
  int result = solve(n, k);
  cout << "n = " << n << "; k = " << k << " -> " << result << ' ';
  if (result == expected_result) {
    cout << "OK\n";
  } else {
    cout << "ERR\n";
  }
}

int main() {
  test(3, 2, 6);
  test(1, 5, 5);
  test(2, 4, 16);
  test(3, 3, 24);
  test(3, 1, 0);
  test(4, 3, 66);
  return 0;
}
