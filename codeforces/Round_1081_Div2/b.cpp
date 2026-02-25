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
	freopen("data/1081b.txt", "r", stdin);
#endif
	int T; scanf("%d", &T);
	while(T--) {
		int n; scanf("%d", &n);
		string s; cin >> s;

		int onecnt = 0;
		int zerocnt = 0;

		vector<int> ones, zeros;

		for(int i=0; i<s.size();i++){
			if(s[i] == '1') { onecnt++; ones.push_back(i+1); }
			if(s[i] == '0') { zerocnt++; zeros.push_back(i+1); }
		}

		if(onecnt%2==0) {
			printf("%d\n", (int)ones.size());

			if(!ones.empty()){
				for(auto v : ones) printf("%d ", v); 
				puts("");
			}
		}else{
			if(zerocnt%2==1){
				printf("%d\n", zerocnt);
				if(!zeros.empty()){
					for(auto v : zeros) printf("%d ", v); 
					puts("");
				}
			}else{
				printf("-1\n");
			}
		}
	}
}