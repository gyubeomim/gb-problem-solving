#include <bits/stdc++.h>
#define rnt register int
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define WATCH(x) cout << #x << " : " << x << '\n';
#define PRINT(x) cout << x << '\n';
using namespace std;
using pii = pair<int,int>;
using ll = long long;

string W,S;

// solution #1
bool match(const string& w, const string& s){
	// w[pos]와 s[pos]를 맞춰나간다
	int pos = 0;
	while(pos < s.size() 
			&& pos < w.size() 
			&& (w[pos] == '?' || w[pos] == s[pos])) {
		++pos;
	}
	
	// 더이상 대응할 수 없으면 왜 while문이 끝났는지 확인한다
	// 2. 패턴 끝에 도달해서 끝난 겨우: 문자열도 끝났어야 대응됨
	if(pos == w.size()) return pos == s.size();
	
	// 4. *를 만나서 끝난 경우: *에 몇 글자를 대응해야 할 지 재귀 호출하면서 확인한다
	if(w[pos] == '*') {
		for(int skip=0; pos+skip <= s.size(); skip++)
			if(match(w.substr(pos+1), s.substr(pos+skip)))
				return true;
	}
	
	// 3. 이외의 경우에는 모두 대응되지 않는다
	return false;
}

// solution #2 DP O(n^3)
// -1: 아직 답이 계산되지 않았음
// 1: 해당 입력들이 서로 대응됨
// 0: 해당 입력들이 서로 대응되지 않음
int dp[105][105];

bool match2(int w, int s){
	int& ret = dp[w][s];
	if(ret != -1) return ret;

	// W[w]와 S[s]를 맞춰나간다
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

// solution #3 DP O(n^2)
// for, while문을 재귀문으로 변경하여 메모이제이션 극대화
bool match3(int w, int s){
	int& ret = dp[w][s];
	if(ret != -1) return ret;
	
	// while --> if문으로 변경
	if(s < S.size() && w < W.size() && 
							(W[w] == '?' || W[w] == S[s])) {
		return ret = match3(w+1, s+1);
	}

	if(w == W.size()) return ret = (s == S.size());

	if(W[w] == '*') {
			// for --> if문으로 변경
			if(match3(w+1, s) 
					  || (s < S.size() && match3(w, s+1)))
				return ret = 1;
	}
		
	return ret = 0;
}

int main(int argc, char **argv){
		int C;
		scanf("%d",&C);

		while(C--){
			cin >> W;

			int N;
			scanf("%d", &N);

			vector<string> ans;
			for(int i=0; i<N; i++){
				memset(dp, -1, sizeof(dp));

				cin >> S;

				// if(match(W,S))  ans.push_back(S);
				// if(match2(0,0))  ans.push_back(S);
				if(match3(0,0)) ans.push_back(S);
			}

			sort(ans.begin(), ans.end());

			for(auto &s : ans) {
				printf("%s\n", s.c_str());
			}
		}
}
