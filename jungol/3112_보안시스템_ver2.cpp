// bitwise + DP
const int LM = 920;
int N, entry[LM + 5];
int popCnt[4096];  // popCnt[i]: i의 1의 개수를 저장

int ffs(int n) {
	for (int i = 0; i < 12; ++i)
		if ((n >> i) & 1) return i;
	return 0;
}

int encoding(int x, int y) {
	for (int i = 1; N < LM; ++i) { // DP 기반으로 popCnt 값 저장
		popCnt[i] = popCnt[i / 2] + (i & 1);
		if (popCnt[i] == 6)
			entry[++N] = i;
	}
	int k = ffs((entry[x] ^ entry[y]) & entry[x]);
	return k + 1;
}

char answer(int p, int k) {
	int ret = (entry[p] >> (k - 1)) & 1;
	return ret ? 'x' : 'y';
}
