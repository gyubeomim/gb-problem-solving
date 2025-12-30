#include <bits/stdc++.h>

using namespace std;

int board[300][300]={0};
int increase[300][300]={0};
int visit[300][300] = {0};

int N,M;

const int dr[4]={-1,1,0,0};
const int dc[4]={0,0,-1,1};

struct Pair{
	Pair(int r,int c){
		r_=r;
		c_=c;
	}
	int r_;
	int c_;
};

int CountNearIces(int r, int c){
  int num = 0;

  if (board[r - 1][c] == 0) num++;
  if (board[r][c - 1] == 0) num++;
  if (board[r + 1][c] == 0) num++;
  if (board[r][c + 1] == 0) num++;

	return num;
}

void MeltDown(){
	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
			if(board[i][j] != 0){
				int num = CountNearIces(i,j);
				increase[i][j] = num;
			}
		}
	}

	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
			board[i][j] -= increase[i][j];
			if(board[i][j]<0) board[i][j] = 0;
		}
	}



	memset(increase, 0, sizeof(increase));
}

bool CheckConnection() {
  Pair p(0, 0);

  bool found = false;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      if (board[i][j] != 0) {
        p.r_ = i;
        p.c_ = j;
        // cout << "PC: " << i << ", " << j << endl;
        found = true;
        break;
      }
    }
    if (found) break;
  }
	if(!found) return false;


  queue<Pair> Q;
  Q.push(p);
	visit[p.r_][p.c_] = -1;

  while (!Q.empty()) {
    int qsize = Q.size();
    for (int i = 0; i < qsize; i++) {
      Pair curr = Q.front();
      Q.pop();

      for (int d = 0; d < 4; d++) {
        int nr = curr.r_ + dr[d];
        int nc = curr.c_ + dc[d];

        if (nc < 0 || nc >= M || nr < 0 || nr >= N) continue;
        if (board[nr][nc] == 0) continue;
        if (visit[nr][nc] == -1) continue;

        visit[nr][nc] = -1;
        Pair next(nr, nc);
        Q.push(next);
      }
    }
  }


  // cout << "BOARD: " << endl;
  // for (int i = 0; i < N; i++) {
  //   for (int j = 0; j < M; j++) {
  //     cout << board[i][j] << ' ';
  //   }
  //   cout << endl;
  // }
  // cout << "VISIT: "<< endl;
  // for (int i = 0; i < N; i++) {
  //   for (int j = 0; j < M; j++) {
  //     cout << visit[i][j] << ' ';
  //   }
  //   cout << endl;
  // }


  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      if (visit[i][j] > 0) {
        return true;
      }
    }
  }

  return false;
}




int main() {
  cin >> N >> M;

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      cin >> board[i][j];
    }
  }

  int time = 1;
  while (true) {
		    MeltDown();

		for(int i=0;i<N;i++){
			for(int j=0;j<M;j++){
				visit[i][j] = board[i][j];
			}
		}


    if (CheckConnection()) {
      break;
    }

    int num=0;
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < M; j++) {
        if (visit[i][j] == 0) {
          num++;
        }
      }
    }
    if (num == N * M){
			cout << 0 << '\n';
			return 0;
		}

		time++;
  }

  cout << time << '\n';

  return 0;
}