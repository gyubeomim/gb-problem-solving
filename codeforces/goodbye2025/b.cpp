#include <bits/stdc++.h>
#define rnt register int
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define X first
#define Y second
using pii = std::pair<int,int>;
using ll = long long;
using namespace std;

const int LM = 200005;


int main(int argc, char **argv){
	#ifndef ONLINE_JUDGE
		freopen("data/d4958.txt", "r", stdin);
	#endif

		int T; scanf("%d", &T);
		while(T--) {
			int ans = 0;
			string s; cin >> s;
			if(s.front() == 'u') ans++;
			if(s.back() == 'u') ans++;

			int i = 1;
			while(i <= s.size()-2){
				if(s[i] != 'u') {i++; continue;}
				int j = i;
				while(j<=s.size()-2 && s[j]=='u') j++;
				int L = j-i;
				ans += (L/2);
				i = j;
			}

			printf("%d\n", ans);
		}
}