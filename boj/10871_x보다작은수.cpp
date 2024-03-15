#include <cstdio>
constexpr int LM = 10005;

int main(int argc, char **argv){
	int N,X;
	scanf("%d %d",&N,&X);

	for(int i=0; i<N; i++){
		int n;
		scanf("%d", &n);

		if(n < X) printf("%d ", n);
	}

	return 0;
}

