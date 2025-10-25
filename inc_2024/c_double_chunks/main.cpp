#include <cstdio>
#include <vector>
#include <map>
using namespace std;

int main() {
  int n;
  scanf("%d", &n);

  vector<long long> chunks(n);

  for (int i = 0; i < n; i++) {
    scanf("%lld", &chunks[i]);
  }

  long long prev = -1;
  map<long long, int> chunk_occurence; // idx is chunk size, value is occurence count
  for (int i = 1; i < n; i++) {
    long long sum = chunks[i-1] + chunks[i];

    if (sum == prev) {
      prev = 0;
      continue;
    }

    chunk_occurence[sum]++;
    prev = sum;
  }

  int max_occurence = 0;
  for (auto const& [key, value] : chunk_occurence) {
    // printf("%lld: %d\n", key, value);
    if (value > max_occurence) {
      max_occurence = value;
    }
  }
  printf("%d\n", max_occurence);

  return 0;
}
