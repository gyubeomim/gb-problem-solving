#include <cstdio>
#include <vector>
#include <string>
using namespace std;

constexpr int LM = 200005;
int N, Q;
int root[LM];

struct Data {
	int x, c, d;
} cmd[LM * 2];

vector<string> rets;

int gnum[LM];

int Find(int n) {
	if (n == gnum[n]) return n;
	return gnum[n] = Find(gnum[n]);
}

void Union(int a, int b) {
	a = Find(a), b = Find(b);
	if (a == b)return;

	gnum[b] = a;
}

int main() {
	scanf("%d %d", &N, &Q);

	for (int i = 2; i <= N; i++) {
		int val;
		scanf("%d", &val);
		root[i] = val;
	}
	root[1] = 1;

	for (int i = 1; i <= N; i++) {
		gnum[i] = i;
	}

	for (int i = 0; i < N - 1 + Q; i++) {
		int x, c = 0, d = 0;
		scanf("%d", &x);

		if(x==0)
			scanf("%d", &c);
		else if(x==1)
			scanf("%d %d", &c, &d);

		cmd[i] = { x, c, d };
	}

	for (int i = N - 2 + Q; i >= 0; i--) {
		int x = cmd[i].x;
		int c = cmd[i].c;
		int d = cmd[i].d;

		if (x == 0) {
			Union(c, root[c]);
		}
		else if (x == 1) {
			c = Find(c);
			d = Find(d);
			string ans;
			if (c == d) ans = "YES\n";
			else ans = "NO\n";
			rets.push_back(ans);
		}
	}

	for (auto rit = rets.rbegin(); rit != rets.rend(); rit++) {
		printf("%s", rit->c_str());
	}


	return 0;
}
