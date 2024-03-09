#include <cstdio>

int main(int argc, char **argv){
	int N;
	scanf("%d",&N);

	for(int i=1;i<=N;i++){
		for(int j=1;j<=i;j++){
			printf("*");
		}
		puts("");
	}

	return 0;
}
