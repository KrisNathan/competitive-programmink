// Stack
// With method to get max
// max should be O(1) without sacrificing existing push and pop performance

#include <cstddef>
#include <iostream>
#include <optional>

struct Node {
  Node *next;
  Node *prev_max;
  int value;

  Node(int value) { this->value = value; }
};

class Stack {
  Node *head;
  Node *max;

public:
  bool is_empty() { return head == NULL; }

  // O(1)
  void push(int value) {
    Node *n = new Node(value);
    if (head == NULL) {
      head = n;
      max = n;
      return;
    }

    n->next = head;
    head = n;

    if (max && value > max->value) {
      n->prev_max = max;
      max = n;
    }
  }

  // O(1)
  std::optional<int> pop() {
    if (head == NULL) {
      return NULL;
    }

    Node *t = head;
    int value = head->value;

    head = head->next;

    if (t == max) {
      max = t->prev_max;
    }

    delete t;

    return value;
  }

  // O(1)
  std::optional<int> get_max() {
    if (max)
      return max->value;
    return NULL;
  }
};

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  Stack *s = new Stack();
  s->push(3);
  s->push(9);
  s->push(4);
  s->push(10);

  while (!s->is_empty()) {
    if (auto max = s->get_max()) {
      std::cout << "max:" << max.value() << '\n';
    }

    if (auto top = s->pop()) {
      std::cout << "top:" << top.value() << '\n';
    }
    std::cout << '\n';
  }

  return 0;
}
