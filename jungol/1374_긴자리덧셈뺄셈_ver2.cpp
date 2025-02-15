// BigInt 클래스 : 1자리 정수
#include <cstdio>

const int LM = 205;
const int BASE = 10;

char as[LM], bs[LM];
int strlen(const char* s, int len = 0) {
	for (; s[len]; ++len);
	return len;
}

struct BigInt {
	int num[LM];
	int len, sign;
	// 기본 생성자: 0으로 초기화
	void init() {
		for (int i = 0; i < LM; ++i) num[i] = 0;
		len = 1;
		sign = 0;  // 0: 양수 또는 0, 1: 음수
	}
	BigInt() { init(); }
	BigInt(const char* s) {
		init();
		if (s[0] == '-')
			++s, sign = 1;
		len = strlen(s);
		for (int i = 0; i < len; ++i)
			num[len - i - 1] = s[i] - '0';
	}
	bool isZero() { return len == 1 && num[0] == 0; }
	inline int max(int a, int b) { return a > b ? a : b; }
	inline int min(int a, int b) { return a < b ? a : b; }
	int arrcmp(int* ap, int alen, int* bp, int blen) {
		if (alen != blen) return alen - blen;  // 1단계: 자릿수가 다르면 길이 비교
		int i = alen - 1;                      // 2단계: 자릿수가 같으면 큰 자리부터 비교
		for (; i > 0 && ap[i] == bp[i]; --i);  //        큰 자리부터 비교하여 다르면 차이를 반환
		return ap[i] - bp[i];                  // 음수(ap<bp), 0(ap==bp), 양수(ap>bp)
	}

	int plus(int* tg, int* ap, int* bp, int len) {
		for (int i = 0; i < len; ++i) {
			tg[i] = ap[i] + bp[i];
			tg[i + 1] += tg[i] / BASE;  // 자리 올림
			tg[i] %= BASE;
		}
		return len + (tg[len] > 0);
	}

	int minus(int* tg, int* ap, int* bp, int len) {
		for (int i = 0; i < len; ++i) {
			tg[i] = ap[i] - bp[i];
			if (tg[i] < 0)
				ap[i + 1]--, tg[i] += BASE;
		}
		int i = len - 1;
		for (; i > 0 && tg[i] == 0; --i);  // 앞쪽의 0 제거
		return i + 1;
	}

	void add(BigInt& b) {  // 덧셈 연산 수행
		if (sign == b.sign) len = plus(num, num, b.num, max(len, b.len));
		else {
			int cmp = arrcmp(num, len, b.num, b.len);
			if (cmp < 0) len = minus(num, b.num, num, b.len);
			else if (cmp > 0) len = minus(num, num, b.num, len);
			else init();   // 값이 0이 되면 초기화
		}
	}

	void subtract(BigInt b) {
		b.sign ^= 1, add(b);
	}

	void toString(char* ret) {
		for (int i = 0; i < len; ++i)
			ret[i] = num[len - i - 1] + '0';
		ret[len] = 0;  // 문자열 끝 표시 (센티넬 값)
	}
} sum, diff, operand;
// 연산: sum += operand
// 차이: diff = abs(diff - operand)

int main() {
	while (scanf("%s %s", as, bs)) {
		sum = diff = BigInt(as);
		operand = BigInt(bs);
		if (sum.isZero() && operand.isZero()) break;
		sum.add(operand);
		diff.subtract(operand);
		sum.toString(as);
		diff.toString(bs);
		puts(as);
		puts(bs);
	}
}

