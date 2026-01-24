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
	freopen("data/d1074c.txt", "r", stdin);
#endif
	int T; scanf("%d", &T);
	while(T--) {
		int N; scanf("%d", &N);

		int A[3005];
		unordered_set<int> S;

		for(int i=0; i<N; i++){
			scanf("%d", &A[i]);
			S.insert(A[i]);
		}

		if(N == 1) { printf("1\n"); continue; }
		if(S.size() == 1) { printf("1\n"); continue; }

		sort(A, A+N);

		int len_seq = 0;
		int cand = 0;
		int x = 0;

		vector<pii> V;

		for(int i=0; i<N; i++){
			if(i == N-1){
				if(len_seq != 0) {
					V.push_back({len_seq+1, cand});
				}
			}
			else{
				if(len_seq == 0 && A[i] == A[i+1]-1){
					cand = A[i];
				}

				if(A[i] == A[i+1]-1){
					len_seq++;
				}else if(A[i] != A[i+1]){
					V.push_back({len_seq+1, cand});
					len_seq = 0;
				}
			}
		}

		// printf("A is ");
		// for(int i=0; i<N; i++){
		// 	printf("%d ", A[i]);
		// }puts("");

		// for(auto v : V){
		// 	printf("seq: %d, cand: %d\n", v.X, v.Y);
		// }

		sort(V.begin(), V.end(), greater<pii>());

		printf("%d\n", V[0].X);

	}
}