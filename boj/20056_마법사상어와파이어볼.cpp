#include <bits/stdc++.h>

using namespace std;

struct Fireball{
	int r,c,m,s,d;

	Fireball(int r, int c,int m, int s, int d)
		:r(r), c(c), m(m), s(s), d(d) {}
};

int N,M,K;
int dr[8]={-1,-1,0,1,1,1,0,-1};
int dc[8]={0,1,1,1,0,-1,-1,-1};
vector<Fireball> board[50][50];

Fireball Move(Fireball f){
	for(int i=0; i<f.s; i++){
		f.r += dr[f.d];
		if(f.r > N-1) f.r = 0;
		else if(f.r < 0) f.r = N-1;

		f.c += dc[f.d];
		if(f.c > N-1) f.c = 0;
		else if(f.c < 0) f.c = N-1;
	}

	return f;
}

void MoveFireballs(){
	vector<Fireball> new_board[50][50];
	
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			for(Fireball f : board[i][j]){
				Fireball next = Move(f);
				new_board[next.r][next.c].push_back(next);
			}
		}
	}

	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			board[i][j] = new_board[i][j];
		}
	}
}

void UnionFireballs(){
	
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			if(board[i][j].size() < 2) continue;

			int totM=0, totS=0, totN=board[i][j].size();
			int chk=0;

			for(Fireball f : board[i][j]) {
				totM += f.m;
				totS += f.s;

				if(f.d % 2 == 0) chk++;
				else chk--;
			}
			board[i][j].clear();
			
			totM /= 5;
			if(totM == 0) continue;
			totS /= totN;
			
			for(int d=0; d<4; d++){
				if(abs(chk) == totN) {
					board[i][j].push_back(Fireball(i,j,totM,totS,d*2));
				}
				else {

					board[i][j].push_back(Fireball(i,j,totM,totS,d*2+1));
				}
			}
		}
	}

}


int main(int argc, char **argv){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	cin>>N>>M>>K;
	for(int i=0; i<M; i++){
		int r,c,m,s,d;
		cin >> r>>c>>m>>s>>d;
		board[r-1][c-1].push_back(Fireball(r-1,c-1,m,s,d));
	}

	while(K--){
		MoveFireballs();
		UnionFireballs();
	}

	int ans=0;
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			for(Fireball f : board[i][j]){
				ans += f.m;
			}
		}
	}
	
	cout << ans;

	return 0;
}
