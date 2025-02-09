#include <bits/stdc++.h>
#define rnt register int
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define WATCH(x) cout << #x << " : " << x << '\n';
#define PRINT(x) cout << x << '\n';
using namespace std;
using pii = pair<int,int>;
using ll = long long;

// solution #1
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

// solution #2 DP O(n^3)
int dp[101][101];
string W,S;

bool match2(int w, int s){
	int& ret = dp[w][s];
	if(ret != -1) return ret;

	while(s < S.size() && w < W.size() && 
							(W[w] == '?' || W[w] == S[s])) {
		++w;
		++s;
	}

	if(w == W.size()) return ret = (s == S.size());

	if(W[w] == '*') 
		for(int skip = 0; skip+s <= S.size(); skip++)
			if(match2(w+1, s+skip))
				return ret = 1;
		
	return ret = 0;
}


int main(int argc, char **argv){
		int C;
		scanf("%d",&C);

		while(C--){
			string w;
			cin >> W;

			int N;
			scanf("%d", &N);

			memset(dp, -1, sizeof(dp));
			
			vector<string> ans;
			for(int i=0; i<N; i++){
				string s;
				cin >> S;
				
				// if(match(w,s))  ans.push_back(s);
				if(match2(0,0))  ans.push_back(S);
			}
			
			sort(ans.begin(), ans.end());

			for(auto &s : ans) {
				printf("%s\n", s.c_str());
			}
		}
}
