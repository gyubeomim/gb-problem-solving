#include <bits/stdc++.h>

using namespace std;





const int dx[4] = {-1,1,0,0};
const int dy[4] = {0,0,-1,1};


char board[12][6] = {};

bool visited[12][6] = {0};


int cont=1;


vector<pair<int,int>> coords;









void ApplyGravity() {


	bool move;




	while(1) {

		move = false;

		for(int i=11; i>0; i--) {
			for(int j=0; j<6; j++) {

				if(board[i][j] == '.' && board[i-1][j] != '.') {
					board[i][j] = board[i-1][j];
					board[i-1][j] = '.';
					move = true;

					// cout << "ij " << i << ", " << j << endl;
				}

			}
		}


		if(!move) break;
	}


	// cout << "\n------------S\n";

	// for(int i=0;i<12;i++) {
	// 	for(int j=0;j<6;j++) {
	// 		cout << board[i][j];
	// 	}
	// 	cout << endl;
	// }
	// cout << "--------------E\n";



}









void FindBubbles(int x, int y, char color) {
	visited[x][y] = true;

	coords.push_back(make_pair(x,y));


	for(int d=0; d<4; d++) {
		int nx = x + dx[d];
		int ny = y + dy[d];


		if(nx < 0 || nx >=12 || ny < 0 || ny >= 6) continue;
		if(visited[nx][ny]) continue;
		if(board[nx][ny] != board[x][y]) continue;


		cont++;
		// cout << "nxnycolor: " << nx << ", " << ny << ", " << color << ", " << cont << endl;
		FindBubbles(nx, ny, color);

		

	}
}














bool RemoveBubbles() {
	if(cont >= 4) {
		for(auto it : coords) {
			board[it.first][it.second] = '.';
		}

		return true;
	}

	return false;
}











int main() {

	for(int i=0; i<12; i++) {
		for(int j=0; j<7; j++) {
			char c;
			scanf("%c", &c);

			if(c == ' ') continue;

			board[i][j] = c;

			// cout << "ij: " << i << ", " << j << ", " << c << endl;
		}
	}






	int count=0;








	while(1) {


		bool removed;
		bool found = false;
		bool update =false;




		for(int i=11; i>=0; i--) {
			for(int j=0; j<6; j++) {


				if(board[i][j] != '.' && !visited[i][j]) {

					// cout << "ij: " << i << ", " << j << endl;


					coords.clear();

					FindBubbles(i, j, board[i][j]);

					removed = RemoveBubbles();

					cont = 1;




					if(removed) {
						found = true;
					}


					memset(visited, 0, sizeof(visited));

				}

			}
		}


		ApplyGravity();


		if(found) {
			count++;
		}
		else break;




	}


	cout << count << '\n';



	

	return 0;
}