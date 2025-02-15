#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;
using pii = pair<int, int>;

int N;
pii S[1000005];    // [ end time, start time ]

int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d%d", &S[i].Y, &S[i].X);
	}
	sort(S, S + N);

	int ans = 0;
	int t = 0;

	for (int i = 0; i < N; i++) {
		int& start = S[i].Y;
		int& end = S[i].X;

		if (t > start) continue;
		ans++;
		t = end;
	}

	printf("%d\n", ans);
}

