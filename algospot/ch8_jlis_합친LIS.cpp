#include <bits/stdc++.h>
#define rnt register int
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define WATCH(x) cout << #x << " : " << x << '\n';
#define PRINT(x) cout << x << '\n';
using namespace std;
using pii = pair<int,int>;
using ll = long long;

constexpr ll NEGINF = numeric_limits<ll>::min();
constexpr int LM = 105;
int N, M;
int dp[LM][LM];
int A[LM], B[LM];

// min(A[indexA], B[indexB]), max(A[indexA], B[indexB])로 시작하는
// 합친 증가 부분 수열의 최대 길이를 반환한다
// 단 indexA == indexB == -1 혹은 A[indexA] != B[indexB]라고 가정한다
int jlis(int indexA, int indexB){
	int& ret = dp[indexA+1][indexB+1];
	if(ret != -1) return ret;
	
	// A[indexA], B[indexB]가 이미 존재하므로 2개는 항상 있다
	ret = 2;
	ll a = (indexA == -1 ? NEGINF : A[indexA]);
	ll b = (indexB == -1 ? NEGINF : B[indexB]);
	ll maxElement = max(a,b);
	
	for(int nextA=indexA+1; nextA<N; nextA++){
		if(maxElement < A[nextA])
			ret = max(ret, jlis(nextA, indexB)+1);
	}
	for(int nextB=indexB+1; nextB<M; nextB++){
		if(maxElement < B[nextB])
			ret = max(ret, jlis(indexA, nextB)+1);
	}
	return ret;
}

int main(int argc, char **argv){
	int C;
	scanf("%d", &C);
	while(C--){
		scanf("%d %d", &N, &M);

		memset(dp, -1, sizeof(dp));

		for(int i=0; i<N; i++){
			scanf("%d", &A[i]);
		}

		for(int i=0; i<M; i++){
			scanf("%d", &B[i]);
		}

		int ans = jlis(-1, -1) - 2;

		printf("%d\n", ans);
	}
}

