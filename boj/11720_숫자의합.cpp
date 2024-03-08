#include <cstdio>

int main(int argc, char **argv){
	int N;
	scanf("%d", &N);
	
	int sum=0;
	for(int i=0;i<N;i++){
		int n;
		scanf("%1d", &n);
		sum += n;
	}

	printf("%d",sum);

	return 0;
}
