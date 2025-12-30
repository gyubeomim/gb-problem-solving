#include <bits/stdc++.h>

using namespace std;





int board[200][200] = {0};

int visit[200][200][31] = {0};



int dw[] = { 0,0,1,-1, -2, -2, -1, -1, 1, 1, 2, 2};
int dh[] = { 1,-1,0,0, -1, 1, -2, 2, -2, 2, -1, 1};
 



int K;

int W, H;









struct Pos {
	int w_;
	int h_;
	int k_;


	Pos(int h, int w, int k) {
		h_=h;
		w_=w;
		k_=k;
	}

};









void bfs() {

	queue<Pos> Q;

	Q.push(Pos(0, 0, 0));




	memset(visit, -1, sizeof(visit));

	visit[0][0][0] = 0;






	while(!Q.empty()) {

				int h = Q.front().h_;
				int w = Q.front().w_;
				int k = Q.front().k_;

				Q.pop();








				for(int d=0; d<12; d++) {
					int nh = h + dh[d];
					int nw = w + dw[d];


					if(d>=4 && k>=K) continue;



					if(nh < 0 || nh >= H || nw < 0 || nw >= W) continue;
					if(board[nh][nw]==1) continue;
					if(d<4 && visit[nh][nw][k] != -1) continue;
					if(d>=4 && visit[nh][nw][k+1] != -1) continue;





					if (d>=4) {
						Q.push(Pos(nh, nw, k+1));
						visit[nh][nw][k+1] = visit[h][w][k] + 1;
					}
					else {
						Q.push(Pos(nh, nw, k));
						visit[nh][nw][k] = visit[h][w][k] + 1;
					}


				}

	}

}










int main() {
	cin >> K;


	cin >> W >> H;




	for(int i=0;i<H;i++) {
		for(int j=0; j<W; j++) {
			cin >> board[i][j];
		}
	}




	bfs();






	int ans = 2100000000;

	for(int i=0; i<=K; i++) {
			// cout << visit[W-1][H-1][i] << '\n';
		if(visit[H-1][W-1][i] != -1 && ans > visit[H-1][W-1][i]) {
			ans = visit[H-1][W-1][i];
		}
	}


	if(ans == 2100000000) cout << -1 << '\n';
	else cout << ans << '\n';

	




	return 0;

}