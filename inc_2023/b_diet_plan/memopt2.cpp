// Memory optimization
// Replace iostream with cstdio printf scanf

// It retains the original time, but sometimes worse memory peak.
// Not sure why vector container causes 100-200KB peaks.
// It probably is because of compiler behaviour (it struggling to optimize it maybe)

#include <cstdio>
#include <queue>
#include <vector>

using namespace std;

int main() {
  int n; // days
  int m; // milk
  int k; // biscuit

  scanf("%d %d %d", &n, &m, &k);

  vector<int> container;
  container.reserve(n);
  priority_queue<int, vector<int>> pq(less<int>(), std::move(container));

  int days = 0;

  int req_milk;
  for (int i = 0; i < n; i++) {
    scanf("%d", &req_milk);

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

  printf("%d\n", days);

  return 0;
}
