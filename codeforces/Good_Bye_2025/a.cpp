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
		freopen("data/d4920.txt", "r", stdin);
	#endif
		int T; scanf("%d", &T);
		while(T--) {
			string s; cin >> s;

			int ycnt = 0;
			for(char c : s) if(c=='Y') ycnt++;

			if(ycnt <= 1) printf("YES\n");
			else printf("NO\n");
		}
}