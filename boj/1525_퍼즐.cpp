#include <bits/stdc++.h>

using namespace std;

queue<int> Q;
map<int, int> dist;

const int dx[] = {-1,1,0,0};
const int dy[] = {0,0,-1,1};


void bfs() {
	while(!Q.empty()) {
		int n = Q.front();
		Q.pop();


		if(n == 123456789) {
			cout << dist[n] << '\n';
			return;
		}



		string s = to_string(n);
		int k = s.find('9');
		int x=k/3;
		int y=k%3;


		for(int d=0; d<4; d++) {
			int nx = x + dx[d];
			int ny = y + dy[d];



			if(nx < 0 || nx >= 3 || ny < 0 || ny >= 3) continue;

			int nk = nx*3 + ny;
			string ns = s;

			swap(ns[nk], ns[k]);

			int nn = stoi(ns);
			if(!dist[nn]) {
				dist[nn] = dist[n] + 1;
				Q.push(nn);
			}
		}
	}
	cout << "-1\n";
}

int main() {
	int n,m=0;
	for(int i=0;i<9;i++) {
		cin >> n;
		if(n==0) n = 9;
		m = m*10 + n;
	}
	Q.push(m);
	bfs();
	return 0;
}