#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char s[1000001];

int main(){
    int n, m, i, cnt=0;
    scanf("%d %d", &n, &m);getchar();
    scanf("%s", s);
    
    int cnt_tmp=0;
    for(i=0;i<m-2;){
        //
        if(s[i]=='I' && s[i+1]=='O' && s[i+2]=='I'){
            cnt_tmp++;
            
            //패턴 일치 확인
            if(cnt_tmp==n){
                cnt++;
                cnt_tmp--;
            } 
            
            i+=2; // 다음 'I' 위치로 이동
        }
        
        else {
            cnt_tmp=0; //무효
            i++;
        }
    }
    printf("%d\n", cnt);
    
    return 0;
}