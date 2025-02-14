#include <bits/stdc++.h>
using namespace std;

int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		int K;
		scanf("%d", &K);

		multiset<int> ms;

		while (K--) {
			char cmd;
			cin >> cmd;

			if (cmd == 'D') {
				int q;
				scanf("%d", &q);

				if (ms.empty()) continue;

				if (q == 1) ms.erase(prev(ms.end()));
				else ms.erase(ms.begin());
			}
			else {
				int q;
				scanf("%d", &q);

				ms.insert(q);
			}
		}

		if (ms.empty()) printf("EMPTY\n");
		else { 
			printf("%d %d\n", *prev(ms.end()), *ms.begin()); 
		}
	}
}

