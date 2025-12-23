
#include <cstdio>

int main() {
	char ch[10];
	scanf("%s", ch);

	int ans = 0;
	for (int i = 1; i < 8; i++) {
		int digit = ch[i] - '0';
		ans = ans * 2  + digit;
	}

	if (ch[0] == '1') ans -= 128;
	printf("%d\n", ans);
}
