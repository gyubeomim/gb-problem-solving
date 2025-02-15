#include <bits/stdc++.h>
using namespace std;

const int LM = 100005;

int N,M;
int A[LM];

bool binarySearch(int target) {
	int l=0;
	int r=N-1;

	while(l<=r){
		int m=(l+r)/2;

		if(A[m] == target) return 1;
		if(A[m]<target) l=m+1;
		else r=m-1;
	}
	return 0;
}

int main(int argc, char **argv){
	scanf("%d", &N);
	for(int i=0; i<N; i++){
		scanf("%d", &A[i]);
	}

	sort(A, A+N);

	scanf("%d", &M);
	for(int i=0; i<M; i++){
		int t;
		scanf("%d", &t);
		if(binarySearch(t)){
			printf("1\n");
		}
		else printf("0\n");
	}
}
