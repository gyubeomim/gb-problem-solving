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
	freopen("data/d1121.txt", "r", stdin);
#endif
	int T; scanf("%d", &T);
	while(T--) {
		int n; scanf("%d", &n);
		string s; cin >> s;

		if(s.find('0') == string::npos){
			printf("0\n");
		}
		else{
			int start = (int)s.find('1');
			int cur = 0 , best = 0;
			for(int k=0; k<n; k++){
				char c = s[(start+k) % n];
				if(c == '0'){
					cur++;
					best = max(best, cur);
				}else{
					cur = 0;
				}
			}
			cout << best << '\n';
		}
	}
}