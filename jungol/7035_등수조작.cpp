#include <bits/stdc++.h>
using namespace std;

constexpr int LM = 100005;
constexpr int MOD = 320;

int N, Q;	
int S[LM];

int A[LM];	// A[score] = cnt
int B[MOD];

void update(int sid, int val) {
	A[S[sid]]--;
	B[S[sid] / MOD]--;

	S[sid] = val;

	A[S[sid]]++;
	B[S[sid] / MOD]++;
}

void query(int l, int r) {
	int sum = 0;

	while (l < r && l%MOD) sum += A[l++];      // l
	
	while (l < r && (r+1)%MOD) sum += A[r--];      // r

	for (; l < r; l+=MOD) sum += B[l/MOD];    // group

	printf("%d\n", N - sum + 1);
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("data/d7979.txt", "r", stdin);
#endif

	scanf("%d%d", &N, &Q);
	for (int i = 1; i <= N; i++) {
		scanf("%d", S + i);
		A[S[i]]++;
		B[S[i] / MOD]++;
	}

	while (Q--) {
		int cmd, a, b;
		scanf("%d%d", &cmd, &a);
		if (cmd == 1) {
			query(0, S[a]);
		}
		else {
			scanf("%d", &b);
			update(a, b);
		}
	}

	return 0;
}