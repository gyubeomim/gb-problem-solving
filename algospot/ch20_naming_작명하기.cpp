#include <bits/stdc++.h>
using namespace std;

// N에서 자기 자신을 찾으면서 나타나는 부분 일치를 이용해 pi[]를 계산한다
vector<int> getPartialMatch(const string&N){
	int m = N.size();
	vector<int> f(m,0);

	// KMP로 자기 자신을 찾는다
	// N을 N에서 찾는다. begin=0이면 자기 자신을 찾아버리니 안됨!
	int begin=1, matched=0;
	while(begin + matched < m){
		if(N[begin+matched] == N[matched]){
			++matched;
			f[begin+matched-1] = matched;
		}
		else{
			if(matched==0) ++begin;
			else{
				begin += matched - f[matched-1];
				matched = f[matched-1];
			}
		}
	}
	return f;
}

vector<int> getPrefixSuffix(const string&s){
	vector<int> ret;

	vector<int> f = getPartialMatch(s);
	int k = s.size();
	while(k>0){
		// s[..k-1]은 답이 아니다
		ret.push_back(k);
		// s[..k-1]의 접미사도 되고 접두사도 되는 문자열도 답이다
		k = f[k-1];
	}

	return ret;
}

int main(int argc, char **argv){
  //freopen("s_in_2231.txt", "r", stdin);
  string fat, mot;
  cin >> fat >> mot;

	string s = fat + mot;

  vector<int> ans = getPrefixSuffix(s);
  sort(ans.begin(), ans.end());
  for (int a : ans) {
    printf("%d ", a);
  }
}
