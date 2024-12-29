#include <stdio.h>

int main(){
    int n;
    scanf("%d", &n);
    if(n<100) printf("%d", n);
    else{
        int cnt=99;
        for(int i=100; i<=n;i++){
            int n1 = i/100 - i/10%10;
            int n2 = i/10%10 - i%10;
            if(n1==n2) cnt++;
        }
        printf("%d", cnt);
    }
    return 0;
}