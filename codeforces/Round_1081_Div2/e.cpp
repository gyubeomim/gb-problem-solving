#include <bits/stdc++.h>
#define rnt register int
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define X first
#define Y second
using pii = std::pair<int,int>;
using ll = long long;
using namespace std;

const int NLM = 1000005;
const int ELM = 1000005;        
const int ARCLM = 2*ELM + 5;

int a[NLM], b[NLM];
int tot_cnt[NLM];

int ea[ELM], eb[ELM], e_origidx[ELM];

int headV[NLM];
int arc_to[ARCLM], arc_nxt[ARCLM], arc_id[ARCLM];
int aptr;

int itV[NLM];
unsigned char usedE[ELM];
int dir_from[ELM], dir_to[ELM];

void addArc(int u, int v, int id){
    arc_to[aptr] = v;
    arc_id[aptr] = id;
    arc_nxt[aptr] = headV[u];
    headV[u] = aptr++;
}

int main(int argc, char **argv){
#ifndef ONLINE_JUDGE
    freopen("data/1081e.txt", "r", stdin);
#endif
    int T;  scanf("%d", &T);

    while(T--){
        int n; scanf("%d", &n);

        for(int i=1;i<=n;i++) scanf("%d", &a[i]);
        for(int i=1;i<=n;i++) scanf("%d", &b[i]);

        for(int i=1;i<=n;i++){
            tot_cnt[i]=0;
            headV[i]=-1;
        }
        aptr=0;

        for(int i=1;i<=n;i++){
            tot_cnt[a[i]]++;
            tot_cnt[b[i]]++;
        }

        bool ok=true;
        for(int x=1;x<=n;x++){
            if(tot_cnt[x]&1){ ok=false; break; }
        }
        if(!ok){
            printf("-1\n");
            continue;
        }

        int m=0;
        for(int i=1;i<=n;i++){
            if(a[i]==b[i]) continue;
            ++m;
            ea[m]=a[i];
            eb[m]=b[i];
            e_origidx[m]=i;
            addArc(ea[m], eb[m], m);
            addArc(eb[m], ea[m], m);
        }

        for(int v=1; v<=n; v++) itV[v]=headV[v];
        for(int i=1;i<=m;i++) usedE[i]=0;

        int st[NLM]; 
        int st_sz=0;

        for(int start=1; start<=n; start++){
            if(headV[start]==-1) continue;

            int p = itV[start];
            while(p!=-1 && usedE[arc_id[p]]) p = arc_nxt[p];
            itV[start]=p;
            if(itV[start]==-1) continue;

            st_sz=0;
            st[st_sz++]=start;

            while(st_sz){
                int v = st[st_sz-1];
                int &e = itV[v];

                while(e!=-1 && usedE[arc_id[e]]) e = arc_nxt[e];

                if(e==-1){
                    st_sz--;
                }else{
                    int eid = arc_id[e];
                    int to = arc_to[e];
                    usedE[eid]=1;

                    dir_from[eid]=v;
                    dir_to[eid]=to;

                    e = arc_nxt[e];
                    st[st_sz++]=to;
                }
            }
        }

        int ans_idx[NLM];
        int ans_cnt=0;

        for(int i=1;i<=m;i++){
            if(dir_from[i]==ea[i] && dir_to[i]==eb[i]){
                ans_idx[ans_cnt++] = e_origidx[i];
            }
        }

        printf("%d\n", ans_cnt);
        if(ans_cnt==0){
            printf("\n");
        }else{
            for(int i=0;i<ans_cnt;i++){
                if(i) printf(" ");
                printf("%d", ans_idx[i]);
            }
            printf("\n");
        }
    }
}