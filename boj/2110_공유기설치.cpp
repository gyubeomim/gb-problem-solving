#include <bits/stdc++.h>

using namespace std;

int N,C;
vector<int> v;

bool Solve(int mid) {
	int count=1;
	int curr = v[0];

	for(int i=1; i<N; i++) {
		if(v[i] - curr >= mid) {
			count++;
			curr = v[i];
		}
	}

	if(count >= C) {
		return true;
	}

	return false;
}

int main(int argc, char **argv){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	cin>>N>>C;

	for(int i=0; i<N; i++) {
		int num;
		cin >> num;
		v.push_back(num);
	}

	sort(v.begin(), v.end());
	
	int left = 1;
	int right = v[v.size()-1] - v[0];
	int ans=0;

	while(left <= right) {
		int mid = (left + right) / 2;
		if(Solve(mid)) {
			ans = max(ans, mid);
			left = mid + 1;
		}
		else {
			right = mid-1;
		}
	}

	cout << ans << '\n';

	return 0;
}
