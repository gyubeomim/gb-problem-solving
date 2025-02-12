#include <bits/stdc++.h>
using namespace std;

constexpr int MOD = 1000000007;

int n;
int dp[105];    

// 2*w 크기의 사각형을 채우는 방법의 수를 MOD로 나눈 나머지를 반환한다
int tiling(int w) {
	// 기저 사례: w가 1 이하일 때
	if(w <= 1) return 1;

	int& ret = dp[w];
	if(ret != -1) return ret;
	return ret = (tiling(w-2) + tiling(w-1)) % MOD;
}

int dp2[105];    

// 2*w 크기의 사각형을 채우는 비대칭 방법의 수를 반환한다
int asymetric2(int w){
	// 너비가 2 이하인 경우
	if(w <= 2) return 0;

	int& ret = dp2[w];
	if(ret != -1) return ret;

	ret = asymetric2(w-2) % MOD;           // a
	ret = ( ret + asymetric2(w-4) ) % MOD; // b
	ret = ( ret + tiling(w-3) ) % MOD;     // c
	ret = ( ret + tiling(w-3) ) % MOD;     // d
	return ret;
}

int main(int argc, char **argv){
	int C; scanf("%d",&C);
	while(C--) {
		scanf("%d",&n);

		memset(dp, -1, sizeof(dp));
		memset(dp2, -1, sizeof(dp2));

		int ans = asymetric2(n);
		printf("%d\n", ans);
	}
}
