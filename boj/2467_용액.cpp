#include <cstdio>
#include <algorithm>

int O[100001];

int main() {
	int N;
	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		int num;
		scanf("%d ", &num);
		
		O[i] = num; // original
	}

	
	std::sort(O, O + N, [](const int& a, const int &b) {
		int c = abs(a);
		int d = abs(b);
		return c < d;
	});



	int ans = 1100000000;
	int candA, candB;
	for (int i = 0; i < N-1; i++) {
			int num = abs(O[i+1] + O[i]);
			if (num < ans) {
				candA = O[i] < O[i + 1] ? O[i] : O[i + 1];
				candB = O[i] > O[i + 1] ? O[i] : O[i + 1];

				ans = num;
			}
	}

	printf("%d %d", candA, candB);

	return 0;
}
