#include <bits/stdc++.h>
#define rnt register int
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define WATCH(x) cout << #x << " : " << x << '\n';
#define PRINT(x) cout << x << '\n';
using namespace std;
using pii = pair<int,int>;
using ll = long long;

int call_bino = 0;
int call_bino2 = 0;

int bino(int n, int r) {
	call_bino++;
	if(r==0 || n==r) return 1;
	return bino(n-1, r-1) + bino(n-1, r);
}

int dp[30][30];
int bino2(int n, int r) {
	call_bino2++;
	if(r == 0 || n == r) return 1;
	
	if(dp[n][r] != -1) return dp[n][r];
	return dp[n][r] = bino2(n-1, r-1) + bino2(n-1, r);
}

int main(int argc, char **argv){
	int n = 25;
	int r = n/2;

	memset(dp, -1, sizeof(dp));

	printf("recursive           ans: %d, call: %d\n", bino(n ,r), call_bino);
	printf("dynamic programming ans: %d, call: %d\n", bino2(n ,r), call_bino2);
}
