#include <stdio.h>
#include <stdlib.h>

int main(){
	int num;
	while(1){
		scanf("%d",&num);
		if (num>=1&&num<=9) break;
	}
	for(int i=1;i<=num;i++){
			for(int j=1;j<=num-i;j++){
				printf(" ");
			}
			for(int j=1;j<=i;j++){
					printf("%d",j);
			}	
			for(int j=i-1;j>0;j--){
					printf("%d",j);
			}
			for(int j=num;j>=i-1;j--){
				printf(" ");
			}
			printf("\n");
	}
	for(int i=1;i<=num-1;i++){
			for(int j=i;j>0;j--){
				printf(" ");
			}
			for(int j=1;j<=num-i;j++){
					printf("%d",j);
			}	
			for(int j=num-i-1;j>0;j--){
					printf("%d",j);
			}
			printf("\n");
	}
}
