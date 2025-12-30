#include <bits/stdc++.h>

using namespace std;

int board[100][100] = {0};
int avail[100][100] = {1};
int connect[100][100] = {1};
int N,L;

bool IsValidCoord(int r, int c) {
	if(r < 0 || r > N-1 || c < 0 || c > N-1) return false;

	return true;
}

int main(int argc, char **argv){
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin>>N>>L;

	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			cin >> board[i][j];
		}
	}

	memset(avail, 1 ,sizeof(avail));
	memset(connect, 0 ,sizeof(connect));
	
	// For Row
	for(int r=0; r<N; r++) {
		for(int c=0; c<N; c++) {
			if(c == 0) {
				connect[r][c] = 1;
				continue;
			}

			int val = board[r][c];
			
			if(IsValidCoord(r, c-1)) {
				int prevval = board[r][c-1];
				
				if(prevval == val) {
					connect[r][c] = 1;
				}
				else if(prevval - val == 1) {
					bool avail_flag = true;

					for(int i=0; i<L; i++) {
						if(IsValidCoord(r, c+i)) {
							if(board[r][c+i] != val || !avail[r][c+i]) {
								avail_flag = false;
								break;
							}
						}
						else {
							avail_flag = false;
							break;
						}
					}
					
					if(avail_flag) {
						for(int i=0; i<L; i++) {
							avail[r][c+i] = 0;
						}

						connect[r][c] = 1;
					}

				}
				else if(val - prevval == 1) {
					bool avail_flag = true;

					for(int i=0; i<L; i++) {
						if(IsValidCoord(r, c-1-i)) {
							if(board[r][c-1-i] != prevval || !avail[r][c-1-i]) {
								avail_flag = false;
								break;
							}
						}
						else {
							avail_flag = false;
							break;
						}
					}
					
					if(avail_flag) {
						for(int i=0; i<L; i++) {
							avail[r][c-1-i] = 0;
						}
						// cout << "AVAIL rc: " << r << ", " << c << endl;
						connect[r][c] = 1;
					}
				}
			}
		}

		// for(int c=0; c<N-1; c++) {
		// 	int first = board[r][c];
		// 	int second = board[r][c+1];
        //
		// 	if(first == second) {
		// 		connect[r][c] = 1;
		// 		connect[r][c+1] = 1;
		// 	}
		// 	else if(first - second == 1) {
		// 		bool avail_flag = true;
        //
		// 		for(int i=0; i<L; i++) {
		// 			if(IsValidCoord(r, c+1+i)) {
		// 				if(board[r][c+1+i] != second && avail[r][c+1+i]) {
		// 					connect[r][c] = 0;
		// 					avail_flag = false;
		// 				}
		// 			}
		// 			else {
		// 				connect[r][c] = 0;
		// 				avail_flag = false;
		// 			}
		// 		}
		// 		
		// 		if(avail_flag) {
		// 			for(int i=0; i<L; i++) {
		// 				if(IsValidCoord(r, c+1+i)) {
		// 					avail[r][c+1+i] = 0;
		// 					connect[r][c] = 1;
		// 					connect[r][c+1+i] = 1;
		// 				}
		// 				else {
		// 					connect[r][c] = 0;
		// 				}
		// 			}
		// 		}
        //
		// 	}
		// 	else if(second - first == 1) {
		// 		bool avail_flag = true;
        //
		// 		for(int i=0; i<L; i++) {
		// 			if(IsValidCoord(r, c-i)) {
		// 				if(board[r][c-i] != second && avail[r][c-i]) {
		// 					connect[r][c] = 0;
		// 					avail_flag = false;
		// 				}
		// 			}
		// 			else {
		// 				connect[r][c] = 0;
		// 				avail_flag = false;
		// 			}
		// 		}
		// 		
		// 		if(avail_flag) {
		// 			for(int i=0; i<L; i++) {
		// 				if(IsValidCoord(r, c-i)) {
		// 					avail[r][c-i] = 0;
		// 				}
		// 				else {
		// 					break;
		// 				}
		// 			}
		// 		}
        //
		// 	}
		// }
	}

	int rcnt = 0;
	for(int r=0; r<N; r++) {
		bool all_connected = true;

		for(int c=0; c<N; c++) {
			if(connect[r][c] == 0) {
				all_connected = false;
				// cout << "Rowwise: not connected rc: " << r << ", " << c << endl;
				break;
			}
		}

		if(all_connected) {
			rcnt += 1;
		}
	}
	
	// cout << "Row connect: " << endl;
	// for(int r=0; r<N; r++){
	// 	for(int c=0; c<N; c++) {
	// 		cout << connect[r][c] << ' ';
	// 	}
	// 	cout << endl;
	// }

	memset(avail, 1 ,sizeof(avail));
	memset(connect, 0 ,sizeof(connect));

	// For Col
	for(int c=0; c<N; c++) {
		for(int r=0; r<N; r++) {
			if(r == 0) {
				connect[r][c] = 1;
				continue;
			}

			int val = board[r][c];
			
			if(IsValidCoord(r-1, c)) {
				int prevval = board[r-1][c];
				
				if(prevval == val) {
					connect[r][c] = 1;
				}
				else if(prevval - val == 1) {
					bool avail_flag = true;

					for(int i=0; i<L; i++) {
						if(IsValidCoord(r+i, c)) {
							if(board[r+i][c] != val || !avail[r+i][c]) {
								avail_flag = false;
								break;
							}
						}
						else {
							avail_flag = false;
							break;
						}
					}
					
					if(avail_flag) {
						for(int i=0; i<L; i++) {
							avail[r+i][c] = 0;
						}

						connect[r][c] = 1;
					}

				}
				else if(val - prevval == 1) {
					bool avail_flag = true;

					for(int i=0; i<L; i++) {
						if(IsValidCoord(r-1-i, c)) {
							if(board[r-1-i][c] != prevval || !avail[r-1-i][c]) {
								avail_flag = false;
								break;
							}
						}
						else {
							avail_flag = false;
							break;
						}
					}
					
					if(avail_flag) {
						for(int i=0; i<L; i++) {
							avail[r-1-i][c] = 0;
						}
						connect[r][c] = 1;
					}
				}
			}
		}
	}

	// cout << "Col connect: " << endl;
	// for(int r=0; r<N; r++){
	// 	for(int c=0; c<N; c++) {
	// 		cout << connect[r][c] << ' ';
	// 	}
	// 	cout << endl;
	// }

	int ccnt = 0;
	// cout << endl;
	for(int c=0; c<N; c++) {
		bool all_connected = true;

		for(int r=0; r<N; r++) {
			if(connect[r][c] == 0) {
				all_connected = false;
				// cout << "Colwise: not connected rc: " << r << ", " << c << endl;
				break;
			}
		}

		if(all_connected) {
			ccnt += 1;
		}
	}
	cout << rcnt + ccnt;

	return 0;
}
