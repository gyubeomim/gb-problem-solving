/// *** user.cpp ***

//Stable ver
constexpr int LM = 1 << 20;    // 1048576
constexpr int CLM = 1 << 16;   // 65536
constexpr int BIAS = 1 << 15;  // 32768

int N, *sortedA, cnt[CLM];

void countingSort(int arraySize, int *arr) {
	N = arraySize;
	sortedA = arr;

	// preprocess
	for (int i = 0; i < N; i++) arr[i] += BIAS;

	for (int i = 0; i < CLM; i++)cnt[i] = 0;
	for (int i = 0; i < N; i++)cnt[arr[i]]++;
	for (int i = 1; i < CLM; i++)cnt[i] += cnt[i - 1];

	for (int i = N - 1; i >= 0; i--) {
		if (arr[i] & LM)arr[i] ^= LM; //이미 정렬된 경우 마킹 지우기
		else {
			for (int j = --cnt[arr[i]]; i != j; j = --cnt[arr[i]]) {
				int tmp = arr[j];
				arr[j] = arr[i] | LM;  // 자리를 찾았다고 마킹하기
				arr[i] = tmp;
			}
		}
	}

	// postprocess
	for (int i = 0; i < N; i++) arr[i] -= BIAS;
}

int query(int idx) {
	return sortedA[idx];
}
