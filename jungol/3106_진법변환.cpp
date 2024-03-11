#include <cstdio>
using namespace std;

using ll = long long;

char S[100];
char chr[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";

void Get(ll ret, int to) {
	if (ret < to) {
		printf("%c", chr[ret]);
		return;
	}
	Get(ret/to, to);
	printf("%c", chr[ret%to]);
}

int main() {
	int from, to;

	while (scanf("%d %s %d", &from, S, &to) && from) {
		//printf("IN %d %s %d\n", from, S, to);
		ll ret = 0;
		for (int i = 0; S[i]; i++) {
			//printf("%d %d", i, S[i]);
			if (S[i] < 'A') ret = ret * from + (S[i] - '0');
			else ret = ret * from + (S[i] - 'A' + 10);
		}
		Get(ret, to);
		puts("");
	}



	return 0;
}
