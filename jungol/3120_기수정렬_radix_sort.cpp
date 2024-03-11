/// ***** user.cpp *****
#define rnt register int 
constexpr int LM = (int)25e6;
constexpr int EXP = 8;
constexpr int MOD = 1 << 8;
constexpr int MASK = MOD - 1;
constexpr int BIAS = 1 << 31;

int N;
int brr[LM + 1], cnt[MOD];
int *ap, *bp, *tp;


/// 배열 A와 원소의 개수 N을 전달받아 초기화한다.
void initUser(int nSize, int *arr) {
	N = nSize, ap = brr, bp = arr;
	rnt i, j;

	//preprocess
	for (i = 0; i < N; i++) ap[i] = bp[i] ^ BIAS;
	//for (i = 0; i < N; i++) ap[i] = bp[i] + BIAS;
	//for (i = 0; i < N; i++) ap[i] = bp[i] - BIAS;

	// radix sort
	for (i = 0; i < 30; i += EXP) {
		for (j = 0; j < MOD; j++)cnt[j] = 0;
		for (j = 0; j < N; j++) cnt[(ap[j] >> i) & MASK]++;
		for (j = 1; j < MOD; j++)cnt[j] += cnt[j - 1];
		for (j = N - 1; j >= 0; j--)
			bp[--cnt[(ap[j] >> i)&MASK]] = ap[j];

		tp = ap, ap = bp, bp = tp;
	}

	// postprocess
	for (i = 0; i < N; i++)ap[i] = ap[i] ^ BIAS;
	//for (i = 0; i < N; i++)ap[i] = ap[i] + BIAS;
	//for (i = 0; i < N; i++)ap[i] = ap[i] - BIAS;
}

/// " A 배열을 오름차순 정렬했을때 nth번째 값은 얼마인가? "
/// 라는 질의에 실시간으로 답하는 함수이다.
/// nth 번째 이므로 0_base배열이라면  nth-1 인덱스의 값을 반환한다. !!!
int query(int nth) {
	return ap[nth - 1];
}
