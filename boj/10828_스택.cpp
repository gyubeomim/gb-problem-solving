#include <cstdio>
#include <cstring>

constexpr int LM = 10005;
int N;
int stack[LM];
int t = -1;

void push(int x) {
	stack[t++] = x;
}

void pop() {
	if (t != -1) printf("%d\n", stack[t-1]), t--;
	else printf("-1\n");
}

void size() {
	printf("%d\n", t + 1);
}

void empty() {
	if (t == -1) printf("1\n");
	else printf("0\n");
}

void top() {
	if (t != -1) printf("%d\n", stack[t-1]);
	else printf("-1\n");
}


int main() {
	scanf("%d", &N);

	char cmd[100];

	for (int i = 0; i < N; i++) {
		scanf("%s", cmd);

		if (strcmp(cmd, "push") == 0) {
			int num;
			scanf("%d", &num);
			push(num);
		}
		else if (strcmp(cmd, "top") == 0) {
			top();
		}
		else if (strcmp(cmd, "pop") == 0) {
			pop();
		}
		else if (strcmp(cmd, "empty") == 0) {
			empty();
		}
		else if (strcmp(cmd, "size") == 0) {
			size();
		}
	}


	return 0;
}

