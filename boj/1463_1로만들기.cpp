#include <bits/stdc++.h>
using namespace std;

constexpr int LM = 1000005;

int dp[LM];
int N;

int main(int argc, char **argv){
	scanf("%d",&N);
	dp[1] = 0;

	for(int i=2; i<=N; i++){
		dp[i] = dp[i-1]+1;
		if(i%2==0) dp[i] = min(dp[i], dp[i/2]+1);
		if(i%3==0) dp[i] = min(dp[i], dp[i/3]+1);
	}
	printf("%d\n", dp[N]);
}
