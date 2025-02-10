// sqrt decomposition : [s, e) , update() 함수 구현
#include <cstdio>

const int LM = 50005;
const int MOD = 256;   // sqrt(50000) = 223.606
int N, Q;
int A[LM];             // 입력 데이터
int B[MOD + 1];        // 각 블록별 최대값

inline int min(int a, int b) { return a < b ? a : b; }
inline int max(int a, int b) { return a > b ? a : b; }

void update(int idx, int newVal) {
	int bn = idx / MOD;                       // idx가 속한 블록 번호
	int sn = bn * MOD, en = min(sn + MOD, N); // idx가 속한 블록의 시작과 끝 인덱스
	A[idx] = B[bn] = newVal;
	for (int i = sn; i < en; ++i)             // 블록 내 최대값 갱신
		B[bn] = max(B[bn], A[i]);
}

int query(int s, int e) {   // 구간 [s, e)에서 최대값 찾기
	int maxValue = A[s];
	// 1. 왼쪽 끝부분에서 블록 경계를 맞추기 위해 개별 비교
	while (s < e && s % MOD)
		maxValue = max(maxValue, A[s++]);

	// 2. 오른쪽 끝부분에서 블록 경계를 맞추기 위해 개별 비교
	while (s < e && e % MOD)
		maxValue = max(maxValue, A[--e]);

	// 3. 블록 단위로 최대값 비교
	for (s /= MOD, e /= MOD; s < e; s++)
		maxValue = max(maxValue, B[s]);

	return maxValue;
}

int main() {
	int s, e;
	scanf("%d %d", &N, &Q);
	for (int i = 0; i < N; ++i) {
		scanf("%d", A + i);
		update(i, A[i]);
	}

	for (int i = 0; i < Q; ++i) {
		scanf("%d %d", &s, &e);
		printf("%d\n", query(s - 1, e));
	}
}

