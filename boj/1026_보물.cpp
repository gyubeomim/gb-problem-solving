#include <bits/stdc++.h>
using namespace std;

int A[105], B[105];
int N;

int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++)scanf("%d", &A[i]);
	for (int i = 0; i < N; i++)scanf("%d", &B[i]);

	sort(A, A + N);
	sort(B, B + N);

	int ans = 0;
	for (int i = 0; i < N; i++)
		ans += A[i] * B[N - 1 - i];
	printf("%d\n", ans);
}

