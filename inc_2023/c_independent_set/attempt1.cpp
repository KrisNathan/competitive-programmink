// Where I messed up:
// I forgot when
// n = 2, only 1 red node
// So min edge where all red nodes are connected = 0

#include <cstdio>
#include <vector>

using namespace std;

typedef vector<vector<long long>> AdjList;

struct DFSRes {
  long long max_node_count;
  bool is_red;
};

DFSRes dfs(long long node, long long parent, AdjList &adj_list) {
  long long nodes = 0;
  bool has_red_child = false;
  for (long long child : adj_list[node]) {
    if (child == node) {
      printf("hi\n");
      continue;
    }
    if (child == parent)
      continue;

    auto childres = dfs(child, node, adj_list);
    nodes += childres.max_node_count;
    if (childres.is_red)
      has_red_child = true;
  }

  // prlong longf("%d: %d %d\n", node, nodes, has_red_child);

  if (has_red_child) {
    return {nodes, false}; // mark current node as black
  }

  return {nodes + 1, true}; // mark current node as red
}

int main() {
  long long n; // node count
  scanf("%lld", &n);

  vector<vector<long long>> adj_list(n + 1);

  for (long long i = 0; i < n - 1; i++) {
    long long parent;
    long long child;
    scanf("%lld %lld", &parent, &child);
    adj_list[parent].push_back(child);
    adj_list[child].push_back(parent); // undirected graph
  }

  if (n < 1) {
    printf("0\n");
    return 0;
  }

  auto max_nodes = dfs(1, 0, adj_list);

  // prlong longf("%d\n", max_nodes.max_node_count);
  printf("%lld\n", max_nodes.max_node_count * (n - 1));

  return 0;
}
