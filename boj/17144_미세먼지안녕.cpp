#include <bits/stdc++.h>

#define pii pair<int,int>
#define ll long long

using namespace std;

const int dr[] = {-1,1,0,0};
const int dc[] = {0,0,-1,1};

int R,C,T;
int board[50][50];
int tmpboard[50][50];

void DistributeDust() {
	 for(int r=0; r<R; r++){
		 for(int c=0; c<C;c++){
			 if(board[r][c] > 0 ){
				 int div = board[r][c]/5;
				
				 int cnt=0;
				 for(int d=0; d<4; d++){
					 int nr = r + dr[d];
					 int nc = c + dc[d];

					if(nr<0 || nr>R-1 || nc<0 || nc>C-1) continue;
					if(board[nr][nc] == -1) continue;

					cnt++;
					tmpboard[nr][nc] += div;

					// cout<< "rc: "<< r << ", " << c << endl;
					// cout << "nrnc passed: "<< nr << ", " << nc << ", cnt: " << cnt << ", div: " << div << endl << endl;
				 }

				 tmpboard[r][c] -= cnt * div;
			 }
		 }
	 }

	 for(int r=0; r<R; r++){
		 for(int c=0; c<C;c++){
			 board[r][c] += tmpboard[r][c];
		 }
	 }

	 memset(tmpboard, 0, sizeof(tmpboard));
}

void RotateWind() {

	int upr=0;
	int downr=0;
	
	for(int r=0; r<R; r++) {
		if(board[r][0] == -1) {
			upr = r;
			downr = r+1;
			break;
		}
	}

	// cout << "updownr: " << upr << ", " << downr << endl;

	// Up Wind
	for(int r=upr-1; r>=1; r--){
		board[r][0] = board[r-1][0];
		board[r-1][0] = 0;
	}
	for(int c=0; c<=C-2; c++){
		board[0][c] = board[0][c+1];
		board[0][c+1]=0;
	}
	for(int r=0; r<=upr-1; r++){
		board[r][C-1] = board[r+1][C-1];
		board[r+1][C-1] = 0;
	}
	for(int c=C-1; c>=2; c--){
		board[upr][c] = board[upr][c-1];
		board[upr][c-1] = 0;
	}
	board[upr][1] = 0;

	// cout << "AFT UpWIND board: " << endl;
	// for(int r=0; r<R; r++){
	// 	for(int c=0; c<C;c++){
	// 		cout << board[r][c] << ' ';
	// 	}
	// 	cout << endl;
	// }
	// cout << endl;


	// Down Wind
	for(int r=downr+1; r<=R-2; r++){
		board[r][0] = board[r+1][0];
		board[r+1][0] = 0;
	}
	for(int c=0; c<=C-2; c++){
		board[R-1][c] = board[R-1][c+1];
		board[R-1][c+1]=0;
	}
	for(int r=R-1; r>=downr+1 ;r--){
		board[r][C-1] = board[r-1][C-1];
		board[r-1][C-1]=0;
	}
	for(int c=C-1; c>=2; c--){
		board[downr][c] = board[downr][c-1];
		board[downr][c-1] = 0;
	}
	board[downr][1] = 0;

	// cout << "AFT DownWIND board: " << endl;
	// for(int r=0; r<R; r++){
	// 	for(int c=0; c<C;c++){
	// 		cout << board[r][c] << ' ';
	// 	}
	// 	cout << endl;
	// }
	// cout << endl;


}

int main(int argc, char **argv){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	 cin >> R >> C >> T;

	 for(int r=0; r<R; r++){
		 for(int c=0; c<C;c++){
			 cin >> board[r][c];
		 }
	 }

	  // cout << "BEF board: " << endl;
	  // for(int r=0; r<R; r++){
	  //   for(int c=0; c<C;c++){
	  //  	 cout << board[r][c] << ' ';
	  //   }
	  //   cout << endl;
	  // }

	 int t=0; 
	 while(t < T) {
		DistributeDust();

		// cout << "AFT DUST board: " << endl;
		// for(int r=0; r<R; r++){
		// 	for(int c=0; c<C;c++){
		// 		cout << board[r][c] << ' ';
		// 	}
		// 	cout << endl;
		// }
		// cout << endl;

		RotateWind();

		// cout << "AFT WIND board: " << endl;
		// for(int r=0; r<R; r++){
		// 	for(int c=0; c<C;c++){
		// 		cout << board[r][c] << ' ';
		// 	}
		// 	cout << endl;
		// }
		// cout << endl;

		t++;
	 }

     

	
	 int sum=0;
	 for(int r=0; r<R; r++){
		 for(int c=0; c<C;c++){
			 if(board[r][c] != -1) {
				 sum += board[r][c];
			 }
		 }
	 }

	 cout << sum;

	return 0;
}
