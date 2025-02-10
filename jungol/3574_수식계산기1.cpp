#include <cstdio>

int main() {
	int ret = 0, a;
	char ch, op = '+';
	while (true) {
		ch = 0;
		scanf("%d", &a);
		ret += op == '+' ? a : -a;

		op = 0;
		scanf("%c", &op);
		if (op != '+' && op != '-')
			break;
	}
	printf("%d\n", ret);
}
