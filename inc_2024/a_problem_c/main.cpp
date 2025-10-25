#include <cstdio>
#include <cstring>

using namespace std;

bool is_vowel(char c) {
  return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}
bool is_consonant(char c) { return (c >= 'a' && c <= 'z') && !is_vowel(c); }

void skibidi(char *word, int len) {
  for (int j = 0; j < len; j++) {
    // ch -> c
    if (j - 1 >= 0) {
      char prev = word[j - 1];

      if (word[j] == 'h' && prev == 'c') {
        word[j] = '#';
        continue;
      }
    }

    if (word[j] != 'c') {
      continue;
    }
    // replace c

    if (j == len - 1) {
      word[j] = 'k';
      continue;
    }

    if (j + 1 < len) {
      char next = word[j + 1];
      if (next == 'a' || next == 'o' || next == 'u') {
        word[j] = 'k';
        continue;
      } else if (is_consonant(next) && next != 'h' && next != 'y') {
        word[j] = 'k';
        continue;
      }

      if (next == 'e' || next == 'i' || next == 'y') {
        word[j] = 's';
        continue;
      }
    }
  }
}

int main() {
  int n; // word count
  scanf("%d", &n);

  char word[102] = {};
  for (int i = 0; i < n; ++i) {
    scanf("%s", word);
    int len = strlen(word);

    skibidi(word, len);
    
    for (int j = 0; j < len; j++) {
      if (word[j] == '#') {
        continue;
      }
      printf("%c", word[j]);
    }
    printf("\n");
  }

  return 0;
}