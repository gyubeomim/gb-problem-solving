#include <bits/stdc++.h>
#define rnt register int
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define X first
#define Y second
using pii = std::pair<int,int>;
using ll = long long;
using namespace std;

const int LM = 200005;
int A[LM];

int main(int argc, char **argv){
	#ifndef ONLINE_JUDGE
		freopen("data/d6969.txt", "r", stdin);
	#endif

		int T; scanf("%d", &T);
		while(T--) {
			int N; scanf("%d", &N);

			memset(A,0,sizeof(A));

			for(int i=0; i<N; i++){
				int a; scanf("%d", &a);
				A[i] = a;
			}

			int sum = 0;

			for(int i=0;i<N-1;i++) 
				sum += abs(A[i] - A[i+1]);

			int best = max(abs(A[0]-A[1]), abs(A[N-2]-A[N-1]));

			for(int i=1; i<N-1; i++){
				int gain = abs(A[i]-A[i-1]) + abs(A[i]-A[i+1]) - abs(A[i-1]-A[i+1]);
				best = max(gain, best);
			}

			printf("%d\n", sum - best);
		}
}