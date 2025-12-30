#include <iostream>
#include <utility>
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
int NUM_CCTV=0;
int board[8][8];
int tmpboard[8][8];
vector<int> ans;
string s;

int one = 4;
int two = 2;
int three = 4;
int four = 4;
int five = 1;

struct Surv {
	string name;
	int r;
	int c;
};

vector<pair<Surv,int>> v;

// dir 
// 0: >
// 1: ^
// 2: <
// 3: v
void Check(int dir, int sr, int sc) {
	if(dir == 0) { // >
		for(int c=sc; c<M; c++){
			if(board[sr][c] == 6) break;
			if(board[sr][c] >= 1 && board[sr][c] <=5) continue;
			// cout << "sr,c : " << sr << ", " << c << endl;
			board[sr][c] = -1;
		}
	}
	else if(dir == 1) { // ^
		for(int r=sr; r>=0; r--){
			if(board[r][sc] == 6) break;
			if(board[r][sc] >= 1 && board[r][sc] <=5) continue;
			board[r][sc] = -1;
		}
	}
	else if(dir == 2) { // <
		for(int c=sc; c>=0; c--){
			if(board[sr][c] == 6) break;
			if(board[sr][c] >= 1 && board[sr][c] <=5) continue;
			board[sr][c] = -1;
		}
	}
	else if(dir == 3) { // v
		for(int r=sr; r<N; r++){
			if(board[r][sc] == 6) break;
			if(board[r][sc] >= 1 && board[r][sc] <=5) continue;
			board[r][sc] = -1;
		}
	}
}

void Surveillance(Surv cctv, int dir) {
	if(cctv.name == "one") {
		switch(dir){
			case 0:  // >
				Check(0, cctv.r, cctv.c);
				break;
			case 1:  // ^
				Check(1, cctv.r, cctv.c);
				break;
			case 2:  // <
				Check(2, cctv.r, cctv.c);
				break;
			case 3:  // v
				Check(3, cctv.r, cctv.c);
				break;
		}
	}
	else if(cctv.name == "two") {
		switch(dir){
			case 0:  // <>
				Check(0, cctv.r, cctv.c);
				Check(2, cctv.r, cctv.c);
				break;
			case 1:  // ^v
				Check(1, cctv.r, cctv.c);
				Check(3, cctv.r, cctv.c);
				break;
		}

	}
	else if(cctv.name == "three") {
		switch(dir){
			case 0:  // ^>
				Check(0, cctv.r, cctv.c);
				Check(1, cctv.r, cctv.c);
				break;
			case 1: // <^
				Check(1, cctv.r, cctv.c);
				Check(2, cctv.r, cctv.c);
				break;
			case 2: // <v
				Check(2, cctv.r, cctv.c);
				Check(3, cctv.r, cctv.c);
				break;
			case 3: // v>
				Check(3, cctv.r, cctv.c);
				Check(0, cctv.r, cctv.c);
				break;
		}

	}
	else if(cctv.name == "four") {
		switch(dir){
			case 0:  // <^>
				Check(0, cctv.r, cctv.c);
				Check(1, cctv.r, cctv.c);
				Check(2, cctv.r, cctv.c);
				break;
			case 1:  // v<^
				Check(1, cctv.r, cctv.c);
				Check(2, cctv.r, cctv.c);
				Check(3, cctv.r, cctv.c);
				break;
			case 2:  // <v>
				Check(2, cctv.r, cctv.c);
				Check(3, cctv.r, cctv.c);
				Check(0, cctv.r, cctv.c);
				break;
			case 3:  // v>^
				Check(3, cctv.r, cctv.c);
				Check(0, cctv.r, cctv.c);
				Check(1, cctv.r, cctv.c);
				break;
		}
	}
	else if(cctv.name == "five") {  // <v>^
		Check(0, cctv.r, cctv.c);
		Check(1, cctv.r, cctv.c);
		Check(2, cctv.r, cctv.c);
		Check(3, cctv.r, cctv.c);
	}
}

int Compute() {
	int result=0;
	
	for(int i=0; i<s.size(); i++){ 
		Surv cctv = v[i].first;
		int dir = s[i] - '0';

		// cout << "cctv name: " << cctv.name << ", r: " << cctv.r << ", c: " << cctv.c << ", dir: " << dir << endl;
		Surveillance(cctv, dir);
	}

	for(int r=0; r<N; r++){
		for(int c=0; c<M; c++){
			if(board[r][c] == 0) result++;
		}
	}
	// cout << endl;

	return result;
}

void dfs(int depth) {
	// cout << "depth: " << depth << endl;
	// cout << "v[depth].second: " << v[depth].second << endl;

	if(depth == NUM_CCTV) {
		// cout << "s: " << s << endl;
			
		for(int r=0; r<N; r++){
			for(int c=0; c<M; c++){
				board[r][c] = tmpboard[r][c];
			}
		}

		// cout << "board update\n";
		// for(int r=0; r<N; r++){
		// 	for(int c=0; c<M; c++){
		// 		cout << board[r][c] << ' ';
		// 	}
		// 	cout << endl;
		// }

		ans.push_back(Compute());

		// for(int i=0; i<v[depth-2].second;i++) {
		// 	cout << "erase" <<endl;
		// 	s.erase(s.end()-1);
		// }

		return;
	}

	for(int i=0; i<v[depth].second; i++){
		s[depth] = to_string(i)[0];
		// cout << "depth: " << depth << ", v[depth].second: " << v[depth].second << ", i: " << i << ", s2: " << s << endl;

		dfs(depth+1);
	}
}


int main(int argc, char **argv){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	cin >>N>>M;

	for(int i=0; i<N;i++){
		for(int j=0;j<M;j++){
			cin >> board[i][j];
			tmpboard[i][j] = board[i][j];

			if(board[i][j] >= 1 && board[i][j] <= 5) {
				Surv surv;
				surv.r = i;
				surv.c = j;
				switch(board[i][j]){
					case 1:
						surv.name = "one";
						v.push_back(make_pair(surv, one));
						break;
					case 2:
						surv.name = "two";
						v.push_back(make_pair(surv, two));
						break;
					case 3:
						surv.name = "three";
						v.push_back(make_pair(surv, three));
						break;
					case 4:
						surv.name = "four";
						v.push_back(make_pair(surv, four));
						break;
					case 5:
						surv.name = "five";
						v.push_back(make_pair(surv, five));
						break;
				}
				NUM_CCTV++;
			}
		}
	}

	// cout << "NUM_CCTV: " << NUM_CCTV << endl;
	// cout << "v: " << endl;
	// for(auto it  : v)  {
	// 	cout << it.first << ", " << it.second << endl;
	// }

	s.resize(NUM_CCTV);

	dfs(0);

	sort(ans.begin(), ans.end());

	// cout << "ans: " << endl;
	// for(auto it : ans ){
	// 	cout << it << ' ';
	// }
	// cout << endl;


	cout << ans[0];
	

	return 0;
}
