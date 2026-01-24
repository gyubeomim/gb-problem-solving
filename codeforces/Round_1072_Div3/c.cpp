#include <bits/stdc++.h>
#define rnt register int
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define X first
#define Y second
using pii = std::pair<int,int>;
using ll = long long;
using namespace std;

/*
	10 --> [5,5] --> [2,3],[2,3]
	11 --> [5,6]
	21 --> [10, 11] --> [5,5], [5,6] --> [2,3],[2,3],[2,3],[3,3]
	
	1'000'000'000 --> 500'000'000 --> 250'000'000

*/

int main(int argc, char **argv){
#ifndef ONLINE_JUDGE
	freopen("data/d1072c.txt", "r", stdin);
#endif
	int T; scanf("%d", &T);
	while(T--) {
		ll N, K; scanf("%lld%lld", &N,&K);

		if(K > N) { 
			printf("-1\n"); 
			continue; 
		}

		ll a = N;
		ll b = N;
		int d = 0;
		int ans = -1;

		while(a > 0){
			if(K==a || K==b) {
				ans = d;
				break;
			}
			a = a/2;      // floor(n/2^d)
			b = (b+1)/2;  // ceil(n/2^d)
			d++;
		}

		printf("%d\n", ans);
	}
}