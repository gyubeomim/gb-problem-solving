#include <bits/stdc++.h>
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
using namespace std;

unordered_set<string> s;

int main() {
	FASTIO;

	int N;
	cin >> N;
	while (N--) {
		string name, log;
		cin >> name >> log;
		if (log == "enter") s.insert(name);
		else s.erase(name);
	}

	vector<string> ans(s.begin(), s.end());
	sort(ans.begin(), ans.end(), greater<string>());
	for (auto x : ans) cout << x << '\n';
}
