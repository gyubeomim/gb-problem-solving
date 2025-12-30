#include <bits/stdc++.h>
#define X first
#define Y second
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
using namespace std;
using pii = pair<int ,int>;

const int LM = 200005;
int Q;
unordered_map<string, pii> ids;
int idcnt;

int main(int argc, char **argv){
	FASTIO
	#ifndef ONLINE_JUDGE
		freopen("data/d3943.txt", "r", stdin);
	#endif
	cin >> Q;
	while(Q--){
		int score;
		string s; 
		cin >> s >> score;

		transform(s.begin(), s.end(), s.begin(), ::tolower);

		if(ids.find(s) == ids.end()){
			ids[s] = {++idcnt, score};
		}
		else {
			ids[s].Y = max(ids[s].Y, score);
		}
		cout << ids[s].X << " " << ids[s].Y << '\n';
	}
}
