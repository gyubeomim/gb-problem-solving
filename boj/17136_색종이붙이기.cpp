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

int ans=40;
int paper_num = 0;
int board[10][10] = {0};

int cnt[6];

bool IsValid(int r, int c, int num) {
	if(c+num > 10 || r+num > 10 || cnt[num] <= 0) 
		return false;

	for(int i=r; i<r+num; i++) {
		for(int j=c; j<c+num; j++) {
			if(board[i][j] == 0) {
				return false;
			}
		}
	}
	return true;
}

void ZeroFill(int r, int c, int num) {
	cnt[num]--;

	for(int i=r; i<r+num; i++) {
		for(int j=c; j<c+num; j++) {
			board[i][j] = 0;
		}
	}

	paper_num -= num*num;

	// if(num == 1) {
	// 	cout << "ZEROFILL" << endl;
	// 	for(int i=0; i<10; i++) {
	// 		for(int j=0; j<10; j++) {
	// 			if(i == r && j == c)
	// 				cout << "* ";
	// 			else 
	// 				cout << board[i][j] << ' ';
	// 		}
	// 		cout << endl;
	// 	}
	// }
}

void Undo(int r, int c, int num) {
	cnt[num]++;

	for(int i=r; i<r+num; i++) {
		for(int j=c; j<c+num; j++) {
			board[i][j] = 1;
		}
	}

	paper_num += num*num;

	// if(num == 1) {
	// 	cout << "UNDO" << endl;
	// for(int i=0; i<10; i++) {
	// 	for(int j=0; j<10; j++) {
	// 		if(i == r && j == c)
	// 			cout << "! ";
	// 		else 
	// 			cout << board[i][j] << ' ';
	// 	}
	// 	cout << endl;
	// }
	// }
}


void DFS(int a, int b, int depth) {
	if(paper_num == 0) {
		ans = min(ans, depth);
		return;
	}
	
	for(int i=a; i<10; i++) {
		for(int j=b; j<10; j++) {
			if(board[i][j] == 1) {
				for(int k=5; k>=1; k--) {
					if(IsValid(i,j,k)) {
						ZeroFill(i,j,k);
						DFS(i, j+k, depth+1);
						Undo(i,j,k);
					}
				}
				return;
			}
		}
		b=0;
	}
}



int main(int argc, char **argv){
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	for(int i=0;i<10;i++){
		for(int j=0;j<10;j++){
			cin >> board[i][j];

			if(board[i][j] == 1) {
				paper_num++;
			}
		}
	}

	for(int i=1; i<=5;i++){
		cnt[i] = 5;
	}

	DFS(0,0,0);

	if(ans == 40)
		cout << "-1";
	else 
		cout << ans;

	return 0;
}
