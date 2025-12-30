#include <bits/stdc++.h>

using namespace std;


int main() {
	int N;
	cin >> N;


	map<int, pair<bool,int>> m;
	vector<int> v(N);

	for(int i=0; i<N;i++){
		int a;
		cin >> a;

		v[i] = a;
		m[v[i]]={false, i};
	}


	int ans=0;
	for(int i=0; i<N; i++) {
		for(int j=i+1; j<N; j++) {
				int sum = v[i] + v[j];

				if(m.count(sum)) {
					if(m[sum].second == i || m[sum].second == j) continue;

					m[sum].first = true;
					// cout << sum << ", " << m[sum].second << endl;
				}
		}
	}


	for(int i=0;i<N;i++){
		if(m[v[i]].first == true) {
			ans++;
		}
	}


	cout << ans << '\n';

	return 0;
}
