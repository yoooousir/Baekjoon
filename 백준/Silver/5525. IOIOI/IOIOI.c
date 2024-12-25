#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    int n, m, i, cnt=0;
    scanf("%d %d", &n, &m);getchar();
    
    char* p = (char*)malloc(sizeof(char)*(2*n+1));
    for(i=0;i<2*n;i+=2){
        p[i]='I';
        p[i+1]='O';
    }
    p[2*n]='I';
    char* s = (char*)malloc(sizeof(char)*m);
    scanf("%s", s);
    
    char* ptr=s;
    while(ptr<s+(int)strlen(s)){
        if(*ptr=='I'){
            if(!strncmp(p, ptr, (2*n+1))){
                cnt++;
                ptr+=2;
            }
            else{
                ptr++;
            }
        }
        else ptr++;
    }
    printf("%d\n", cnt);
    
    return 0;
}