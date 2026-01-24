#include <bits/stdc++.h>
#define rnt register int
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define X first
#define Y second
using pii = std::pair<int,int>;
using ll = long long;
using namespace std;

const ll MOD = 1000000007LL;

/*
	n: the length of the string (<2e5)
	c: the number that limits the value of the function (<1e9)
*/

int main(int argc, char **argv){
#ifndef ONLINE_JUDGE
	freopen("data/1075d1.txt", "r", stdin);
#endif
	int T; scanf("%d", &T);
	while(T--) {
		int n;
		ll c;
		scanf("%d%lld", &n,&c);

		char s[200005];
		scanf("%s", s);

		if(s[0] == '0' || s[n-1] == '0'){
			puts("-1"); continue;
		}

		ll ans = 1;
		ll need = c;

		for(int i=1; i<=n-1; i++){
			ll factor;
			if(s[i-1] == '1') factor = 2;
			else factor = (ll)(i-1);

			ans = (ans *(factor%MOD)) % MOD;

			if(need > 1){
				ll g = std::gcd(need, factor);
				need /= g;
			}
		}

		if(need == 1) puts("-1");
		else printf("%lld\n", ans);
	}
}