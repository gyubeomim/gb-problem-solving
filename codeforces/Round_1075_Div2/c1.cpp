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
	freopen("data/1075c1.txt", "r", stdin);
#endif
	int T; scanf("%d", &T);
	while(T--) {
		int n; scanf("%d", &n);

		int A[200005];
		char used[200005];
		memset(used, 0, sizeof(used));

		A[n]=1;
		used[1]=1;

		for(int i=2; i<=n-1; i++){
			A[i] = 1 ^ i;
			used[A[i]] = 1;
		}

		int missing = 0;
		for(int i=1; i<=n; i++){
			if(!used[i]) {missing = i; break;}
		}

		A[1] = missing;

		for(int i=1; i<=n; i++){
			printf("%d ", A[i]);
		}puts("");

	}
}