#include <cstdio>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

struct Treasure {
  int weight;
  int value;
};

struct TreasureByValue : Treasure {
  TreasureByValue(Treasure t) {
    weight = t.weight;
    value = t.value;
  }
  bool operator<(const Treasure rhs) const { return value < rhs.value; }
};

int main() {
  int n; // treasure
  int m; // cart

  scanf("%d %d", &n, &m);

  vector<Treasure> ts; // should this be list
  ts.reserve(100000);

  for (int i = 0; i < n; i++) {
    int weight;
    int value;
    scanf("%d %d", &weight, &value);
    ts.push_back({weight, value});
  }

  vector<int> carts;
  carts.reserve(100000);

  for (int i = 0; i < m; i++) {
    int cart;
    scanf("%d", &cart);
    carts.push_back(cart);
  }

  // sort both asc
  sort(ts.begin(), ts.end(), [](const Treasure &lhs, const Treasure &rhs) {
    return lhs.weight < rhs.weight;
  });
  sort(carts.begin(), carts.end(),
       [](const int &lhs, const int &rhs) { return lhs < rhs; });

  priority_queue<TreasureByValue> pq; // max
  auto tsit = ts.begin();

  long long value = 0;

  for (int cart : carts) {
    while (tsit != ts.end()) {
      Treasure t = *tsit;
      if (t.weight > cart) {
        break;
      }
      pq.push((TreasureByValue)t);
      tsit++;
    }

    if (pq.empty()) {
      continue;
    }
    value += pq.top().value;
    pq.pop();
  }

  printf("%lld\n", value);

  return 0;
}
