#include <bits/stdc++.h>
#define rnt register int
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define WATCH(x) cout << #x << " : " << x << '\n';
#define PRINT(x) cout << x << '\n';
using namespace std;
using pii = pair<int,int>;
using ll = long long;

// solution #1
int n, board[100][100];
bool jump(int y, int x){
	if(y>=n || x>=n) return false;

	if(y==n-1 && x==n-1) return true;

	int jumpSize = board[y][x];
	return jump(y+jumpSize, x) || jump(y, x+jumpSize);
}

// solution #2
int dp[100][100];
int jump2(int y, int x) {
	if(y>=n || x>=n) return 0;
	if(y == n-1 && x == n-1) return 1;

	int& ret = dp[y][x];
	if(ret != -1) return ret;

	int jumpSize = board[y][x];
	return ret = (jump2(y+jumpSize, x) || jump2(y, x+jumpSize));
}

int main(int argc, char **argv){
	 int C;
	 scanf("%d", &C);

	 while(C--){
		 scanf("%d", &n);
		 for(int i=0; i<n; i++){
			 for(int j=0; j<n; j++){
				 scanf("%d ", &board[i][j]);
			 }
		 }
		
		 memset(dp, -1, sizeof(dp));

		 // string ans = jump(0,0) ? "YES" : "NO";
		 string ans = jump2(0,0) ? "YES" : "NO";
		 printf("%s\n", ans.c_str());
	 }
}
