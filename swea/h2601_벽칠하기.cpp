#include <bits/stdc++.h>
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define X first
#define Y second
using pii = std::pair<int,int>;
using ll = long long;
using namespace std;
 
int main(int argc, char **argv){
    #ifndef ONLINE_JUDGE
    #endif
    int T; scanf("%d",&T);
    while(T--){
        int N,M,K; scanf("%d%d%d",&N,&M,&K);
         
        vector<int> C(N);
        vector<vector<int>> CW(K);
         
        for(int i=0;i<N;i++){
            scanf("%d", &C[i]);
        }
         
        for(int i=0; i<M; i++){
            int c; scanf("%d", &c);
            for(int j=0; j<c; j++){
                int n; scanf("%d", &n);
                CW[n].push_back(i);
            }
        }
         
        vector<int> cnt(M,0); 
        vector<int> max_reach(N, -1);
        int active_cnt = 0;  
         
        for(int l=0; l<M; l++){
            int color = C[l];
            for(int worker : CW[color]){
                int x = (worker - l)%M;
                if(x < 0) x += M;
                cnt[x]++;
            }
        }
         
        for(int x=0; x<M; x++){
            if(cnt[x] == M) active_cnt++;
        }
         
        for(int y=0; y<=N-M; y++){
            if(active_cnt > 0){
                max_reach[y] = y+M-1;
            }
             
            if(y == N-M) break;
             
            int c_remove = C[y];
            for(int worker : CW[c_remove]){
                int x = (worker - y)%M;  
                if(x<0) x+=M;
                if(cnt[x] == M) active_cnt--;
                cnt[x]--;
            }
             
            int c_add = C[y+M];
            for(int worker : CW[c_add]){
                int x = (worker - (y+M))%M;
                if(x < 0) x += M;
                cnt[x]++;
                if(cnt[x] == M) active_cnt++;
            }
        }
         
        int ans = 0;
        int i =0;
        deque<int> dq;
        int next_y = 0;
         
        while(i < N){
            int l = max(0, i-M+1);
            int r = min(i, N-M);
             
            if(l>r) {
                ans = -1; break;
            }
             
            while(!dq.empty() && dq.front() < l){
                dq.pop_front();
            }
             
            while(next_y <= r){
                if(max_reach[next_y] != -1){
                    while(!dq.empty() && max_reach[dq.back()] <= max_reach[next_y]){
                        dq.pop_back();
                    }
                    dq.push_back(next_y);
                }
                next_y++;
            }
             
            if(dq.empty() || max_reach[dq.front()] < i){
                ans = -1;
                break;
            }
             
            int best = max_reach[dq.front()];
            i = best+1;
            ans++;
        }
         
        printf("%d\n", ans);
    }
}