#include <bits/stdc++.h>
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define X first
#define Y second
using pii = std::pair<int,int>;
using ll = long long;
using namespace std;

const int LM = 1005;

int dp[LM][LM];

int main(int argc, char **argv){
	#ifndef ONLINE_JUDGE
		freopen("data/1858.txt", "r", stdin);
	#endif

	int n,m;
	string s1,s2;

	cin >> n >> s1;
	cin >> m >> s2;

	int best = 0, bi=0, bj=0;
	for(int i=1; i<=n; i++){
		for(int j=1; j<=m; j++){
			int match = (s1[i-1] == s2[j-1]) ? 3 : -2;

			dp[i][j] = max({0, 
											dp[i-1][j-1] + match,
											dp[i-1][j] - 2, 
											dp[i][j-1] - 2
										});

			if(dp[i][j] > best){
				best = dp[i][j];
				bi = i; bj = j;
			}
		}
	}

	string sub1, sub2;
	int i=bi, j=bj;
	while(i>0 && j>0 && dp[i][j]>0){
		int cur = dp[i][j];
		int match = (s1[i-1]==s2[j-1]) ? 3 : -2;

		if(cur == dp[i-1][j-1] + match){
			sub1.push_back(s1[i-1]);
			sub2.push_back(s2[j-1]);
			i--; j--;
		}
		else if(cur == dp[i-1][j] - 2){
			sub1.push_back(s1[i-1]);
			i--;
		}
		else{
			sub2.push_back(s2[j-1]);
			j--;
		}
	}
	reverse(sub1.begin(), sub1.end());
	reverse(sub2.begin(), sub2.end());


	printf("%d\n%s\n%s\n", best, sub1.c_str(), sub2.c_str());
}