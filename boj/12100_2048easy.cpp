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

#define DEBUG false

#define pii pair<int,int>
#define ll long long

using namespace std;
int board[21][21] = {0};
int tmpboard[21][21] = {0};
int N;

void Sum(int dir) {
	switch(dir) {
		case 1: // Up
			for(int c=0; c<N; c++) {
				for(int r=0; r<N-1; r++) {
					if(board[r][c] != 0) {
						int n1 = board[r][c];

						for(int k=r+1; k<N; k++) {
							if(board[k][c]) {
								int n2 = board[k][c];

								if(n1 == n2) {
									board[r][c] += n2;
									board[k][c] = 0;
								}
								break;
							}
						}

					}
				}
			}
			break;
		case 2: // Right
			for(int r=0; r<N; r++) {
				for(int c=N-1; c>0; c--) {
					if(board[r][c] != 0) {
						int n1 = board[r][c];

						for(int k=c-1; k>=0; k--) {
							if(board[r][k]) {
								int n2 = board[r][k];

								if(n1 == n2) {
									// cout << "d2 n1n2: " << n1 << ", " << n2 << endl;
									board[r][c] += n2;
									board[r][k] = 0;
								}
								break;
							}
						}
					}
				}
			}
			break;
		case 3: // Down
			for(int c=0; c<N; c++) {
				for(int r=N-1; r>0; r--) {
					if(board[r][c] != 0) {
						int n1 = board[r][c];

						// int n2 = board[r-1][c];
                        //
						// if(n1 == n2) {
						// 	board[r][c] += n2;
						// 	board[r-1][c] = 0;
						// 	r--;
						// }

						for(int k=r-1; k>=0; k--) {
							if(board[k][c]) {
								int n2 = board[k][c];

								if(n1 == n2) {
									// cout << "d3 n1n2: " << n1 << ", " << n2 << endl;
									board[r][c] += n2;
									board[k][c] = 0;
								}
								break;
							}
						}


					}
				}
			}
			break;
		case 4: // Left
			for(int r=0; r<N; r++) {
				for(int c=0; c<N-1; c++) {
					if(board[r][c] != 0) {
						int n1 = board[r][c];

						// int n2 = board[r][c+1];
                        //
						// if(n1 == n2) {
						// 	board[r][c] += n2;
						// 	board[r][c+1] = 0;
						// 	c++;
						// }

						for(int k=c+1; k<N; k++) {
							if(board[r][k]) {
								int n2 = board[r][k];

								if(n1 == n2) {
									// cout << "d4 n1n2: " << n1 << ", " << n2 << endl;
									board[r][c] += n2;
									board[r][k] = 0;
								}
								break;
							}
						}

					}
				}
			}
			break;
	}

#if DEBUG
	cout << "IN Sum()" << endl;
	for(int i=0; i<N;i++){
		for(int j=0;j<N;j++){
			cout << board[i][j] << ' ';
		}
		cout << endl;
	}
#endif
}

