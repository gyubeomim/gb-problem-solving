#include <bits/stdc++.h>
#define rnt register int
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define X first
#define Y second
using pii = std::pair<int,int>;
using ll = long long;
using namespace std;

int N;
struct Data{
 int lo, hi;
 bool operator<(const Data &r) const {
	return hi < r.hi;
 }
};
vector<Data> V;

int main(int argc, char **argv){
	#ifndef ONLINE_JUDGE
		freopen("data/d1828.txt", "r", stdin);
	#endif

	scanf("%d", &N);

	for(int i=0; i<N; i++){
		int lo, hi;  scanf("%d%d", &lo, &hi);
		V.push_back({lo, hi});
	}

	sort(V.begin(), V.end());

	int ans = 1;
	int cur = V[0].hi;

	for(int i=1; i<V.size(); i++){
		if(V[i].lo <= cur && cur <= V[i].hi) continue;
		else {
			ans++;
			cur = V[i].hi;
		}
	}
	printf("%d\n", ans);
}