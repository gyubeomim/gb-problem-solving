#include <cstdio>

int main(int argc, char **argv){
	int N;
	scanf("%d", &N);

	int maxval=-(int)1e7;
	int minval=(int)1e7;

	for(int i=0;i<N;i++){
		int n;
		scanf("%d", &n);

		if(n < minval) minval = n;
		if(n > maxval) maxval = n;
	}

	printf("%d %d", minval, maxval);

	return 0;
}
