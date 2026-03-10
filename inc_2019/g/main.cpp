/*
golf field
x = a to b

theres inf tall post @ a and b

ball currently on (s, 0)

hole at (t, 0)

n trees
p = position of tree
h = height of tree

single strike
x to x + 2r
centered at x + r

- golf can hit top endpoint
- below no
- hit post no


*/

typedef unsigned int uint;

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

struct Tree {
  uint pos;
  uint height;
};

int main() {
  uint n, // number of trees
      a,  // post
      b,  // post
      s,  // ball
      t;  // hole
  cin >> n >> a >> b >> s >> t;

  vector<uint> tree_pos(n);
  for (auto &pos : tree_pos) {
    cin >> pos;
  }
  vector<Tree> trees_between_start_and_hole;
  vector<uint> tree_height(n);
  for (int i = 0; i < n; i++) {
    cin >> tree_height[i];
    if ((tree_pos[i] > min(s, t)) && (tree_pos[i] < max(s, t))) {
      trees_between_start_and_hole.push_back({tree_pos[i], tree_height[i]});
    }
  }
  
  sort(trees_between_start_and_hole.begin(), trees_between_start_and_hole.end(),
       [](const Tree &a, const Tree &b) { return a.pos < b.pos; });

  


  return 0;
}