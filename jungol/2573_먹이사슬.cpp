#include <bits/stdc++.h>
#define X first
#define Y second
using pii = std::pair<int,int>;
using ll = long long;
using namespace std;

int main() {
#ifndef ONLINE_JUDGE
	freopen("data/2573.txt", "r", stdin);
#endif
	int N;
	scanf("%d", &N);
	
	vector<pii> v;
	for (int i = 0; i < N; i++) {
			int idx, L, R;
			scanf("%d%d%d", &idx, &L, &R);
			v.push_back({L, R});
	}
	
	sort(v.begin(), v.end(), [](auto& a, auto& b) {
			if (a.first == b.first) return a.second > b.second;
			return a.first < b.first;
	});
	v.erase(unique(v.begin(), v.end()), v.end());
	
	vector<pii> dp;
	
	for (auto& p : v) {
		auto it = lower_bound(dp.begin(), dp.end(), p,
				[](auto& a, auto& b) { return a.Y >= b.Y;  });
		if (it != dp.end()) {
				*it = p;
		}else{
			dp.push_back(p);
		}
	}
	
	printf("%d\n", (int)dp.size());
}
