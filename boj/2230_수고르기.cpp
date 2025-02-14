#include <bits/stdc++.h>
using namespace std;

constexpr int LM = 100'005;
constexpr int INF = 0x7fffffff;

int N,M;
int A[LM];

int main(int argc, char **argv){
	scanf("%d%d",&N, &M);

	for(int i=0; i<N; i++){
		scanf("%d", &A[i]);
	}

	sort(A, A+N);

	int ans = INF;
	
	// Two pointers
	int en = 0;
	for(int st=0; st<N; st++){
		while(en < N && A[en] - A[st] < M) en++;
		if(en == N) break;  // en이 범위를 벗어날 시 종료
		ans = min(ans, A[en] - A[st]);
	}

	printf("%d\n", ans);
}

