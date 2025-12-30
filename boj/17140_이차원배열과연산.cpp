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

vector<pii> V;
int board[101][101]={0};
int R,C,K;
map<int, int> m;
vector<int> Ccand, Rcand;

int main(int argc, char **argv){
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin>>R>>C>>K;

	memset(board,0,sizeof(board));

	for(int r=1;r<=3;r++){
		for(int c=1; c<=3;c++){
			cin>>board[r][c];
		}
	}
	
	int t=0;
	int Rnum=3;
	int Cnum=3;

	while(true) {
		if(board[R][C] == K) {
			break;
		}

		if(t > 100) {
			t = -1;
			break;
		}
	
		// cout << "Rnum: "<< Rnum <<", Cnum: " << Cnum <<", t: "<< t << endl;
	
		if(Rnum >= Cnum) {
			// cout << "Doing Row-wise" << endl;
			// Col-wise
			for(int r=1;r<=Rnum;r++){
				m.clear();
				V.clear();

				for(int c=1; c<=Cnum;c++){
					if(board[r][c] == 0) continue;
					int num = board[r][c];
					m[num]++;
					// cout << "num: " << num << ", m[num]:" << m[num] << ", c: " << c << ", Cnum: " <<Cnum<<endl;
				}

				for(auto it : m) {
					V.push_back({it.first, it.second}); // number, count
				}

				sort(V.begin(), V.end(), [](const pii &a, const pii &b) {
						if(a.second == b.second) {
						return a.first < b.first;
						}
						else {
						return a.second < b.second;
						}
						});
				
				int ccand=0;
				for(int mc=1; mc<100; mc+=2) {
					if(V.empty()) {
						board[r][mc]=0;
						board[r][mc+1]=0;
						continue;
					}
					pii A = V[0];
					V.erase(V.begin());

					board[r][mc] = A.first;
					board[r][mc+1] = A.second;

					ccand = mc+1;
				}

				Ccand.push_back(ccand);
			}

			sort(Ccand.begin(), Ccand.end());
			Cnum = Ccand.back();
			Ccand.clear();

			// cout << "Complete Row-wise" << endl;
			// for(int r=1;r<=Rnum;r++){
			// 	for(int c=1; c<=Cnum;c++){
			// 		cout << board[r][c] << ' ';
			// 	}
			// 	cout << endl;
			// }
			// cout << endl;
		}
		else {
			// cout << "Doing Col-wise" << endl;
			// Row-wise
			for(int c=1; c<=Cnum;c++){
				m.clear();
				V.clear();

				for(int r=1; r<=Rnum;r++){
					if(board[r][c] == 0) continue;
					int num = board[r][c];
					m[num]++;
				}

				for(auto it : m) {
					V.push_back({it.first, it.second}); // number, count
				}

				sort(V.begin(), V.end(), [](const pii &a, const pii &b) {
						if(a.second == b.second) {
						return a.first < b.first;
						}
						else {
						return a.second < b.second;
						}
						});
				
				int rcand=0;
				for(int mr=1; mr<100; mr+=2) {
					if(V.empty()) {
						board[mr][c]=0;
						board[mr+1][c]=0;
						continue;
					}
					pii A = V[0];
					V.erase(V.begin());

					board[mr][c] = A.first;
					board[mr+1][c] = A.second;

					rcand=mr+1;
				}

				Rcand.push_back(rcand);
			}

			sort(Rcand.begin(), Rcand.end());
			Rnum = Rcand.back();
			Rcand.clear();

			// cout << "Complete Col-wise" << endl;
			// for(int r=1;r<=Rnum;r++){
			// 	for(int c=1; c<=Cnum;c++){
			// 		cout << board[r][c] << ' ';
			// 	}
			// 	cout << endl;
			// }
			// cout << endl;
		}

		t++;
	}

	cout << t;


	return 0;
}
