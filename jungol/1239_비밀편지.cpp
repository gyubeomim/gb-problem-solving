#include <cstdio>

int code[] = { 0, 0x0f, 0b010011, 0b011100, 0b100110, 0b101001, 0b110101, 0b111010 };
char ans[12];

int getChar(int d) {
	// 오류 검출 및 문자 변환
	for (int i = 0; i < 8; ++i) {
		int bit = d ^ code[i];       // 입력값과 코드값을 XOR 연산하여 차이 확인
		if ((bit & (bit - 1)) == 0) { // 한 비트 차이만 있는 경우 유효한 문자로 판별
			return i;
		}
	}
	return -1;   // 변환 실패
}

int main() {
	int N, d, a;
	scanf("%d", &N);
	for (int i = 0; i < N; ++i) {
		// 6비트 입력을 하나의 정수로 변환
		d = 0;
		for (int j = 0; j < 6; ++j) {
			scanf("%1d", &a);
			d = d * 2 + a; // Horner's method 활용
		}

		// 변환된 정수를 문자로 매핑
		int rv = getChar(d); // -1이면 오류, 0 ~ 7이면 정상
		if (rv < 0) { // 오류 발생 시 위치 출력 후 종료
			printf("%d\n", i + 1);
			return 0;
		}
		// rv: 0 ~ 7
		ans[i] = rv + 'A'; // 변환된 문자 저장
	}
	puts(ans); // 결과 문자열 출력
}
