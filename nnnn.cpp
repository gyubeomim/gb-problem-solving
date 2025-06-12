#include <bits/stdc++.h>
#define rnt register int
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define WATCH(x) cout << #x << " : " << x << '\n';
#define PRINT(x) cout << x << '\n';
#define X first
#define Y second
using pii = std::pair<int,int>;
using ll = long long;
using namespace std;

const int INF = numeric_limits<int>::max();
const int LM = 1005;

int V;
vector<pii> adj[LM];

vector<int> bellmanFord(int src){
    vector<int> upper(V,INF);
    upper[src] = 0;
    bool updated;

    for(int iter=0; iter<V; iter++){
        updated = false;
        for(int cur=0; cur<V; cur++){
            for(int i=0; i<adj[cur].size(); i++) {
              int next = adj[cur][i].X;
              int cost = adj[cur][i].Y;

              if(upper[next] > upper[cur]+cost){
                upper[next] = upper[cur]+cost;
                updated=true;
              }
            }
        }
        if(!updated) break;
    }
    if(updated) upper.clear();
    return upper;
}

int main(int argc, char **argv){

}