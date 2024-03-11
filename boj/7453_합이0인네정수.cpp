#include <cstdio>

#define rnt register int
using ll = long long;
constexpr int LM = 4005;

ll BIAS = 1<<28;

ll A[LM], B[LM], C[LM], D[LM];

ll AB[LM*LM], CD[LM*LM];

ll trr[LM*LM];

void MergeSort(ll arr[], int s, int e) {
	if (s >= e) return;
	int m = (s + e) / 2;
	int i = s, j = m + 1, k = s;

	MergeSort(arr, s, m);
	MergeSort(arr, m + 1, e);

	while (i <= m && j <= e) {
		if (arr[i] <= arr[j]) trr[k++] = arr[i++];
		else trr[k++] = arr[j++];
	}
	while (i <= m) trr[k++] = arr[i++];
	while (j <= e) trr[k++] = arr[j++];

	for (i = s; i <= e; i++) arr[i] = trr[i];
}

ll min(const ll &a, const ll &b) {
	return a < b ? a : b;
}

int main() {
	int N;
	scanf("%d", &N);

	int NN = N * N;

	for (int i = 0; i < N; i++) {
		ll a, b, c, d;
		scanf("%lld %lld %lld %lld", &a, &b, &c, &d);
		A[i] = a;
		B[i] = b;
		C[i] = c;
		D[i] = d;
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			AB[i*N+j] = A[i] + B[j] + BIAS;
			CD[i*N+j] = -(C[i] + D[j]) + BIAS;
		}
	}

	MergeSort(AB, 0, NN-1);
	MergeSort(CD, 0, NN-1);

	ll ab = 0, cd = 0;
	ll ans = 0;

	for (int i = 0, j = 0; i < NN && j < NN;) {
		if (AB[i] < CD[j]) ++i;
		else if (AB[i] > CD[j]) ++j;
		else {
			rnt tg = AB[i], abCnt = 0, cdCnt = 0;
			for (; i < NN && AB[i] == tg; ++i) abCnt++;
			for (; j < NN && CD[j] == tg; ++j) cdCnt++;
			ans += (ll)abCnt*cdCnt;
		}
	}

	printf("%lld\n", ans);

	return 0;
}

