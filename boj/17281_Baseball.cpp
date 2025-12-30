#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int N;
int batter[51][10];
vector<int> Vs;

pair<int,int> Inning(int start, int n) {
	int out =0;
	int base[5] = {0,0,0,0,0};

	for(;;start++) {
		if(start > 9) start=1;

		base[0] = 1;

		int roo = batter[n][Vs[start-1]];

		if(roo == 0) {
			out++;
			if(out == 3) break;
			continue;
		}

		for(int k=0; k<roo; k++) {
			for(int j=3; j>=0; j--) {
				base[j+1] += base[j];
				base[j] = 0;
			}
		}
	}
	
	pair<int,int> ret;
	ret = {start+1, base[4]};
	return ret;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

	cin >> N;

	for(int i=1; i<=N; i++){
		for(int j=1; j<=9; j++){
			cin >> batter[i][j];
		}
	}

	for(int i=1;i<=9;i++){
		Vs.push_back(i);
	}
	
	int max_score=-1;
	do {
		if(Vs[3] != 1) 
			continue;
		
		int score=0;

		pair<int,int> s;
		s = {1,0};

		for(int n=1; n<=N; n++){
			int start = s.first;
			score += s.second;

			s = Inning(start, n);
		}
		score += s.second;
		max_score = max(max_score, score);

		 
	} while (next_permutation(Vs.begin(), Vs.end()));

	cout << max_score;


    return 0;
}
