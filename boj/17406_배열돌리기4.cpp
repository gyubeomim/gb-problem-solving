#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <map>
#include <stack>
#include <deque>
#include <cmath>
#include <algorithm>

using namespace std;

int A[51][51] = {0};
int copyA[51][51] = {0};
bool visited[7] = {false};
int N,M,K;
int ans=9999;

struct Rot {
	int r,c,s;
};

vector<Rot> tmpRots;
vector<Rot> Rots;

void RotateSubMatrix(Rot rot) {
	int r = rot.r -1;
	int c = rot.c -1;
	int s = rot.s;
	
	int tmpA[51][51] = {0};
	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
			tmpA[i][j] = A[i][j];
		}
	}

	
	while(s>0) {
		int sr = r-s;
		int er = r+s;
		int sc = c-s;
		int ec = c+s;

		int i = sr;
		int j = sc;

		while(j<ec) {
			tmpA[i][j+1] = A[i][j];
			j++;
		}

		while(i<er) {
			tmpA[i+1][j] = A[i][j];
			i++;
		}

		while(j>sc) {
			tmpA[i][j-1] = A[i][j];
			j--;
		}

		while(i>sr) {
			tmpA[i-1][j] = A[i][j];
			i--;
		}

		for(int i=0;i<N;i++){
			for(int j=0;j<M;j++){
				A[i][j] = tmpA[i][j];
			}
		}
		s--;
	}

	// cout << endl << "Rot A" << endl;
	// for(int i=0;i<N;i++){
	// 	for(int j=0;j<M;j++){
	// 		cout << A[i][j] << ' ';
	// 	}
	// 	cout << endl;
	// }
	// cout << endl;
}


int Calculate() {
	int min_val= 9999;
	
	for(int r=0; r<N; r++){
		int sum=0;
		for(int c=0; c<M; c++){
			sum += A[r][c];
		}
		if(sum < min_val) {
			min_val = sum;
		}
	}
	// cout<<"minval: " << min_val<< endl;
	return min_val;
}

void Reset(){
	for(int i=0; i<N; i++){
		for(int j=0; j<M; j++){
			A[i][j] = copyA[i][j];
		}
	}
}

void Backtracking() {
	
	if(Rots.size() == K) {
		for(int i=0; i<Rots.size(); i++){
			RotateSubMatrix(Rots[i]);
		}
		ans = min(ans, Calculate());
		Reset();

		return;
	}


	for(int i=0; i<K; i++) {
		if(!visited[i]) {
			visited[i] = true;
			Rots.push_back(tmpRots[i]);
			Backtracking();
			Rots.pop_back();
			visited[i] = false;
		}
	}
}

int main(int argc, char **argv){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	cin >> N>>M>>K;

	for(int i=0; i<N;i++){
		for(int j=0;j<M;j++){
			cin >> A[i][j];
			copyA[i][j] = A[i][j];
		}
	}


	for(int i=0; i<K; i++){
		Rot rot;
		cin >> rot.r >> rot.c >> rot.s;
		tmpRots.push_back(rot);
	}

	Backtracking();

	cout << ans;
	 

	return 0;
}
