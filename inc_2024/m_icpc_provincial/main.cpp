#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int n; // teams
  scanf("%d", &n);
  
  vector<int> strengths(n*3, 0);
  for (int i = 0; i < n * 3; i++) {
    scanf("%d", &strengths[i]);
  }

  sort(strengths.begin(), strengths.end());

  printf("%d\n", strengths[n]);

  return 0;
}

// 1 2 3 4 5 6
// 1 3 5
// 2 4 6

// 1 2 3 4 5 6 7 8 9
// 1 4 7
// 2 5 8
// 3 6 9