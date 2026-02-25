#include <bits/stdc++.h>
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define X first
#define Y second
using pii = std::pair<int,int>;
using ll = long long;
using namespace std;

int main(int argc, char **argv){
#ifndef ONLINE_JUDGE
	freopen("data/h2602.txt", "r", stdin);
#endif
	int Q; scanf("%d", &Q);
	while(Q--) {
		int N,x; scanf("%d%d",&N,&x);

		int A[65];
		memset(A,0,sizeof(A));

		ll sum = 0;
		for(int i=0;i<N;i++){
			scanf("%d", &A[i]);
			sum += (1<<i) * A[i];
		}

		ll mx = sum / x;

		queue<int> Q;
		for(int i=N-1; i>=0; i--){
			for(int j=0; j<A[i]; j++){
				int val = (1<<i);
				Q.push(val);
			}
		}

		// printf("Q "); while(!Q.empty()) { printf("%d ", Q.front()); Q.pop(); } puts("");

		int ans = 0;

		while(1){
			ll tot = 0;
			int cnt = 0;
			queue<int> tmp = Q;
			ll target = mx;

			while(!tmp.empty()){
				
			}

		}

	}
}