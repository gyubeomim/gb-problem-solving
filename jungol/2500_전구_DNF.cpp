#include <bits/stdc++.h>
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define X first
#define Y second
using pii = std::pair<int,int>;
using ll = long long;
using namespace std;

int main(int argc, char **argv){
#ifndef ONLINE_JUDGE
	freopen("data/2500.txt", "r", stdin);
#endif
	int N,K; scanf("%d%d", &N, &K);

	vector<int> a(N),b;
	for(int i=0; i<N; i++){
		scanf("%d", &a[i]);
	}

	for(int x : a){
		if(b.empty() || b.back() != x) b.push_back(x);
	}

	int M = (int)b.size();
	vector<vector<int>> dp(M, vector<int>(M,0));

	for(int len=2; len<=N; len++){
		for(int i=0; i+len-1<N; i++){
			int j = i+len-1;
			dp[i][j] = 
		}
	}
}