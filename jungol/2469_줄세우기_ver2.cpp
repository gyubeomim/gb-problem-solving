// 세그먼트 트리
#include <cstdio>

const int LM = 100005;
const int TLM = 1 << 18;  // 262144
const int SHIFT = 8;
const int MOD = 1 << SHIFT;
const int MASK = MOD - 1;

int N, H[LM], T[LM]; // N: 데이터 개수, H[] : 키 값, T[]: 임시 배열
int tree[TLM];       // tree[] : 세그먼트 트리
int qrr[LM];         // qrr[i] : i번째 질의에 해당하는 순위, 이를 기반으로 정렬된 배열에서 값을 찾음
int ans[LM];         // ans[i] : i번째 질의에 대한 결과 값
int cnt[MOD];

void radixSort() {
	int* ap = H, * bp = T, * tp;
	int i, j;
	for (i = 0; i < 4 * SHIFT; i += SHIFT) {
		for (j = 0; j < MOD; ++j) cnt[j] = 0;                  // 0. cnt 배열 초기화
		for (j = 1; j <= N; ++j) cnt[(ap[j] >> i) & MASK] ++;  // 1. 카운팅
		for (j = 1; j < MOD; ++j) cnt[j] += cnt[j - 1];        // 2. 누적 합 계산
		for (j = N; j > 0; --j) {                              // 3. 기수 정렬 수행
			bp[cnt[(ap[j] >> i) & MASK]--] = ap[j];
		}
		tp = ap, ap = bp, bp = tp;
	}
}

void buildTree(int node, int s, int e) {  // 세그먼트 트리 초기화
	if (s >= e) {
		tree[node] = 1;
		return;
	}
	int m = (s + e) / 2, lch = node * 2, rch = lch + 1;
	buildTree(lch, s, m);
	buildTree(rch, m + 1, e);
	tree[node] = tree[lch] + tree[rch];
}

int query(int node, int s, int e, int cnt) {
	tree[node] --;
	if (s >= e) {
		return H[s];
	}
	int m = (s + e) / 2, lch = node * 2, rch = lch + 1;
	if (tree[lch] > cnt) return query(lch, s, m, cnt);
	return query(rch, m + 1, e, cnt - tree[lch]);
}

int main() {
	scanf("%d", &N);
	for (int i = 1; i <= N; ++i) scanf("%d", H + i);
	for (int i = 0; i < N; ++i) scanf("%d", qrr + i);
	radixSort();
	buildTree(1, 1, N);

	for (int i = N - 1; i >= 0; --i) {
		ans[i] = query(1, 1, N, qrr[i]);
	}

	for (int i = 0; i < N; ++i) printf("%d\n", ans[i]);
}
