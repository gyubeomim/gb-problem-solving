#include <bits/stdc++.h>
using namespace std;

int K = 0;
string S;

struct Comparator {
	const vector<int>& group;
	int t;

	Comparator(const vector<int>& _group, int _t) 
		:group(_group), t(_t) {}

	bool operator()(int a,int b){
		if(group[a]!=group[b]) return group[a] < group[b];
		return group[a+t] < group[b+t];
	}
};

vector<int> getSuffixArray(const string& s){
	int n = s.size();
	int t = 1;
	vector<int> group(n+1);

	for(int i=0; i<n; i++) group[i] = s[i];
	group[n] = -1;

	vector<int> perm(n);
	for(int i=0 ;i<n;i++) perm[i] = i;

	while(t<n){
		Comparator comp(group, t);
		sort(perm.begin(), perm.end(), comp);

		t*=2;
		if(t>=n) break;

		vector<int> ngroup(n+1);
		ngroup[n]=-1;
		ngroup[perm[0]]=0;

		for(int i=1;i<n;i++){
			if(comp(perm[i-1],perm[i])) ngroup[perm[i]] = ngroup[perm[i-1]]+1;
			else                        ngroup[perm[i]] = ngroup[perm[i-1]];
		}
		group = ngroup;
	}
	return perm;
}

// S[i..], S[j..]의 공통 접두사의 최대 길이를 계산한다
int commonPrefix(const string& s, int i, int j){
	int k = 0;
	while(i<s.size() && j<s.size() && s[i] == s[j]){
		++i,++j,++k;
	}
	return k;
}

int longestFrequent(int k, const string& s){
	vector<int> a = getSuffixArray(s);
	int ret = 0;
	for(int i=0; i+k<=s.size(); i++){
		ret = max(ret, commonPrefix(s, a[i], a[i+k-1]));
	}
	return ret;
}

int main(int argc, char **argv){
		//freopen("s_in_2244.txt", "r", stdin);
		int C; scanf("%d",&C);
		while(C--){
			scanf("%d", &K);
			cin >> S;

			int ans = longestFrequent(K, S);
			printf("%d\n", ans);
		}
}
