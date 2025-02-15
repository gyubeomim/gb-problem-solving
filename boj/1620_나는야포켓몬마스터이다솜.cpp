#include <bits/stdc++.h>
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
using namespace std;

unordered_map<string, int> s2i;
string i2s[100005];

int main() {
	FASTIO;

	int N, M;
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		cin >> i2s[i];
		s2i[i2s[i]] = i;
	}

	while (M--) {
		string query;
		cin >> query;
		if (isdigit(query[0])) cout << i2s[stoi(query)] << '\n';
		else cout << s2i[query] << '\n';
	}

}

