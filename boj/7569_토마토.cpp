#include <bits/stdc++.h>

using namespace std;

int board[100][100][100] = {-2};

	int N,M,H;

int dx[]={-1,1, 0,0, 0,0};
int dy[]={ 0,0,-1,1, 0,0};
int dz[]={ 0,0, 0,0,-1,1};


struct Coord{
	int x_,y_,z_;

	Coord(int x, int y, int z){
		x_=x;
		y_=y;
		z_=z;
	}
};

queue<Coord> Q;


int bfs(){

		int day=0;
		while (!Q.empty())
		{
			int qsize = Q.size();
			int count=0;
			for (int i = 0; i < qsize; i++)
			{

				Coord c = Q.front();
				Q.pop();

				for (int d = 0; d < 6; d++)
				{
					int nx = c.x_ + dx[d];
					int ny = c.y_ + dy[d];
					int nz = c.z_ + dz[d];

					if (nx < 0 || nx >= N || ny < 0 || ny >= M || nz < 0 || nz >= H)
						continue;
					if (board[nx][ny][nz] == -1)
						continue;
					if (board[nx][ny][nz] == 1)
						continue;

					// cout << "board: " << board[nx][ny][nz] << endl;

					board[nx][ny][nz] = 1;
					Q.push(Coord(nx, ny, nz));
					count++;

					// cout << "nxnynz: " << nx << ", " << ny << ", " << nz << ", day: " << day << endl;
				}
			}
			if(count) {
				day++;
			}
			
		}

		return day;
}


bool CheckTomato(){
	// cout << "--------------------------" << endl;
	// for (int z = 0; z < H; z++)	{
	// 	for (int y = 0; y < M; y++)		{
	// 		for (int x = 0; x < N; x++)			{
	// 			cout << board[x][y][z] << ' ';
	// 		}
	// 		cout << endl;
	// 	}
	// 	cout << endl;
	// }




	for (int z = 0; z < H; z++)	{
		for (int y = 0; y < M; y++)		{
			for (int x = 0; x < N; x++)			{
				if (board[x][y][z] == 0)				{
					return false;
				}
			}
		}
	}

		return true;
}


int main() {
	cin>>N>>M>>H;


	for (int z = 0; z < H; z++)	{
		for (int y = 0; y < M; y++)		{
			for (int x = 0; x < N; x++)			{
				int tomato;
				cin>>tomato;	
				board[x][y][z] = tomato;

				if(tomato == 1) {
					Q.push(Coord(x,y,z));
				}

			}
		}
	}


	int day=0;
	if(Q.size() == 0) {
		cout << -1 << '\n';
	}
	else {
		day = bfs();
		if(!CheckTomato()){
			cout << -1 << '\n';
		}
		else {
			cout << day << '\n';
		}
	}






	return 0;
}