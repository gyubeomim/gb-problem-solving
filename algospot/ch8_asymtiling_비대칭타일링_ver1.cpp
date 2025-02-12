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

// 2*w 크기의 사각형을 채우는 비대칭 방법의 수를 반환한다
int asymetric(int w){
	int ret = tiling(w);

	if(w%2 == 1) {                                    // w가 홀수인 경우
		return (ret - tiling(w/2) + MOD) % MOD;
	}
	else {                                            // w가 짝수인 경우
		ret = (ret - tiling(w/2) + MOD) % MOD;
		ret = (ret - tiling(w/2-1) + MOD) % MOD;
		return ret;
	}
}

int main(int argc, char **argv){
	int C; scanf("%d",&C);
	while(C--) {
		scanf("%d",&n);

		memset(dp, -1, sizeof(dp));

		int ans = asymetric(n);
		printf("%d\n", ans);
	}
}
