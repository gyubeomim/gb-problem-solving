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

int board[20][20];

int N, M;

bool IsValidMovement(int r, int c) {
	if(r <0 || r>N-1 || c<0 || c>M-1) {
		return false;
	}
		return true;
}

struct Dice {
	int Up;
	int Down;
	int Left;
	int Right;
	int Center;
	int Top;
	
	int Val[7] = {0};

	void Debug() {
		cout << "--------------------------" << endl;
		cout << ' ' << Top  << ' '<< endl;
		cout << ' ' << Up  << ' '<< endl;
		cout << Left << Center << Right << endl;
		cout << ' ' << Down << ' ' << endl;
		cout << ' ' << Top  << ' '<< endl;
		cout << "--------------------------" << endl;
	}

	void DebugVal() {
		cout << "--------------------------" << endl;
		cout << ' ' << Val[Top]  << ' '<< endl;
		cout << ' ' << Val[Up]  << ' '<< endl;
		cout << Val[Left] << Val[Center] << Val[Right] << endl;
		cout << ' ' << Val[Down] << ' ' << endl;
		cout << ' ' << Val[Top]  << ' '<< endl;
		cout << "--------------------------" << endl << endl;
		cout << Val[0] << Val[1] << Val[2] << Val[3] << Val[4] << Val[5] << Val[6] << endl;
		cout << "==========================" << endl << endl;
	}

	void Print() {
		cout << Val[Top] << '\n';
	}

	bool RollD1(int &r, int &c) { // Right
		if(!IsValidMovement(r, c+1)) return false;

		c++;

		// Val[7-Left] = Val[Top];
		// Val[Top] = Val[Left];
		// Val[Left] = Val[Center];
		// Val[Center] = Val[Right];
		// Val[Right] = Val[7 - Left];

		Left = Center;
		Center = Right;
		Right = 7 - Left;
		Top = 7 - Center;
		
		return true;
	}

	bool RollD2(int &r, int &c) { // Left
		if(!IsValidMovement(r, c-1)) return false;

		c--;

		// Val[7-Right] = Val[Top];
		// Val[Top] = Val[Right];
		// Val[Right] = Val[Center];
		// Val[Center] = Val[Left];
		// Val[Left] = Val[7 - Right];

		Right = Center;
		Center = Left;
		Left = 7 - Right;
		Top = 7 - Center;

		return true;
	}

	bool RollD3(int &r, int &c) { // Up
		if(!IsValidMovement(r-1, c)) return false;

		r--;

		// Val[7-Down] = Val[Top];
		// Val[Top] = Val[Down];
		// Val[Down] = Val[Center];
		// Val[Center] = Val[Up];
		// Val[Up] = Val[7 - Down];

		Down = Center;
		Center = Up;
		Up = 7-Down;
		Top = 7 - Center;

		return true;
	}

	bool RollD4(int &r, int &c) { // Down
		if(!IsValidMovement(r+1, c)) return false;

		r++;

		// Val[7-Up] = Val[Top];
		// Val[Top] = Val[Up];
		// Val[Up] = Val[Center];
		// Val[Center] = Val[Down];
		// Val[Down] = Val[7 - Up];
	
		Up = Center;
		Center = Down;
		Down = 7 - Up;
		Top = 7 - Center;

		return true;
	}

	void Copy(int r, int c) {

		// cout << "Copy rc: " << r << ", " << c << ", board[r][c]: " << board[r][c] << endl;
		// cout << "Val[Center]: " << Val[Center] << endl;

		if(board[r][c] != 0) {
			Val[Center] = board[r][c];
			board[r][c] = 0;

			// cout << "1 Copied from board[r][c]: " << board[r][c] << ", to Val[Center]: " << Val[Center] << endl;
		}
		else {
			board[r][c] = Val[Center];
			// cout << "2 Copied from Val[Center]: " << Val[Center] << ", board[r][c]: " << board[r][c] << endl;
		}

		// cout << "Copied Done rc: "<< r << ", " << c << endl;
		// DebugVal();
	}
};

int main(int argc, char **argv){
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int sr,sc, K;

	cin >> N >> M >>sr>>sc>>K;

	for(int i=0; i<N;i++){
		for(int j=0;j<M; j++){
			cin >> board[i][j];
		}
	}

	vector<int> commands;
	for(int i=0;i<K;i++){
		int c;
		cin>>c;
		commands.push_back(c);
	}

	Dice dice;
	dice.Center = 6;
	dice.Up = 2;
	dice.Down = 5;
	dice.Left = 4;
	dice.Right = 3;

	int r = sr;
	int c = sc;

	for(int i=0; i<commands.size(); i++) {
		int cur_cmd = commands[i];

		// cout << "cur r,c: " << r << ", " << c << ", cmd: " << cur_cmd << endl;

		switch(cur_cmd) {
			case 1:
				if(dice.RollD1(r,c)) {
					// cout << "D1 Valid rc: " << r << ", " << c << endl;
					dice.Copy(r, c);
					dice.Print();
				}
				break;
			case 2:
				if(dice.RollD2(r,c)) {
					// cout << "D2 Valid rc: " << r << ", " << c << endl;
					dice.Copy(r, c);
					dice.Print();
				}
				break;
			case 3:
				if(dice.RollD3(r,c)) {
					// cout << "D3 Valid rc: " << r << ", " << c << endl;
					dice.Copy(r, c);
					dice.Print();
				}
				break;
			case 4:
				if(dice.RollD4(r,c)) {
					// cout << "D4 Valid rc: " << r << ", " << c << endl;
					dice.Copy(r, c);
					dice.Print();
				}
				break;
		}


	}
	
	 
	return 0;
}
