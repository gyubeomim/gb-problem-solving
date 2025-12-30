#include <bits/stdc++.h>
using namespace std;

int main() {
	int N;
	cin >> N;

	map<string, int> m;
	for(int i=0; i<N; i++) {
		string s;
		cin >> s;

		m[s] = i;
	}

	vector<string> v(N);
	for(int i=0; i<N; i++) {
		cin >> v[i];
	}


	int ans=0;
	for(int i=0;i<N-1;i++) {
		for(int j=i+1;j<N;j++){
			if(m[v[i]] > m[v[j]]) {
				ans++;
				break;
			}
		}
	}

	cout << ans << '\n';

	return 0;
}


