#include <bits/stdc++.h>
using namespace std;

constexpr int MOD = 1000000007;

int n;
int dp[105];    
// dp[n] : 2xn 크기의 직사각형을 채우는 방법의 수
// dp[n] = (dp[n-1] + dp[n-2]) % MOD

// 시간복잡도: O(n)  (부분문제 O(n), 계산 O(1))
// 2*width 크기의 사각형을 채우는 방법의 수를 MOD로 나눈 나머지를 반환한다
int tiling(int width) {
	// 기저 사례: width가 1 이하일 때
	if(width <= 1) return 1;

	int& ret = dp[width];
	if(ret != -1) return ret;
	return ret = (tiling(width-2) + tiling(width-1)) % MOD;
}

int main(int argc, char **argv){
	 int C; scanf("%d",&C);
	 while(C--){
		 scanf("%d", &n);

		 memset(dp, -1, sizeof(dp));
		 
		 int ret = tiling(n);
		 printf("%d\n", ret);
	 }
}
