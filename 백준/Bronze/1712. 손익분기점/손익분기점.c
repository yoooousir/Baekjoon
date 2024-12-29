#include <stdio.h>

int main(){
    long long a, b, c;
    scanf("%lld %lld %lld", &a, &b, &c);
    if(c<=b) {
        printf("-1");
        return 0;
    }
    else{
        printf("%lld", a/(c-b)+1);
        return 0;
    }
}