#include <bits/stdc++.h>

using namespace std;

int N,M;

vector<pair<int,int>> chics;
int board[51][51] = {};

int CheckDistance(int r, int c) {
	int mindist = 9999;

	for(int i=1;i<=N;i++){
		for(int j=1; j<=N; j++){ 
			if(board[i][j] == 2) {
				int dist = abs(i-r) + abs(j-c);
				mindist = min(dist, mindist);
			}
		}
	}

	return mindist;
}

int main(int argc, char **argv){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	


	cin>>N>>M;

	for(int i=1;i<=N;i++){
		for(int j=1; j<=N; j++){ 
			cin >> board[i][j];

			if(board[i][j] == 2) {
				chics.push_back(make_pair(i,j));
				board[i][j] = 0;
			}
		}
	}
		
	int minsum = 9999;

	vector<int> tmpv;
	for(int i=0; i<chics.size()-M; i++){
		tmpv.push_back(0);
	}
	for(int i=0; i<M; i++){
		tmpv.push_back(1);
	}

	do {
		vector<int> dists;
	
		// cout << "chics: ";
		// for(auto it : chics) {
		// 	cout << "("<< it.first << ", " << it.second << ")" << ' ';
		// }cout<<endl;

		// cout << "tmpv: " ;
		// for(auto it : tmpv) {
		// 	cout << it << ' ';
		// } cout<< endl;

		// cout << "chics: ";
		// for(int j=0; j<tmpv.size(); j++) {
		// 	if(tmpv[j] == 1) {
		// 		cout << "("<< chics[j].first << ", " << chics[j].second << ")" << ' ';
		// 	}
		// }cout<<endl;
		
		// Initialize
		for(int j=0; j<tmpv.size(); j++) {
			if(tmpv[j] == 1) {
				int r = chics[j].first;
				int c = chics[j].second;
				board[r][c] = 2;
			}
		}

		for(int i=1;i<=N;i++){
			for(int j=1; j<=N; j++){ 
				if(board[i][j] == 1) {
					int d = CheckDistance(i,j);
					dists.push_back(d);
				}
			}
		}

		sort(dists.begin(), dists.end());

		// cout << "dists is : ";
		// for(auto it : dists) {
		// 	cout << it << ' ';
		// }
		// cout << endl;

		int sum=0;
		for(auto it : dists){
			sum += it;
		}
		
		minsum = min(minsum, sum);

		// Clear values
		dists.clear();
		for(int i=1;i<=N;i++){
			for(int j=1; j<=N; j++){ 
				if(board[i][j] == 2) {
					board[i][j] = 0;
				}
			}
		}


	} while (next_permutation(tmpv.begin(), tmpv.end()));
		
	cout << minsum;


	return 0;
}
