#include <bits/stdc++.h>
using namespace std;

// s에서 자기 자신을 찾으면서 나타나는 부분 일치를 이용해 f[]를 계산한다
vector<int> getPartialMatch(const string&s){
	int m = s.size();
	vector<int> f(m,0);

	// KMP로 자기 자신을 찾는다
	// s을 s에서 찾는다. i=0이면 자기 자신을 찾아버리니 안됨!
	int j=0;
	for(int i=1; i<s.size(); i++){
		while(j>0 && s[i] != s[j]) j = f[j-1];
		if(s[i] == s[j]) f[i] = ++j;
	}
	return f;
}

vector<int> kmpSearch2(const string&s, const string&p){
	int n = s.size(), m = p.size();
	vector<int> ret;
	vector<int> f = getPartialMatch(p);

	int j=0;
	for(int i=0; i<n; i++){
		while(j>0 && s[i] != p[j]) j = f[j-1];
		if(s[i] == p[j]) {
			++j;
			if(j == m) {
				ret.push_back(i - m + 1);
				j = f[j-1];
			}
		}
	}
	return ret;
}

int shifts(string& s, string& t){
	return kmpSearch2(s+s, t)[0];
}

int main(int argc, char **argv){
	//freopen("s_in_2235.txt", "r", stdin);
	int C; scanf("%d", &C);
	while(C--){
		int k;
		scanf("%d", &k);
		// cin >> k;

		string s;
		cin >> s;
		int ans = 0;
		bool flag = false;

		while(k--){
			string t;
			cin >> t;

			if(flag) ans += shifts(s, t);
			else ans += shifts(t, s);

			s = t;
			flag = !flag;
		}
		printf("%d\n", ans);
	}
}
