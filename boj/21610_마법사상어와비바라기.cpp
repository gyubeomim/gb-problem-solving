#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <map>
#include <stack>
#include <deque>
#include <set>
#include <cmath>
#include <algorithm>
#include <cstring>

#define pii pair<int,int>
#define ll long long

using namespace std;

int N,M;

int** cloud;
int** board;

int roff[8] = {0, -1, -1, -1, 0, 1, 1, 1};
int coff[8] = {-1, -1, 0, 1, 1, 1, 0, -1};

void FindOtherCloud() {
	int** tmpcloud = new int*[51];
	for(int i=0; i<=50; i++){ 
		tmpcloud[i] = new int[51];
	}

	for(int r=1; r<=N; r++) {
		for(int c=1; c<=N; c++) {
			if(!cloud[r][c] && board[r][c] >= 2) {
				tmpcloud[r][c] = 1;
				board[r][c] -= 2;
			}
		}
	}

	for(int r=1; r<=N; r++) {
		for(int c=1; c<=N; c++) {
			cloud[r][c] = tmpcloud[r][c];
		}
	}
}

void WaterCopyBug() {
	int** tmpboard = new int*[51];
	for(int i=0;i<=50;i++){
		tmpboard[i] = new int[51];
	}

	for(int r=1; r<=N; r++) {
		for(int c=1; c<=N; c++) {
			tmpboard[r][c] = board[r][c];
		}
	}


	for(int r=1; r<=N; r++) {
		for(int c=1; c<=N; c++) {
			if(cloud[r][c]) {
				if(r-1 >=1 && r-1<=N && c-1>=1 && c-1<=N)
					if(board[r-1][c-1]) {
						tmpboard[r][c]++;
					}
				if(r-1 >=1 && r-1<=N && c+1>=1 && c+1<=N)
					if(board[r-1][c+1]) {
						tmpboard[r][c]++;
					}
				if(r+1 >=1 && r+1<=N && c-1>=1 && c-1<=N)
					if(board[r+1][c-1]) {
						tmpboard[r][c]++;
					}
				if(r+1 >=1 && r+1<=N && c+1>=1 && c+1<=N)
					if(board[r+1][c+1]) {
						tmpboard[r][c]++;
					}
			}
		}
	}

	for(int r=1; r<=N; r++) {
		for(int c=1; c<=N; c++) {
			board[r][c] = tmpboard[r][c];
		}
	}

}


void MoveCloud(int d, int s) {
	int** tmpcloud = new int*[51];
	for(int i=0; i<=50; i++){ 
		tmpcloud[i] = new int[51];
	}

	for(int r=1; r<=N; r++) {
		for(int c=1; c<=N; c++) {
			if(!cloud[r][c]) continue;

			int nr = r + roff[d-1] * s;
			int nc = c + coff[d-1] * s;

			// cout << "bef nrnc: " << nr << ", " << nc << endl;

			if(nr < 1) nr = N+nr;
			else if(nr > N) nr = nr-N;
			if(nc < 1) nc = N+nc;
			else if(nc > N) nc = nc-N;

			tmpcloud[nr][nc] = 1;

			// cout << "rc: " << r << ", " << c << endl;
			// cout << "nrnc: " << nr << ", " << nc << endl << endl;
		}
	}

	for(int r=1; r<=N; r++) {
		for(int c=1; c<=N; c++) {
			cloud[r][c] = tmpcloud[r][c];
		}
	}

}

void AddWater() {
	for(int r=1; r<=N; r++) {
		for(int c=1; c<=N; c++) {
			if(cloud[r][c]) {
				board[r][c]++;
			}
		}
	}
}

int main(int argc, char **argv){
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> M;

	cloud = new int*[51];
	for(int i=0;i<=50;i++){
		cloud[i] = new int[51];
	}

	board = new int*[51];
	for(int i=0;i<=50;i++){
		board[i] = new int[51];
	}

	for(int i=1; i<=N; i++) {
		for(int j=1; j<=N; j++) {
			cin >> board[i][j];
		}
	}

	vector<int> ds;
	vector<int> ss;

	for(int i=0; i<M; i++) {
		int d,s;
		cin>>d >> s;

		ds.push_back(d);
		ss.push_back(s);
	}

	cloud[N][1] = 1;
	cloud[N][2] = 1;
	cloud[N-1][1] = 1;
	cloud[N-1][2] = 1;

	for(int i=0; i<M; i++){
		int d = ds[i];
		int s = ss[i];

		if(s>N) s = s%N;
		
		MoveCloud(d,s);
		AddWater();
		WaterCopyBug();
		FindOtherCloud();
	}

	int ans=0;
	for(int r=1; r<=N; r++) {
		for(int c=1; c<=N; c++) {
			ans += board[r][c];
		}
	}

	cout << ans;




	return 0;
}
