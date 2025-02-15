#include <bits/stdc++.h>
using namespace std;

const int LM = 500005;

int A[LM];
int N;

int upperIndex(int t){
	int l=0, r=N;
	while(l<r){
		int m = (l+r)/2;
		if(A[m]>t) r=m;
		else l=m+1;
	}
	return l;
}

int lowerIndex(int t){
	int l=0, r=N;
	while(l<r){
		int m = (l+r)/2;
		if(A[m]>=t) r=m;
		else l=m+1;
	}
	return l;
}

int main(int argc, char **argv){
	scanf("%d ",&N);
	for(int i=0;i<N;i++) scanf("%d", &A[i]);

	sort(A, A+N);

	int M;
	scanf("%d",&M);
	while(M--){
		int t;
		scanf("%d", &t);
		printf("%d ", upperIndex(t) - lowerIndex(t));
	}
	puts("");
}
