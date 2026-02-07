#include <bits/stdc++.h>
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define X first
#define Y second
using ll = long long;
using pii = std::pair<int,int>;
using pll = std::pair<ll,ll>;
using namespace std;

const int LM = 100005;
const ll INF = 0x3f3f3f3f3f3f3f3f;

struct Obs{
 int x;
 ll yl, yh;
};

map<ll, ll> dp;   // dp[y] = min vertical distance to be at y 

int main(int argc, char **argv){
#ifndef ONLINE_JUDGE
	freopen("data/2994.txt", "r", stdin);
#endif
	int N; scanf("%d", &N);
	ll y0;
	int Xf; 
	scanf("%lld%d", &y0, &Xf);

	vector<Obs> obs;
	obs.reserve(N);

	for(int i=0;i<N;i++){
		int x; ll yl, yh;
		scanf("%d%lld%lld", &x, &yl, &yh);
		obs.push_back({x, yl, yh});
	}

	sort(obs.begin(), obs.end(), [](const Obs&a, const Obs&b){
		return a.x < b.x;
	});

	dp[y0] = 0;

	// dp[y] = min(dp[y], val);
	auto update = [&](ll y, ll val){
		auto it = dp.find(y);
		if(it == dp.end()) dp[y] = val;
		else if (it->Y > val) it->Y = val;
	};

	for(const auto& o : obs){
		ll yl = o.yl,  yh = o.yh;
		ll bestyl = INF,  bestyh = INF;

		auto it = dp.upper_bound(yl);
		while(it != dp.end() && it->X < yh){
			ll y = it->X;
			ll d = it->Y;

			bestyl = min(bestyl, d+(y-yl));
			bestyh = min(bestyh, d+(yh-y));

			it = dp.erase(it);
		}
		if(bestyl < INF/2) update(yl, bestyl);
		if(bestyh < INF/2) update(yh, bestyh);
	}

	ll best = INF;
	for(auto &v : dp) best = min(best, v.Y);

	ll ans = (ll) Xf + best;

	vector<ll> ys;
	ys.reserve(dp.size());
	for(auto &v : dp){
		if(v.Y == best) ys.push_back(v.X);
	}

	printf("%lld\n", ans);
	printf("%d ", (int)ys.size());
	for(ll y : ys) printf("%lld ", y);
	printf("\n");
}