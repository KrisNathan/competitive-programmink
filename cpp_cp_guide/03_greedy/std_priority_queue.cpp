#include <iostream>
#include <queue>
#include <vector>

void max_queue_example() {
  std::priority_queue<int> max_queue;

  max_queue.push(5);
  max_queue.push(3);
  max_queue.push(7);
  max_queue.push(1);

  while (!max_queue.empty()) {
    int v = max_queue.top();
    max_queue.pop();
    std::cout << v << ' ';
  }
  std::cout << '\n';
}

void min_queue_example() {
  std::priority_queue<int, std::vector<int>, std::greater<int>> min_queue;

  min_queue.push(5);
  min_queue.push(3);
  min_queue.push(7);
  min_queue.push(1);

  while (!min_queue.empty()) {
    int v = min_queue.top();
    min_queue.pop();
    std::cout << v << ' ';
  }
  std::cout << '\n';
}

/**
 * This should be Avoided.
 * Reallocations happen rarely enough that it evens out in the long run (ammortized time complexity)
 * Doing this sometimes causes the peak memory footprint to balloon unpredictably.
 */
void max_queue_reserved_example() {
  std::vector<int> container;
  container.reserve(4);
  std::priority_queue<int> max_queue(std::less<int>(), std::move(container));

  max_queue.push(5);
  max_queue.push(3);
  max_queue.push(7);
  max_queue.push(1);

  while (!max_queue.empty()) {
    int v = max_queue.top();
    max_queue.pop();
    std::cout << v << ' ';
  }
  std::cout << '\n';
}

struct Item {
  int value;
  int weight;

  // Overload the less-than operator for custom comparison
  // For a max-priority queue (default), return true if
  // 'this' should come AFTER 'other'
  bool operator<(const Item &rhs) const {
    float left_worth = (float)value / weight;
    float right_worth = (float)rhs.value / rhs.weight;
    return left_worth < right_worth;
  }

  // For min-priority queue with std::greater<T>
  bool operator>(const Item &rhs) const {
    float left_worth = (float)value / weight;
    float right_worth = (float)rhs.value / rhs.weight;
    return left_worth > right_worth;
  }
};

void struct_max_queue_example() {
  std::priority_queue<Item> max_queue;

  max_queue.push({10, 30});
  max_queue.push({5, 9});
  max_queue.push({20, 10});
  max_queue.push({1, 5});

  std::cout << "{\n";
  while (!max_queue.empty()) {
    auto v = max_queue.top();
    max_queue.pop();
    std::cout << '\t' << v.value << ' ' << v.weight << ' '
              << (float)v.value / v.weight << '\n';
  }
  std::cout << "}\n";
}
void struct_min_queue_example() {
  std::priority_queue<Item, std::vector<Item>, std::greater<Item>> min_queue;

  min_queue.push({10, 30});
  min_queue.push({5, 9});
  min_queue.push({20, 10});
  min_queue.push({1, 5});

  std::cout << "{\n";
  while (!min_queue.empty()) {
    auto v = min_queue.top();
    min_queue.pop();
    std::cout << '\t' << v.value << ' ' << v.weight << ' '
              << (float)v.value / v.weight << '\n';
  }
  std::cout << "}\n";
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  max_queue_example();
  min_queue_example();
  struct_max_queue_example();
  struct_min_queue_example();

  return 0;
}
