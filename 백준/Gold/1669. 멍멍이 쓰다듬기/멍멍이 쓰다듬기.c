#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <math.h>

int MINDATE(int x, int y){
    if((y-x)<1) return 0;
    int s_need = (int)pow((y-x), 0.5);
    if(pow(s_need, 2) == y-x) return 2*s_need-1;
    else{
        double p_need = y-x - pow(s_need, 2);
        if(p_need<=s_need) return 2*s_need;
        else return 2*s_need+1;
    }
}

int main(){
    int x, y;
    scanf("%d %d", &x, &y);
    printf("%d", MINDATE(x, y));
    
    return 0;
}