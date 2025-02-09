#include <bits/stdc++.h>
#define rnt register int
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define WATCH(x) cout << #x << " : " << x << '\n';
#define PRINT(x) cout << x << '\n';
using namespace std;
using pii = pair<int,int>;
using ll = long long;

bool match(const string& w, const string& s){
	int pos = 0;
	while(pos < s.size() 
			&& pos < w.size() 
			&& (w[pos] == '?' || w[pos] == s[pos])) {
		++pos;
	}

	if(pos == w.size()) return pos == s.size();

	if(w[pos] == '*') {
		for(int skip=0; pos+skip <= s.size(); skip++)
			if(match(w.substr(pos+1), s.substr(pos+skip)))
				return true;
	}

	return false;
}

int main(int argc, char **argv){
		int C;
		scanf("%d",&C);

		while(C--){
			string w;
			cin >> w;

			int N;
			scanf("%d", &N);
			
			vector<string> ans;
			for(int i=0; i<N; i++){
				string s;
				cin >> s;
				
				if(match(w,s)) 
					ans.push_back(s);
			}
			
			sort(ans.begin(), ans.end());

			for(auto &s : ans) {
				printf("%s\n", s.c_str());
			}
		}
}
