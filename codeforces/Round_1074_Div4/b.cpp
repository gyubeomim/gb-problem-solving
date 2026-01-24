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
	freopen("data/d1074b.txt", "r", stdin);
#endif
	int T; scanf("%d", &T);
	while(T--) {
		int n; scanf("%d", &n);

		int A[55];
		int maxn = 0;
		for(int i=0 ;i<n;i++){
			scanf("%d", &A[i]);
			maxn = max(maxn, A[i]);
		}

		printf("%d\n", maxn * n);

	}
}