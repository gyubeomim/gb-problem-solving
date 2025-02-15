const int LM = 920;
int N, entry[LM + 5];

int popCount(int val) {
	int pc = 0;
	while (val) {
		pc += val & 1;
		val /= 2;
	}
	return pc;
}

int ffs(int bit) {
	for (int i = 0; i < 12; ++i) {
		if ((bit >> i) & 1)
			return i + 1;
	}
	return 0;
}

int encoding(int x, int y) {
	// 6비트가 설정된 값을 저장
	for (int i = 63; N < LM; ++i) {
		if (popCount(i) == 6)
			entry[++N] = i;
	}
	int rv = ffs((entry[x] ^ entry[y]) & entry[x]);
	return rv;
}

char answer(int p, int k) {
	if ((entry[p] >> (k - 1)) & 1) return 'x';
	return 'y';
}
