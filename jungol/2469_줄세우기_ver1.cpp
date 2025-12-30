// sqrt decomposition
#include <bits/stdc++.h>

const int LM = 100005;
const int MOD = 256;

int N, H[LM], T[LM]; // N: 데이터 개수, H[] : 키 값, T[]: 임시 배열
int B[LM];           // B[] : 블록별 원소 개수 저장
int qrr[LM];         // qrr[i] : i번째 질의에 해당하는 순위, 이를 기반으로 정렬된 배열에서 값을 찾음
int ans[LM];         // ans[i] : i번째 질의에 대한 결과 값

void mergeSort(int* arr, int s, int e) {
	if (s >= e) return;
	int m = (s + e) / 2, i = s, j = m + 1, k = s;
	mergeSort(arr, s, m);
	mergeSort(arr, m + 1, e);

	while (i <= m && j <= e) {
		if (arr[i] <= arr[j]) T[k++] = arr[i++];
		else T[k++] = arr[j++];
	}
	while (i <= m) T[k++] = arr[i++];
	while (j <= e) T[k++] = arr[j++];
	for (i = s; i <= e; ++i) arr[i] = T[i];
}

int query(int cnt) {  // cnt번째 순위 값을 찾기
	int i = 0;
	for (; B[i / MOD] < cnt; i += MOD) cnt -= B[i / MOD];

	// 개별 원소 탐색하여 순위값 찾기
	for (; cnt > 0; ++i) {
		if (H[i] > 0) cnt--;
		if (cnt == 0) return i;
	}
	return -1; // 불가능한 경우
}

int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; ++i) {
		scanf("%d", H + i);
		B[i / MOD] ++;
	}
	for (int i = 0; i < N; ++i) scanf("%d", qrr + i);

	mergeSort(H, 0, N - 1);

	for (int i = N - 1; i >= 0; --i) {
		int ret = query(qrr[i] + 1);
		ans[i] = H[ret];  // 정답 저장

		// 업데이트
		H[ret] = 0;
		B[ret / MOD] --;
	}

	for (int i = 0; i < N; ++i) printf("%d\n", ans[i]);
}
