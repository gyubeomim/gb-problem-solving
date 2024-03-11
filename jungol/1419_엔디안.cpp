#include <cstdio>

unsigned int N, ans ;

void swap(char &a, char&b) {
	char t = a; a = b; b = t;
}

void method0() {
	unsigned int B = 0b11111111;
	unsigned int sum = 0;

	int cnt = 0;
	while (N) {
		sum += (N & B) << (24 - 8 * cnt);
		N = N >> 8;
		cnt++;
	}
	printf("%u", sum);
}

void method1() {
	for (int i = 0; i < 32; i += 8) {
		ans = (ans << 8) | ((N >> i) & 255);
		// unsigned int div =  1<<i;
		// ans = ans*256 + N/div%256;
	}
	printf("%u", ans);
}

void method2() {
	ans = (N << 24) | ((N << 8) & 0x00ff0000) | ((N >> 8) & 0x0000ff00) | (N >> 24);
	printf("%u", ans);
}

void method3() {
	union {
		unsigned int A;
		char str[4];
	};
	A = N;
	for (int i = 0; i < 4; i++) {
		ans = (ans << 8) | str[i];
	}
	printf("%u", ans);
}

void method4() {
	char*str = (char*)&N;

	for (int i = 0; i < 4; i++) {
		ans = (ans << 8) | str[i];
	}
	printf("%u", ans);
}

void method5() {
	char *str = (char*)&N;

	swap(str[0], str[3]);
	swap(str[1], str[2]);
	ans = N;
	printf("%u", ans);
}

int main() {
	scanf("%u", &N);

	//method0();
	//method1();
	method2();
	//method3();
	//method4();
	//method5();



	return 0;
}
