#include <cstdio>
#include <cmath>

using ll=long long;
constexpr int LM = 100005;

ll A[LM];

int main() {
	int N;
	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		scanf("%lld", &A[i]);
	}

	int l=0, r=N-1;

	int res = abs(A[l] + A[r]);
	ll ansA = A[l];
	ll ansB = A[r];

	while(l<r) {
		int tmp = A[l]+A[r];

		if(abs(tmp) < res) {
			res = abs(tmp);
			ansA = A[l];
			ansB = A[r];
		}

		if(tmp < 0) l++;
		else r--;

	}

	printf("%lld %lld", ansA, ansB);

	return 0;
}

