#include <bits/stdc++.h>

#define pii pair<int,int>
#define ll long long

using namespace std;

int N,M,T;
int board[51][51] = {0};

struct Rotate {
	int x;
	int d;
	int k;
};
vector<Rotate> v;

// CW >>>>
void RotationCW(const int r, int k) {
	// cout << "Bef RotationCW >>>> rk: " << r << ", " << k << endl;
	// for(int r=1; r<=N; r++) {
	// 	for(int c=1; c<=M; c++) {
	// 		cout << board[r][c] << ' ';
	// 	}
	// 	cout << endl;
	// }

	while(k--) {
		int tmpval = board[r][M];
		for(int c=M; c>=2; c--) {
			board[r][c] = board[r][c-1];
		}
		board[r][1] = tmpval;
	}

	// cout << "Aft RotationCW >>>> rk: " << r << ", " << k << endl;
	// for(int r=1; r<=N; r++) {
	// 	for(int c=1; c<=M; c++) {
	// 		cout << board[r][c] << ' ';
	// 	}
	// 	cout << endl;
	// }

}

// CCW <<<<
void RotationCCW(const int r, int k) {
	// cout << "Bef RotationCCW <<<< rk: " << r << ", " << k << endl;
	// for(int r=1; r<=N; r++) {
	// 	for(int c=1; c<=M; c++) {
	// 		cout << board[r][c] << ' ';
	// 	}
	// 	cout << endl;
	// }

	while(k--) {
		int tmpval = board[r][1];
		for(int c=1; c<=M-1; c++) {
			board[r][c] = board[r][c+1];
		}
		board[r][M] = tmpval;
	}

	// cout << "Aft RotationCCW <<<< rk: " << r << ", " << k << endl;
	// for(int r=1; r<=N; r++) {
	// 	for(int c=1; c<=M; c++) {
	// 		cout << board[r][c] << ' ';
	// 	}
	// 	cout << endl;
	// }
}

void RemoveAdjecents() {
	int ck[51][51] = {0};
	bool found = false;

	memset(ck, 0, sizeof(ck));

	for(int r=1; r<=N; r++) {
		for(int c=1; c<=M; c++) {
			if(board[r][c] >0){
				if(c>1 && board[r][c] == board[r][c-1]){
					ck[r][c] = 1;
					ck[r][c-1] = 1;
					found = true;
				}

				if(board[r][1] != 0 && board[r][1] == board[r][M]){
					ck[r][1] = 1;
					ck[r][M] = 1;
					found = true;
				}

				if(r>1) {
					if(board[r][c] == board[r-1][c]) {
						ck[r][c] = 1;
						ck[r-1][c] = 1;
						found = true;
					}
				}
			}
		}
	}

	if(found) {
		// cout << "Found!"<<endl;
		for(int r=1; r<=N; r++) {
			for(int c=1; c<=M; c++) {
				if(ck[r][c]) {
					// cout << "Found rc: " << r << ", "<<c<<endl;
					board[r][c] = 0;
				}
			}
		}
	}
	else {
		double sum =0;
		double avg=0;
		int count=0;

		for(int r=1; r<=N; r++) {
			for(int c=1; c<=M; c++) {
				if(board[r][c]>0){
					sum += board[r][c];
					count++;
				}
			}
		}

		avg = (double)sum / count;

		// cout << "Not Found avg: " << avg << ", " <<sum<<","<<count<<endl;

		for(int r=1; r<=N; r++) {
			for(int c=1; c<=M; c++) {
				if(board[r][c] >0){
					if(avg > board[r][c]) {
						board[r][c]++;
					}
					else if(avg < board[r][c]){
						board[r][c]--;
					}
				}
			}
		}

	}

	// cout << "Removed Adj: " << endl;
	// for(int r=1; r<=N; r++) {
	// 	for(int c=1; c<=M; c++) {
	// 		cout << board[r][c] << ' ';
	// 	}
	// 	cout << endl;
	// }

}

void Sum() {
	int sum=0;
	
	// cout << "Sum board: " << endl;
	// for(int r=1; r<=N; r++) {
	// 	for(int c=1; c<=M; c++) {
	// 		cout << board[r][c] << ' ';
	// 	}
	// 	cout << endl;
	// }

	for(int r=1; r<=N; r++) {
		for(int c=1; c<=M; c++) {
			sum += board[r][c];
		}
	}

	cout << sum;
}

int main(int argc, char **argv){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	 cin>>N>>M>>T;

	 for(int i=1;i<=N;i++){
		 for(int j=1; j<=M;j++){
			 cin >> board[i][j];
		 }
	 }

	while(T--) {
		Rotate r;
		cin >> r.x >> r.d >> r.k;
		v.push_back(r);
	}

	// for(auto it:v){
	// 	cout <<it.x<<"," << it.d  <<","<< it.k<<endl;
	// }
	// cout<<"vsize: "<<v.size()<<endl;


	for(int i=0; i<v.size(); i++) {
		Rotate cur_r = v[i];

		const int x= cur_r.x;
		const int d= cur_r.d;
		const int k= cur_r.k;

		for(int r=1; r<=N; r++) {
			if(r % x == 0) {
				if(d == 0) {
					RotationCW(r,k);
				}
				else if (d == 1) {
					RotationCCW(r,k);
				}
			}
		}

		RemoveAdjecents();
	}
	Sum();



	return 0;
}
