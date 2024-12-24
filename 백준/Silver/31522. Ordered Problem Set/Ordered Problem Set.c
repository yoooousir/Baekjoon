#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

void detk(int n, bool* k, int* d);
bool difficulty(int* d, int n, int k);

int main()
{
    int n, i, j;
    scanf("%d", &n);
    int* d = (int*)malloc(sizeof(int)*n); //difficulty
    bool* k = (bool*)malloc(sizeof(bool)*n);
    
    for(i=0;i<n;i++)scanf("%d", &d[i]);
    
    detk(n, k, d);
    
    int p=-1;
    
    for(i=0;i<n;i++){
        if(k[i]){
            printf("%d\n", i+1);
            p++;
        }
    }
    if(p==-1) printf("%d", p);
    
    free(d);
    free(k);
    
    return 0;
}

void detk(int n, bool* k, int* d){
    int idx = 0;
    
    while(idx<n){
        k[idx]=false;
        
        //1은 건너뜀
        if(!idx){
            idx++;
            continue;
        }
        
        //약수면 difficulty 체크
        if(n%(idx+1)==0){
            k[idx]=difficulty(d, n, idx+1);
            // n/idx도 약수이므로 diffuculty 체크
            if(idx+1<n && idx+1 != n/(idx+1)){
                k[n/(idx+1)-1]=difficulty(d, n, n/(idx+1));
            }
        }
        
        //자기자신은 항상 약수
        if(idx+1==n){
            k[idx]=difficulty(d, n, idx+1);
        }
        
        idx++;
    }
}

bool difficulty(int* d, int n, int k){
    int prev_max=0, cur_max=0, cur_min=0, dev=n/k;
    
    for(int i=0; i<dev; i++) prev_max=(!i || prev_max<d[i])?d[i]:prev_max;

    for(int i=dev; i<n; i+=dev){
        for(int j=i; j<i+dev; j++){
            cur_max=(j==i || cur_max<d[j])?d[j]:cur_max;
            cur_min=(j==i || cur_min>d[j])?d[j]:cur_min;
        }
        if(prev_max>cur_min) return false;
        prev_max=cur_max;
        cur_max=cur_min=0;
    }
    return true;
}