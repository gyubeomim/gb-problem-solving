#include <bits/stdc++.h>
#define rnt register int
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define X first
#define Y second
using pii = std::pair<int,int>;
using ll = long long;
using namespace std;

/*
 1 - min(a_l, a_r)
-->  0이 하나라도 있으면  --> 1
-->  0이 하나도 없으면   -->  0

0 1 --> 1
0 1 0 --> 1
1 1 --> 0
1 1 1 1 --> 0
1 1 1 0 --> 1

1 1 0 --> 1 1 --> 0
1 0 1 --> 1 1 --> 0
1 1 1 --> 0

*/

const int LM = 105;

int N;
int A[LM];


int main(int argc, char **argv){
#ifndef ONLINE_JUDGE
	freopen("data/d2026a.txt", "r", stdin);
#endif
	int T; scanf("%d", &T);
	while(T--) {
		scanf("%d", &N);
		for(int i=0;i<N;i++){
			scanf("%d", &A[i]);
		}

		if(A[0] == 0 && A[N-1] == 0) printf("Bob\n");
		else printf("Alice\n");
	}
}