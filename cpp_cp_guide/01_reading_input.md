# Reading Input

Most fundamental instruction for a program that solves competitive programming problems.


## Reading List

1. https://stackoverflow.com/questions/1042110/using-scanf-in-c-programs-is-faster-than-using-cin


## You should use cstdio instead of iostream. (If you need to type faster)

`scanf` is significantly faster **by default**.

Quoting a guy in the stack overflow question (link 1) mentioned:

```
iostream version:  24.3 seconds
scanf version:      6.4 seconds
```

Why is this?

> User clyfish points out below that the speed difference is largely due to the iostream I/O functions maintaining synchronization with the C I/O functions. We can turn this off with a call to `std::ios::sync_with_stdio(false);`

- When synchronization is enabled (sync_with_stdio(true)), the C++ streams (cin, cout) are synchronized with their C counterparts (stdin, stdout).
- This ensures that you can safely mix C++ and C I/O operations in the same program.
- However, this synchronization introduces overhead, making I/O operations slower.

## Making iostream faster

### iostream can be faster with by disabling `sync_with_stdio`

```cpp
#include <iostream>

int main(int argc, char **argv) {

  int parity = 0;
  int x;

  std::ios::sync_with_stdio(false);

  while (std::cin >> x)
    parity ^= x;
  std::cout << parity << std::endl;

  return 0;
}
```

```
iostream version:                       21.9 seconds
scanf version:                           6.8 seconds
iostream with sync_with_stdio(false):    5.5 seconds
```

- Use `sync_with_stdio(false)` in competitive programming or performance-critical applications where you only use C++ I/O (cin, cout) and need faster execution.
- Avoid it if you need to mix C++ and C I/O functions or require thread-safe I/O operations. (**YOU CAN'T USE IT WITH C IO FUNCTIONS LIKE SCANF OR PRINTF**)

### Untie `cin`

```cpp
std::cin.tie(nullptr);
```

The `cin.tie(nullptr)` detaches cin from cout, preventing automatic flushing of cout before cin operations, further improving performance.
