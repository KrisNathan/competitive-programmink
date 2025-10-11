// Memory optimization
// Replace iostream with cstdio printf scanf
// Remove vector reserve

// This produces the best result when it comes to balancing time and memory

#include <cstdio>
#include <queue>

using namespace std;

int main() {
  int n; // days
  int m; // milk
  int k; // biscuit

  scanf("%d %d %d", &n, &m, &k);

  priority_queue<int, vector<int>> pq;

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