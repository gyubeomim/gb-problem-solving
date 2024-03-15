#include <cstdio>
#include <cstring>

constexpr int LM = 10005;
int N;
int que[LM];
int fr = 0, re = 0;

void push(int x) {
	que[re++] = x;
}

void pop() {
	if(que[fr]) printf("%d\n", que[fr++]);
	else printf("-1\n");
}

void size() {
	printf("%d\n", re - fr);
}

void empty() {
	if (fr == re) printf("1\n");
	else printf("0\n");
}

void front() {
	if (que[fr])printf("%d\n", que[fr]);
	else printf("-1\n");
}

void back() {
	if (que[fr])printf("%d\n", que[re-1]);
	else printf("-1\n");
}

int main() {
#ifdef _WIN32
	freopen("D2.txt", "r", stdin);
#endif // _WIN32

	scanf("%d", &N);

	char cmd[100];

	for (int i = 0; i < N; i++) {
		scanf("%s", cmd);

		if (strcmp(cmd, "push") == 0) {
			int num;
			scanf("%d", &num);
			push(num);
		}
		else if (strcmp(cmd, "front") == 0) {
			front();
		}
		else if (strcmp(cmd, "back") == 0) {
			back();
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
