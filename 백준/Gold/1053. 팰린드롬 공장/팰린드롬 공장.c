#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define min3(a, b, c) ((a < b && a < c) ? (a) : (b < c ? (b) : (c)))
#define min2(a, b) ((a < b) ? (a) : (b))

int dp[51][51];
char st[51];

int solve(int l, int r) {
    if (dp[l][r] != -1) return dp[l][r];
    if (l >= r) return 0;
    dp[l][r] = min3(solve(l + 1, r) + 1, solve(l, r - 1) + 1, solve(l + 1, r - 1) + (st[l] != st[r]));
    return dp[l][r];
}

void swap(char* a, char* b) {
    char tmp = *a;
    *a = *b;
    *b = tmp;
}

int main() {
    scanf("%s", st);
    memset(dp, -1, sizeof(dp));
    int result = solve(0, strlen(st) - 1);
    
    for (int i = 0; i < strlen(st); i++) {
        for (int j = i + 1; j < strlen(st); j++) {
            memset(dp, -1, sizeof(dp));
            swap(&st[i], &st[j]);
            result = min2(result, solve(0, strlen(st) - 1) + 1);
            swap(&st[i], &st[j]);
        }
    }
    printf("%d\n", result);
    return 0;
}
