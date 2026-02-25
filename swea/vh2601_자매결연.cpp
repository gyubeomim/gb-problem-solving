#include <bits/stdc++.h>
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
using namespace std;
using ll = long long;

const int LM = 100005;

struct Edge{
    int u,v,w;
    bool operator<(const Edge& r)const{
        return w < r.w;
    }
};

int p[LM], sz[LM];
int edge_cnt[LM];
char has_deg3[LM];

void init(int n){
    for(int i=0;i<n;i++){
        p[i]=i;
        sz[i]=1;
        edge_cnt[i]=0;
        has_deg3[i]=0;
    }
}

int find(int a){
    if(p[a]==a) return a;
    return p[a]=find(p[a]);
}

void Union(int a,int b){
    a=find(a); b=find(b);
    if(a==b) return;
    if(sz[a]<sz[b]) swap(a,b);
    p[b]=a;
    sz[a]+=sz[b];
    edge_cnt[a]+=edge_cnt[b];
    has_deg3[a]=has_deg3[a] | has_deg3[b];
}

void addEdge(int u,int v){
    int ru=find(u), rv=find(v);
    if(ru==rv){
        edge_cnt[ru]++;
    }else{
        Union(ru,rv);
        int r=find(ru);
        edge_cnt[r]++;
    }
}

void markDeg3(int u){
    int r = find(u);
    has_deg3[r]=1;
}

bool possible(int r){
    r = find(r);
    return has_deg3[r] || edge_cnt[r] >= sz[r];
}

int main(int argc,char** argv){
    #ifndef ONLINE_JUDGE
    freopen("data/d2601vh.txt","r",stdin);
    #endif

    int T; scanf("%d",&T);
    while(T--){
        int N,M; scanf("%d%d",&N,&M);

        vector<Edge> edges(M);
        for(int i=0;i<M;i++)
            scanf("%d%d%d",&edges[i].u,&edges[i].v,&edges[i].w);

        sort(edges.begin(),edges.end());

        int Q; scanf("%d",&Q);

        vector<int> X(Q),Y(Q);
        for(int i=0;i<Q;i++)
            scanf("%d%d",&X[i],&Y[i]);

        vector<int> lo(Q,0), hi(Q,M-1), ans_idx(Q,-1);

        for(int iter=0; iter<20; iter++){
            vector<vector<int>> bucket(M);
            bool any=false;

            for(int i=0;i<Q;i++){
                if(lo[i]<=hi[i]){
                    int mid = (lo[i]+hi[i])/2;
                    bucket[mid].push_back(i);
                    any=true;
                }
            }
            if(!any) break;

            init(N);
            vector<int> deg(N,0);

            for(int i=0;i<M;i++){
                int u=edges[i].u;
                int v=edges[i].v;

                deg[u]++; deg[v]++;
                if(deg[u]==3) markDeg3(u);
                if(deg[v]==3) markDeg3(v);

                addEdge(u,v);

                for(int q : bucket[i]){
                    int rx = find(X[q]);
                    int ry = find(Y[q]);

                    bool ok = (rx==ry) && possible(rx);

                    if(ok){
                        ans_idx[q]=i;
                        hi[q]=i-1;
                    }else{
                        lo[q]=i+1;
                    }
                }
            }
        }

        for(int i=0;i<Q;i++){
            if(ans_idx[i]==-1) printf("-1 ");
            else printf("%d ",edges[ans_idx[i]].w);
        }
        printf("\n");
    }
    return 0;
}