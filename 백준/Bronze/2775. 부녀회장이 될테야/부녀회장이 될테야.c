#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int apt[15][14];

void init(){
    for(int i=1;i<=14;i++){
        apt[0][i-1]=i;
    }
    
    for(int i=1;i<=14;i++){
        int sum=apt[i][0]=apt[i-1][0];
        for(int j=1; j<14; j++){
            apt[i][j]=sum+=apt[i-1][j];
        }
    }
}
/*

*/
int main(){
    init();
    int t, k, n, i;
    scanf("%d", &t);
    while(t--){
        scanf("%d %d", &k, &n);
        printf("%d\n", apt[k][n-1]);
        
    }
    
    return 0;
}