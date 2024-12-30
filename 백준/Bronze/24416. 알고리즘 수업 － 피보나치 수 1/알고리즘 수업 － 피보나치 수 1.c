#include <stdio.h>

int cnt1 = 0, cnt2 = 0; 
int f[41];

void fibonacci(int n) {
    f[1] = f[2] = 1; 
    for (int i = 3; i <= n; i++) {
        f[i] = f[i - 1] + f[i - 2];
        cnt2++;
    }
    return;
}

void fib(int n) {
    if (n == 1 || n == 2) {
        cnt1++;
        return;
    }
    fib(n - 1);
    fib(n - 2);
}

int main() {
    int n;
    scanf("%d", &n);

    fib(n); 
    fibonacci(n); 

    printf("%d %d\n", cnt1, cnt2);
    return 0;
}
