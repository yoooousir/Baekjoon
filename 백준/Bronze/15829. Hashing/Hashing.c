#include <stdio.h>
#include <math.h>

int Hash(int l, char* str){
    int result=0;
    for(int i=0;i<l;i++){
        result+=((str[i]-'a'+1)*(pow(31, i)));
    }
    return result%1234567891;
}

int main()
{
    int l;
    char str[51];
    scanf("%d %s", &l, str);
    
    printf("%d", Hash(l, str));

    return 0;
}