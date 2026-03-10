#include <stdio.h>
#include <string.h>

int f[26];
int used[26];
char s[200005], half[200005];

void palindrome(char mid, int arr[26]) {
    int len = 0;
    for (int i = 0; i < 26; i++) {
        int t = arr[i] / 2;
        while (t--) {
            half[len++] = 'a' + i;
        }
    }

    for (int i = 0; i < len; i++) {
        putchar(half[i]);
    } 

    if (mid) {
        putchar(mid);
    } 

    for (int i = len - 1; i >= 0; i--){
        putchar(half[i]);
    } 

    putchar('\n');
}

int main() {
    scanf("%s", s);
    int lens = strlen(s);

    for (int i = 0; i < lens; i++) {
        f[s[i] - 'a']++;
    } 

    int odd = 0;
    for (int i = 0; i < 26; i++) {
        if (f[i] % 2) odd++;
    }

    if (!odd) {
        odd = 1;
    }

    printf("%d\n", odd);

    char totalAlpha[26];
    int m = 0;
    for (int i = 0; i < lens; i++) {
        int id = s[i] - 'a';
        if (f[id] % 2 && !used[id]) {
            used[id] = 1;
            totalAlpha[m++] = s[i];
        }
    }
    if (m == 0) {
        totalAlpha[m++] = 0;
    } 

    int tmp[26];
    memcpy(tmp, f, sizeof(f));

    int per = lens / m;
    for (int k = 0; k < m; k++) {
        int cnt[26] = {0}, sum = 0;
        for (int i = 0; i < 26 && sum + 2 <= per; i++) {
            while (tmp[i] >= 2 && sum + 2 <= per) {
                tmp[i] -= 2;
                cnt[i] += 2;
                sum += 2;
            }
        }
        palindrome(totalAlpha[k], cnt);
    }
    return 0;
}