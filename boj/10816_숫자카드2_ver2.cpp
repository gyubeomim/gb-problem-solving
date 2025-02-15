#include <bits/stdc++.h>
using namespace std;

const int LM = 500005;

int A[LM];
int N;

int main(int argc, char **argv){
	 scanf("%d", &N);
	 for(int i=0; i<N; i++) scanf("%d", &A[i]);
	 sort(A, A+N);

	 int M;
	 scanf("%d", &M);
	 while(M--){
		 int t;
		 scanf("%d", &t);
		 printf("%ld ", upper_bound(A,A+N,t) - lower_bound(A,A+N,t));
	 }
}
