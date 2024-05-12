#include <bits/stdc++.h>
#define rnt register int
#define fasti cin.tie(0)->sync_with_stdio(0);
#define fastio cin.tie(0)->sync_with_stdio(0); cout.tie(0);
using namespace std;
using pii = pair<int,int>;
using ll = long long;

int N;
ll dp[2];

int main(int argc, char **argv){
	 scanf("%d", &N);

	 dp[0] = 0;
	 dp[1] = 1;

	 for(int i=1; i<N; i++){
		 ll tmp0 = dp[0] + dp[1];
		 ll tmp1 = dp[0];

		 dp[0] = tmp0;  // 0, 1, 1, 2
		 dp[1] = tmp1;  // 1, 0, 1, 1
	 }
	 printf("%lld", dp[0]+dp[1]);
}
