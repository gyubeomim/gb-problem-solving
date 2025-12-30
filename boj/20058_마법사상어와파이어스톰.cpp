#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <map>
#include <stack>
#include <deque>
#include <cmath>
#include <algorithm>
#include <cstring>

#define pii pair<int,int>
#define ll long long
#define MAX_N 1000

using namespace std;

int N, NN;
int board[MAX_N][MAX_N];
vector<int> B;

bool ck[MAX_N][MAX_N];

const int dr[4] = {-1,1,0,0};
const int dc[4] = {0,0,1,-1};


int** ReadSubmatrix(int r,int c, int b) {
	int** sub;
	sub = new int*[b];
	for(int i=0; i<b; i++){
		sub[i] = new int[b];
	}
	
	for(int i=r; i<r+b; i++){
		for(int j=c; j<c+b; j++){
			sub[i-r][j-c] = board[i][j];
		}
	}

	return sub;
}

void PrintMatrix(int** sub, int b) {
	cout << "Sub" << endl;
	for(int i=0; i<b; i++){
		for(int j=0; j<b; j++){
			cout << sub[i][j] << ' ';
		}
		cout << endl;
	}
}

void RotateSubmatrix(int** sub, int b) {
	int* tmp;
	tmp = new int[b*b];

	int cnt=0;
	for(int c=0; c<b; c++){
		for(int r=b-1; r>=0; r--){
			*(tmp+cnt++) = sub[r][c];
		}
	}
	
	for(int r=0; r<b; r++){
		for(int c=0; c<b; c++){
			sub[r][c] = tmp[r*b + c];
		}
	}
}

void WriteSubmatrix(int** sub,int r, int c, int b) {
	for(int i=r; i<r+b; i++) {
		for(int j=c; j<c+b; j++){
			board[i][j] = sub[i-r][j-c];
		}
	}
}

void Rotate(int b){
	for(int r=0; r<=NN-b; r+=b){
		for(int c=0; c<=NN-b; c+=b){
			int** sub = ReadSubmatrix(r,c,b);
			// PrintMatrix(sub, b);
			RotateSubmatrix(sub,b);
			WriteSubmatrix(sub,r,c,b);
		}
	}
}

pii CheckMeltDown(int r, int c) {
	pii m = make_pair(-1,-1);
	int count = 0;

	for(int d=0; d<4; d++){
		int nr = r + dr[d];
		int nc = c + dc[d];

		if(nr<0 || nr>NN-1 || nc<0 || nc>NN-1) continue;
		if(board[nr][nc] == 0) continue;

		count++;
	}

	if(count < 3) {
		m = make_pair(r,c);
	}
	return m;
}

void DecreaseIce() {
	vector<pii> meltdowns;

	for(int i=0; i<NN; i++){
		for(int j=0; j<NN; j++){
			if(board[i][j] == 0) continue;

			pii m = CheckMeltDown(i,j);
			if(m.first != -1 && m.second != -1)
				meltdowns.push_back(m);
		}
	}

	for(auto m : meltdowns) {
		int r = m.first;
		int c = m.second;

		board[r][c]--;
	}
	
}

int BFS2(int r, int c) {
	queue<pii> q;
	q.push({r,c});
		
	ck[r][c] = true;
	int count = 1;

	while(!q.empty()) {
		int rr = q.front().first;
		int cc = q.front().second;
		q.pop();

		for(int d=0; d<4; d++){
			int nr = rr + dr[d];
			int nc = cc + dc[d];

			if(nr<0 || nr>NN-1 || nc<0 || nc>NN-1) continue;
			if(ck[nr][nc]) continue;
			if(board[nr][nc] == 0) continue;
	
			ck[nr][nc] = true;
			q.push({nr,nc});
			count++;
		}
	}

	return count;
}

void CalcResult() {
	memset(ck, false, sizeof(ck));

	int tot_sum=0;
	for(int i=0; i<NN; i++){
		for(int j=0; j<NN; j++){
			if(board[i][j] <= 0) continue;
			tot_sum += board[i][j];
		}
	}

	int count=0;
	for(int i=0; i<NN; i++){
		for(int j=0; j<NN; j++){
			if(ck[i][j] || board[i][j] <= 0) continue;
			count = max(count, BFS2(i,j));

		}
	}

	cout << tot_sum << '\n' << count << '\n';
}

int main(int argc, char **argv){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
		
	int K;
	cin >> N >> K;
	
	NN = 1 << N;

	for(int i=0; i<NN; i++){
		for(int j=0; j<NN; j++){
			cin >> board[i][j];
		}
	}
	
	for(int i=0; i<K; i++){
		int b;
		cin>>b;

		int bb = 1 << b;

		B.push_back(bb);
	}
	
	for(auto bb : B) {
		Rotate(bb);
		DecreaseIce();
	}

	CalcResult();

	return 0;
}
