#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

int n, m;
int *names;
int *dp;

int square(int a) {
    return a * a;
}

int solution(int idx) {
    if (dp[idx] < INT_MAX) {
        return dp[idx];
    }

    int remain = m - names[idx];

    for (int i = idx + 1; i <= n && remain >= 0; i++) {
        if (i == n) {
            dp[idx] = 0;
            break;
        }
        dp[idx] = dp[idx] < remain * remain + solution(i) ? dp[idx] : remain * remain + solution(i);
        remain -= names[i] + 1;
    }

    return dp[idx];
}

int main() {
    scanf("%d %d", &n, &m);

    names = (int *)malloc(n * sizeof(int));
    dp = (int *)malloc(n * sizeof(int));

    for (int i = 0; i < n; i++) dp[i] = INT_MAX;

    for (int i = 0; i < n; i++) scanf("%d", &names[i]);

    dp[n - 1] = 0;
    printf("%d\n", solution(0));

    free(names);
    free(dp);

    return 0;
}
