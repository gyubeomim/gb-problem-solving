#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;
using ll = long long;
using pil = pair<int,ll>;

struct Data {
  ll cost, p, q;
};

const ll INF = LLONG_MAX;
const int BLM = 30;

int idx(int c){ return c+1; }
int val(int i){ return i-1; }

pil step(int sc, int b, int xb, ll w){
  if(sc==0){
    if(b==xb) return {0,0};
    return {(b>xb)?1:-1, w};
  }
  if(sc==1) return {1, (ll)(b - xb)*w};
  return {-1, (ll)(xb - b)*w};
}

bool better(const Data& a, const Data& b){
  if(a.cost != b.cost) return a.cost < b.cost;
  if(a.p != b.p) return a.p > b.p;
  return a.q > b.q;
}

int main(){
  #ifndef ONLINE_JUDGE
    freopen("data/1077d.txt", "r", stdin);
  #endif

  int T; scanf("%d", &T);
  while(T--){
    ll x, y; scanf("%lld %lld", &x, &y);

    Data dp[3][3], ndp[3][3];

    for(int i=0;i<3;i++) 
			for(int j=0;j<3;j++) 
				dp[i][j] = {INF, 0, 0};

    dp[idx(0)][idx(0)] = {0, 0, 0};

    for(int bit=BLM; bit>=0; --bit){
      for(int i=0;i<3;i++) 
				for(int j=0;j<3;j++) 
					ndp[i][j] = {INF, 0, 0};

      int xb = (x>>bit)&1;
      int yb = (y>>bit)&1;
      ll w = 1LL<<bit;

      for(int cx=0; cx<3; ++cx){
        for(int cy=0; cy<3; ++cy){
          if(dp[cx][cy].cost == INF) continue;

          int scx = val(cx), scy = val(cy);

          for(int t=0; t<3; ++t){
            int pi = (t==1);
            int qi = (t==2);

            pil sx = step(scx, pi, xb, w);
            pil sy = step(scy, qi, yb, w);

            Data cand;
            cand.cost = dp[cx][cy].cost + sx.Y + sy.Y;
            cand.p = dp[cx][cy].p | ((ll)pi<<bit);
            cand.q = dp[cx][cy].q | ((ll)qi<<bit);

            int icx = idx(sx.X), icy = idx(sy.X);

            if(better(cand, ndp[icx][icy])) 
							ndp[icx][icy] = cand;
          }
        }
      }

      for(int i=0;i<3;i++) 
				for(int j=0;j<3;j++) 
					dp[i][j] = ndp[i][j];
    }

    Data best = {INF, 0, 0};

    for(int i=0;i<3;i++) 
			for(int j=0;j<3;j++)
      	if(dp[i][j].cost != INF 
					&& (best.cost==INF || better(dp[i][j], best)))
        	best = dp[i][j];

    printf("%lld %lld\n", best.p, best.q);
  }
}