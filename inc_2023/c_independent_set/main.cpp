#include <cstdio>
#include <vector>

using namespace std;

vector<vector<int>> adj_list;
vector<bool> has_red;
int redcount = 0;

void search(int node, int parent) {
  for (int neigh : adj_list[node]) {
    if (neigh == parent) {
      continue;
    }

    search(neigh, node);
  }

  if (has_red[node]) {
    return;
  }

  redcount++;
  has_red[parent] = true;
}

int main() {
  int n; // node count
  scanf("%d", &n);

  if (n <= 2) {
    printf("0\n");
    return 0;
  }

  adj_list.assign(n + 1, vector<int>());
  has_red.assign(n + 1, false);

  for (int i = 0; i < n - 1; i++) {
    int u, v;
    scanf("%d %d", &u, &v);
    adj_list[u].push_back(v);
    adj_list[v].push_back(u);
  }

  search(1, 0);

  printf("%lld\n", (long long)redcount * (n - 1));

  return 0;
}
