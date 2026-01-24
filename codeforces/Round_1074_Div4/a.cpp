#include <bits/stdc++.h>
#define rnt register int
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define X first
#define Y second
using pii = std::pair<int,int>;
using ll = long long;
using namespace std;

int main(int argc, char **argv){
#ifndef ONLINE_JUDGE
	freopen("data/d1074a.txt", "r", stdin);
#endif
	int T; scanf("%d", &T);
	while(T--) {
		int n; scanf("%d", &n);
		for(int i=1; i<=n; i++){
			printf("%d ", i);
		}puts("");
	}
}