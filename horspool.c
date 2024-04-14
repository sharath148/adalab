#include<stdio.h>
#include<string.h>

#define MAX_CHAR 256

int ST[MAX_CHAR];

void shiftTable(char *p) {
    int n = strlen(p);
    for (int i = 0; i < MAX_CHAR; i++) {
        ST[i] = n;
    }
    for (int j = 0; j < n - 1; j++) {
        ST[p[j]] = n - 1 - j;
    }
}

int horspool(char *p, char *s) {
    shiftTable(p);
    int m = strlen(p);
    int n = strlen(s);
    int i = m - 1;
    while (i <= n - 1) {
        int k = 0;
        while (k <= m - 1 && p[m - 1 - k] == s[i - k]) {
            k++;
        }
        if (k == m) {
            return i - m + 1;
        } else {
            i = i + ST[s[i]];
        }
    }
    return -1;
}

int main() {
    char s[1000], p[1000];
    printf("\nEnter a string: ");
    fgets(s, sizeof(s), stdin);
    printf("\nEnter pattern to be searched: ");
    fgets(p, sizeof(p), stdin);
    p[strcspn(p, "\n")] = '\0'; // Remove trailing newline character

    int res = horspool(p, s);
    if (res == -1)
        printf("\nPattern not found");
    else
        printf("\nPattern found at position %d", res + 1);

    return 0;
}
