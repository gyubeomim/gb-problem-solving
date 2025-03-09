#include <bits/stdc++.h>
#define rnt register int
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define WATCH(x) cout << #x << " : " << x << '\n';
#define PRINT(x) cout << x << '\n';
using namespace std;
using pii = pair<int,int>;
using ll = long long;

const int LM = 305;

int S[LM];
int N;
int dp[LM][3];  
// dp[i][j] = 현재까지 j개의 계단을 연속해서 밟고 i번째 계단까지 올라섰을때 점수 합의 최대값
//            단, i번째 계단은 반드시 밟아야함

int main(int argc, char **argv){
	scanf("%d", &N);
	for(int i=1;i<=N;i++) scanf("%d", &S[i]);

	if(N==1) {
		printf("%d\n", S[1]); return 0;
	}

	dp[1][1] = S[1];
	dp[1][2] = 0;
	dp[2][1] = S[2];
	dp[2][2] = S[1]+S[2];

	for(int i=3;i<=N;i++){
		dp[i][1] = max(dp[i-2][1], dp[i-2][2]) + S[i];
		dp[i][2] = dp[i-1][1] + S[i];
	}
	printf("%d\n", max(dp[N][1], dp[N][2]));
}
