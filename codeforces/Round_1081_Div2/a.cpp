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
	freopen("data/1081a.txt", "r", stdin);
#endif
	int T; scanf("%d", &T);
	while(T--) {
			int n;
			string s;
			cin >> n >> s;

			int C = 0;
			for (int i = 0; i < n; i++) {
					if (s[i] != s[(i + 1) % n]) C++;
			}

			int ans = (C == n ? n : C + 1);
			cout << ans << "\n";
	}
}