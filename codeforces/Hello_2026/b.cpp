#include <bits/stdc++.h>
#define rnt register int
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define X first
#define Y second
using pii = std::pair<int,int>;
using ll = long long;
using namespace std;

int N,K;

int main(int argc, char **argv){
#ifndef ONLINE_JUDGE
	freopen("data/d2026b.txt", "r", stdin);
#endif
	int T; scanf("%d", &T);
	while(T--) {	
		scanf("%d%d", &N, &K);

		vector<int> cnt(N+2, 0);
		for(int i=0; i<N; i++){
			int x; scanf("%d", &x);
			if(0 <= x && x <= N+1) cnt[x]++;
		}

		int mex = 0;
		while(mex <= N+1 && cnt[mex] > 0) mex++;
		
		printf("%d\n", min(mex, K-1));
	}
}