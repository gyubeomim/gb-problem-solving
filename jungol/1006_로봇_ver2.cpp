#include <bits/stdc++.h>
#define rnt register int
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define X first
#define Y second
using pii = std::pair<int,int>;
using ll = long long;
using namespace std;

constexpr int LM = 105;
constexpr int INF = 0x3f3f3f3f;

enum DIR { E_=1, W_=2, S_=3, N_=4 };

int M,N;
int board[LM][LM];

int sr,sc,sd;
int er,ec,ed;

struct Data{
    int r,c,d, step;
    bool operator<(const Data& r) const {
        return step > r.step;  // min-heap
    }
};

int dist[LM][LM][5];

constexpr int dr[] = {0, 0,0,1,-1};  // E, W, S, N (from index 1)
constexpr int dc[] = {0, 1,-1,0,0};

int turn(int from, int to) {
    if(from == to) return 0;
    if((from==E_ && to==W_) || (from==W_ && to == E_) ||
            (from==S_ && to==N_) || (from==N_ && to==S_)) {
                return 2;
    }
    return 1;
}

int dijkstra() {
	for(int i=1;i<=M;i++){
		for(int j=1;j<=N;j++){
			for(int k=1; k<=4; k++){
				dist[i][j][k] = INF;
			}
		}
	}
    
	priority_queue<Data> pq;
	dist[sr][sc][sd] = 0;
	pq.push({sr,sc,sd,0});

	while(!pq.empty()){
		auto [ r, c, d, step ] = pq.top(); pq.pop();

		if(step > dist[r][c][d]) continue;

		if(r == er && c == ec){
			return step + turn(d, ed);
		}

		// TURN
		for(int nd=1; nd<=4; nd++){
			if(nd == d) continue;
			int nstep = step + turn(d, nd);
			if(dist[r][c][nd] > nstep){
				dist[r][c][nd] = nstep;
				pq.push({ r, c, nd, nstep });
			}
		}

		// GO
		for(int i=1; i<=3; i++){
			int nr = r + dr[d] * i;
			int nc = c + dc[d] * i;
			if(nr<1 || nr>M || nc<1 || nc>N) break;
			if(board[nr][nc] == 1) break;
			
			int nstep = step + 1;
			if(dist[nr][nc][d] > nstep){
				dist[nr][nc][d] = nstep;
				pq.push({nr, nc, d, nstep});
			}
		}
	}
	return -1;
}

int main(int argc, char **argv){
    #ifndef ONLINE_JUDGE
        freopen("data/d1006.txt", "r", stdin);
    #endif
    
    FASTIO;
    
    cin >> M >> N;
    for(int r=1; r<=M; r++){
        for(int c=1; c<=N; c++){
            cin >> board[r][c];
        }
    }
    
    cin >> sr >> sc >> sd;
    cin >> er >> ec >> ed;
    
    int ans = dijkstra();
    cout << ans << "\n";
    
    return 0;
}
