#include <bits/stdc++.h>
#define rnt register int
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define X first
#define Y second
using pii = std::pair<int,int>;
using ll = long long;
using namespace std;

ll d(ll v){
	ll s = 0;
	while(v>0) { 
		s+=(v%10);
		v/=10;
	}
	return s;
}

int main(int argc, char **argv){
#ifndef ONLINE_JUDGE
	freopen("data/1079a.txt", "r", stdin);
#endif
	int T; scanf("%d", &T);
	while(T--) {
		int x; scanf("%d", &x);

		int ans = 0;
		for(ll y=x; y<=x+90; y++){
			if(y - d(y) == x) ans++;
		}
		printf("%d\n", ans);
	}
}