#include <cstdio>
#include <queue>

using namespace std;

/**
 * Basically you want to take the tallest ducks first until you reach or exceed the
 * height of the book case.
 * To do this, we can use a max heap (priority queue) to always get the tallest duck
 * available.
 * 
 * Time complexity: O(n log n) due to the heap operations.
 * Space complexity: O(n) for storing the duck heights in the heap.
 */

int main() {
  int n; // duck count
  int b; // book case height

  priority_queue<int> duck_heights; // max heap

  scanf("%d %d", &n, &b);

  int temp = 0;
  for (int i = 0; i < n; i++) {
    scanf("%d", &temp);
    duck_heights.push(temp);
  }

  int total_height = 0;
  int duck_count = 0;
  while (total_height < b) {
    total_height += duck_heights.top();
    duck_heights.pop();
    duck_count++;
  }

  printf("%d\n", duck_count);

  return 0;
}