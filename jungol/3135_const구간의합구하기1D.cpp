#include <cstdio>
using ll = long long;
int N;
int M;
ll S[1000001];

int main() {
	scanf("%d", &N);

	S[0] = 0;

	for (int i = 1; i <= N; i++) {
		int num;
		scanf("%d ", &num);

		S[i] = num + S[i-1];
	}

	scanf("%d", &M);
	for (int i = 0; i < M; i++) {
		int s=0, e=0;
		scanf("%d %d", &s, &e);
		printf("%lld\n", S[e] - S[s-1]);
	}


	return 0;
}
