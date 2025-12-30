#include <bits/stdc++.h>

using namespace std;

int N,M,K;
int **A;
int **board;
vector<int> **trees;
vector<int> **dead_trees;

const int dr[] = {-1, -1, -1, 0, 0, 1, 1, 1};
const int dc[] = {-1, 0, 1, -1, 1, -1, 0, 1};

void Spring() {
	for(int i=1;i<=N;i++){
		for(int j=1;j<=N;j++){
			sort(trees[i][j].begin(), trees[i][j].end());
			
			for(int k=0; k<trees[i][j].size(); k++) {
				if(board[i][j] >= trees[i][j][k]) {
					// cout << "Spring BF feed ij: " << i << ", " << j << ", board[i][j]: " << board[i][j] << ", trees[i][j][k]: " << trees[i][j][k] << endl;
					board[i][j] -= trees[i][j][k];
					trees[i][j][k] += 1;
					// cout << "Spring AFT feed ij: " << i << ", " << j << ", board[i][j]: " << board[i][j] << ", trees[i][j][k]: " << trees[i][j][k] << endl;
				}
				else {
					// cout << "Spring BF dead ij: " << i << ", " << j << ", trees[i][j][k]: " << trees[i][j][k]  << ", tree size: " << trees[i][j].size() << ", dead tree size: " << dead_trees[i][j].size()  << endl;

					for(int z=k; z<trees[i][j].size(); z++) {
						dead_trees[i][j].push_back(trees[i][j][z]);
					}
					trees[i][j].erase(trees[i][j].begin() + k, trees[i][j].end());
					break;
					// cout << "Spring AFT dead ij: " << i << ", " << j << ", trees[i][j][k]: " << trees[i][j][k]  << ", tree size: " << trees[i][j].size() << ", dead tree size: " << dead_trees[i][j].size()  << endl;
				}
			}

			
		}
	}


}

void Summer() {
	for(int i=1;i<=N;i++){
		for(int j=1;j<=N;j++){
			for(int k=0; k<dead_trees[i][j].size(); k++) {
				// cout << "Summer BF dead feeding ij: " << i << ", " << j << ", dead tree size: " << dead_trees[i][j].size()  << endl;
				board[i][j] += (int)dead_trees[i][j][k]/2;
				// cout << "Summer AFT dead feeding ij: " << i << ", " << j << ", dead tree size: " << dead_trees[i][j].size()  << endl;
			}
			dead_trees[i][j].clear();
			// dead_trees[i][j].erase(dead_trees[i][j].begin(), dead_trees[i][j].end());
		}
	}
}

void Fall() {
	for(int i=1;i<=N;i++){
		for(int j=1;j<=N;j++){
			sort(trees[i][j].begin(), trees[i][j].end());

			for(int k=0; k<trees[i][j].size(); k++) {
				if(trees[i][j][k] % 5 == 0 && trees[i][j][k] > 1 ) {
					// cout << "Fall BF breeding ij: " << i << ", " << j << ", tree size: " << trees[i][j].size() << ", trees[i][j][k]: " << trees[i][j][k]  << endl;
					for(int d=0; d<8; d++) {
						int nr = i + dr[d];
						int nc = j + dc[d];
						
						if(nr < 1 || nr > N || nc < 1 || nc > N) continue;

						// cout << "Fall BF breeding ij: " << i << ", " << j << ", nrnc: " << nr << ", " << nc << ", board[nr][nc]: " << board[nr][nc] << endl;
						// board[nr][nc] += 1;
						// cout << "Fall AFT breeding ij: " << i << ", " << j << ", nrnc: " << nr << ", " << nc << ", board[nr][nc]: " << board[nr][nc] << endl;
						trees[nr][nc].push_back(1);
						// sort(trees[nr][nc].begin(), trees[nr][nc].end());
					}
				}
			}
		}
	}
}

void Winter() {
	for(int i=1;i<=N;i++){
		for(int j=1;j<=N;j++){
			board[i][j] += A[i][j];
		}
	}
}

int main(int argc, char **argv){
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >>M>>K;

	A = new int*[N+1];
	for(int i=0; i<=N; i++){
		A[i] = new int[N+1];
	}
	// std::cout << "Debug-3" << std::endl;

	board = new int*[N+1];
	for(int i=0; i<=N; i++){
		board[i] = new int[N+1];
	}
	// std::cout << "Debug-2" << std::endl;

	trees = new vector<int>*[N+1];
	for(int i=0; i<=N; i++){
		trees[i] = new vector<int>[N+1];
	}
	// std::cout << "Debug-1" << std::endl;

	dead_trees = new vector<int>*[N+1];
	for(int i=0; i<=N; i++){
		dead_trees[i] = new vector<int>[N+1];
	}


	// std::cout << "Debug00" << std::endl;
	for(int i=1; i<=N; i++){
		for(int j=1; j<=N; j++) {
			board[i][j] = 5;
		}
	}

	for(int i=1; i<=N; i++){
		for(int j=1; j<=N; j++) {
			cin >> A[i][j];
		}
	}

	for(int i=0;i<M;i++){
		int x, y, f;
		cin>>x>>y>>f;

		trees[x][y].push_back(f);
	}

	int year=0;
	
	// std::cout << "Debug01" << std::endl;
	while(year < K) {
		// cout << "YEAR: " << year << endl;

		Spring();
		Summer();
		Fall();
		Winter();

		year++;
	}

	// std::cout << "Debug02" << std::endl;
	int ans=0;
	for(int i=1; i<=N; i++){
		for(int j=1; j<=N; j++){
			ans += trees[i][j].size();

			// if(!trees[i][j].empty()) {
			// 	cout << "living trees ij: " << i << ", " << j << ", size: " << trees[i][j].size() << endl;
			// 	cout << "TREE: ";
			// 	for(auto t : trees[i][j]) {
			// 		cout << t << ' ';
			// 	} cout << endl;
            //
			// 	cout << "BOARD: ";
			// 	cout << board[i][j] << ' ';
			// 	cout << endl;
			// }
		}
	}
	

	// std::cout << "Debug03" << std::endl;
	cout << ans;
	 

	return 0;
}
