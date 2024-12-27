#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

int T_arr[44];
void init_T();
int T(int n);
bool is_3T(int k);
int find_idx(int num);

int main()
{
    init_T();
    
    int t, i, k;
    scanf("%d", &t);
    
    for(i=0;i<t;i++){
        scanf("%d", &k);
        printf("%d\n", is_3T(k));
    }
    
    return 0;
}

int T(int n){
    return n*(n+1)/2;
}

void init_T(){
    int len=0, n=1, t=1;
    while((t=T(n++))<1000){
        T_arr[len++]=t;
    }
}

bool is_3T(int k) {
    int idx = find_idx(k);

    for (int i = 0; i <= idx; i++) {
        for (int j = 0; j <= idx; j++) {
            int remaining = k - T_arr[i] - T_arr[j];
            if (remaining < 0) {
                continue;
            }
            for (int l = 0; l <= idx; l++) {
                if (T_arr[l] == remaining) {
                    return true;
                }
            }
        }
    }

    return false;
}


int find_idx(int num) {
    int low = 0, high = 43, mid;

    while (low <= high) {
        mid = (low + high) / 2;

        if (num == T_arr[mid]) {
            return mid;
        }

        if (mid < 43 && T_arr[mid] < num && T_arr[mid + 1] > num) {
            return mid + 1;
        }

        if (num < T_arr[mid]) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    // 만약 num이 T_arr의 값보다 크다면, 마지막 인덱스를 반환
    return 43;
}

