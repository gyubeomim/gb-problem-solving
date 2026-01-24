#include <bits/stdc++.h>
#define rnt register int
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define X first
#define Y second
using pii = std::pair<int,int>;
using ll = long long;
using namespace std;

/*
	S: the number of minutes the hourglass measures
	K: the number of minutes after which the hourglass flips
	M: the number of minutes after which Vadim will leave for errands
*/

int main(int argc, char **argv){
#ifndef ONLINE_JUDGE
	freopen("data/d1072b.txt", "r", stdin);
#endif
	int T; scanf("%d", &T);
	while(T--) {
		ll S,K,M;
		scanf("%lld%lld%lld", &S, &K, &M);

		ll q = M/K;
		ll rem = M%K;
		
		ll rq;

		if(S <= K) rq = S;
		else       rq = (q%2 == 0 ? S : K);

		ll ans = rq - rem;
		if(ans < 0) ans = 0;

		printf("%lld\n", ans);


	}
}