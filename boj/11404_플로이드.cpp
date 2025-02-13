#include <bits/stdc++.h>
using namespace std;

const int LM = 105;
const int INF = 0x3f3f3f3f;

int d[LM][LM];
int n, m;

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		fill(d[i], d[i] + n + 1, INF);
	}

	while (m--) {
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		d[a][b] = min(d[a][b], c);
	}

	for (int i = 1; i <= n; i++) 
		d[i][i] = 0;
	
	// Floyd-Warshall
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
				// if (d[i][k] + d[k][j] < d[i][j]) d[i][j] = d[i][k] + d[k][j];
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (d[i][j] == INF) printf("0 ");
			else printf("%d ", d[i][j]);
		}
		puts("");
	}
}

