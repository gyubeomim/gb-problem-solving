// 8자리 압축, Duff's device 사용
#include <cstdio>
#define rnt register int

const int BASE = 100'000'000;   // 8자리 단위 기준
const int LM = 205;
const int NLM = LM / 8 + 2;

inline int max(int a, int b) { return a > b ? a : b; }
inline int strlen(char* s, int i = 0) {
	while (s[i]) ++i;
	return i;
}
struct Bigint {
	int num[NLM];
	int sign, len;
	Bigint() { init(); }
	Bigint(char* s) {
		init();                         // 0으로 초기화
		if (s[0] == '-') sign = 1, ++s; // 음수 처리
		int slen = strlen(s);           // '-' 제외한 길이 계산
		len = (slen + 7) / 8;           // 자릿수 계산
		rnt d = 0;
		rnt i = len - 1;
		// Duff's device : 루프 전개 사용
		// https://johngrib.github.io/wiki/duff-s-device/
		switch ((slen - 1) % 8) {          // 루프 전개 최적화
			case 7:
				do {
					d = d * 10 + *s++ - '0';  // 숫자 변환
					case 6: d = d * 10 + *s++ - '0';
					case 5: d = d * 10 + *s++ - '0';
					case 4: d = d * 10 + *s++ - '0';
					case 3: d = d * 10 + *s++ - '0';
					case 2: d = d * 10 + *s++ - '0';
					case 1: d = d * 10 + *s++ - '0';
					case 0: d = d * 10 + *s++ - '0';
									num[i--] = d, d = 0;
				} while (i > -1);
		}
	}
	void init() {    // 0으로 초기화
		sign = 0, len = 1;
		for (rnt i = 0; i < NLM; ++i) num[i] = 0;
	}

	bool isZero() { return len == 1 && num[0] == 0; }
	int arrCmp(int* ap, int alen, int* bp, int blen) {
		if (alen != blen) return alen - blen;
		rnt i = alen - 1; // 큰 자리부터 비교
		for (; i > 0 && ap[i] == bp[i]; --i);
		return ap[i] - bp[i];
	}

	int plus(int* ap, int* bp, int len) {
		for (rnt i = 0; i < len; ++i) {
			ap[i] += bp[i];            // 덧셈 수행
			ap[i + 1] += ap[i] / BASE; // 자리 올림
			ap[i] %= BASE;             // 자리수 유지
		}
		return len + (ap[len] > 0);
	}
	int minus(int* tg, int* ap, int* bp, int len) {
		// ap[]에서 bp[]를 빼고 결과를 tg[]에 저장
		for (rnt i = 0; i < len; ++i) {
			tg[i] = ap[i] - bp[i];
			if (tg[i] < 0)  // 자리 내림 처리
				tg[i] += BASE, ap[i + 1] --;
		}
		for (; len > 0 && tg[len] == 0; --len); // 앞쪽 0 제거
		return len + 1;     // 최종 자리 계산
	}
	void add(Bigint& r) {    // 덧셈 연산 수행
		if (sign == r.sign) // 같은 부호일 때 덧셈
			len = plus(num, r.num, max(len, r.len));
		else {              // 부호가 다르면 비교 후 뺄셈 수행
			int cmp = arrCmp(num, len, r.num, r.len);
			if (cmp < 0) len = minus(num, r.num, num, r.len), sign = r.sign;
			else if (cmp > 0) len = minus(num, num, r.num, len);
			else init();    // 값이 0이 되면 초기화
		}
	}
	void subtract(Bigint r) { // (A - B) 연산 수행
		r.sign ^= 1, add(r);  // 부호 반전 후 add() 수행
	}
	void toString(char* s) {   // 결과를 문자열로 변환
		rnt i = 0, j, k = 0, n;
		for (; i < len; ++i) {  // 각 자리수를 문자열로 변환
			n = num[i];
			for (j = 0; j < 8; ++j, n /= 10)
				s[k++] = n % 10 + '0';
		}
		s[k] = '0';                                 // 문자열 종료
		for (; k > 0 && s[k] == '0'; --k) s[k] = 0; // 앞쪽 0 제거

		for (j = 0; j < k; ++j, --k) {              // 문자열 반전
			char t = s[j]; s[j] = s[k]; s[k] = t;
		}
	}
}sumRet, subRet, operand;

char as[LM], bs[LM];

int main() {
	while (scanf("%s %s", &as, &bs)) {
		sumRet = subRet = Bigint(as);
		operand = Bigint(bs);
		if (sumRet.isZero() && operand.isZero()) break;
		sumRet.add(operand);
		subRet.subtract(operand);

		sumRet.toString(as);
		subRet.toString(bs);
		puts(as);
		puts(bs);
	}
}

