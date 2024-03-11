#include <cstdio>

#define rnt register int

using ll = long long;

int main(int argc, char **argv){

	while(true) {

		int A,B; 
		scanf("%d %d", &A,&B);

		if(A==0 && B==0) break;
		else if(A>B) printf("Yes\n");
		else printf("No\n");

	}

	return 0;
}
