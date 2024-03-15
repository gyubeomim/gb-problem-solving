#include <cstdio>
#include <cstring>
#include <stack>
using namespace std;

constexpr int LM = 1005;

stack<char> S;

void Print() {
	while (!S.empty()) {
		printf("%c", S.top());
		S.pop();
	}
}


int main() {
	int T;
	scanf("%d ", &T);

	while (T--) {
		while (!S.empty()) S.pop();
		char str[LM];

		fgets(str, LM, stdin);
		int len = strlen(str);

		//printf("%s\n", str);
		//printf("%d\n", len);

		for (int i = 0; i < len; i++) {
			if (str[i] == ' ' || i == len - 1) {
				Print(); printf(" ");
			}
			else {
				S.push(str[i]);
			}
		}
		puts("");

	}

	return 0;
}

