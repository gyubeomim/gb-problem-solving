#include <cstdio>
int N, M;

using ll = long long;
constexpr int LM = (int)1004;
ll **S;

int main() {
	scanf("%d", &N);

	S = new ll*[LM];
	for (int i = 0; i < LM; i++) {
		S[i] = new ll[LM];
	}

	S[0][0] = 0;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			int num;
			scanf("%d ", &num);

			if (j - 1 < 0 && i - 1 < 0) {
				S[i][j] =  num;
			}
			else if (j -1 < 0) {
				S[i][j] = S[i-1][j] + num;
			}
			else if (i - 1 < 0) {
				S[i][j] = S[i][j-1] + num;
			}
			else  {
				S[i][j] = S[i-1][j] + S[i][j-1] - S[i-1][j-1] + num;
			}
		}
	}

	scanf("%d", &M);

	ll ans = 0;
	for (int i = 0; i < M; i++) {
		int sr, sc, er, ec;
		scanf("%d %d %d %d", &sr, &sc, &er, &ec);

		ans = S[er][ec] - S[er][sc - 1] - S[sr - 1][ec] + S[sr - 1][sc - 1];
		printf("%lld\n", ans);
	}


	return 0;
}
