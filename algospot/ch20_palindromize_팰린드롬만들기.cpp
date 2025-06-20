#include <bits/stdc++.h>
using namespace std;

// N에서 자기 자신을 찾으면서 나타나는 부분 일치를 이용해 pi[]를 계산한다
vector<int> getPartialMatch(const string&s){
	int m = s.size();
	vector<int> f(m,0);

	// KMP로 자기 자신을 찾는다
	// s을 s에서 찾는다. i=0이면 자기 자신을 찾아버리니 안됨!
	int j = 0;
	for(int i=1; i<s.size(); i++){
		while(j>0 && s[i] != s[j]) j = f[j-1];
		if(s[i] == s[j]) f[i] = ++j;
	}
	return f;
}

// a의 접미사이면서 b의 접두사인 문자열의 최대 길이를 구한다
int maxOverlab(const string& a, const string& b){
	int n = a.size(), m = b.size();
	vector<int> f = getPartialMatch(b);

	int begin=0, matched=0;
	while(begin < n){
		if(matched<m && a[begin+matched] == b[matched]){
			++matched;
			if(begin+matched == n){
				return matched;
			}
		} else{
			if(matched == 0) ++begin;
			else{
				begin += matched - f[matched-1];
				matched = f[matched-1];
			}
		}
	}
	return 0;
}

int main(int argc, char **argv){
  //freopen("s_in_2232.txt", "r", stdin);
  int C; scanf("%d",&C);
	while(C--){
		string s; cin >> s;

		string r = s;
		reverse(r.begin(), r.end());
		printf("%ld\n", s.length()*2 - maxOverlab(s,r));
	}

}
