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
	freopen("data/d2025.txt", "r", stdin);
#endif
	int T; scanf("%d", &T);
	while(T--) {
		int n;
		string s; 
		cin >> n >> s;

		int subpos = s.find("2025");
		if(subpos != string::npos){
			int subpos2 = s.find("2026");
			if(subpos2 != string::npos){
				printf("0\n");
			}
			else printf("1\n");
		}else printf("0\n");

		// printf("%d %s\n",n, s.c_str());
	}
}