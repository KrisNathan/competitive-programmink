#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n; // days
  int m; // milk
  int k; // biscuit

  cin >> n >> m >> k;

  vector<int> container;
  container.reserve(n);
  priority_queue<int, vector<int>> pq(less<int>(), std::move(container));

  int days = 0;

  int req_milk;
  for (int i = 0; i < n; i++) {
    cin >> req_milk;

    m -= req_milk;
    pq.push(req_milk);

    if (m < 0 && k > 0) {
      int t = pq.top();
      pq.pop();
      m += t;
      k--;
    }

    if (m < 0) {
      break;
    }

    days++;
  }

  cout << days << '\n';

  return 0;
}