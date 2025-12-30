#include <bits/stdc++.h>

using namespace std;

struct Enroll{
	int id_;
	int order_;
	
	Enroll(int id, int order) {
		id_ = id;
		order_ = order;
	}
};

int main() {
	int K,L;
	cin >> K >> L;


	map<string ,int> m;
	for(int i=0; i<L; i++) {
		string s;
		cin >> s;

		m[s] = i;
	}


	vector<pair<string,int>> v(m.begin(), m.end());

	sort(v.begin(), v.end(), [](const pair<string, int> &a, const pair<string, int> &b) {
		return a.second < b.second;
	});

	int count=0;
	for(auto it : v) {
		cout << it.first << '\n';
		count++;

		if(count == K) break;
	}
	

	return 0;
}