#include <bits/stdc++.h>
#define rnt register int
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define X first
#define Y second
using pii = std::pair<int,int>;
using ll = long long;
using namespace std;

int main(int argc, char **argv){
#ifndef ONLINE_JUDGE
	freopen("data/d1121.txt", "r", stdin);
#endif
	int T; scanf("%d", &T);

	while(T--) {
		int n; scanf("%d", &n);

		int ans = 0;
		int mx = 0;

		for(int i=0; i<n; i++){
			int x; scanf("%d", &x);
			if(x < mx) ans++;
			else mx = x;
		}
		printf("%d\n", ans);
	}
}