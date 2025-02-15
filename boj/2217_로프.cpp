#include <bits/stdc++.h>
using namespace std;

int N;
int W[100005];

int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) scanf("%d", &W[i]);
	sort(W, W + N);

	int ans = 0;
	for (int i = 1; i <= N; i++)
		ans = max(ans, W[N-i] * i);
	printf("%d\n", ans);
}

