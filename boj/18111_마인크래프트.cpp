#include <cstdio>

constexpr int LM = 505;
int R, C, N, H[LM * LM];
int inven, ansTime, ansHeight;

int abs(int a) { return a < 0 ? -a : a; }
bool Bruteforce(int th) {
	int costTime = 0, tcnt = inven, i;
	for (i = 1; i <= N; ++i) {
		int diff = abs(th - H[i]);
		if (H[i] > th) {  // 인벤으로 가져가기
			costTime += diff * 2;
			tcnt += diff;
		}
		else {            // 인벤에서 가져오기
			costTime += diff;
			tcnt -= diff;
		}
	}
	if (tcnt < 0) return 0;
	if (ansTime >= costTime) 
		ansTime = costTime, ansHeight = th;
	return 1;
}

int main() {
#ifdef _WIN32
	freopen("13.txt", "r", stdin);
#endif // _WIN32
	scanf("%d %d %d", &R, &C, &inven);
	N = R * C, ansTime = 1 << 30;
	int i;
	for (i = 1; i <= N; ++i) scanf("%d", H + i);

	for (i = 0; i < 257; ++i) {
		if (Bruteforce(i) == 0) break;
	}
	printf("%d %d\n", ansTime, ansHeight);
	return 0;
}
