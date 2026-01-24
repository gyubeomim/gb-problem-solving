#include <bits/stdc++.h>
#define rnt register int
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define X first
#define Y second
using pii = std::pair<int,int>;
using ll = long long;
using namespace std;

const int INF = 0x3f3f3f3f;

/*
	N: the number of robots, 
	M: spikes, 
	K: instructions respectively.
*/

int main(int argc, char **argv){
#ifndef ONLINE_JUDGE
    freopen("data/d1074e.txt", "r", stdin);
#endif
    int T; scanf("%d", &T);
    while(T--) {
        int N,M,K; scanf("%d%d%d", &N, &M, &K);

        vector<ll> robot(N), spike(M);
        for(int i=0; i<N; i++) scanf("%lld", &robot[i]);
        for(int i=0; i<M; i++) scanf("%lld", &spike[i]);

        static char cmd[200005];
        scanf("%s", cmd);

        vector<int> first_pos(K+2, INF);
        vector<int> first_neg(K+2, INF);

        int cur = 0;
        int max_pos = 0;
        int min_neg = 0;

        for(int i=1; i<=K; i++){
            if(cmd[i-1] == 'R') cur++;
            else cur--;

            if(cur > max_pos){
                max_pos = cur;
                first_pos[max_pos] = i;
            }
            if(cur < min_neg){
                min_neg = cur;
                first_neg[-min_neg] = i;
            }
        }

        sort(spike.begin(), spike.end());

        vector<int> dead(K+2, 0);

        for(int i=0; i<N; i++){
            ll pos = robot[i];
            auto it = lower_bound(spike.begin(), spike.end(), pos);

            int die_time = INF;

            if(it != spike.end()){
                ll dR = *it - pos;
                if(dR <= max_pos){
                    die_time = min(die_time, first_pos[(int)dR]);
                }
            }
            if(it != spike.begin()){
                --it;
                ll dL = pos - *it;
                int max_neg = -min_neg;
                if(dL <= max_neg){
                    die_time = min(die_time, first_neg[(int)dL]);
                }
            }

            if(die_time != INF){
                dead[die_time]++;
            }
        }

        int deadcnt = 0;
        for(int i=1; i<=K; i++){
            deadcnt += dead[i];
            int alive = N - deadcnt;
            printf("%d ", alive);
        }
        puts("");
    }
}