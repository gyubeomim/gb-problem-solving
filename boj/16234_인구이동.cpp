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

const int dr[]={0,-1,1,0,0};
const int dc[]={0,0,0,-1,1};
int N,L,R;
int board[50][50] = {0};
int tmpboard[50][50] = {0};
int connected[50][50] = {0};
int label=1;
int days=0;

int sum[10001] = {0};
int cnt[10001] = {0};

void BFS(int r, int c) {
	if(connected[r][c]) return;

	queue<pair<int,int>> Q;
	Q.push(make_pair(r,c));

	while(!Q.empty()){
		int r = Q.front().first;
		int c = Q.front().second;
		Q.pop();

		for(int d=0; d<5; d++) {
			int nr = r + dr[d];
			int nc = c + dc[d];

			// cout << "rc: " << r << ", " << c <<  ", nrnc: " << nr << ", " << nc << endl;

			if(nr < 0 || nr > N-1 || nc < 0 || nc > N-1) continue;
			if(connected[nr][nc]) continue;

			if(abs(board[nr][nc] - board[r][c]) >= L && abs(board[nr][nc] - board[r][c]) <= R) {
				connected[nr][nc] = label;
				Q.push(make_pair(nr, nc));
				sum[label] += board[nr][nc];
				cnt[label]++;
				// cout << "connected label: " << label << ", nrnc: " << nr << ", " << nc << endl;
			}
		}
	}
	label++;
}

void Distribute() {
	for(int l=1; l<=label; l++) {
		if(cnt[l] == 0) continue;

		for(int r=0; r<N; r++) {
			for(int c=0; c<N; c++) {
				if(connected[r][c] == l) {
					board[r][c] = sum[l] / cnt[l];
				}
			}
		}

	}
	

}

bool IsEnd() {
	// for(int r=0; r<N; r++) {
	// 	for(int c=0; c<N; c++) {
	// 		if(tmpboard[r][c] != board[r][c]) {
	// 			return false;
	// 		}
	// 	}
	// }
    //
	// return true;


	for(int l=1; l<=label; l++) {
		if(cnt[l] > 1) {
			return false;
		}
	}
	return true;
}

void Copy() {
	// cout << "DEBUG tmpboard" << endl;
	// for(int r=0; r<N; r++) {
	// 	for(int c=0; c<N; c++) {
	// 		cout << tmpboard[r][c] << ' ';
	// 	}
	// 	cout << endl;
	// }
	// cout << endl;
	//
	// cout << "DEBUG board" << endl;
	// for(int r=0; r<N; r++) {
	// 	for(int c=0; c<N; c++) {
	// 		cout << board[r][c] << ' ';
	// 	}
	// 	cout << endl;
	// }
	// cout << endl;

	for(int r=0; r<N; r++) {
		for(int c=0; c<N; c++) {
			tmpboard[r][c] = board[r][c];
		}
	}
}

int main(int argc, char **argv){
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin>>N>>L>>R;

	for(int i=0; i<N;i++){
		for(int j=0;j<N;j++){
			cin >> board[i][j];
			tmpboard[i][j] = board[i][j];
		}
	}

	while(true) {
		memset(connected, 0, sizeof(connected));
		memset(sum, 0, sizeof(sum));
		memset(cnt, 0, sizeof(cnt));
		label=1;
		
		for(int r=0; r<N;r++){
			for(int c=0;c<N;c++){
				// cout << "IN rc: " << r << ", "<<c<<endl;
				if(!connected[r][c])
					BFS(r,c);
			}
		}

		Distribute();

		if(IsEnd()) {
			cout << days;
			return 0;
		}
		else { 
			days++; 
			Copy();
		}

		// cout<<days<<endl;
	}

	return 0;
}
