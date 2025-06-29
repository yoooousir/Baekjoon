#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

int n, ans = 1e9;
int stats[20][20];
bool check[20];

void DFS(int count, int pos){
    if(count==n/2){
        int start=0, link=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i==j) continue;
                else{
                    //true: start
                    if(check[i] && check[j]) start+=stats[i][j];
                    //false: link
                    else if(!check[i] && !check[j]) link+=stats[i][j];
                }
            }
        }
        int diff = abs(start-link);
        ans = (ans>diff)? diff: ans;
        return;
    }
    
    for(int i=pos;i<n;i++){
        check[i]=true;
        DFS(count+1, i+1);
        check[i]=false;
    }
}

int main(){
    scanf("%d", &n);
    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++) scanf("%d", &stats[i][j]);
    }
    DFS(0, 0);
    printf("%d", ans);
    
    return 0;
}