#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){
	int n, i; scanf("%d", &n);
	//if(n>10000){
		int num[10000];
		int rank[10000];
		for(i=0; i<10000; i++){
			num[i]=i+1;
			rank[i]=0;
		}
		int t, cnt=0, j;
		for(i=0; i<n; i++){
			scanf("%d", &t);
			rank[t-1]++;
		}
		for(i=0; i<10000; i++){
			if(rank[i]>0){
				for(j=0; j<rank[i]; j++) printf("%d\n", num[i]);
			}
		}
	//}
	/*else {
		int*num=(int*)malloc(sizeof(int)*n);
	}
	
		
	}*/
	
	return 0;
}