void Move(int dir) {
	switch(dir) {
		case 1: // Up
			for(int c=0; c<N; c++) {
				for(int r=0; r<N; r++) {
					if(board[r][c] != 0) {

						// cout << "d1 rc: " << r << ", " <<c << endl;

						for(int k=r-1; k>=0; k--) {
							if(board[k][c]) {
								// cout << "d1 k: "<< k << ", rc: "<< r<< ", " << c << endl;
								if(k+1>0 && k+1<N && r!=k+1) {
									k++;
									board[k][c] = board[r][c];
									board[r][c] = 0;
								}
								break;
							}
							else if(board[k][c] == 0 && k == 0) {
								board[k][c] = board[r][c];
								board[r][c] = 0;
							}
						}

						// cout << "debug3: " << r << ", " <<c << endl;
					}
				}
			}
			break;
		case 2: // Right
			for(int r=0; r<N; r++) {
				for(int c=N-1; c>=0; c--) {
					if(board[r][c] != 0) {
						// cout << "d2 board[r][c]: " << r << ", " << c << ", " << board[r][c] << endl;

						for(int k=c+1; k<N; k++) {
							if(board[r][k]) {
								// cout << "d2 found k: " << k << endl;
								if(k-1>0 && k-1<N && c != k-1) {
									k--;
									// cout << "d2 move board[r][c] rc: " << r << ", " << c << ", k: " << k << endl;
									board[r][k] = board[r][c];
									board[r][c] = 0;
								}
								break;
							}
							else if(board[r][k] == 0 && k == N-1) {
								board[r][k] = board[r][c];
								board[r][c] = 0;
							}
						}
					}
				}
			}
			break;
		case 3: // Down
			for(int c=0; c<N; c++) {
				for(int r=N-1; r>=0; r--) {
					if(board[r][c] != 0) {

						for(int k=r+1; k<N; k++) {
							if(board[k][c]) {
								// cout << "d1 k: "<< k << ", rc: "<< r<< ", " << c << endl;
								if(k-1>=0 && k-1<N && r!=k-1) {
									k--;
									board[k][c] = board[r][c];
									board[r][c] = 0;
								}
								break;
							}
							else if(board[k][c] == 0 && k == N-1) {
								board[k][c] = board[r][c];
								board[r][c] = 0;
							}
						}
					}
				}
			}

			break;
		case 4: // Left
			for(int r=0; r<N; r++) {
				for(int c=0; c<N; c++) {
					if(board[r][c] != 0) {

						for(int k=c-1; k>=0; k--) {
							if(board[r][k]) {
								if(k+1>0 && k+1<N && c != k+1) {
									k++;
									board[r][k] = board[r][c];
									board[r][c] = 0;
								}
								break;
							}
							else if(board[r][k] == 0 && k == 0) {
								board[r][k] = board[r][c];
								board[r][c] = 0;
							}

						}
					}
				}
			}
			break;
	}

#if DEBUG
	cout << "IN Move()" << endl;
	for(int i=0; i<N;i++){
		for(int j=0;j<N;j++){
			cout << board[i][j] << ' ';
		}
		cout << endl;
	}
#endif
}



int Solve(string s) {
	for(int i=0; i<s.size(); i++) {
		int d = s[i] - '0';

#if DEBUG
		cout << "d: " << d<< endl;
#endif
		Sum(d);
		Move(d);

#if DEBUG
		cout<< endl;
#endif
	}

	int result = -1;
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			if(result < board[i][j]) {
				result = board[i][j];
			}
		}
	}

	return result;
}

int main(int argc, char **argv){
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	vector<string> v;
	string s;

	for(int i=1; i<=4; i++) {
		for(int j=1; j<=4; j++) {
			for(int k=1; k<=4; k++) {
				for(int x=1; x<=4; x++) {
					for(int y=1; y<=4; y++) {
						string n1 = to_string(y);
						string n2 = to_string(x);
						string n3 = to_string(k);
						string n4 = to_string(j);
						string n5 = to_string(i);

						// if(n1 == n2) continue;
						// if(n2 == n3) continue;
						// if(n3 == n4) continue;
						// if(n4 == n5) continue;

						s = n1 + n2 + n3 + n4 + n5;
						v.push_back(s);
						s.clear();
					}
				}
			}
		}
	}

	// std::cout << "Debug01" << std::endl;
	cin >> N;
	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			cin >> board[i][j];
			tmpboard[i][j] = board[i][j];
		}
	}

	// for(auto it : v) {
	// 	cout << it << endl;
	// }
	// cout << v.size() << endl;

	// std::cout << "Debug02" << std::endl;
	int max_val = 2;

#if DEBUG
	v.clear();
	v.push_back("43412");
#endif

	for(int k=0; k<v.size(); k++) {
		string s = v[k];

		for(int i=0; i<N; i++){
			for(int j=0; j<N; j++){
				board[i][j] = tmpboard[i][j];
			}
		}

		// for(int i=0; i<N; i++){
		// 	for(int j=0; j<N; j++){
		// 		cout << board[i][j] << ' ';
		// 	}
		// 	cout << endl;
		// }

		// cout << "IN s: " << s << endl;

		int result = Solve(s);

		// cout << "result: " << result <<  endl;

		if(result > max_val) {
			max_val = result;
			// if(max_val == 128) cout << s << endl;
		}
	}

	// std::cout << "Debug04" << std::endl;
	cout << max_val;


	return 0;
}

