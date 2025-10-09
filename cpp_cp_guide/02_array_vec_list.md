# Array

So you can either use C style arrays:

```cpp
int numbers[100] = {};
```

Or use `std::array`

```cpp
#include <array>
std::array<int, 100> numbers = {};
```

`std::array` provides neat helper functions without the baggage of `std::vector`

# Vector

```cpp
#include <vector>

std::vector<int> vec;
```

Behind the scenes, `std::vector` in C++ is implemented using a dynamic array that can grow as needed. Here's a concise explanation of how it works:

1. **Dynamic Array Allocation**: Initially, `std::vector` allocates a block of memory to store its elements. This memory is contiguous, just like a regular array.
2. **Reallocation on Growth**: When the vector's capacity is exceeded (i.e., you try to add more elements than it can currently hold), it allocates a new, larger block of memory. The size of this new block is **typically double the current capacity** to minimize the frequency of reallocations.
3. **Copying Elements**: After allocating the new memory, all existing elements are copied or moved to the new memory block, and the old memory is deallocated.
4. **Amortized Constant Time**: While reallocations involve copying elements, they occur infrequently. As a result, the average time complexity for adding elements (push_back) is amortized O(1).

Avoid if:
1. If you need something that supports *infinite* (a lot, but unknown) length -> use `list`.
2. Inserting or deleting in the middle (`vector` is an array behind the scenes; would shift every single element O(n)) -> use `list`

## Predefined size

If you know the size beforehand, you *should use arrays* or do this:

```cpp
std::vector<int> vec(5); // Creates a vector of size 5, all elements initialized to 0
std::vector<int> vec2(5, 1); // Creates a vector of size 5, all elements initialized to 1
```


# List

Doubly Linked list basically.

```cpp
#include <iostream>
#include <list>

int main() {
  std::list<int> myList = {10, 20, 30};

  // Adding elements
  myList.push_back(40);
  myList.push_front(5);

  // Iterating through the list
  for (int value : myList) {
      std::cout << value << " ";
  }
  std::cout << std::endl;

  // Removing elements
  myList.pop_back();
  myList.pop_front();

  // Displaying the modified list
  for (int value : myList) {
      std::cout << value << " ";
  }

  return 0;
}
```

Avoid if:
1. You need fast random access (you know index) -> use `vector` or `array`