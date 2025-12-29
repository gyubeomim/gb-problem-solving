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
	freopen("data/d5000.txt", "r", stdin);
#endif
	int T; scanf("%d", &T);
	while(T--) {
		int n; scanf("%d", &n);

		vector<int> A(n), B(n), C(n);

		for(int i=0; i<n; i++) scanf("%d", &A[i]);
		for(int i=0; i<n; i++) scanf("%d", &B[i]);
		for(int i=0; i<n; i++) scanf("%d", &C[i]);

		int cntAB=0;
		for(int s=0; s<n; s++){
			bool ok = true;
			for(int t=0; t<n; t++){
				if(!(A[t] < B[(t+s)%n])) { ok = false; break; }
			}
			if(ok) cntAB++;
		}

		int cntBC=0;
		for(int s=0; s<n; s++){
			bool ok = true;
			for(int t=0; t<n; t++){
				if(!(B[t] < C[(t+s)%n])) { ok = false; break; }
			}
			if(ok) cntBC++;
		}

		// printf("%d %d\n", cntAB, cntBC);
		ll ans = 1ll * n * cntAB * cntBC;

		printf("%lld\n", ans);
	}
}