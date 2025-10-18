#include <cstdio>
#include <vector>

using namespace std;

int max(int a, int b, int c) {
  int t = a > b ? a : b;
  return t > c ? t : c;
}

int min(int a, int b, int c) {
  int t = a < b ? a : b;
  return t < c ? t : c;
}

int rating_difference(int a, int b, int c) {
  return max(a, b, c) - min(a, b, c);
}

int main() {
  int n; // number of students
  int m; // rating diff thres
  scanf("%d %d", &n, &m);

  vector<int> student_ratings;

  for (int i = 0; i < n; i++) {
    int student_rating;
    scanf("%d", &student_rating);
    student_ratings.push_back(student_rating);
  }

  int party_count = 0;
  int highest_rating = 0;

  for (int i = 0; i < n - 2; i++) {
    for (int j = i + 1; j < n - 1; j++) {
      for (int k = j + 1; k < n; k++) {
        int diff = rating_difference(student_ratings[i], student_ratings[j],
                                     student_ratings[k]);
        int rating =
            student_ratings[i] + student_ratings[j] + student_ratings[k];
        if (diff <= m) {
          party_count++;
          if (rating > highest_rating) {
            highest_rating = rating;
          }
        }
      }
    }
  }

  if (party_count == 0) {
    printf("-1\n");
    return 0;
  }
  
  printf("%d %d\n", party_count, highest_rating);

  return 0;
}