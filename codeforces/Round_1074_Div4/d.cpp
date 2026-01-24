#include <bits/stdc++.h>
#define rnt register int
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define X first
#define Y second
using pii = std::pair<int,int>;
using ll = long long;
using namespace std;

int main(int argc, char **argv){
#ifndef ONLINE_JUDGE
    freopen("data/d1074d.txt", "r", stdin);
#endif
    int T; scanf("%d", &T);
    while(T--) {
        int N, M;
        ll H;
        scanf("%d%d%lld", &N, &M, &H);

        vector<ll> orig(N);
        for(int i=0; i<N; i++) scanf("%lld", &orig[i]);

        vector<ll> val(N, 0);
        vector<int> upd(N, -1);   
        int reset_time = 0;      

        for(int op=1; op<=M; op++){
            int b; ll c;
            scanf("%d%lld", &b, &c);
            int idx = b - 1;

            ll cur = (upd[idx] < reset_time) ? orig[idx] : val[idx];
            ll nxt = cur + c;

            if(nxt > H){
                reset_time = op;
            }else{
                val[idx] = nxt;
                upd[idx] = op;
            }
        }

        for(int i=0; i<N; i++){
            ll ans = (upd[i] < reset_time) ? orig[i] : val[i];
            printf("%lld ", ans);
        }
        puts("");
    }
}