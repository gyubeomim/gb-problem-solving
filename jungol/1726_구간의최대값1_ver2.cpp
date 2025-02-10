// 세그먼트 트리 : 업데이트 및 쿼리
#include <cstdio>

const int LM = 50005;
const int TLM = 1 << 17; // 131072

int N, Q;
int tree[TLM];

int max(int a, int b) { return a > b ? a : b; }

// 세그먼트 트리 업데이트 함수
void update(int node, int s, int e, int tg, int val) {
	if (s >= e) { // 리프 노드에 도달했을 때 값 업데이트
		tree[node] = val;
		return;
	}
	int m = (s + e) / 2, lch = node * 2, rch = lch + 1;
	if (tg <= m) update(lch, s, m, tg, val);  // 왼쪽 자식 노드 업데이트
	else update(rch, m + 1, e, tg, val);      // 오른쪽 자식 노드 업데이트
	tree[node] = max(tree[lch], tree[rch]);   // 부모 노드는 자식 노드 중 최댓값을 저장
}

// 구간 내 최댓값을 찾는 쿼리 함수
int query(int node, int s, int e, int qs, int qe) {
	if (e < qs || qe < s) return -1;           // 쿼리 범위 밖이면 무효값 반환
	if (qs <= s && e <= qe) return tree[node]; // 현재 구간이 완전히 쿼리 범위에 포함되면 반환
	int m = (s + e) / 2, lch = node * 2, rch = lch + 1;
	int leftMax = query(lch, s, m, qs, qe);    // 왼쪽 서브트리 탐색
	int rightMax = query(rch, m + 1, e, qs, qe); // 오른쪽 서브트리 탐색
	return max(leftMax, rightMax);             // 두 값 중 최댓값 반환
}

int main() {
	scanf("%d %d", &N, &Q);
	int i, s, e, val;

	// 초기 데이터 입력 및 트리 업데이트
	for (i = 1; i <= N; ++i) {
		scanf("%d", &val);
		update(1, 1, N, i, val);
	}

	// 쿼리 처리
	for (i = 0; i < Q; ++i) {
		scanf("%d %d", &s, &e);
		printf("%d\n", query(1, 1, N, s, e));
	}
}

