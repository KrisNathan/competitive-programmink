#include <cstdio>
#include <vector>

#define DEBUG 0

using namespace std;

int main() {
  int n; // doneness level
  scanf("%d", &n);

  vector<int> times(n + 1, 0);
  for (int i = 2; i <= n; i++) {
    int time = 0;
    scanf("%d", &time);
    times[i] = time;
  }

  vector<int> steaks(n + 1, 0); // idx is doneness level (but 1 idx)
  vector<int> steaks_cum(n + 1, 0);
  for (int i = 1; i <= n; i++) {
    int steak = 0;
    scanf("%d", &steak);
    steaks[i] = steak;
    steaks_cum[i] = steaks_cum[i - 1] + steak;
  }

  int total_time = 0;

  vector<int> orders(n + 1, 0); // idx is doneness level too
  for (int i = 1; i <= n; i++) {
    scanf("%d", &orders[i]);
  }

  for (int i = n; i >= 1; i--) {
#if (DEBUG)
    printf("\no:");
    for (int a : orders) {
      printf("%d", a);
    }
    printf("\nsc:");
    for (int a : steaks_cum) {
      printf("%d", a);
    }
    printf("\ns:");
    for (int a : steaks) {
      printf("%d", a);
    }
    printf("\n");
    printf("%d: %d > %d\n", i, orders[i], steaks[i]);
#endif

    if (orders[i] > steaks_cum[i]) {
      printf("-1\n");
      return 0;
    }
    if (orders[i] > steaks[i]) {
      int deficit = orders[i] - steaks[i];
      orders[i - 1] += deficit;
      total_time += deficit * times[i];
      steaks_cum[i] -= orders[i];

#if (DEBUG)
      printf("%d = %d * %d\n", deficit * times[i], deficit, times[i]);
#endif
    }

    steaks[i] = 0;
  }

  printf("%d\n", total_time);

  return 0;
}
