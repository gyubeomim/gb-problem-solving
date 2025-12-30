#include <bits/stdc++.h>

using namespace std;



	int R, C;


char board[50][50] = {};
bool visited[50][50] = {0};




const int dr[4] = {-1, 1, 0, 0};
const int dc[4] = {0, 0, -1, 1};



vector<int> starts;
vector<int> waters;






int bfs(int dest) {

	queue<int> Q, Qw;




	for(auto it : starts) {
	Q.push(it);
	}

	for(auto it : waters) {
		Qw.push(it);
	}





	int destx = dest / 50;
	int desty = dest % 50;




	int step = 0;



	while(!Q.empty()) {
		int qsize = Q.size();
		int qwsize = Qw.size();


		for(int i=0; i<qwsize; i++) {
			int rw = Qw.front() / 50;
			int cw = Qw.front() % 50;



			Qw.pop();



			for(int d=0; d<4; d++) {
				int nrw = rw + dr[d];
				int ncw = cw + dc[d];



				if(nrw < 0 || nrw >= R || ncw < 0 || ncw >= C) continue;
				if(board[nrw][ncw] == 'S' || 
				board[nrw][ncw] == 'X' || 
				board[nrw][ncw] == 'D' ||
				board[nrw][ncw] == '*') continue;

				board[nrw][ncw] = '*';
				Qw.push(nrw * 50 + ncw);
			}


		}



		for(int i=0; i<qsize; i++) {
			int r = Q.front() / 50;
			int c = Q.front() % 50;



			Q.pop();


			if(r == destx && c == desty) {
				return step;
			}



			for(int d=0; d<4; d++) {
				int nr = r + dr[d];
				int nc = c + dc[d];


				if(nr < 0 || nr >= R || nc < 0 || nc >= C) continue;
				if(board[nr][nc] == '*' || board[nr][nc] == 'X') continue;
				if(visited[nr][nc]) continue;

				visited[nr][nc] = true;
				Q.push(nr * 50 + nc);
			}


		}



	// 	cout << "step: " << step << endl;
	// for(int i=0; i<R; i++) {
	// 	for(int j=0; j<C; j++) {
	// 		cout << board[i][j] << ' ';
	// 	}
	// 	cout << endl;
	// }
	// cout << endl;




		step++;
	}



	return -1;

}








int main() {
	cin >> R >> C;



	int dest;





	for(int i=0; i<R; i++) {
		for(int j=0; j<C; j++) {
			char c;
			cin >> c;

			board[i][j] = c;


			if(c == 'D') {
				dest = i*50 + j;
			}

			if(c == '*') {
				waters.push_back(i*50 + j);
			}

			if(c == 'S') {
				starts.push_back(i*50 +j);
				visited[i][j] = true;
			}


		}
	}





	int ans = bfs(dest);





	if(ans == -1) {
		cout << "KAKTUS";
	}
	else {
		cout << ans << '\n';
	}
	

	return 0;
}