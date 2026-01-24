#include <bits/stdc++.h>
#define rnt register int
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define X first
#define Y second
using pii = std::pair<int,int>;
using ll = long long;
using namespace std;

/*
	n: number of types of jumps the frog can make (<100,000)
	x: its final target (10^18)
*/

int main(int argc, char **argv){
#ifndef ONLINE_JUDGE
	freopen("data/1075b.txt", "r", stdin);
#endif

	int T; scanf("%d", &T);
	while(T--) {
			ll n,x; scanf("%lld%lld", &n, &x);
			
			ll A[100005], B[100005], C[100005];

			ll F = 0;
			ll G = 0;

			for(int i=0;i<n;i++){
				scanf("%lld%lld%lld", &A[i], &B[i], &C[i]);
				F += A[i] * (B[i]-1);
				G = max(G, A[i]*B[i] - C[i]);
			}

			if(F >= x) printf("0\n");
			else{
				if(G <= 0) printf("-1\n");
				else{
					ll R = x-F;
					ll ans = (R+G-1) / G;
					printf("%lld\n", ans);
				}
			}
	}
}