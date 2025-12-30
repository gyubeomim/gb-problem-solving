#include <bits/stdc++.h>

using namespace std;



int used[100] = {0};


int main() {

	vector<vector<int>> v;

	int n;
	cin >> n;


	int a, b;
	cin >> a >> b;


	int m;
	cin >> m;


	v.resize(n+1);


	for(int i=0; i<m; i++) {
		int x,y;
		cin >> x >> y;

		v[x].push_back(y);
		v[y].push_back(x);
	}







	queue<int> Q;
	Q.push(a);

	int len = 1;

	while(!Q.empty()) {
		int qsize = Q.size();


		for(int i=0; i<qsize; i++) {
			int curr = Q.front();
			Q.pop();


			for(int j=0; j<v[curr].size(); j++) {
				int next = v[curr][j];

				if(next == b) {
					cout << len << '\n';
					return 0;
				}

				if(used[next]) continue;


				used[next] = 1;
				Q.push(next);
			}
		}
		len++;


	}

	cout << "-1\n";





	return 0;
}